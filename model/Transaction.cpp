// Copyright (c) 2023. Ahmed Osama

//
// Created by Mohamed Abdelhady on 9/20/2023.
//

#include "Transaction.h"
#include "../manger/ClientManger.h"


namespace Model {
    Transaction::Transaction(const std::string &line) {
        std::vector<std::string> data = Helper::parseLine(line, ',');
        ///        @data{ transactionId, senderId, receiverId, transactionType, transactionTime }
        lastId = std::max(lastId, stoll(data[0]));
        this->setTransactionId(stoll(data[0]));
        this->setSender(Manger::ClientManger::idClient[stoll(data[1])]);
        this->setReceiver(Manger::ClientManger::idClient[stoll(data[2])]);
        this->setTransactionType(data[3]);
        this->setAmount(stod(data[4]));
        this->setDate(data[5]);
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
        std::string currentTime = currentTimeToString(), line;
        std::vector<std::string> data;
        data.push_back(std::to_string(generateId()));
        data.push_back(std::to_string(Sender->getId()));
        data.push_back(std::to_string(Receiver->getId()));
        data.push_back(TransactionType);
        data.push_back(std::to_string(Amount));
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

    std::string Transaction::currentTimeToString() {
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        time_t currentTime = std::chrono::system_clock::to_time_t(now);
        tm *localTime = localtime(&currentTime);

        std::ostringstream oss;
        oss << std::put_time(localTime, "%Y%m%d%H%M%S");
        std::string s = oss.str();
        return s;
    }

    std::string Transaction::currentTimeToFormattedString() {
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        time_t currentTime = std::chrono::system_clock::to_time_t(now);
        tm *localTime = localtime(&currentTime);

        std::ostringstream oss;
        oss << std::put_time(localTime, "%Y/%m/%d %H:%M:%S");
        std::string s = oss.str();
        return s;
    }

    std::string Transaction::TimeStingToFormattedString(const std::string &timeString) {
        std::string year = timeString.substr(0, 4);
        std::string month = timeString.substr(4, 2);
        std::string day = timeString.substr(6, 2);
        std::string hour = timeString.substr(8, 2);
        std::string minute = timeString.substr(10, 2);
        std::string second = timeString.substr(12, 2);

        return year + '/' + month + '/' + day + ' ' + hour + ':' + minute + ':' + second;
    }

    long long Transaction::generateId() {
        return ++lastId;
    }

}// namespace Model