#include <day1.hpp>
#include <iostream>
#include <filesystem>
#include <day2.hpp>
#include <day3.hpp>

int main()
{
    Day1::solveDay1("../inputs/input1.txt");
    Day2::solveDay2("../inputs/input2.txt");
    Day3::solve("../inputs/input3.txt");
}
