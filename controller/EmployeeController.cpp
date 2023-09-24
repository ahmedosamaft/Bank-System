// Copyright (c) 2023. Ahmed Osama

//
// Created by mohamed tamer on 19-Sep-23.
//

#include "EmployeeController.h"

namespace Controller {
    string EmployeeController::employeeDirectory = "../database/employee.txt";
    vector<shared_ptr<Model::Employee>> EmployeeController::allEmployees = vector<shared_ptr<Model::Employee>>();
    shared_ptr<Model::Employee> EmployeeController::currentEmployee = std::make_shared<Model::Employee>();
    map<long long, shared_ptr<Model::Employee>> EmployeeController::idEmployee = map<long long, shared_ptr<Model::Employee>>();
    map<string, shared_ptr<Model::Employee>> EmployeeController::allEmployeesUserName = map<string, shared_ptr<Model::Employee>>();
    long long EmployeeController::lastId = 0;

    void EmployeeController::readEmployees() {
        allEmployees.clear();
        idEmployee.clear();
        allEmployeesUserName.clear();
        ifstream fin(employeeDirectory);
        string line;
        while (getline(fin, line)) {
            shared_ptr<Model::Employee> employee{new Model::Employee(line)};
            allEmployees.push_back(employee);
            idEmployee[employee->getId()] = employee;
            allEmployeesUserName[employee->getUserName()] = employee;
            EmployeeController::lastId = max(EmployeeController::lastId, employee->getId());
        }
    }

    void EmployeeController::reloadData() {
        reloadEmployees();
    }

    void EmployeeController::reloadEmployees() {
        fstream sout(employeeDirectory, ios::out);
        for (auto &[id, employee]: allEmployeesUserName) {
            if (employee != nullptr)
                sout << employee->toString() << '\n';
        }
        sout.close();
    }


    bool EmployeeController::isValid(std::string &userName, std::string &password) {
        return (allEmployeesUserName.count(userName) && allEmployeesUserName[userName]->getPassword() == password);
    }

    shared_ptr<Model::Employee> EmployeeController::getEmployee(std::string &userName) {
        return allEmployeesUserName[userName];
    }

    void EmployeeController::takeControl(string &userName) {
        currentEmployee = getEmployee(userName);
        std::cout << "\n  Welcome Mr " << currentEmployee->getName() << "\n\n";
        std::vector<std::string> menu = {"Account Information", "Show User Information", "Create User", "Delete User"};
        if (currentEmployee->isAdmin())
            menu.emplace_back("Show System Transaction");
        menu.emplace_back("Logout");
        while (true) {
            int choice = Helper::runMenu(menu);
            if (choice == 1) {
                accountInformation();
            } else if (choice == 2) {
                controlUser();
            } else if (choice == 3) {
                makeUser();
            } else if (choice == 4) {
                deleteUser();
            } else if (choice == 5 && currentEmployee->isAdmin()) {
                showAllTransactions();
            } else
                return;
        }
    }

    void EmployeeController::accountInformation() {
        std::cout << "Name: " << currentEmployee->getName() << "\n username: " << currentEmployee->getUserName();
        std::cout << "\n Authority: " << (currentEmployee->isAdmin() ? "Admin" : "Employee");
        std::cout << "\n Account Salary: $" << currentEmployee->getSalary() << "\n\n";
    }

    void EmployeeController::accountInformation(const shared_ptr<Model::Employee> &employee) {
        std::cout << "Name: " << employee->getName() << "\n Username: " << employee->getUserName();
        std::cout << "\n Authority: " << (employee->isAdmin() ? "Admin" : "Employee");
        std::cout << "\n Account Salary: $" << employee->getSalary() << "\n\n";
    }

    bool EmployeeController::checkAuthorization(string &userName) {
        return (!ClientController::allClientsUserName.count(userName) &&
                (EmployeeController::allEmployeesUserName.count(userName) && !currentEmployee->isAdmin()));
    }

    void EmployeeController::notAuthorized() {
        std::cout << "You are currently 3bd! so You do not have the authority to make this action.\n";
        std::cout << "Try another User username.\n";
    }

    void EmployeeController::controlUser() {
        string userName;
        std::cout << "Enter Username: ";
        while (true) {
            std::cin >> userName;
            if (checkAuthorization(userName)) {
                notAuthorized();
                continue;
            }
            if (!ClientController::allClientsUserName.count(userName) &&
                !EmployeeController::allEmployeesUserName.count(userName)) {
                std::cout << "Invalid username!\n";
                std::cout << "Try another username: \n";
                continue;
            }
            break;
        }
        if (ClientController::allClientsUserName.count(userName))
            EmployeeController::controlClient(userName);
        else if (EmployeeController::allEmployeesUserName.count(userName))
            EmployeeController::controlEmployee(userName);
    }

    void EmployeeController::controlClient(string &userName) {
        shared_ptr<Model::Client> currentClient = Controller::ClientController::allClientsUserName[userName];
        std::vector<std::string> menu = {"Account Information", "Withdraw", "Deposit", "Transfer Money To", "Transaction History", "Exit"};
        ClientController::currentClient = ClientController::getClient((string &) currentClient->getUserName());
        while (true) {
            int choice = Helper::runMenu(menu);
            if (choice == 1) {
                ClientController::accountInformation();
            } else if (choice == 2) {
                ClientController::withdraw();
            } else if (choice == 3) {
                ClientController::deposit();
            } else if (choice == 4) {
                ClientController::transferTo();
            } else if (choice == 5) {
                ClientController::showTransactionHistory();
            } else
                return;
        }
    }

    void EmployeeController::controlEmployee(string &userName) {
        shared_ptr<Model::Employee> employee = Controller::EmployeeController::allEmployeesUserName[userName];
        std::vector<std::string> menu = {"Account Information", "Exit"};
        EmployeeController::getEmployee((string &) employee->getUserName());
        while (true) {
            int choice = Helper::runMenu(menu);
            if (choice == 1)
                EmployeeController::accountInformation(employee);
            else
                return;
        }
    }

    void EmployeeController::makeUser() {
        std::vector<std::string> menu = {"Client"};
        if (currentEmployee->isAdmin())
            menu.emplace_back("Employee");
        menu.emplace_back("Exit");
        int choice = Helper::runMenu(menu);
        if (choice == menu.size()) return;
        string userName, password, name;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter username: ";
        while (true) {
            cin >> userName;
            if (ClientController::allClientsUserName.count(userName) || EmployeeController::allEmployeesUserName.count(userName)) {
                cout << userName << " is not available. Try Another username: \n";
                continue;
            }
            break;
        }
        cout << "Enter password: ";
        cin >> password;

        double money;
        if (choice == 1) cout << "Enter Balance: ";
        else
            cout << "Enter Salary: ";

        while (true) {
            cin >> money;
            if (cin.fail()) {
                cout << "input a valid amount of money: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            break;
        }

        if (choice == 1)
            makeClient(name, userName, password, money);
        else if (choice == 2 && currentEmployee->isAdmin())
            makeEmployee(name, userName, password, money);
        else
            notAuthorized();
    }

    void EmployeeController::makeClient(string &name, string &userName, string &password, double &balance) {
        long long id = ClientController::generateIdClient();
        shared_ptr<Model::Client> client{new Model::Client(id, name, userName, password, Helper::currentTimeToString())};
        client->setBalance(balance);
        ClientController::idClient[id] = client;
        ClientController::allClientsUserName[userName] = client;
        ClientController::allClients.push_back(client);
        cout << "Client Created Successfully!\n";
        ClientController::reloadData();
    }

    void EmployeeController::makeEmployee(string &name, string &userName, string &password, double &salary) {
        long long id = EmployeeController::generateId();
        shared_ptr<Model::Employee> employee{new Model::Employee(id, name, userName, password, Helper::currentTimeToString())};
        employee->setSalary(salary);
        EmployeeController::idEmployee[id] = employee;
        EmployeeController::allEmployeesUserName[userName] = employee;
        EmployeeController::allEmployees.push_back(employee);
        cout << "Employee Created Successfully!\n";
        EmployeeController::reloadData();
    }

    void EmployeeController::deleteUser() {
        std::vector<std::string> menu = {"Client"};
        if (currentEmployee->isAdmin())
            menu.emplace_back("Employee");
        menu.emplace_back("Exit");
        string userName;
        int choice = Helper::runMenu(menu);
        if (choice == menu.size()) return;
        std::cout << "Enter username: ";
        while (true) {
            std::cin >> userName;
            if (allEmployeesUserName.count(userName) && !currentEmployee->isAdmin()) {
                notAuthorized();
                continue;
            }
            if (!ClientController::allClientsUserName.count(userName) && !allEmployeesUserName.count(userName)) {
                std::cout << "Invalid username!\n";
                std::cout << "Try another username: \n";
                continue;
            }
            break;
        }
        if (choice == 1)
            deleteClient(userName);
        else if (choice == 2 && currentEmployee->isAdmin())
            deleteEmployee(userName);
    }

    void EmployeeController::deleteClient(string &userName) {
        for (auto &transaction: ClientController::allClientsUserName[userName]->getTransactionHistory()) {
            ClientController::idTransaction[transaction->getId()] = nullptr;
        }
        ClientController::allClientsUserName[userName] = nullptr;
        ClientController::reloadData();
        ClientController::readClients();
        ClientController::readTransactions();
        std::cout << "Client Deleted Successfully!\n";
    }

    void EmployeeController::deleteEmployee(string &userName) {
        EmployeeController::allEmployeesUserName[userName] = nullptr;
        EmployeeController::reloadData();
        EmployeeController::readEmployees();
        std::cout << "Employee Deleted Successfully!\n";
    }

    void EmployeeController::showAllTransactions() {
        for (const auto &[id, transaction]: ClientController::idTransaction)
            ClientController::showTransaction(transaction);
    }

    long long int EmployeeController::generateId() {
        return ++lastId;
    }

}// namespace Controller
