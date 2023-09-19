#include "manger/ClientManger.h"
#include "model/Client.h"
#include <iostream>
#include <string>


int main() {
    std::string s = "c001";
    Manger::ClientManger::readClients();
    Manger::ClientManger::takeControl(s, s);
    std::cout << 1;
    return 0;
}
