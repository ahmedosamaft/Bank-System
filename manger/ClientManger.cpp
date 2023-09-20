//
// Created by andro on 9/19/2023.
//

#include "ClientManger.h"
#include <chrono>

namespace Manger {
    string ClientManger::clientsDirectory = "../database/client.txt";
    string ClientManger::transactionHistoryDirectory = "../database/transactionHistory.txt";
    vector<shared_ptr<Model::Client>> ClientManger::allClients = vector<shared_ptr<Model::Client>>();
    shared_ptr<Model::Client> ClientManger::currentClient = std::make_shared<Model::Client>();
    map<long long, shared_ptr<Model::Client>> ClientManger::idClient = map<long long, shared_ptr<Model::Client>>();
    map<string, shared_ptr<Model::Client>> ClientManger::allClientsUserName = map<string, shared_ptr<Model::Client>>();


    void ClientManger::readClients() {
        allClients.clear();
        idClient.clear();
        ifstream fin(clientsDirectory);
        std::string line;
        while (getline(fin, line)) {
            shared_ptr<Model::Client> client{new Model::Client(line)};
            allClients.push_back(client);
            idClient[client->getId()] = client;
            allClientsUserName[client->getUserName()] = client;
        }
        fin.close();
///       Reading Transaction History
        ifstream sin(transactionHistoryDirectory);
        line = "";
        while (getline(sin, line)) {
            shared_ptr<Model::Transaction> transaction{new Model::Transaction(line)};
            transaction->getSender()->setTransactionHistory(transaction);
///            if there is a receiver
            if (transaction->getTransactionType() == "3")
                transaction->getReceiver()->setTransactionHistory(transaction);
        }
    }

    bool ClientManger::isValidClient(string &userName, string &password) {
        for (const auto &i: allClients) {
            if (*i == userName) {
                return i->getPassword() == password;
            }
        }
        return false;
    }

    void ClientManger::getClient(string &userName, string &password) {
        for (const auto &i: allClients) {
            if (*i == userName) {
                currentClient = i;
                return;
            }
        }
    }

    shared_ptr<Model::Client> ClientManger::getClient(string &userName) {
        for (const auto &i: allClients) {
            if (*i == userName) {
                return i;
            }
        }
        return nullptr;
    }


    void ClientManger::takeControl(string &userName, string &password) {
        getClient(userName, password);
        long long userId = currentClient->getId();
        std::cout << "\twelcome, " << currentClient->getName() << "\n\n";
        std::vector<std::string> menu = {"Account Information", "withdraw", "deposit", "Transfer Money To", "Transaction History", "Exit"};
        int choice = Helper::runMenu(menu);
        if (choice == 1) {
        } else if (choice == 2) {
            withdraw(userId);
        } else if (choice == 3) {
            deposit(userId);
        } else if (choice == 4) {
            transferTo(userId);
        } else if (choice == 5) {
            showTransactionHistory(userId);
        } else
            return;
    }


    void ClientManger::withdraw(long long &userId) {
        cout << "How much amount you want to withdraw: ";
        double amountOFMoney, currentBalance = currentClient->getBalance();
        while (true) {
            cin >> amountOFMoney;
            if (cin.fail() || amountOFMoney < 0) {
                cout << "input a valid Amount of Money to withdraw: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if (amountOFMoney > currentBalance) {
                cout << "Sorry Your Balance is $" << currentBalance << "\nTry another amount: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                double newBalance = currentBalance - amountOFMoney;
                currentClient->setBalance(newBalance);
                reloadData();
                break;
            }
        }
    }

    void ClientManger::deposit(long long &userId) {
        cout << "How much amount you want to deposit: ";
        double amountOFMoney, currentBalance = currentClient->getBalance();
        while (true) {
            cin >> amountOFMoney;
            if (cin.fail() || amountOFMoney < 0) {
                cout << "input a valid Amount of Money to deposit: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                double newBalance = currentBalance + amountOFMoney;
                currentClient->setBalance(newBalance);
                reloadData();
                break;
            }
        }
    }


    void ClientManger::showTransactionHistory(long long &userId) {
    }

    void ClientManger::transferTo(const long long int &userId) {
        cout << "Enter client username to transfer money to: ";
        string receiverUserName;
        shared_ptr<Model::Client> receiverClient = getClient(receiverUserName);
        while (true) {
            cin >> receiverUserName;
            receiverClient = getClient(receiverUserName);
            if (receiverClient == nullptr || receiverClient->getId() == userId) {
                cout << "input a valid username: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                cout << "How much amount you want to transfer: ";
                double amountOFMoney, currentBalance = currentClient->getBalance();
                break;
            }
        }
        double amountOfMoney, currentBalance = currentClient->getBalance();
        while (true) {
            cin >> amountOfMoney;
            if (cin.fail() || amountOfMoney < 0) {
                cout << "input a valid Amount of Money: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if (amountOfMoney > currentBalance) {
                cout << "Sorry Your Balance is $" << currentBalance << "\nTry another amount: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                double newBalance = currentBalance - amountOfMoney, receiverNewBalance = receiverClient->getBalance() + amountOfMoney;
                currentClient->setBalance(newBalance);
                receiverClient->setBalance(receiverNewBalance);
                reloadData();
                break;
            }
        }
    }

    void ClientManger::reloadData() {
        fstream sout(clientsDirectory, ios::out);
        for (const auto &i: allClients) {
            sout << i->toString() << '\n';
        }
    }

}// namespace Manger