#include "input_parser.hpp"
#include <day5.hpp>
#include <iostream>
#include <queue>

/**
 * @brief Sprawdza, czy podana kolejność aktualizacji jest zgodna z regułami.
 * 
 * @param rules Mapa reguł, gdzie klucz to strona, a wartość to zbiór stron, które muszą być przed nią.
 * @param update Wektor stron do aktualizacji.
 * @return true Jeśli kolejność jest zgodna z regułami.
 * @return false Jeśli kolejność nie jest zgodna z regułami.
 */
bool Day5::isValidOrder(const std::unordered_map< int, std::unordered_set< int > >& rules,
                        const std::vector< int >& update)
{
    std::unordered_map< int, int > positions;
    for (size_t i = 0; i < update.size(); ++i)
    {
        positions[update[i]] = i;
    }

    for (const auto& [x, dependents] : rules)
    {
        if (positions.find(x) != positions.end())
        {
            for (int y : dependents)
            {
                if (positions.find(y) != positions.end() && positions[x] > positions[y])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

/**
 * @brief Naprawia kolejność aktualizacji stron zgodnie z regułami.
 * 
 * @param rules Mapa reguł, gdzie klucz to strona, a wartość to zbiór stron, które muszą być przed nią.
 * @param update Wektor stron do aktualizacji.
 * @return std::vector<int> Poprawiona kolejność stron.
 */
std::vector<int>  Day5::fixOrder(const std::unordered_map<int, std::unordered_set<int>>& rules, const std::vector<int>& update) {
        // Create a directed graph for the pages in the update
        std::unordered_map<int, int> inDegree;
        std::unordered_map<int, std::vector<int>> graph;

        for (int page : update) {
            inDegree[page] = 0;
        }

        for (const auto& [x, dependents] : rules) {
            if (inDegree.find(x) != inDegree.end()) {
                for (int y : dependents) {
                    if (inDegree.find(y) != inDegree.end()) {
                        graph[x].push_back(y);
                        inDegree[y]++;
                    }
                }
            }
        }

        // Perform topological sort
        std::queue<int> q;
        for (const auto& [page, degree] : inDegree) {
            if (degree == 0) {
                q.push(page);
            }
        }

        std::vector<int> sortedOrder;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            sortedOrder.push_back(current);

            for (int neighbor : graph[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return sortedOrder;
    }

 /**
 * @brief Rozwiązuje zadanie dnia 5 na podstawie pliku wejściowego.
 * 
 * @param filename Nazwa pliku wejściowego.
 */
void Day5::solveDay5(const std::string& filename)
{
    auto [rules, updates] = InputParser::parseInputDay5(filename);
    int sumOfMiddles      = 0;
    int sumOfMiddles2     = 0;

    for (const auto& update : updates)
    {
        if (isValidOrder(rules, update))
        {
            sumOfMiddles += update[update.size() / 2];
        }
        else{
            std::vector<int> fixedOrder = fixOrder(rules, update);
            sumOfMiddles2 += fixedOrder[fixedOrder.size() / 2];
        }
    }
    std::cout << "The sum of middle page numbers is: " << sumOfMiddles << std::endl;
    std::cout << "The sum of middle page numbers for part 2 is: " << sumOfMiddles2 << std::endl;
}