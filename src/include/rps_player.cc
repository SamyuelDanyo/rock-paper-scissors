#include <iostream>
#include <random>
#include <string>
#include <memory>
#include <mutex>

#include "rps_player.h"

namespace rock_paper_scissors {
    Player::Player() :
        name_("Default") {}

    Player::Player(const std::string &player_name) :
        name_(player_name) {}

    std::string
    Player::GetName() const {return name_;}

    int
    Player::GetWins() const {return wins_;}

    void
    Player::IncrementWins() {++wins_;}

    void
    Player::DecrementWins() {--wins_;}

    void
    Player::ResetWins() {wins_ = 0;}

    std::string
    Player::MakeSymbol() {
        Print({"Rock! Paper! Scissors!"});
        auto symbol = GetSymbol();
        return symbol;
    }
}