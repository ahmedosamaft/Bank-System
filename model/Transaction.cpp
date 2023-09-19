// Copyright (c) 2023. Ahmed Osama

//
// Created by Mohamed Abdelhady on 9/20/2023.
//

#include "Transaction.h"
#include "../manger/ClientManger.h"

namespace Model {
    Transaction::Transaction(const std::string &line) {
        std::vector<std::string> data = Helper::parseLine(line, ',');
        this->setSender(Manger::ClientManger::allClientsUserName[data[0]]);
        this->setReceiver(Manger::ClientManger::allClientsUserName[data[1]]);
        this->setTransactionType(data[2]);
        this->setAmount(stod(data[3]));
        this->setDate(data[4]);
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
}// namespace Model