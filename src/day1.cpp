#include "day1.hpp"
#include "input_parser.hpp"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <numeric>

/// Funkcja do obliczania całkowitej odległości
int Day1::computeTotalDistance(std::vector< int >& leftList, std::vector< int >& rightList)
{
    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

     int totalDistance = std::transform_reduce(
        leftList.begin(), leftList.end(), 
        rightList.begin(), 
        0, 
        std::plus<>(), 
        [](int left, int right) { return std::abs(left - right); }
    );

    return totalDistance;
}

/// Funkcja do obliczania współczynnika podobieństwa
int calculateSimilarityScore(const std::vector< int >& leftList, const std::vector< int >& rightList)
{
    std::unordered_map< int, int > rightListCounts;

    // Zlicz wystąpienia każdej liczby w prawej liście
    std::for_each(rightList.begin(), rightList.end(), [&](int num) {
        rightListCounts[num]++;
    });


    // Oblicz współczynnik podobieństwa, mnożąc liczbę przez jej liczbę wystąpień w prawej liście
     int similarityScore = std::accumulate(leftList.begin(), leftList.end(), 0, [&](int sum, int num) {
        auto it = rightListCounts.find(num);
        return sum + (it != rightListCounts.end() ? num * it->second : 0);
    });

    return similarityScore;
}

/// Funkcja do rozwiązania zadania z dnia 1
void Day1::solveDay1(const std::string& inputFile)
{
    std::vector< int > leftList, rightList;

    // Parsowanie wejścia
    std::vector< std::vector< int > > reports;
    InputParser::parseInput(inputFile, reports);

    for (const auto& report : reports)
    {
        if (report.size() == 2)
        {
            leftList.push_back(report[0]);
            rightList.push_back(report[1]);
        }
    }

    // Compute the total distance
    int totalDistance = computeTotalDistance(leftList, rightList);

    // Output the result
    std::cout << "Total distance: " << totalDistance << std::endl;

    int similarityScore = calculateSimilarityScore(leftList, rightList);

    std::cout << "Similarity Score: " << similarityScore << std::endl;
}
