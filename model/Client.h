//
// Created by Mohamed Abdelhady on 9/19/2023.
//

#ifndef BANK_SYSTEM_CLIENT_H
#define BANK_SYSTEM_CLIENT_H

#include "Person.h"

namespace Model {
    class Client : public Person {
    private:
        double balance{};
        
    public:
        using Person::Person;
        explicit Client(const std::string &line);
        double getBalance() const;
        void setBalance(double balance);
    };
}// namespace Model

#endif//BANK_SYSTEM_CLIENT_H
