#ifndef RPS_PLAYER_COMPUTER_H
#define RPS_PLAYER_COMPUTER_H

#include <random>
#include <string>
#include <memory>

#include "rps_util.h"
#include "rps_player.h"

namespace rock_paper_scissors {
    class PlayerComputer : public Player {
      public:
        PlayerComputer();
        PlayerComputer(const std::string &player_name);
        std::string GetSymbol() override;

      private:
        std::mt19937 gen_;
        std::uniform_int_distribution<> distr_;
    };
}
#endif // RPS_PLAYER_COMPUTER_H