#ifndef DAY2_HPP
#define DAY2_HPP

#include <vector>
#include <string>

class Day2 {
public:
    static void solveDay2(const std::string& inputFile);
    static int countSafeReports(const std::vector<std::vector<int>>& reports);
    static bool isSafeReport(const std::vector<int>& report);
    static int countSafeReportsWithDampener(const std::vector<std::vector<int>>& reports);
    static bool isSafeWithDampener(const std::vector<int>& report);
};

#endif // DAY2_HPP
