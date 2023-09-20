// Copyright (c) 2023. Ahmed Osama

//
// Created by Mohamed Abdelhady on 9/20/2023.
//

#ifndef INC_47D9A51B96C94111B0F6FD714BAA33E5
#define INC_47D9A51B96C94111B0F6FD714BAA33E5


#include <chrono>
#include <iomanip>
#include <memory>
#include <sstream>
#include <string>

namespace Manger {
    class ClientManger;
}// namespace Manger

namespace Model {
    class Client;
    class Transaction {
        std::shared_ptr<Client> sender, receiver;
        std::string transactionType, date;
        long long transactionId;
        double amount;

    public:
        inline static long long lastId;
        explicit Transaction(const std::string &line);

        long long getTransactionId() const;
        void setTransactionId(const long long &transactionId);

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


        static void makeNewTransaction(const std::shared_ptr<Client> &Sender, const std::shared_ptr<Client> &Receiver, const std::string &TransactionType, const double &Amount);
        static std::string currentTimeToString();
        static std::string currentTimeToFormattedString();
        static std::string TimeStingToFormattedString(const std::string &timeString);
        static long long generateId();
    };

}// namespace Model

#endif//INC_47D9A51B96C94111B0F6FD714BAA33E5
