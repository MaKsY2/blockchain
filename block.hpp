#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <iostream>
#include <sstream>

class Block
{
public:
    Block(int index, const std::string &data, const std::string &prevHash);

    void mine(int difficult);
    std::string calculateHash();
    int getIndex() const { return m_index; }
    std::string getData() const { return m_data; }
    std::string getPrevHash() const { return m_prevHash; }
    std::string getHash() const { return m_hash; }

private:
    int m_index;
    std::string m_data;
    std::string m_prevHash;
    std::string m_hash;
    int m_nonce;
};

#endif
