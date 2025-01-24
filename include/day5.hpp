#ifndef DAY5_HPP
#define DAY5_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Day5 {
public:
    static void solveDay5(const std::string& inputFile);

private:
    static bool isValidOrder(const std::unordered_map<int, std::unordered_set<int>>& rules, const std::vector<int>& update);
    static std::vector<int> fixOrder(const std::unordered_map<int, std::unordered_set<int>>& rules, const std::vector<int>& update);
};

#endif // DAY5_HPP
