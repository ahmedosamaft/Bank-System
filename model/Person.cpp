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

    const std::string Person::toString() {
        return std::string();
    }

    bool Person::operator==(const Person &rhs) const {
        return id == rhs.id;
    }
    bool Person::operator==(const long long &id) const {
        return (this->id == id);
    }
    bool Person::operator==(const std::string &userName) const {
        return (this->userName == userName);
    }

    Person::Person() {}
    const std::string &Person::getName() const {
        return name;
    }
    void Person::setName(const std::string &name) {
        Person::name = name;
    }

    Person::Person(long long int id, const std::string &name, const std::string &userName, const std::string &password, const std::string &creationDate) : id(id), name(name), userName(userName), password(password), creationTime(creationDate) {}

    const std::string &Person::getCreationTime() const {
        return creationTime;
    }
    void Person::setCreationTime(const std::string &creationDate) {
        Person::creationTime = creationDate;
    }


}// namespace Model