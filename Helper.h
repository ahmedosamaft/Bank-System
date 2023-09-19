//
// Created by andro on 9/19/2023.
//

#ifndef INC_8AD4B2443FFC43468B905CF99DDC2CA3
#define INC_8AD4B2443FFC43468B905CF99DDC2CA3


#include <string>
#include <vector>
class Helper {
public:
    static std::vector<std::string> parseLine(std::string entity, char delimiter);
    static int getChoice(std::vector<std::string> &Menu);
};


#endif//INC_8AD4B2443FFC43468B905CF99DDC2CA3
