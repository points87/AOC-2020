#include <iostream>
#include <fstream>
#include <vector>
#include <string>

static const std::string FILE_NAME = "input.txt";
static const int SUM = 2020;

bool input(std::vector<int> &numList) {
    std::ifstream in(FILE_NAME.c_str());
    std::string inputStr;
    if (!in) {
        std::cerr << "Could not open file: " << FILE_NAME << std::endl;
        return false;
    }
    while (std::getline(in, inputStr)) {
        int num = std::stoi(inputStr);
        numList.push_back(num);
    }
    in.close();
    return true;
}

int solutionOne(std::vector<int> &numList) {
    for (int i = 0; i < numList.size(); i++) {
        for (int j = 0; j < numList.size(); j++) {
            if (i != j) {
                if (numList.at(i) + numList.at(j) == SUM) {
                    return numList.at(i) * numList.at(j);
                }
            }
        }
    }
    return -1;
}

int solutionTwo(std::vector<int> &numList) {
    for (int i = 0; i < numList.size(); i++) {
        for (int j = 0; j < numList.size(); j++) {
            for (int k = 0; k < numList.size(); k++) {
                if (i != j && j != k) {
                    if (numList.at(i) + numList.at(j) + numList.at(k) == SUM) {
                        return numList.at(i) * numList.at(j) * numList.at(k);
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    std::vector<int> numList;
    if (input(numList)) {
        std::cout << solutionOne(numList) << std::endl;
        std::cout << solutionTwo(numList) << std::endl;
    }
    return 0;
}
