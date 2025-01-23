#ifndef INPUTPARSER_HPP
#define INPUTPARSER_HPP

#include <vector>
#include <string>
#include <istream>

class InputParser {
public:
    static void parseInput(const std::string& inputFile, std::vector<int>& leftList, std::vector<int>& rightList);
};

#endif // INPUTPARSER_HPP
