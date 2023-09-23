// Copyright (c) 2023. Ahmed Osama

//
// Created by mohamed tamer on 19-Sep-23.
//

#ifndef INC_5FDA1EAC732F499A94DC5EF107D62D97
#define INC_5FDA1EAC732F499A94DC5EF107D62D97


#include "../controller/ClientController.h"
#include "../model/Employee.h"
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
namespace Controller {
    using namespace std;
    class EmployeeController {
    public:
        static vector<shared_ptr<Model::Employee>> allEmployees;
        static string employeeDirectory;
        static shared_ptr<Model::Employee> currentEmployee;
        static map<long long, shared_ptr<Model::Employee>> idEmployee;
        static map<string, shared_ptr<Model::Employee>> allEmployeesUserName;
        static long long lastId;

    public:
        static void readEmployees();
        static bool isValid(string &userName, string &password);
        static shared_ptr<Model::Employee> getEmployee(string &userName);
        static void takeControl(string &userName);
        static void accountInformation();
        static void controlUser();
        static void controlClient(string &userName);
        static void controlEmployee(string &userName);
        static void deleteUser();
        static void deleteClient(string &userName);
        static void deleteEmployee(string &userName);
        static void reloadData();
        static void reloadEmployees();
        static void accountInformation(const shared_ptr<Model::Employee>& employee);
        static void makeClient(string &name, string &userName, string &password);
        static void notAuthorized();
        static void makeEmployee(string &name, string &userName, string &password);
        static long long int generateId();
        static void makeUser();
        static bool checkAuth(string &userName);
        static void showAllTransactions();
    };
}// namespace Controller


#endif//INC_5FDA1EAC732F499A94DC5EF107D62D97
