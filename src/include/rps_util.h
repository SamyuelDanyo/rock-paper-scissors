#ifndef RPS_UTIL_H
#define RPS_UTIL_H

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <unordered_map>

namespace rock_paper_scissors {

    extern std::array<std::string, 3> symbols;

    bool IsValid(std::string symbol);

    std::string
    GetWinnerName(const std::string &symbol1, const std::string &symbol2);

    void
    Print(std::vector<std::string> input);
}
#endif // RPS_UTIL_H