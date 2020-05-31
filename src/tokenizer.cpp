//
// Created by mornie on 30.05.2020.
//

#include "tokenizer.hpp"

std::vector< std::string > tokenize(std::string str, const std::string& delimiter){
    std::vector< std::string > tokens;
    str.append(delimiter);
    while (str.find(delimiter) != std::string::npos){
        tokens.push_back(str.substr(0, str.find(delimiter)));
        str.erase(str.begin(), str.begin() + str.find(delimiter) + delimiter.size());
    }
    return tokens;
}