//
// Created by andro on 9/19/2023.
//

#ifndef INC_8ACBB991E22240ACAF39A01A825CDC0E
#define INC_8ACBB991E22240ACAF39A01A825CDC0E

#include "../model/Client.h"
#include <map>
#include <memory>
#include <vector>
#include <fstream>
#include <iostream>
#include <memory>

namespace Manger {
    using namespace std;
    class ClientManger {

    public:
        static vector<shared_ptr<Model::Client>> allClients;
        static string clientsDirectory;
        static shared_ptr<Model::Client> currentClient;
        static map<long long, shared_ptr<Model::Client>> idClient;

        static void readClients();
        static bool isValidClient(string &userName, string &password);
        static void getClient(string &userName, string &password);
        static shared_ptr<Model::Client> getClient(string &userName);
        static void takeControl(string &userName, string &password);
        static void withdraw(long long &userId);
        static void deposit(long long &userId);
        static void showTransactionHistory(long long &userId);
        static void transferTo();
        static void applyChanges();
        // Todo: display() :void;
    };

}// namespace Manger

#endif//INC_8ACBB991E22240ACAF39A01A825CDC0E
