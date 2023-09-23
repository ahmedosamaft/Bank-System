// Copyright (c) 2023. Ahmed Osama

//
// Created by mohamed tamer on 19-Sep-23.
//

#ifndef INC_51CBF8FBE6C74E8E99E29EF03138241F
#define INC_51CBF8FBE6C74E8E99E29EF03138241F

#include "Person.h"

namespace Model {
    class Employee : public Person {
    private:
        double salary;
        bool isAdmin_;



    public:
        using Person::Person;
        const std::string toString() override;
        explicit Employee(const std::string &line);
        double getSalary() const;
        void setSalary(double balance);
        bool isAdmin() const;
        void setIsAdmin(bool isAdmin);
    };
}// namespace Model

#endif//INC_51CBF8FBE6C74E8E99E29EF03138241F
