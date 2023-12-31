//
// Created by Mohamed Abdelhady on 9/19/2023.
//

#include "Client.h"
namespace Model {

    Client::Client(const std::string &line) {
        std::vector<std::string> entity = Helper::parseLine(line, ',');
        this->setId(std::stoll(entity[0]));
        this->setUserName(entity[1]);
        this->setPassword(entity[2]);
        this->setName(entity[3]);
        this->setBalance(std::stod(entity[4]));
        this->setCreationTime(entity[5]);
    }

    double Client::getBalance() const {
        return balance;
    }
    void Client::setBalance(double balance) {
        Client::balance = balance;
    }

    std::vector<std::shared_ptr<Model::Transaction>> &Client::getTransactionHistory() {
        return transactionHistory;
    }
    void Client::setTransactionHistory(const std::shared_ptr<Model::Transaction> &TransactionHistory) {
        transactionHistory.push_back(TransactionHistory);
    }

    const std::string Client::toString() {
        std::vector<std::string> data;
        data.push_back(std::to_string(this->getId()));
        data.push_back(this->getUserName());
        data.push_back(this->getPassword());
        data.push_back(this->getName());
        data.push_back(std::to_string(this->getBalance()));
        data.push_back(this->getCreationTime());
        return Helper::makeEntity(data, ',');
    }

}// namespace Model