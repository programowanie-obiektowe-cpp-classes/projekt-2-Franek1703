#include "day2.hpp"
#include <cmath>
#include <input_parser.hpp>
#include <iostream>
#include <numeric>
#include <algorithm>

/**
 * Sprawdza, czy dany raport jest bezpieczny.
 * @param report Wektor liczb całkowitych reprezentujących raport.
 * @return true, jeśli raport jest bezpieczny, w przeciwnym razie false.
 */
bool Day2::isSafeReport(const std::vector<int>& report) {
    if (report.empty()) return false;
    
    // Obliczamy różnice między kolejnymi elementami.
    std::vector<int> diffs(report.size() - 1);
    std::transform(report.begin() + 1, report.end(), report.begin(), diffs.begin(),
                   [](int current, int previous) {
                       return current - previous;
                   });
    
    // Sprawdzamy, czy każda różnica mieści się w przedziale [1,3] (w wartościach bezwzględnych).
    if (!std::all_of(diffs.begin(), diffs.end(), [](int diff) {
            return std::abs(diff) >= 1 && std::abs(diff) <= 3;
        }))
    {
        return false;
    }
    
    // Raport jest bezpieczny, jeśli wszystkie różnice są dodatnie (ciąg rosnący)
    // lub wszystkie są ujemne (ciąg malejący).
    bool increasing = std::all_of(diffs.begin(), diffs.end(), [](int diff) {
        return diff > 0;
    });
    bool decreasing = std::all_of(diffs.begin(), diffs.end(), [](int diff) {
        return diff < 0;
    });
    
    return increasing || decreasing;
}

/**
 * Liczy liczbę bezpiecznych raportów.
 * @param reports Wektor wektorów liczb całkowitych reprezentujących raporty.
 * @return Liczba bezpiecznych raportów.
 */
int Day2::countSafeReports(const std::vector<std::vector<int>>& reports) {
    return std::count_if(reports.begin(), reports.end(), [this](const std::vector<int>& report) {
        return isSafeReport(report);
    });
}

/**
 * Sprawdza, czy dany raport jest bezpieczny po zastosowaniu Dampenera.
 * @param report Wektor liczb całkowitych reprezentujących raport.
 * @return true, jeśli raport jest bezpieczny po zastosowaniu Dampenera, w przeciwnym razie false.
 */
bool Day2::isSafeWithDampener(const std::vector<int>& report) {
    if (isSafeReport(report)) {
        return true; // Już bezpieczny bez modyfikacji
    }

    std::vector<size_t> indices(report.size());
    std::iota(indices.begin(), indices.end(), 0);
    
    // Sprawdzamy, czy usunięcie któregokolwiek elementu uczyni raport bezpiecznym.
    return std::any_of(indices.begin(), indices.end(), [&](size_t i) {
        auto modifiedReport = report;
        modifiedReport.erase(modifiedReport.begin() + i);
        return isSafeReport(modifiedReport);
    });
}

/**
 * Liczy liczbę bezpiecznych raportów po zastosowaniu Dampenera.
 * @param reports Wektor wektorów liczb całkowitych reprezentujących raporty.
 * @return Liczba bezpiecznych raportów po zastosowaniu Dampenera.
 */
int Day2::countSafeReportsWithDampener(const std::vector<std::vector<int>>& reports) {
     return std::count_if(reports.begin(), reports.end(), [this](const std::vector<int>& report) {
        return isSafeWithDampener(report);
    });
}

/**
 * Rozwiązuje zadanie dnia 2 na podstawie pliku wejściowego.
 * @param inputFile Ścieżka do pliku wejściowego.
 */
void Day2::solveDay2(const std::string& inputFile) {
    InputParser parser;
    std::vector<std::vector<int>> reports;

    // Wczytaj dane wejściowe
    parser.parseInput(inputFile, reports);
    Day2 day2;
    // Policz bezpieczne raporty (część 1)
    int safeCount = day2.countSafeReports(reports);
    std::cout << "Number of safe reports: " << safeCount << std::endl;

    // Policz bezpieczne raporty z Dampenerem (część 2)
    int safeCountWithDampener = day2.countSafeReportsWithDampener(reports);
    std::cout << "Number of safe reports with Dampener: " << safeCountWithDampener << std::endl;
}