#include <thread>
#include <future>
# include <functional>

#include "rps_round.h"
#include "rps_player_computer.h"
#include "rps_player_human.h"

namespace rock_paper_scissors {
    template<class Player1T, class Player2T>
    Round<Player1T, Player2T>::Round(const int &round_id, Player1T &round_player1,
                                     Player2T &round_player2
    ) :
        id_(round_id), player1_(round_player1), player2_(round_player2) {}

    template<class Player1T, class Player2T>
    int
    Round<Player1T, Player2T>::GetId() {return id_;}

    template<class Player1T, class Player2T>
    bool
    Round<Player1T, Player2T>::IsPlayed() {return round_played_;}

    template<class Player1T, class Player2T>
    void
    Round<Player1T, Player2T>::Play() {
        if(round_played_) {
            Print({"Replaying round ", std::to_string(id_)});
        }
        auto future_symbol1 = std::async(std::bind(&Player1T::MakeSymbol, std::ref(player1_)));
        auto future_symbol2 = std::async(std::bind(&Player2T::MakeSymbol, std::ref(player2_)));
        symbol_player1_ = future_symbol1.get();
        symbol_player2_ = future_symbol2.get();
        auto winner_name = GetWinnerName(symbol_player1_, symbol_player2_);
        if(winner_name == "player1") {
            winner_ = std::make_shared<Player1T>(player1_);
            player1_.IncrementWins();
        } else if(winner_name == "player2") {
            winner_ = std::make_shared<Player2T>(player2_);
            player2_.IncrementWins();
        } else if (winner_name == "none") {
            Print({"Wrong symbol encountered!"});
        }
        round_played_ = true;
    }

    template<class Player1T, class Player2T>
    void
    Round<Player1T, Player2T>::Review() {
        Print({"\n", ">>> Round ", std::to_string(id_), " Review <<<"});
        Print({player1_.GetName(), " vs ", player2_.GetName()});
        if(!round_played_) {
            Print({"Round is not played yet. Come back later!", "\n"});
            return;
        }
        Print({symbol_player1_, " vs ", symbol_player2_});
        if(winner_ == nullptr) {
            Print({"Outcome: Draw!", "\n"});
            return;
        }
        Print({"Outcome: Winner: ", winner_->GetName(), "\n"});
    }

    template class Round<PlayerHuman, PlayerHuman>;
    template class Round<PlayerHuman, PlayerComputer>;
    template class Round<PlayerComputer, PlayerHuman>;
    template class Round<PlayerComputer, PlayerComputer>;
}