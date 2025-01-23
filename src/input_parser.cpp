#include "input_parser.hpp"
#include <sstream>
#include <iostream>
#include <fstream>

void InputParser::parseInput(const std::string& inputFile, std::vector<int>& leftList, std::vector<int>& rightList) {
    
    //Open file
     std::ifstream input(inputFile);
    if (!input) {
        std::cerr << "Error: Unable to open file " << inputFile << std::endl;
        return;
    }
    std::string line;
    while (std::getline(input, line)) {
        std::stringstream ss(line);
        int left, right;
        ss >> left >> right;
        leftList.push_back(left);
        rightList.push_back(right);
    }
}
