//
// Created by andro on 9/19/2023.
//

#ifndef INC_8ACBB991E22240ACAF39A01A825CDC0E
#define INC_8ACBB991E22240ACAF39A01A825CDC0E

#include "../model/Client.h"
#include <map>
#include <memory>
#include <vector>

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
        static void takeControl(string &userName, string &password);
        // Todo: TakeControl(user, password) : void
        // Todo: Withdraw();
        // Todo: Deposit();
        // Todo: transferTo(Client) :void;
        // Todo: display() :void;
    };

}// namespace Manger

#endif//INC_8ACBB991E22240ACAF39A01A825CDC0E
