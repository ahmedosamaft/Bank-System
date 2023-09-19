//
// Created by andro on 9/19/2023.
//

#ifndef INC_8ACBB991E22240ACAF39A01A825CDC0E
#define INC_8ACBB991E22240ACAF39A01A825CDC0E

#include "../model/Client.h"
#include <vector>
#include <map>
#include <memory>
namespace Manger {
    using namespace std;
    class ClientManger {
    public:
        static vector<shared_ptr<Model::Client>> all_clients;
        static string clients_dir;
        static shared_ptr<Model::Client> current_client;
        static map<long long,shared_ptr<Model::Client>> id_client;

        static void readClients();
    };

}// namespace Manger

#endif//INC_8ACBB991E22240ACAF39A01A825CDC0E
