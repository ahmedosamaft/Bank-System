//
// Created by andro on 9/19/2023.
//

#include "ClientManger.h"
#include <fstream>
#include <iostream>
#include <memory>

namespace Manger {
    string ClientManger::clientsDirectory = "../database/client.txt";
    vector<shared_ptr<Model::Client>> ClientManger::allClients = vector<shared_ptr<Model::Client>>();
    shared_ptr<Model::Client> ClientManger::currentClient = std::make_shared<Model::Client>();
    map<long long, shared_ptr<Model::Client>> ClientManger::idClient = map<long long, shared_ptr<Model::Client>>();


    void ClientManger::readClients() {
        allClients.clear();
        idClient.clear();
        ifstream fin(clientsDirectory);
        std::string line;
        while (getline(fin, line)) {
            shared_ptr<Model::Client> client{new Model::Client(line)};
            allClients.push_back(client);
            idClient[client->getId()] = client;
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

    void ClientManger::takeControl(string &userName, string &password) {
        getClient(userName, password);
        std::cout << "\twelcome, " << currentClient->getName() << '\n';

    }
}// namespace Manger