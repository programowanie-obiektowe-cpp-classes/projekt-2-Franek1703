#include "input_parser.hpp"
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>

void InputParser::parseInput(const std::string& inputFile, std::vector< std::vector< int > >& reports)
{
    // Open file
    std::ifstream input(inputFile);
    if (!input)
    {
        std::cerr << "Error: Unable to open file " << inputFile << std::endl;
        return;
    }

    std::string line;
    while (std::getline(input, line))
    {
        std::stringstream  ss(line);
        std::vector< int > report;
        int                value;

        // Parse integers in a line and add them to the current report
        while (ss >> value)
        {
            report.push_back(value);
        }

        reports.push_back(report);
    }
}

void InputParser::parseInputDay3(const std::string& inputFile, std::vector< std::pair< int, int > >& validInstructions)
{
    // Open file
    std::ifstream file(inputFile);
    if (!file)
    {
        std::cerr << "Error: Unable to open file " << inputFile << std::endl;
        return;
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string                 input = buffer.str();
    std::regex                  mulRegex(R"(mul\((\d{1,3}),(\d{1,3})\))");
    std::smatch                 match;
    std::string::const_iterator searchStart(input.cbegin());

    while (std::regex_search(searchStart, input.cend(), match, mulRegex))
    {
        try
        {
            int x = std::stoi(match[1].str());
            int y = std::stoi(match[2].str());
            validInstructions.emplace_back(x, y);
        }
        catch (const std::exception& e)
        {
            // Skip invalid matches
            continue;
        }
        searchStart = match.suffix().first;
    }
}