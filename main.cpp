#include "manger/ClientManger.h"
#include "model/Client.h"
#include <iostream>
#include <string>


int main() {
    std::string s = "c002";
    Manger::ClientManger::readClients();
    while (true)
    Manger::ClientManger::takeControl(s, s);
    return 0;
}
