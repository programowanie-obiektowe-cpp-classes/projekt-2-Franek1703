#include "day4.hpp"
#include "input_parser.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

/**
 * @brief Rozwiązuje zadanie dnia 4.
 * 
 * @param inputFile Ścieżka do pliku wejściowego.
 */
void Day4::solveDay4(const std::string& inputFile) {
    std::vector<std::string> grid;
    InputParser::parseInputDay4(inputFile, grid);

    // Część 1: Zlicz wszystkie wystąpienia "XMAS"
    int totalOccurrences = countWordInGrid(grid, "XMAS");
    std::cout << "Number of XMAS occurrences: " << totalOccurrences << std::endl;

    // Część 2: Zlicz wszystkie wzorce "X-MAS"
    int totalXMASPatterns = findAllXMASPatterns(grid);
    std::cout << "Part 2: Number of X-MAS patterns: " << totalXMASPatterns << std::endl;
}

/**
 * @brief Zlicza wystąpienia danego słowa w siatce.
 * 
 * @param grid Siatka znaków.
 * @param word Słowo do zliczenia.
 * @return int Liczba wystąpień słowa.
 */
int Day4::countWordInGrid(const std::vector<std::string>& grid, const std::string& word) {
    int totalCount = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    int directions[8][2] = {
        {0, 1},  {1, 0},  {0, -1}, {-1, 0}, // Horizontal and Vertical
        {1, 1},  {1, -1}, {-1, 1}, {-1, -1} // Diagonals
    };

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            for (const auto& [dx, dy] : directions) {
                totalCount += countWordInDirection(grid, row, col, dx, dy, word);
            }
        }
    }

    return totalCount;
}

/**
 * @brief Zlicza wystąpienia słowa w danym kierunku.
 * 
 * @param grid Siatka znaków.
 * @param row Wiersz początkowy.
 * @param col Kolumna początkowa.
 * @param dx Kierunek w osi X.
 * @param dy Kierunek w osi Y.
 * @param word Słowo do zliczenia.
 * @return int Liczba wystąpień słowa w danym kierunku.
 */
int Day4::countWordInDirection(const std::vector<std::string>& grid, int row, int col, int dx, int dy, const std::string& word) {
    int wordLength = word.size();
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < wordLength; ++i) {
        int newRow = row + i * dx;
        int newCol = col + i * dy;

        if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || grid[newRow][newCol] != word[i]) {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Zlicza wszystkie wzorce "X-MAS" w siatce.
 * 
 * @param grid Siatka znaków.
 * @return int Liczba wzorców "X-MAS".
 */
int Day4::findAllXMASPatterns(const std::vector<std::string>& grid) {
    int totalCount = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (isValidXMASPattern(grid, row, col)) {
                totalCount++;
                // std::cout << "Pattern #" << totalCount << " detected at (" << row << ", " << col << ")" << std::endl;
            }
        }
    }

    return totalCount;
}

/**
 * @brief Sprawdza, czy dany wzorzec "X-MAS" jest poprawny.
 * 
 * @param grid Siatka znaków.
 * @param row Wiersz początkowy.
 * @param col Kolumna początkowa.
 * @return true Jeśli wzorzec jest poprawny.
 * @return false Jeśli wzorzec jest niepoprawny.
 */
bool Day4::isValidXMASPattern(const std::vector<std::string>& grid, int row, int col) {
    // Sprawdza, czy bieżąca komórka to 'A'
    if (grid[row][col] != 'A') {
        return false;
    }

    int rows = grid.size();
    int cols = grid[0].size();
    if (row - 1 < 0 || row + 1 >= rows || col - 1 < 0 || col + 1 >= cols) {
        return false;
    }

    // Sprawdza lewy wzorzec "MAS" lub "SAM"
    bool leftMAS = (grid[row - 1][col - 1] == 'M' && grid[row + 1][col + 1] == 'S');
    bool leftSAM = (grid[row - 1][col - 1] == 'S' && grid[row + 1][col + 1] == 'M');

    // Sprawdza prawy wzorzec "MAS" lub "SAM"
    bool rightMAS = (grid[row - 1][col + 1] == 'M' && grid[row + 1][col - 1] == 'S');
    bool rightSAM = (grid[row - 1][col + 1] == 'S' && grid[row + 1][col - 1] == 'M');

    // Sprawdza, czy lewy wzorzec jest poprawny
    bool leftValid = leftMAS || leftSAM;
    
    // Sprawdza, czy prawy wzorzec jest poprawny
    bool rightValid = rightMAS || rightSAM;

    // Zwraca true, jeśli oba wzorce są poprawne
    return leftValid && rightValid;
}
