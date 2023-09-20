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
        Model::Client::lastId = 0;
        while (getline(fin, line) && !line.empty()) {
            shared_ptr<Model::Client> client{new Model::Client(line)};
            allClients.push_back(client);
            idClient[client->getId()] = client;
            allClientsUserName[client->getUserName()] = client;
        }
        fin.close();
        ///       Reading Transaction History
        ifstream sin(transactionHistoryDirectory);
        line = "";
        Model::Transaction::lastId = 0;
        while (getline(sin, line) && !line.empty()) {
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
        std::cout << "\n\tWelcome " << currentClient->getName() << "\n\n";
        std::vector<std::string> menu = {"Account Information", "withdraw", "deposit", "Transfer Money To", "Transaction History", "Exit"};
        int choice = Helper::runMenu(menu);
        if (choice == 1) {
            accountInformation();
        } else if (choice == 2) {
            withdraw();
        } else if (choice == 3) {
            deposit();
        } else if (choice == 4) {
            transferTo();
        } else if (choice == 5) {
            showTransactionHistory();
        } else
            return;
    }

    void ClientManger::accountInformation() {
        std::cout << "\tWelcome " << currentClient->getName() << "\n\nusername: " << currentClient->getUserName();
        std::cout << "\nAccount Balance: $" << currentClient->getBalance() << '\n';
    }

    void ClientManger::withdraw() {
        cout << "How much amount you want to withdraw: ";
        long long userId = currentClient->getId();
        double amountOfMoney, currentBalance = currentClient->getBalance();
        while (true) {
            cin >> amountOfMoney;
            if (cin.fail() || amountOfMoney < 0) {
                cout << "input a valid Amount of Money to withdraw: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if (amountOfMoney > currentBalance) {
                cout << "Sorry Your Balance is $" << currentBalance << "\nTry another amount: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                double newBalance = currentBalance - amountOfMoney;
                Model::Transaction::makeNewTransaction(currentClient, currentClient, "1", amountOfMoney);
                currentClient->setBalance(newBalance);
                reloadData();
                cout << "\nSuccessful!\n";
                break;
            }
        }
    }

    void ClientManger::deposit() {
        cout << "How much amount you want to deposit: ";
        long long userId = currentClient->getId();
        double amountOfMoney, currentBalance = currentClient->getBalance();
        while (true) {
            cin >> amountOfMoney;
            if (cin.fail() || amountOfMoney < 0) {
                cout << "input a valid Amount of Money to deposit: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                double newBalance = currentBalance + amountOfMoney;
                Model::Transaction::makeNewTransaction(currentClient, currentClient, "2", amountOfMoney);
                currentClient->setBalance(newBalance);
                reloadData();
                cout << "\nSuccessful!\n";
                break;
            }
        }
    }

    void ClientManger::transferTo() {
        cout << "Enter client username to transfer money to: ";
        long long userId = currentClient->getId();
        string receiverUserName;
        shared_ptr<Model::Client> receiverClient;
        while (true) {
            cin >> receiverUserName;
            receiverClient = getClient(receiverUserName);
            if (receiverClient == nullptr || receiverClient->getId() == userId) {
                cout << "input a valid username: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                cout << "How much amount you want to transfer: ";
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
                Model::Transaction::makeNewTransaction(currentClient, receiverClient, "3", amountOfMoney);
                currentClient->setBalance(newBalance);
                receiverClient->setBalance(receiverNewBalance);
                reloadData();
                cout << "\nSuccessful!\n";
                break;
            }
        }
    }

    void ClientManger::showTransactionHistory() {
        long long userId = currentClient->getId();
        std::vector<std::shared_ptr<Model::Transaction>> transactions = currentClient->getTransactionHistory();
        for (const auto &trans: transactions) {
            if (trans->getTransactionType() == "1") {
                cout << "Withdrawing $" << trans->getAmount() << " (Account Balance Changed from $" << trans->getSenderPreviousBalance() << " to $"
                     << trans->getSenderPreviousBalance() - trans->getAmount() << ") on "
                     << Helper::TimeStingToFormattedString(trans->getDate()) << '\n';
            } else if (trans->getTransactionType() == "2") {
                cout << "Depositing $" << trans->getAmount() << " (Account Balance Changed from $" << trans->getSenderPreviousBalance() << " to $"
                     << trans->getSenderPreviousBalance() + trans->getAmount() << ") on "
                     << Helper::TimeStingToFormattedString(trans->getDate()) << '\n';
            } else if (trans->getTransactionType() == "3") {
                if (trans->getSender()->getId() == userId) {
                    cout << "Sending $" << trans->getAmount() << " to " << trans->getReceiver()->getUserName()
                         << " (Account Balance Changed from $" << trans->getSenderPreviousBalance()
                         << " to $" << trans->getSenderPreviousBalance() - trans->getAmount()
                         << ") on " << Helper::TimeStingToFormattedString(trans->getDate()) << '\n';
                } else if (trans->getReceiver()->getId() == userId) {
                    cout << "Receiving $" << trans->getAmount() << " from " << trans->getSender()->getUserName()
                         << " (Account Balance Changed from $" << trans->getReceiverPreviousBalance()
                         << " to $" << trans->getReceiverPreviousBalance() + trans->getAmount()
                         << ") on " << Helper::TimeStingToFormattedString(trans->getDate()) << '\n';
                }
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