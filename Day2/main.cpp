#include "input_loader.h"
#include <sstream>

struct Data {
    int min;
    int max;
    char check;
    std::string password;
};

bool initDataVec(std::vector<std::string> &inputStrVec, std::vector<Data> &dataVec) {
    char dash, colon;
    for (std::string &str : inputStrVec) {
        std::istringstream iss(str);
        Data data = Data();
        if (!(iss >> data.min >> dash >> data.max >> data.check >> colon >> data.password
              && dash == '-' && colon == ':')) {
            std::cerr << "Invalid String: " << str << std::endl;
            return false;
        } else {
            dataVec.push_back(data);
        }
    }
    return true;

}

int solutionOne(std::vector<Data> &dataVec) {
    int validCount = 0;
    for (Data data : dataVec) {
        int n = std::count(data.password.begin(), data.password.end(), data.check);
        if (n >= data.min && n <= data.max) {
            validCount++;
        }
    }
    return validCount;
}

int solutionTwo(std::vector<Data> &dataVec) {
    int validCount = 0;
    for (Data data : dataVec) {
        std::string password = data.password;
        int posOne = data.min - 1;
        int posTwo = data.max - 1;

        if (password.at(posOne) == data.check || password.at(posTwo) == data.check) {
            if (!(password.at(posOne) == data.check && password.at(posTwo) == data.check)) {
                validCount++;
            }
        }
    }
    return validCount;
}


int main() {
    std::vector<std::string> inputStrVec;
    std::vector<Data> dataVec;

    if (input(inputStrVec) && initDataVec(inputStrVec, dataVec)) {
        std::cout << solutionOne(dataVec) << std::endl;
        std::cout << solutionTwo(dataVec) << std::endl;
    }
    return 0;
}
