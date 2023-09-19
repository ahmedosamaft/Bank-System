// Copyright (c) 2023. Ahmed Osama

#ifndef BANK_SYSTEM_PERSON_H
#define BANK_SYSTEM_PERSON_H

#include <string>
namespace Model {

    class Person {
    private:
        long long id;
        std::string first_name;
        std::string last_name;
        std::string userName;
        std::string password;


    public:
        Person(long long int id, const std::string firstName, const std::string lastName, const std::string userName, const std::string password);
        Person(std::string &line);
        std::string ToSting();
        bool operator==(const Person &rhs) const;
        bool operator==(const long long &id) const;

    public:
        long long int getId() const;
        void setId(long long int id);
        const std::string &getFirstName() const;
        void setFirstName(const std::string &firstName);
        const std::string &getLastName() const;
        void setLastName(const std::string &lastName);
        const std::string &getUserName() const;
        void setUserName(const std::string &userName);
        const std::string &getPassword() const;
        void setPassword(const std::string &password);
    };

}// namespace Model

#endif//BANK_SYSTEM_PERSON_H
