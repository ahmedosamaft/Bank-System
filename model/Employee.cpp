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
    }
    double Employee::getSalary() const {
        return Employee::salary;
    }
    void Employee::setSalary(double salary) {
        Employee::salary = salary;
    }
}// namespace Model