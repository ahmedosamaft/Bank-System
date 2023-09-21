// Copyright (c) 2023. Ahmed Osama

//
// Created by mohamed tamer on 19-Sep-23.
//

#include "EmployeeManager.h"

namespace Manger {
    string EmployeeManger::EmployeeDirectory = "../database/employee.txt";
    vector<shared_ptr<Model::Employee>> EmployeeManger::allEmployees = vector<shared_ptr<Model::Employee>>();
    shared_ptr<Model::Employee> EmployeeManger::currentEmployee = std::make_shared<Model::Employee>();
    map<long long, shared_ptr<Model::Employee>> EmployeeManger::idEmployee = map<long long, shared_ptr<Model::Employee>>();

    void EmployeeManger::readEmployees() {
        allEmployees.clear();
        idEmployee.clear();
        ifstream fin(EmployeeDirectory);
        string line;
        while (getline(fin, line)) {
            shared_ptr<Model::Employee> employee{new Model::Employee(line)};
            allEmployees.push_back(employee);
            idEmployee[employee->getId()] = employee;
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
                currentEmployee = i;
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
    void EmployeeManger::takeControl(string &userName, string &password) {
        getEmployee(userName, password);
        std::cout << "\n\tWelcome " << currentEmployee->getName() << "\n\n";
        std::vector<std::string> menu = {"Account Information", "Show Client Information", "Create Client", "Delete Client", "Exit"};
        int choice = Helper::runMenu(menu);
        if (choice == 1) {
            accountInformation();
        } else if (choice == 2) {
            controlClient();
        } else if (choice == 3) {
            makeClient();
        } else if (choice == 4) {
            deleteClient();
        } else
            return;
    }
    void EmployeeManger::accountInformation() {
        std::cout << "\tWelcome " << currentEmployee->getName() << "\n\nusername: " << currentEmployee->getUserName();
        std::cout << "\nAccount Salary: $" << currentEmployee->getSalary() << '\n';
    }
    void EmployeeManger::controlClient() {
        long long ClientId = 0;
        while (true) {
            std::cout << "Enter Client ID\n";
            std::cin >> ClientId;
            if (!Manger::ClientManger::idClient.count(ClientId)) {
                std::cout << "No Client has this ID.\n";
                std::cout << "Try another Client ID.\n";
                continue;
            }
            break;
        }
        shared_ptr<Model::Client> currentClient = Manger::ClientManger::idClient[ClientId];
        //Manger::ClientManger::takeControl(currentClient->getUserName(), currentClient->getPassword());
    }
    void EmployeeManger::makeClient() {
        string userName, password;
        //long long id = Model::Client::generateId();
        long long id = 5;
        while (true) {
            std::cout << "Enter Client Username: ";
            std::cin >> userName;
            if (ClientManger::allClientsUserName.count(userName)) {
                std::cout << userName << " is not available. Try Another Username\n";
                continue;
            }
            break;
        }
        cin >> password;
        shared_ptr<Model::Client> client{new Model::Client(id, "ad", userName, password)};
        ClientManger::idClient[id] = client;
        ClientManger::allClientsUserName[userName] = client;
        std::cout << "Client Created Successfully.\n";
    }
    void EmployeeManger::deleteClient() {
        long long id;
        while (true) {
            cin >> id;
            if (!ClientManger::idClient.count(id)) {
                std::cout << "No Client has this ID.\n";
                std::cout << "Try another Client ID.\n";
                continue;
            }
            break;
        }
        auto clientToDelete = ClientManger::idClient[id];

        // ClientManger::allClients.erase(clientToDelete);
        ClientManger::idClient.erase(id);
        ClientManger::allClientsUserName.erase(clientToDelete->getUserName());
        std::cout << "Client Deleted Successfully.\n";
    }

}// namespace Manger
