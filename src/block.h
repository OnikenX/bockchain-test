#ifndef BLOCK_H
#define BLOCK_H

#include <ctime>
#include <src/transactiondata.h>
#include <vector>

class Block
{
private:
    int index;
    size_t blockHash;
    size_t previousHash;
    size_t generateHash();

    //transaction data
    TransactionData data;

public:


    Block(int index, TransactionData transactionData, size_t previousHash );

    //get original hash
    size_t getHash();

    //get previous hash
    size_t getPreviousHash();



    const TransactionData &getData() const;

    //validate hash
    bool isHashValid();

};

#endif // BLOCK_H
