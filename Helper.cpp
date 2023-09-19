//
// Created by andro on 9/19/2023.
//

#include "Helper.h"
#include <iostream>
std::vector<std::string> Helper::parseLine(std::string entity, char delimiter) {
    std::vector<std::string> entity_vec;
    entity += delimiter;
    std::string word;
    for (const auto &ch: entity) {
        if (ch == delimiter) {
            if (!word.empty())
                entity_vec.push_back(word);
            word.clear();
        } else {
            word += ch;
        }
    }
    return entity_vec;
}
static int getChoice(std::vector<std::string> &menu) {
    std::cout << "Please make a choice:\n";
    for (int i = 0; i < menu.size(); ++i) {
        std::cout << i + 1 << " - " << menu[i] << std::endl;
    }
    std::cout << "Choice: ";
    int choose;
    std::cin >> choose;
    return choose;
}