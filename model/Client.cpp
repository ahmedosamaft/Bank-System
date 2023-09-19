//
// Created by Mohamed Abdelhady on 9/19/2023.
//

#include "Client.h"
namespace Model {
    Client::Client(const std::string &line){
       std::vector<std::string> entity = Helper::parseLine(line,',');
       this->setId(std::stoll(entity[0]));
       this->setUserName(entity[1]);
       this->setPassword(entity[2]);
       this->setName(entity[3]);
       this->setBalance(std::stod(entity[4]));
    }

    double Client::getBalance() const {
       return balance;
    }
    void Client::setBalance(double balance) {
       Client::balance = balance;
    }
}