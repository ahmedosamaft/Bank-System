// Copyright (c) 2023. Ahmed Osama

//
// Created by Mohamed Abdelhady on 9/20/2023.
//

#ifndef INC_47D9A51B96C94111B0F6FD714BAA33E5
#define INC_47D9A51B96C94111B0F6FD714BAA33E5


#include <memory>
#include <string>

namespace Controller {
    class ClientController;
}// namespace Controller

namespace Model {
    class Client;
    class Transaction {
        std::shared_ptr<Client> sender, receiver;
        std::string transactionType, date;
        long long id;
        double amount, receiverPreviousBalance, senderPreviousBalance;

    public:
        explicit Transaction(const std::string &line);
        Transaction();

        long long getId() const;
        void setId(const long long &TransactionId);

        const std::shared_ptr<Client> &getSender() const;
        void setSender(const std::shared_ptr<Client> &Sender);

        const std::shared_ptr<Client> &getReceiver() const;
        void setReceiver(const std::shared_ptr<Client> &Receiver);

        const std::string &getTransactionType() const;
        void setTransactionType(const std::string &TransactionType);

        const std::string &getDate() const;
        void setDate(const std::string &Date);

        double getReceiverPreviousBalance() const;
        void setReceiverPreviousBalance(double ReceiverPreviousBalance);

        double getSenderPreviousBalance() const;
        void setSenderPreviousBalance(double SenderPreviousBalance);

        double getAmount() const;
        void setAmount(double Amount);

        std::string toString();
    };

}// namespace Model

#endif//INC_47D9A51B96C94111B0F6FD714BAA33E5
