#ifndef INPUTPARSER_HPP
#define INPUTPARSER_HPP

#include <vector>
#include <string>
#include <istream>
#include <unordered_map>
#include <unordered_set>

class InputParser {
public:
    static void parseInput(const std::string& inputFile, std::vector<std::vector<int>>& reports);
    static void parseInputDay3(const std::string &inputFile, std::vector<std::pair<int, int>>& validInstructions);
    static void parseInputDay3Part2(const std::string &inputFile, std::vector<std::pair<int, int>>& validInstructions);
    static void parseInputDay4(const std::string& inputFile, std::vector<std::string>& grid);
    static std::pair<std::unordered_map<int, std::unordered_set<int>>, std::vector<std::vector<int>>> parseInputDay5(const std::string& filename);
};

#endif // INPUTPARSER_HPP
