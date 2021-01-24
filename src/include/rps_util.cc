#include <array>
#include <algorithm>

#include "rps_util.h"

namespace rock_paper_scissors {
    std::array<std::string, 3> symbols {"rock", "paper", "scissors"};

    bool
    IsValid(std::string symbol) {
        return std::find(symbols.begin(), symbols.end(), symbol) != symbols.end();
    }

    std::string
    GetWinnerName(const std::string &symbol1, const std::string &symbol2) {
        if(!IsValid(symbol1) || !IsValid(symbol2)) {
            return "none";
        }
        
        if(symbol1 == symbol2) {
            return "draw";
        }
        
        if(symbol1 == "rock") {
            if(symbol2 == "paper") {return "player2";}
            if(symbol2 == "scissors") {return "player1";}
        } else if(symbol1 == "paper") {
            if(symbol2 == "rock") {return "player1";}
            if(symbol2 == "scissors") {return "player2";}
        } else if(symbol1 == "scissors") {
            if(symbol2 == "rock") {return "player2";}
            if(symbol2 == "paper") {return "player1";}
        }
        return "none";
    }

    void
    Print(std::vector<std::string> input) {
        for(auto el : input) {
            std::cout << el;
        }
        std::cout << std::endl;
    }
}