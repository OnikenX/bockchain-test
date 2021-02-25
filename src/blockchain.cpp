#include "blockchain.h"

#include <utility>

Blockchain::Blockchain() {
    Block genesis = createGenesisBlock();
    chain.push_back(genesis);

}

Block Blockchain::createGenesisBlock() {
    time_t current;
    TransactionData d;
    d.amount = 0;
    d.receiverKey = "None";
    d.senderKey = "None";
    d.timestamp = time(&current);
    std::hash<int> hash1;
    Block genesis(0, d, hash1(0));
    return genesis;
}


Block &Blockchain::getLatestBlock() {
    return chain.back();
}

void Blockchain::addBlock(TransactionData &data) {
    int index = (int)chain.size() -1;
    Block newBlock(index, data, getLatestBlock().getHash());
}

bool Blockchain::isChainValid() {
    for(auto &it : chain){
        if(!it.isHashValid())
            return false;
        if(chain.size() > 1)
            if(it.getPreviousHash() != std::prev(&it)->getHash())
                return false;
    }
    return true;
}


