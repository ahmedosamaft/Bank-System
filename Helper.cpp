//
// Created by andro on 9/19/2023.
//

#include "Helper.h"
std::vector<std::string> Helper::parseLine(std::string entity, char delimiter) {
    std::vector<std::string> entity_vec;
    entity += delimiter;
    std::string word;
    for (const auto &ch: entity) {
        if(ch == delimiter){
            if(!word.empty())
                entity_vec.push_back(word);
            word.clear();
        } else {
            word += ch;
        }
    }
    return entity_vec;
}