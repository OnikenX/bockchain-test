#ifndef TRANSACTIONDATA_H
#define TRANSACTIONDATA_H

#include <ctime>
#include <string>
#include <utility>

struct TransactionData
{
    double amount{};
    std::string senderKey{};
    std::string receiverKey{};
    time_t timestamp{};

    TransactionData(double amount, const std::string &senderKey, const std::string &receiverKey, time_t timestamp)
            : amount(amount), senderKey(senderKey), receiverKey(receiverKey), timestamp(timestamp) {}

    TransactionData() {}
};

#endif // TRANSACTIONDATA_H
