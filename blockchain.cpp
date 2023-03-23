#include "blockchain.hpp"

#include <ctime>
#include <sstream>
#include <iomanip>
#include <thread>

const int BLOCK_DIFF = 2;

Blockchain::Blockchain()
{
    m_blocks.emplace_back(Block(0, "Genesis Block", ""));
    m_blocks[0].mine(BLOCK_DIFF);
}

Blockchain::~Blockchain()
{
}

void Blockchain::addBlock(std::string data)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    int index = m_blocks.size();
    std::string prevHash = m_blocks.back().getHash();
    Block block(index, data, prevHash);

    std::cout << "Mining block " << index << "..." << std::endl;

    std::vector<std::thread> threads;
    for (int i = 0; i < std::thread::hardware_concurrency(); i++)
    {
        threads.emplace_back([this, &block]()
                             { block.mine(BLOCK_DIFF); });
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    m_blocks.push_back(block);

    std::cout << "Block " << index << " mined with hash: " << block.getHash() << std::endl;
}

void Blockchain::print()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    for (const auto &block : m_blocks)
    {
        std::cout << "Block " << block.getIndex() << " (" << block.getData() << ") with hash: " << block.getHash() << std::endl;
    }
}