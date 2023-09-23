// Copyright (c) 2023. Ahmed Osama

//
// Created by andro on 9/24/2023.
//

#include "View.h"


void View::runMainMenu() {
    std::vector<std::string> menu = {"Login","Quit"};
    Controller::ClientController::readClients();
    Controller::ClientController::readTransactions();
    Controller::EmployeeController::readEmployees();
    while (true){
        int choice = Helper::runMenu(menu);
        if(choice == 1)
            doLogin();
        else
            return ;
    }
}

void View::doLogin() {
    printf("Please enter username and password >> ");
    std::string username;
    std::string password;
    std::cin >> username >> password;
    if(Controller::ClientController::isValid(username,password))
        Controller::ClientController::takeControl(username);
    else if (Controller::EmployeeController::isValid(username,password))
        Controller::EmployeeController::takeControl(username);
}
