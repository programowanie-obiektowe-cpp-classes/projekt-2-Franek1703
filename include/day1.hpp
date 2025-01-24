#ifndef DAY1_HPP
#define DAY1_HPP

#include <string>
#include <vector>

class Day1
{
public:
    static int computeTotalDistance(std::vector< int >& leftList, std::vector< int >& rightList);

    // Deklaracja głównej funkcji do rozwiązania zadania
    static void solveDay1(const std::string& inputFile);
};

#endif // DAY1_HPP
