//
// Created by andro on 9/19/2023.
//

#include "ClientController.h"
#include <chrono>

namespace Controller {
    string ClientController::clientsDirectory = "../database/client.txt";
    string ClientController::transactionHistoryDirectory = "../database/transactionHistory.txt";
    vector<shared_ptr<Model::Client>> ClientController::allClients = vector<shared_ptr<Model::Client>>();
    shared_ptr<Model::Client> ClientController::currentClient = std::make_shared<Model::Client>();
    map<long long, shared_ptr<Model::Client>> ClientController::idClient = map<long long, shared_ptr<Model::Client>>();
    map<long long, shared_ptr<Model::Transaction>> ClientController::idTransaction = map<long long, shared_ptr<Model::Transaction>>();
    map<string, shared_ptr<Model::Client>> ClientController::allClientsUserName = map<string, shared_ptr<Model::Client>>();
    long long ClientController::lastIdClient = 0;
    long long ClientController::lastIdTransaction = 0;

    void ClientController::readClients() {
        allClients.clear();
        idClient.clear();
        allClientsUserName.clear();
        ifstream fin(clientsDirectory);
        std::string line;
        while (getline(fin, line) && !line.empty()) {
            shared_ptr<Model::Client> client{new Model::Client(line)};
            allClients.push_back(client);
            idClient[client->getId()] = client;
            allClientsUserName[client->getUserName()] = client;
            lastIdClient = max(lastIdClient, client->getId());
        }
        fin.close();
    }

    void ClientController::readTransactions() {
        idTransaction.clear();
        ifstream sin(transactionHistoryDirectory);
        std::string line;
        while (getline(sin, line) && !line.empty()) {
            shared_ptr<Model::Transaction> transaction{new Model::Transaction(line)};
            transaction->getSender()->setTransactionHistory(transaction);
            if (transaction->getTransactionType() == "3")
                transaction->getReceiver()->setTransactionHistory(transaction);
            idTransaction[transaction->getId()] = transaction;
            lastIdTransaction = max(lastIdTransaction, transaction->getId());
        }
    }

    bool ClientController::isValid(string &userName, string &password) {
        return (allClientsUserName.count(userName) && allClientsUserName[userName]->getPassword() == password);
    }

    shared_ptr<Model::Client> ClientController::getClient(string &userName) {
        return allClientsUserName[userName];
    }

    void ClientController::reloadData() {
        reloadTransactions();
        reloadClients();
    }

    void ClientController::reloadClients() {
        fstream sout(clientsDirectory,ios::out);
        for (auto &[id, client] : allClientsUserName) {
            if(client != nullptr)
                sout << client->toString() << '\n';
        }
        sout.close();
    }

    void ClientController::reloadTransactions() {
        fstream sout(transactionHistoryDirectory, ios::out);
        for (auto &[id, transaction] : idTransaction) {
            if(transaction != nullptr)
                sout << transaction->toString() << '\n';
        }
        sout.close();
    }

    void ClientController::takeControl(string &userName) {
        currentClient = getClient(userName);
        std::cout << "  Welcome " << currentClient->getName() << "\n";
        std::vector<std::string> menu = {"Account Information", "Withdraw", "Deposit", "Transfer Money To", "Transaction History", "Logout"};
        while (true){
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
    }

    void ClientController::accountInformation() {
        std::cout << "Name: " << currentClient->getName() << "\n username: " << currentClient->getUserName();
        std::cout << "\n Account Created at " << Helper::TimeStingToFormattedString(currentClient->getCreationDate());
        std::cout << "\n Account Balance: $" << currentClient->getBalance() << "\n\n";
    }

    void ClientController::withdraw() {
        cout << "How much amount you want to withdraw: ";
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
                makeTransaction(currentClient, currentClient, "1", amountOfMoney);
                currentClient->setBalance(newBalance);
                reloadData();
                cout << "Successful!\n";
                break;
            }
        }
    }

    void ClientController::deposit() {
        cout << "How much amount you want to deposit: ";
        double amountOfMoney, currentBalance = currentClient->getBalance();
        while (true) {
            cin >> amountOfMoney;
            if (cin.fail() || amountOfMoney < 0) {
                cout << "input a valid Amount of Money to deposit: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                double newBalance = currentBalance + amountOfMoney;
                makeTransaction(currentClient, currentClient, "2", amountOfMoney);
                currentClient->setBalance(newBalance);
                reloadData();
                cout << "Successful!\n";
                break;
            }
        }
    }

    void ClientController::transferTo() {
        cout << "Enter client username to transfer money to: ";
        string receiverUserName;
        shared_ptr<Model::Client> receiverClient;
        while (true) {
            cin >> receiverUserName;
            receiverClient = getClient(receiverUserName);
            if (receiverClient == nullptr || receiverClient->getId() == currentClient->getId()) {
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
                makeTransaction(currentClient, receiverClient, "3", amountOfMoney);
                currentClient->setBalance(newBalance);
                receiverClient->setBalance(receiverNewBalance);
                reloadData();
                cout << "Successful!\n";
                break;
            }
        }
    }

    void ClientController::showTransactionHistory() {
        std::vector<std::shared_ptr<Model::Transaction>> transactions = currentClient->getTransactionHistory();
        for (const auto &trans: transactions) {
            showTransaction(trans);
        }
    }

    void ClientController::showTransaction(const std::shared_ptr<Model::Transaction>& transaction) {
        if (transaction->getTransactionType() == "1") cout << "Withdrawing $";
        else if (transaction->getTransactionType() == "2")
            cout << "Depositing $";
        else if (transaction->getTransactionType() == "3") {
            if (transaction->getSender()->getId() == currentClient->getId())
                cout << "Sending $";
            else
                cout << "Receiving $";
        }
        cout << transaction->getAmount();


        if (transaction->getTransactionType() == "3") {
            if (transaction->getSender()->getId() == currentClient->getId())
                cout << " to " << transaction->getReceiver()->getUserName()
                     << " (Account Balance Changed from $" << transaction->getSenderPreviousBalance()
                     << " to $" << transaction->getSenderPreviousBalance() - transaction->getAmount();
            else
                cout << " from " << transaction->getSender()->getUserName()
                     << " (Account Balance Changed from $" << transaction->getReceiverPreviousBalance()
                     << " to $" << transaction->getReceiverPreviousBalance() + transaction->getAmount();
        } else
            cout << " (Account Balance Changed from $"
                 << transaction->getSenderPreviousBalance() << " to $"
                 << transaction->getSenderPreviousBalance() - transaction->getAmount();

        cout << ") on " << Helper::TimeStingToFormattedString(transaction->getDate()) << '\n';
    }

    void ClientController::makeTransaction(const shared_ptr<Model::Client> &sender, const shared_ptr<Model::Client> &receiver, const std::string &transactionType, double amount) {
        std::shared_ptr<Model::Transaction> transaction{new Model::Transaction()};
        transaction->setId(generateIdTransaction());
        transaction->setSender(sender);
        transaction->setReceiver(receiver);
        transaction->setReceiverPreviousBalance(receiver->getBalance());
        transaction->setSenderPreviousBalance(sender->getBalance());
        transaction->setAmount(amount);
        transaction->setTransactionType(transactionType);
        transaction->setDate(Helper::currentTimeToString());
        sender->setTransactionHistory(transaction);
        if (transaction->getTransactionType() == "3")// NOTE: 3 == transfer to
            transaction->getReceiver()->setTransactionHistory(transaction);
        saveTransaction(transaction);
    }

    void ClientController::saveTransaction(std::shared_ptr<Model::Transaction>& transaction) {
        std::fstream sout(Controller::ClientController::transactionHistoryDirectory, std::ios::app);
        idTransaction[transaction->getId()] = transaction;
        sout << transaction->toString() << '\n';
    }

    long long ClientController::generateIdClient() {
        return ++lastIdClient;
    }

    long long ClientController::generateIdTransaction() {
        return ++lastIdTransaction;
    }


}// namespace Controller