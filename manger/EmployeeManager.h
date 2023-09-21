// Copyright (c) 2023. Ahmed Osama

//
// Created by mohamed tamer on 19-Sep-23.
//

#ifndef INC_5FDA1EAC732F499A94DC5EF107D62D97
#define INC_5FDA1EAC732F499A94DC5EF107D62D97


#include "../model/Employee.h"
#include "../manger/ClientManger.h"
#include <map>
#include <memory>
#include <vector>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
namespace Manger {
    using namespace std;
    class EmployeeManger {
    public:
        static vector<shared_ptr<Model::Employee>> allEmployees;
        static string EmployeeDirectory;
        static shared_ptr<Model::Employee> currentEmployee;
        static map<long long, shared_ptr<Model::Employee>> idEmployee;
        static void readEmployees();
        static bool validEmployee(string &userName, string &password);
        static void getEmployee(string &userName, string &password);
        static shared_ptr<Model::Employee> getEmployee(string &userName);
        static void takeControl(string &userName, string &password);
        static void accountInformation();
        static void controlClient();
        static void makeClient();
        static void deleteClient();
    };
}// namespace Manger


#endif//INC_5FDA1EAC732F499A94DC5EF107D62D97
