#include <iostream>
#include <random>
#include <string>
#include <memory>
#include <chrono>
#include <cstdint>

#include "rps_player_computer.h"

namespace rock_paper_scissors {
    PlayerComputer::PlayerComputer() :
        Player("Computer"), distr_(0, 2) {
            auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            gen_.seed(static_cast<int>(seed));
        }

    PlayerComputer::PlayerComputer(const std::string &player_name) :
        Player(player_name), distr_(0, 2) {
            auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            gen_.seed(static_cast<int>(seed));
        }

    std::string
    PlayerComputer::GetSymbol() {
        return symbols[distr_(gen_)];
    }
}