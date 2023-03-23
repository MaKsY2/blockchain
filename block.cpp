#include "block.hpp"

#include <openssl/sha.h>

Block::Block(int index, const std::string &data, const std::string &prevHash) : m_index(index),
                                                                                m_data(data),
                                                                                m_prevHash(prevHash),
                                                                                m_nonce(0)
{
}

void Block::mine(int difficult)
{
    std::string target(difficult, '0');
    std::string hash;
    do
    {
        hash = calculateHash();
        // std::cout << hash << std::endl;
        m_nonce++;
    } while (hash.substr(0, difficult) != target);

    m_hash = hash;
}

std::string Block::calculateHash()
{
    std::stringstream ss;
    ss << m_index << m_data << m_prevHash << m_nonce;
    std::string input = ss.str();

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss2;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss2 << std::hex << (int)hash[i];
    }

    return ss2.str();
}