#ifndef RPS_GAME_H
#define RPS_GAME_H

#include <vector>
#include <string>

#include "rps_round.h"
#include "rps_player_human.h"
#include "rps_player_computer.h"

namespace rock_paper_scissors {
    template<class Player1T=rock_paper_scissors::PlayerHuman, class Player2T=rock_paper_scissors::PlayerComputer>
    class Game {
      public:
        Game(int &number_of_rounds);
        Game(int &number_of_rounds, std::string &player1_name);
        Game(int &number_of_rounds, std::string &player1_name, std::string &player2_name);
        std::vector<Round<Player1T, Player2T>>& GetRounds();
        bool CheckEarlyVictory(Round<Player1T, Player2T> &round);
        void PlayRound(Round<Player1T, Player2T> &round);
        void Play();
        void Review();

      private:
        std::vector<Round<Player1T, Player2T>> game_rounds_;
        Player1T player1_;
        Player2T player2_;
    };
}
#endif // RPS_GAME_H