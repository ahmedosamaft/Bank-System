// Copyright (c) 2023. Ahmed Osama

//
// Created by Mohamed Abdelhady on 9/20/2023.
//

#include "Transaction.h"
#include "../manger/ClientManger.h"


namespace Model {
    Transaction::Transaction(const std::string &line) {
        std::vector<std::string> data = Helper::parseLine(line, ',');
        ///        @data{ id, senderId, receiverId, transactionType, amount, senderPreviousBalance, receiverPreviousBalance transactionTime }
        this->setId(stoll(data[0]));
        this->setSender(Manger::ClientManger::idClient[stoll(data[1])]);
        this->setReceiver(Manger::ClientManger::idClient[stoll(data[2])]);
        this->setTransactionType(data[3]);
        this->setAmount(stod(data[4]));
        this->setSenderPreviousBalance(stod(data[5]));
        this->setReceiverPreviousBalance(stod(data[6]));
        this->setDate(data[7]);
    }

    long long Transaction::getId() const {
        return id;
    }
    void Transaction::setId(const long long &TransactionId) {
        Transaction::id = TransactionId;
    }

    const std::shared_ptr<Client> &Transaction::getSender() const {
        return sender;
    }
    void Transaction::setSender(const std::shared_ptr<Client> &Sender) {
        Transaction::sender = Sender;
    }

    const std::shared_ptr<Client> &Transaction::getReceiver() const {
        return receiver;
    }
    void Transaction::setReceiver(const std::shared_ptr<Client> &Receiver) {
        Transaction::receiver = Receiver;
    }

    const std::string &Transaction::getTransactionType() const {
        return transactionType;
    }
    void Transaction::setTransactionType(const std::string &TransactionType) {
        Transaction::transactionType = TransactionType;
    }

    double Transaction::getReceiverPreviousBalance() const {
        return receiverPreviousBalance;
    }
    void Transaction::setReceiverPreviousBalance(double ReceiverPreviousBalance) {
        Transaction::receiverPreviousBalance = ReceiverPreviousBalance;
    }
    double Transaction::getSenderPreviousBalance() const {
        return senderPreviousBalance;
    }
    void Transaction::setSenderPreviousBalance(double SenderPreviousBalance) {
        Transaction::senderPreviousBalance = SenderPreviousBalance;
    }

    const std::string &Transaction::getDate() const {
        return date;
    }
    void Transaction::setDate(const std::string &Date) {
        Transaction::date = Date;
    }

    double Transaction::getAmount() const {
        return amount;
    }
    void Transaction::setAmount(double Amount) {
        Transaction::amount = Amount;
    }
    std::string Transaction::toString() {
        std::string currentTime = Helper::currentTimeToString(), line;
        std::vector<std::string> data;
        data.push_back(std::to_string(id));
        data.push_back(std::to_string(sender->getId()));
        data.push_back(std::to_string(receiver->getId()));
        data.push_back(transactionType);
        data.push_back(std::to_string(amount));
        data.push_back(std::to_string(sender->getBalance()));
        data.push_back(std::to_string(receiver->getBalance()));
        data.push_back(currentTime);
        return  Helper::makeEntity(data, ',');
    }
    Transaction::Transaction() {}
}// namespace Model