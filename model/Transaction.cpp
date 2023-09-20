// Copyright (c) 2023. Ahmed Osama

//
// Created by Mohamed Abdelhady on 9/20/2023.
//

#include "Transaction.h"
#include "../manger/ClientManger.h"


namespace Model {
    Transaction::Transaction(const std::string &line) {
        std::vector<std::string> data = Helper::parseLine(line, ',');
        ///        @data{ transactionId, senderId, receiverId, transactionType, amount, senderPreviousBalance, receiverPreviousBalance transactionTime }
        lastId = std::max(lastId, stoll(data[0]));
        this->setTransactionId(stoll(data[0]));
        this->setSender(Manger::ClientManger::idClient[stoll(data[1])]);
        this->setReceiver(Manger::ClientManger::idClient[stoll(data[2])]);
        this->setTransactionType(data[3]);
        this->setAmount(stod(data[4]));
        this->setSenderPreviousBalance(stod(data[5]));
        this->setReceiverPreviousBalance(stod(data[6]));
        this->setDate(data[7]);
    }

    long long Transaction::getTransactionId() const {
        return transactionId;
    }
    void Transaction::setTransactionId(const long long &TransactionId) {
        Transaction::transactionId = TransactionId;
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
    void Transaction::makeNewTransaction(const std::shared_ptr<Client> &Sender, const std::shared_ptr<Client> &Receiver, const std::string &TransactionType, const double &Amount) {
        std::string currentTime = Helper::currentTimeToString(), line;
        std::vector<std::string> data;
        data.push_back(std::to_string(generateId()));
        data.push_back(std::to_string(Sender->getId()));
        data.push_back(std::to_string(Receiver->getId()));
        data.push_back(TransactionType);
        data.push_back(std::to_string(Amount));
        data.push_back(std::to_string(Sender->getBalance()));
        data.push_back(std::to_string(Receiver->getBalance()));
        data.push_back(currentTime);

        line = Helper::makeEntity(data, ',');
        std::shared_ptr<Model::Transaction> transaction{new Model::Transaction(line)};
        Sender->setTransactionHistory(transaction);
        ///       if there is a receiver
        if (transaction->getTransactionType() == "3")
            transaction->getReceiver()->setTransactionHistory(transaction);
        std::fstream sout(Manger::ClientManger::transactionHistoryDirectory, std::ios::app);
        sout << line << '\n';
    }


    long long Transaction::generateId() {
        return ++lastId;
    }

}// namespace Model