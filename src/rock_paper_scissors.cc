#include <iostream>
#include <string>

#include "include/rps_game.h"
#include "include/rps_player_human.h"
#include "include/rps_player_computer.h"
#include "include/rps_util.h"

int main() {
    rock_paper_scissors::Print({"Welcome to Rock-Paper-Scissors!"});
    std::string player_name;
    char play_another_game;
    rock_paper_scissors::Print({"Enter your name:"});
    std::cin >> player_name;
    do {
        int number_of_rounds;
        rock_paper_scissors::Print({"Enter number of game rounds:"});
        std::cin >> number_of_rounds;
        rock_paper_scissors::Game<> game(number_of_rounds, player_name);
        game.Play();
        game.Review();
        rock_paper_scissors::Print({"Would you like to play another game?(y/n)"});
        if(std::cin.fail()) {
            break;
        }
        std::cin >> play_another_game;
    } while(play_another_game == 'y');
    return 0;
}