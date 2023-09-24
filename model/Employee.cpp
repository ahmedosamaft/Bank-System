// Copyright (c) 2023. Ahmed Osama

//
// Created by mohamed tamer on 19-Sep-23.
//

#include "Employee.h"

namespace Model {
    Employee::Employee(const std::string &line) {
        std::vector<std::string> entity = Helper::parseLine(line, ',');
        this->setId(std::stoll(entity[0]));
        this->setUserName(entity[1]);
        this->setPassword(entity[2]);
        this->setName(entity[3]);
        this->setSalary(std::stod(entity[4]));
        this->setIsAdmin(entity[5] == "1");
        this->setCreationTime(entity[6]);
    }
    double Employee::getSalary() const {
        return Employee::salary;
    }
    void Employee::setSalary(double salary) {
        Employee::salary = salary;
    }
    bool Employee::isAdmin() const {
        return isAdmin_;
    }
    void Employee::setIsAdmin(bool isAdmin) {
        isAdmin_ = isAdmin;
    }
    const std::string Employee::toString() {
        std::vector<std::string> data;
        data.push_back(std::to_string(this->getId()));
        data.push_back(this->getUserName());
        data.push_back(this->getPassword());
        data.push_back(this->getName());
        data.push_back(std::to_string(this->getSalary()));
        data.push_back(std::to_string(this->isAdmin()));
        data.push_back(this->getCreationTime());
        return Helper::makeEntity(data, ',');
    }
}// namespace Model