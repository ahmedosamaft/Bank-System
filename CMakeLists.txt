cmake_minimum_required(VERSION 3.25)
project(bank_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(bank_system main.cpp model/Person.cpp model/Person.h model/Client.h model/Client.cpp)
