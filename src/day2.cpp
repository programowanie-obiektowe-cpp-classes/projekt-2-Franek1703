#include "day2.hpp"
#include <cmath>
#include <input_parser.hpp>
#include <iostream>

/**
 * Sprawdza, czy dany raport jest bezpieczny.
 * @param report Wektor liczb całkowitych reprezentujących raport.
 * @return true, jeśli raport jest bezpieczny, w przeciwnym razie false.
 */
bool Day2::isSafeReport(const std::vector<int>& report) {
    if (report.empty()) return false;

    bool increasing = true;
    bool decreasing = true;

    for (size_t i = 1; i < report.size(); ++i) {
        int diff = report[i] - report[i - 1];

        if (std::abs(diff) < 1 || std::abs(diff) > 3) {
            return false;
        }

        if (diff > 0) {
            decreasing = false;
        } else if (diff < 0) {
            increasing = false;
        }
    }

    return increasing || decreasing;
}

/**
 * Liczy liczbę bezpiecznych raportów.
 * @param reports Wektor wektorów liczb całkowitych reprezentujących raporty.
 * @return Liczba bezpiecznych raportów.
 */
int Day2::countSafeReports(const std::vector<std::vector<int>>& reports) {
    int safeCount = 0;

    for (const auto& report : reports) {
        if (isSafeReport(report)) {
            ++safeCount;
        }
    }

    return safeCount;
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

    for (size_t i = 0; i < report.size(); ++i) {
        std::vector<int> modifiedReport = report;
        modifiedReport.erase(modifiedReport.begin() + i); // Usuń jeden poziom

        if (isSafeReport(modifiedReport)) {
            return true; // Stał się bezpieczny po usunięciu poziomu
        }
    }

    return false; // Nie da się naprawić usunięciem jednego poziomu
}

/**
 * Liczy liczbę bezpiecznych raportów po zastosowaniu Dampenera.
 * @param reports Wektor wektorów liczb całkowitych reprezentujących raporty.
 * @return Liczba bezpiecznych raportów po zastosowaniu Dampenera.
 */
int Day2::countSafeReportsWithDampener(const std::vector<std::vector<int>>& reports) {
    int safeCount = 0;

    for (const auto& report : reports) {
        if (isSafeWithDampener(report)) {
            ++safeCount;
        }
    }

    return safeCount;
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

    // Policz bezpieczne raporty (część 1)
    int safeCount = countSafeReports(reports);
    std::cout << "Number of safe reports: " << safeCount << std::endl;

    // Policz bezpieczne raporty z Dampenerem (część 2)
    int safeCountWithDampener = countSafeReportsWithDampener(reports);
    std::cout << "Number of safe reports with Dampener: " << safeCountWithDampener << std::endl;
}