#include "block.h"

Block::Block(int index, TransactionData transactionData, size_t previousHash ): index(index),previousHash(previousHash)
{
    data = std::move(transactionData);
    blockHash = generateHash();
}

const TransactionData &Block::getData() const {
    return data;
}

size_t Block::generateHash() {
    std::hash<std::string> hash1;
    std::hash<size_t> hash2;
    std::hash<size_t> finalHash;
    std::string toHash =
            std::to_string(data.amount)+
            data.receiverKey +
            data.senderKey + std::to_string(data.timestamp);

    return finalHash(hash1(toHash)+hash2(previousHash));
}

size_t Block::getPreviousHash() {
    return previousHash;
}

size_t Block::getHash() {
    return blockHash;
}

bool Block::isHashValid() {
    return generateHash() == blockHash;
}


