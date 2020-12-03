#ifndef INPUT_LOADER_H
#define INPUT_LOADER_H

#include <iostream>
#include <vector>
#include <fstream>

static const std::string FILE_NAME = "input.txt";

bool input(std::vector<std::string> &numList) {
    std::ifstream in(FILE_NAME.c_str());
    std::string inputStr;
    if (!in) {
        std::cerr << "Could not open file: " << FILE_NAME << std::endl;
        return false;
    }
    while (std::getline(in, inputStr)) {
        numList.push_back(inputStr);
    }
    in.close();
    return true;
}

#endif
