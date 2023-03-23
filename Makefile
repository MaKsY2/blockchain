all: Blockchain

Blockchain: main.o blockchain.o block.o
	g++ main.o blockchain.o block.o -o block  --std c++20 -I/usr/local/include -L/usr/local/lib -lcrypto -lssl

main.o: main.cpp
	g++ -c main.cpp --std c++20 

blockchain.o: blockchain.cpp
	g++ -c blockchain.cpp --std c++20

block.o: block.cpp
	g++ -c block.cpp --std c++20 
	
clean:
	rm -rf *.o hello