// Copyright (c) 2023. Ahmed Osama

//
// Created by andro on 9/24/2023.
//

#include "View.h"


void View::runMainMenu() {
    std::vector<std::string> menu = {"Login", "Quit"};
    Controller::ClientController::readClients();
    Controller::ClientController::readTransactions();
    Controller::EmployeeController::readEmployees();
    while (true) {
        int choice = Helper::runMenu(menu);
        if (choice == 1)
            login();
        else
            return;
    }
}

void View::login() {
    std::string username;
    std::string password;
    printf("Enter username: ");
    std::cin >> username;
    printf("Enter password: ");
    std::cin >> password;
    if (Controller::ClientController::isValid(username, password))
        Controller::ClientController::takeControl(username);
    else if (Controller::EmployeeController::isValid(username, password))
        Controller::EmployeeController::takeControl(username);
    else
        std::cout << "Wrong Password or username!\n";
}
