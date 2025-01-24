#ifndef INPUTPARSER_HPP
#define INPUTPARSER_HPP

#include <vector>
#include <string>
#include <istream>

class InputParser {
public:
    static void parseInput(const std::string& inputFile, std::vector<std::vector<int>>& reports);
    static void parseInputDay3(const std::string &inputFile, std::vector<std::pair<int, int>>& validInstructions);
    static void parseInputDay3Part2(const std::string &inputFile, std::vector<std::pair<int, int>>& validInstructions);
};

#endif // INPUTPARSER_HPP
