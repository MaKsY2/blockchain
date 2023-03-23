#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include <vector>
#include <ctime>
#include <mutex>

#include "block.hpp"

class Blockchain
{
private:
    std::vector<Block> m_blocks;
    std::mutex m_mutex;

public:
    void addBlock(std::string data);
    void print();
    Blockchain();
    ~Blockchain();
};

#endif
