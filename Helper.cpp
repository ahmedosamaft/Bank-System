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

int Helper::runMenu(std::vector<std::string> &menu) {
    std::cout << "Please make a choice:\n";
    for (int i = 0; i < menu.size(); ++i) {
        std::cout << i + 1 << " - " << menu[i] << std::endl;
    }
    std::cout << "Choice: ";
    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || choice > menu.size() || choice < 0) {
            std::cout << "ERROR please input a number in range 1 to " << menu.size() << ": ";
        } else
            break;
    }
    return choice;
}
std::string Helper::makeEntity(std::vector<std::string> &data, char delimiter) {
    std::string ret;
    for (const auto &datum: data) {
        ret += datum + delimiter;
    }
    ret.pop_back();
    return ret;
}


std::string Helper::currentTimeToString() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    time_t currentTime = std::chrono::system_clock::to_time_t(now);
    tm *localTime = localtime(&currentTime);

    std::ostringstream oss;
    oss << std::put_time(localTime, "%Y%m%d%H%M%S");
    std::string s = oss.str();
    return s;
}

std::string Helper::currentTimeToFormattedString() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    time_t currentTime = std::chrono::system_clock::to_time_t(now);
    tm *localTime = localtime(&currentTime);

    std::ostringstream oss;
    oss << std::put_time(localTime, "%Y/%m/%d %H:%M:%S");
    std::string s = oss.str();
    return s;
}

std::string Helper::TimeStingToFormattedString(const std::string &timeString) {
    std::string year = timeString.substr(0, 4);
    std::string month = timeString.substr(4, 2);
    std::string day = timeString.substr(6, 2);
    std::string hour = timeString.substr(8, 2);
    std::string minute = timeString.substr(10, 2);
    std::string second = timeString.substr(12, 2);

    return year + '/' + month + '/' + day + ' ' + hour + ':' + minute + ':' + second;
}
template<class T>
void Helper::eraseEntity(std::vector<std::shared_ptr<T>> &entities, std::shared_ptr<T> &entityToDelete) {
    std::vector<T> ret;
    for (const auto &entity: entities) {
        if(entity != entityToDelete)
            ret.push_back(entity);
    }
    entities = ret;
}
