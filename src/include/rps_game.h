#ifndef RPS_GAME_H
#define RPS_GAME_H

#include <vector>
#include <string>

#include "rps_round.h"
#include "rps_player_human.h"
#include "rps_player_computer.h"

namespace rock_paper_scissors {
    class Game {
      public:
        Game(std::string &player1_name, int &number_of_rounds);
        std::vector<Round>& GetRounds();
        bool CheckEarlyVictory(Round &round);
        void PlayRound(Round &round);
        void Play();
        void Review();

      private:
        std::vector<Round> game_rounds_;
        PlayerHuman player1_;
        PlayerComputer player2_;
    };
}
#endif // RPS_GAME_H