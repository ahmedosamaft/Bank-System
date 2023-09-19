// Copyright (c) 2023. Ahmed Osama

//
// Created by mohamed tamer on 19-Sep-23.
//

#include "EmployeeManager.h"

namespace Manger {
    string EmployeeManger::EmployeeDirectory = "../database/employee.txt";
    vector<shared_ptr<Model::Employee>> EmployeeManger::allEmployees = vector<shared_ptr<Model::Employee>>();
    vector<shared_ptr<Model::Employee>> EmployeeManger::allAdmins = vector<shared_ptr<Model::Employee>>();
    shared_ptr<Model::Employee> EmployeeManger::current_Employee = std::make_shared<Model::Employee>();
    map<long long, shared_ptr<Model::Employee>> EmployeeManger::id_Employee = map<long long, shared_ptr<Model::Employee>>();

    void EmployeeManger::readEmployees() {
        allEmployees.clear();
        allAdmins.clear();
        id_Employee.clear();
        ifstream fin(EmployeeDirectory);
        string line;
        while (getline(fin, line)) {
            shared_ptr<Model::Employee> employee{new Model::Employee(line)};
            if (employee->isAdmin)
                allAdmins.push_back(employee);
            else
                allEmployees.push_back(employee);
            id_Employee[employee->getId()] = employee;
        }
    }
    bool EmployeeManger::validEmployee(std::string &username, std::string &password) {
        for (const auto &i: allEmployees) {
            if (*i == username) {
                return i->getPassword() == password;
            }
        }
        return false;
    }
    void EmployeeManger::getEmployee(std::string &username, std::string &password) {
        for (const auto &i: allEmployees) {
            if (*i == username) {
                current_Employee = i;
                return;
            }
        }
    }
    shared_ptr<Model::Employee> EmployeeManger::getEmployee(std::string &userName) {
        for (const auto &i: allEmployees) {
            if (*i == userName) {
                return i;
            }
        }
        return nullptr;
    }


}// namespace Manger
