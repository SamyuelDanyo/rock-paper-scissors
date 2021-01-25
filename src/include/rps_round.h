#ifndef RPS_ROUND_H
#define RPS_ROUND_H

#include "rps_player_computer.h"
#include "rps_player_human.h"

namespace rock_paper_scissors {
    template<class Player1T=PlayerHuman, class Player2T=PlayerComputer>
    class Round {
      public:
        Round(const int &round_id, Player1T &round_player1, Player2T &round_player2);
        int GetId();
        bool IsPlayed();
        void Play();
        void Review();

      private:
        const int id_;
        bool round_played_ {false};
        Player1T &player1_;
        Player2T &player2_;
        std::string symbol_player1_;
        std::string symbol_player2_;
        std::shared_ptr<Player> winner_;
    };
}
#endif // RPS_ROUND_H