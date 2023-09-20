//
// Created by Mohamed Abdelhady on 9/19/2023.
//

#ifndef BANK_SYSTEM_CLIENT_H
#define BANK_SYSTEM_CLIENT_H

#include "Person.h"
#include "Transaction.h"
#include <memory>

namespace Model {
    class Client : public Person {
    private:
        double balance{};
        std::vector<std::shared_ptr<Model::Transaction>> transactionHistory;

    public:
        using Person::Person;
        explicit Client(const std::string &line);
        const std::string toString() override;
        double getBalance() const;
        void setBalance(double balance);
        const std::vector<std::shared_ptr<Model::Transaction>> &getTransactionHistory();
        void setTransactionHistory(const std::shared_ptr<Model::Transaction> &TransactionHistory);
        static long long generateId();
    };
}// namespace Model

#endif//BANK_SYSTEM_CLIENT_H
