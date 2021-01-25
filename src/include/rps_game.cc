#include <string>
#include <iostream>

#include "rps_game.h"
#include "rps_util.h"

namespace rock_paper_scissors {
    template<class Player1T, class Player2T>
    Game<Player1T, Player2T>::Game(int &number_of_rounds
    ) :
        player1_(), player2_()
    {
        for(int i=0; i<number_of_rounds; ++i) {
            game_rounds_.push_back(Round<Player1T, Player2T>(i+1, player1_, player2_));
        }
    }
    template<class Player1T, class Player2T>
    Game<Player1T, Player2T>::Game(int &number_of_rounds,
                                   std::string &player1_name
    ) :
        player1_(player1_name), player2_()
    {
        for(int i=0; i<number_of_rounds; ++i) {
            game_rounds_.push_back(Round<Player1T, Player2T>(i+1, player1_, player2_));
        }
    }
    template<class Player1T, class Player2T>
    Game<Player1T, Player2T>::Game(int &number_of_rounds,
                                   std::string &player1_name,
                                   std::string &player2_name
    ) :
        player1_(player1_name), player2_(player2_name)
    {
        for(int i=0; i<number_of_rounds; ++i) {
            game_rounds_.push_back(Round<Player1T, Player2T>(i+1, player1_, player2_));
        }
    }

    template<class Player1T, class Player2T>
    std::vector<Round<Player1T, Player2T>>&
    Game<Player1T, Player2T>::GetRounds() {return game_rounds_;}

    template<class Player1T, class Player2T>
    bool
    Game<Player1T, Player2T>::CheckEarlyVictory(Round<Player1T, Player2T> &round) {
        if(round.IsPlayed()) {
            Print({"This round has already been played!"});
            return false;
        }
        bool not_last_round = round.GetId() < static_cast<int>(game_rounds_.size());
        int difference_in_wins {player1_.GetWins() - player2_.GetWins()};
        int rounds_left {static_cast<int>(game_rounds_.size() - round.GetId())};
        if(not_last_round) {
            if(difference_in_wins > rounds_left) {
                Print({player1_.GetName(), " achieves early victory!"});
                return true;
            }
            if(-difference_in_wins > rounds_left) {
                Print({player2_.GetName(), " achieves early victory!"});
                return true;
            }
        } else {
            if(difference_in_wins > 1) {
                Print({player1_.GetName(), " achieves early victory!"});
                return true;
            }
            if(-difference_in_wins > 1) {
                Print({player2_.GetName(), " achieves early victory!"});
                return true;
            }
        }
        return false;
    }

    template<class Player1T, class Player2T>
    void
    Game<Player1T, Player2T>::PlayRound(Round<Player1T, Player2T> &round) {
        round.Play();
        round.Review();
    }

    template<class Player1T, class Player2T>
    void
    Game<Player1T, Player2T>::Play() {
        if(game_rounds_.size() == 0) {
            Print({"There are 0 rounds in this game. No winners today!"});
            return;
        }
        Print({"\n", "### New Game Starts! ###"});
        Print({player1_.GetName(), " vs ", player2_.GetName(), "\n"});
        for(auto &round : game_rounds_) {
            if(CheckEarlyVictory(round)) {
                break;
            }
            PlayRound(round);
        }
        while(player1_.GetWins() == player2_.GetWins()) {
            Print({"The rounds are over but the score is draw!"});
            Print({"Would you like to play an additional round to settle this? (y/n)"});
            char user_choice;
            std::cin >> user_choice;
            if (user_choice == 'y') {
                game_rounds_.push_back(
                    Round<Player1T, Player2T>(game_rounds_.back().GetId()+1, player1_, player2_));
                PlayRound(game_rounds_.back());
            } else {
                break;
            }
        }
    }

    template<class Player1T, class Player2T>
    void
    Game<Player1T, Player2T>::Review() {
        Print({"\n", "### Game Review ###"});
        Print({player1_.GetName(), " round wins: ", std::to_string(player1_.GetWins()), " | ",
               player2_.GetName(), " round wins: ", std::to_string(player2_.GetWins())});
        if(player1_.GetWins() > player2_.GetWins()) {
            Print({player1_.GetName(), " wins the game!", "\n"});
        } else if(player2_.GetWins() > player1_.GetWins()) {
            Print({player2_.GetName(), " wins the game!", "\n"});
        } else {
            Print({"The game is draw!", "\n"});
        }
        
    }

    template class Game<PlayerHuman, PlayerComputer>;
    template class Game<PlayerHuman, PlayerHuman>;
    template class Game<PlayerComputer, PlayerHuman>;
    template class Game<PlayerComputer, PlayerComputer>;
}