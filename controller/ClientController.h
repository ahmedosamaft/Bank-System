//
// Created by andro on 9/19/2023.
//

#ifndef INC_8ACBB991E22240ACAF39A01A825CDC0E
#define INC_8ACBB991E22240ACAF39A01A825CDC0E

#include "../model/Client.h"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

namespace Controller {
    using namespace std;
    class ClientController {

    public:
        static vector<shared_ptr<Model::Client>> allClients;
        static string clientsDirectory, transactionHistoryDirectory;
        static shared_ptr<Model::Client> currentClient;
        static map<long long, shared_ptr<Model::Client>> idClient;
        static map<string, shared_ptr<Model::Client>> allClientsUserName;
        static map<long long, shared_ptr<Model::Transaction>> idTransaction;
        static long long lastIdClient;
        static long long lastIdTransaction;


        static void readClients();
        static void readTransactions();
        static bool isValid(string &userName, string &password);
        static shared_ptr<Model::Client> getClient(string &userName);
        static void takeControl(string &userName);
        static void accountInformation();
        static void withdraw();
        static void deposit();
        static void showTransactionHistory();
        static void transferTo();
        static void makeTransaction(const shared_ptr<Model::Client>& sender, const shared_ptr<Model::Client>& receiver, const string& transactionType, double amount);
        static void saveTransaction(shared_ptr<Model::Transaction>& transaction);
        static void showTransaction(const shared_ptr<Model::Transaction>& transaction);
        static long long generateIdClient();
        static long long generateIdTransaction();
        static void reloadData();
        static void reloadClients();
        static void reloadTransactions();
    };

}// namespace Controller

#endif//INC_8ACBB991E22240ACAF39A01A825CDC0E
