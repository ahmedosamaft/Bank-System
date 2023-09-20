// Copyright (c) 2023. Ahmed Osama

//
// Created by Mohamed Abdelhady on 9/20/2023.
//

#ifndef INC_47D9A51B96C94111B0F6FD714BAA33E5
#define INC_47D9A51B96C94111B0F6FD714BAA33E5


#include <memory>
#include <string>

namespace Manger {
    class ClientManger;
}// namespace Manger

namespace Model {
    class Client;
    class Transaction {
        std::shared_ptr<Client> sender, receiver;
        std::string transactionType, date;
        double amount;

    public:
        explicit Transaction(const std::string &line);

        const std::shared_ptr<Client> &getSender() const;
        void setSender(const std::shared_ptr<Client> &sender);

        const std::shared_ptr<Client> &getReceiver() const;
        void setReceiver(const std::shared_ptr<Client> &receiver);

        const std::string &getTransactionType() const;
        void setTransactionType(const std::string &transactionType);

        const std::string &getDate() const;
        void setDate(const std::string &date);

        double getAmount() const;
        void setAmount(double amount);
    };

}// namespace Model

#endif//INC_47D9A51B96C94111B0F6FD714BAA33E5
