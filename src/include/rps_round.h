#ifndef RPS_ROUND_H
#define RPS_ROUND_H

#include "rps_player_computer.h"
#include "rps_player_human.h"

namespace rock_paper_scissors {
    class Round {
      public:
        Round(const int &round_id, PlayerHuman &round_player1,
              PlayerComputer &round_player2);
        int GetId();
        bool IsPlayed();
        void Play();
        void Review();

      private:
        const int id_;
        bool round_played_ {false};
        PlayerHuman &player1_;
        PlayerComputer &player2_;
        std::string symbol_player1_;
        std::string symbol_player2_;
        std::shared_ptr<Player> winner_;
    };
}
#endif // RPS_ROUND_H