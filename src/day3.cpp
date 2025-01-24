
#include "day3.hpp"
#include <input_parser.hpp>
#include <iostream>
// Compute the sum of all valid multiplications
int Day3::computeResult(const std::vector<std::pair<int, int>> &instructions) {
    int result = 0;
    for (const auto &[x, y] : instructions) {
        result += x * y;
    }
    return result;
}

void Day3::solve(const std::string& inputFile) {
        std::vector<std::pair<int, int>> instructions;
        std::vector<std::pair<int, int>> instructions2;
        InputParser::parseInputDay3(inputFile, instructions);
        int result = computeResult(instructions);
        std::cout << "The sum of all valid mul results is: " << result << std::endl;

        InputParser::parseInputDay3Part2(inputFile, instructions2);
        int result2 = computeResult(instructions2);
        std::cout << "The sum of all valid mul results for part 2 is: " << result2 << std::endl;
}