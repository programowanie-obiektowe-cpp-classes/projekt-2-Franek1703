#include "day1.hpp"
#include "input_parser.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

/// Function to compute the total distance
int computeTotalDistance(std::vector<int>& leftList, std::vector<int>& rightList) {
    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

    int totalDistance = 0;

    for (size_t i = 0; i < leftList.size(); ++i) {
        totalDistance += std::abs(leftList[i] - rightList[i]);
    }

    return totalDistance;
}

// Function to solve Day 1
void solveDay1(const std::string& inputFile) {
    std::vector<int> leftList, rightList;

    // Parse input
    InputParser::parseInput(inputFile, leftList, rightList);

    // Compute the total distance
    int totalDistance = computeTotalDistance(leftList, rightList);

    // Output the result
    std::cout << "Total distance: " << totalDistance << std::endl;
}
