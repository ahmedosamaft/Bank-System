//
// Created by andro on 9/19/2023.
//

#include "Person.h"

namespace Model {
    long long int Person::getId() const {
        return id;
    }
    void Person::setId(long long int id) {
        Person::id = id;
    }
    const std::string &Person::getFirstName() const {
        return first_name;
    }
    void Person::setFirstName(const std::string &firstName) {
        first_name = firstName;
    }
    const std::string &Person::getLastName() const {
        return last_name;
    }
    void Person::setLastName(const std::string &lastName) {
        last_name = lastName;
    }
    const std::string &Person::getUserName() const {
        return userName;
    }
    void Person::setUserName(const std::string &userName) {
        Person::userName = userName;
    }
    const std::string &Person::getPassword() const {
        return password;
    }
    void Person::setPassword(const std::string &password) {
        Person::password = password;
    }
    Person::Person(long long int id, const std::string firstName, const std::string lastName, const std::string userName, const std::string password) : id(id), first_name(firstName), last_name(lastName), userName(userName), password(password) {}
    /// read Entity from DB
    Person::Person(std::string &line) {
    }
    // TODO: return Entity as string
    std::string Person::ToSting() {
        return std::string();
    }
    bool Person::operator==(const Person &rhs) const {
        return id == rhs.id;
    }
    bool Person::operator==(const long long &id) const {
        return (this->id == id);
    }
}// namespace Model