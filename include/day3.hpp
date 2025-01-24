#ifndef DAY3_HPP
#define DAY3_HPP

#include <vector>
#include <string>
#include <utility>

class Day3 {
public:
    // Parse the input string and extract valid mul(X,Y) instructions
    static std::vector<std::pair<int, int>> parseInput(const std::string &input);

    // Compute the sum of all valid multiplications
    static int computeResult(const std::vector<std::pair<int, int>> &instructions);

    // Main solver function
    static void solve(const std::string& inputFile);
};

#endif // DAY3_HPP