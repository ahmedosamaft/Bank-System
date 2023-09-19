// Copyright (c) 2023. Ahmed Osama

//
// Created by mohamed tamer on 19-Sep-23.
//

#ifndef INC_5FDA1EAC732F499A94DC5EF107D62D97
#define INC_5FDA1EAC732F499A94DC5EF107D62D97


#include "../model/Employee.h"
#include <vector>
#include <map>
#include <memory>
namespace Manger {
    using namespace std;
    class EmployeeManger {
    public:
        static vector<shared_ptr<Model::Employee>> all_clients;
        static string Employee_dir;
        static shared_ptr<Model::Employee> current_client;
        static map<long long,shared_ptr<Model::Employee>> id_client;
        static void readEmployees();

    };
}

// Todo: Valid Employee (user, password) : bool
// Todo: Get Employee (user, password) : void
// Todo: TakeControl(user, password) : void
// Todo: makeClient();
// Todo: deleteClient();
// Todo: showSalary() :void;
// Todo: showList() :void;


#endif//INC_5FDA1EAC732F499A94DC5EF107D62D97
