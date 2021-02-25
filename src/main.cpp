//
// Created by onikenx on 22/02/21.
//

#include <iostream>
#include "blockchain.h"

void testBlockchain(){
    //init
    Blockchain awesomecoin;

    //data for first added block
    TransactionData data1(1.5, "Joe", "Sally", time(nullptr));
    time_t now = time(nullptr);
    std::cout << ctime(&now) << std::endl;

    std::cout << "is chain valid: "<< awesomecoin.isChainValid() << std::endl;
}

void testprev(){
 std::vector<int> valores;
 for(int i =1 ; i <= 10; ++i)
     valores.push_back(i);
 for(auto it = valores.begin(); it!=valores.end();++it)
     std::cout << "actual: "<< *it << "; prev:" << *std::prev(it) << std::endl;
}

int main(){
    testprev();
    return 0;
}