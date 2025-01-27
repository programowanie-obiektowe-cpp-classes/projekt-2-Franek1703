#include "day1.hpp"
#include "input_parser.hpp"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

/// Funkcja do obliczania całkowitej odległości
int Day1::computeTotalDistance(std::vector< int >& leftList, std::vector< int >& rightList)
{
    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

    int totalDistance = 0;

    for (size_t i = 0; i < leftList.size(); ++i)
    {
        totalDistance += std::abs(leftList[i] - rightList[i]);
    }

    return totalDistance;
}

/// Funkcja do obliczania współczynnika podobieństwa
int calculateSimilarityScore(const std::vector< int >& leftList, const std::vector< int >& rightList)
{
    std::unordered_map< int, int > rightListCounts;

    // Zlicz wystąpienia każdej liczby w prawej liście
    for (int num : rightList)
    {
        rightListCounts[num]++;
    }

    int similarityScore = 0;

    // Oblicz współczynnik podobieństwa, mnożąc liczbę przez jej liczbę wystąpień w prawej liście
    for (int num : leftList)
    {
        if (rightListCounts.find(num) != rightListCounts.end())
        {
            similarityScore += num * rightListCounts[num];
        }
    }

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
