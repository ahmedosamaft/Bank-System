//
// Created by andro on 9/19/2023.
//

#include "ClientManger.h"
#include <memory>
#include <fstream>

namespace Manger {
    string ClientManger::clients_dir = "../database/client.txt";
    vector<shared_ptr<Model::Client>> ClientManger::all_clients = vector<shared_ptr<Model::Client>>();
    shared_ptr<Model::Client> ClientManger::current_client = std::make_shared<Model::Client> ();
    map<long long,shared_ptr<Model::Client>> ClientManger::id_client = map<long long,shared_ptr<Model::Client>> ();


    void ClientManger::readClients() {
        all_clients.clear();
        id_client.clear();
        ifstream fin(clients_dir);
        std::string line;
        while (getline(fin,line)){
            shared_ptr<Model::Client> client{new Model::Client(line)};
            all_clients.push_back(client);
            id_client[client->getId()] = client;
        }
    }
}// namespace Manger