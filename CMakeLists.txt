cmake_minimum_required(VERSION 3.25)
project(bank_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(bank_system main.cpp model/Person.cpp model/Person.h model/Client.h model/Client.cpp model/Employee.cpp model/Employee.h model/Admin.cpp model/Admin.h manger/ClientManger.cpp manger/ClientManger.h Helper.cpp Helper.h manger/EmployeeManager.cpp manger/EmployeeManager.h
        model/Transaction.cpp
        model/Transaction.h manger/AdminManger.cpp manger/AdminManger.h)
