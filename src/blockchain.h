#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <src/block.h>



class Blockchain
{
    Block createGenesisBlock();


public:
    std::vector<Block> chain;
    Blockchain();


    void addBlock(TransactionData &data);
    bool isChainValid();

    Block& getLatestBlock();
};

#endif // BLOCKCHAIN_H
