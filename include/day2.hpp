#ifndef DAY2_HPP
#define DAY2_HPP

#include <vector>
#include <string>

class Day2 {
public:
    static void solveDay2(const std::string& inputFile);
    int countSafeReports(const std::vector<std::vector<int>>& reports);
    static bool isSafeReport(const std::vector<int>& report);
    int countSafeReportsWithDampener(const std::vector<std::vector<int>>& reports);
    static bool isSafeWithDampener(const std::vector<int>& report);
};

#endif // DAY2_HPP
