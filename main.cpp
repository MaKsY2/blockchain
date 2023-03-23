#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <fstream>

#include "blockchain.hpp"

unsigned int my_hardware_concurrency();

int main()
{

    unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " threads are working right now " << std::endl;
    Blockchain blockchain;
    blockchain.addBlock("Hello");
    blockchain.addBlock("World");
    blockchain.print();

    return 0;
}

unsigned int my_hardware_concurrency()
{
    std::ifstream cpuinfo("/proc/cpuinfo");

    return std::count(std::istream_iterator<std::string>(cpuinfo),
                      std::istream_iterator<std::string>(),
                      std::string("processor"));
}