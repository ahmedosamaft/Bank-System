//
// Created by andro on 9/19/2023.
//

#ifndef INC_8AD4B2443FFC43468B905CF99DDC2CA3
#define INC_8AD4B2443FFC43468B905CF99DDC2CA3


#include <chrono>
#include <iomanip>
#include <memory>
#include <sstream>
#include <string>
#include <vector>


class Helper {
public:
    static std::vector<std::string> parseLine(std::string entity, char delimiter);
    static int runMenu(std::vector<std::string> &menu);
    static std::string makeEntity(std::vector<std::string> &data, char delimiter);
    static std::string currentTimeToString();
    static std::string currentTimeToFormattedString();
    static std::string TimeStingToFormattedString(const std::string &timeString);
    template<class T>
    static void eraseEntity(std::vector<std::shared_ptr<T>> & entities,std::shared_ptr<T>& entityToDelete);
    static bool isInteger(const std::string &s);
};


#endif//INC_8AD4B2443FFC43468B905CF99DDC2CA3
