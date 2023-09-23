cmake_minimum_required(VERSION 3.25)
project(bank_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(bank_system main.cpp model/Person.cpp model/Person.h model/Client.h model/Client.cpp model/Employee.cpp model/Employee.h controller/ClientController.cpp controller/ClientController.h Helper.cpp Helper.h controller/EmployeeController.cpp controller/EmployeeController.h
        model/Transaction.cpp
        model/Transaction.h controller/AdminController.cpp controller/AdminController.h view/View.cpp view/View.h)
