#ifndef DAY4_HPP
#define DAY4_HPP

#include <string>
#include <vector>

class Day4 {
public:
    static void solveDay4(const std::string& inputFile);

private:
    static int countWordInGrid(const std::vector<std::string>& grid, const std::string& word);
    static int countWordInDirection(const std::vector<std::string>& grid, int row, int col, int dx, int dy, const std::string& word);
    static int findAllXMASPatterns(const std::vector<std::string>& grid);
    static bool isValidXMASPattern(const std::vector<std::string>& grid, int row, int col);
};

#endif // DAY4_HPP
