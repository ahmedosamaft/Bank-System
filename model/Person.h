// Copyright (c) 2023. Ahmed Osama

#ifndef BANK_SYSTEM_PERSON_H
#define BANK_SYSTEM_PERSON_H

#include "../Helper.h"
#include <memory>
#include <string>

namespace Model {

    class Person {
    private:
        long long id;
        std::string name;
        std::string userName;
        std::string password;
        std::string createdAt;


    public:
        Person();
        Person(long long int id, const std::string &name, const std::string &userName, const std::string &password);
        virtual const std::string toString();
        bool operator==(const Person &rhs) const;
        bool operator==(const long long &id) const;
        bool operator==(const std::string &userName) const;


    public:
        long long int getId() const;
        void setId(long long int id);
        const std::string &getName() const;
        void setName(const std::string &name);
        const std::string &getUserName() const;
        void setUserName(const std::string &userName);
        const std::string &getPassword() const;
        void setPassword(const std::string &password);
    };

}// namespace Model

#endif//BANK_SYSTEM_PERSON_H
