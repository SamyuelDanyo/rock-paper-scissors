#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <memory>

#include "rps_player_human.h"
#include "rps_util.h"

namespace rock_paper_scissors {
    PlayerHuman::PlayerHuman() :
        Player("Human") {}

    PlayerHuman::PlayerHuman(const std::string &player_name) :
        Player(player_name) {}

    std::string
    PlayerHuman::GetSymbol() {
        std::string player_symbol;
        Print({"Choose your symbol!(rock/paper/scissors)"});
        std::cin >> player_symbol;
        while(!IsValid(player_symbol)) {
            Print({"Please enter a valid symbols!(rock/paper/scissors)"});
            std::cin >> player_symbol;
        }
        return player_symbol;
    }
}