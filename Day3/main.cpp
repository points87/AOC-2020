#include <cmath>
#include "input_loader.h"

int is_integer(double num) {
    return std::floor(num) == num;
}

//m : slope, x = m * y
int solutionOne(std::vector<std::string> &data, double m) {
    int treeCount = 0;
    for (int y = 0; y < data.size(); y++) {
        std::string row = data.at(y);
        double x = std::fmod(m * y, row.length());
        if (is_integer(x) && row[x] == '#') {
            treeCount++;
        }
    }
    return treeCount;
}

unsigned int solutionTwo(std::vector<std::string> &data) {
    unsigned int treeCount = 1;
    std::vector<double> slopes = {1, 3, 5, 7, 0.5};
    for (double slope : slopes) {
        treeCount = treeCount * solutionOne(data, slope);
    }
    return treeCount;
}


int main() {
    std::vector<std::string> data;

    if (input(data)) {
        std::cout << solutionOne(data, 3) << std::endl;
        std::cout << solutionTwo(data) << std::endl;
    }
    return 0;
}
