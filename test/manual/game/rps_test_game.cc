#include <algorithm>
#include <cassert>
#include <string>


#include "rps_test_game.h"
#include "src/include/rps_game.h"
#include "src/include/rps_util.h"

namespace rock_paper_scissors {
    void TestGameBasicFunctionality() {
        std::string player_name {"TestHuman"};
        int number_of_rounds {5};
        Game game(player_name, number_of_rounds);
        assert(game.CheckEarlyVictory(game.GetRounds()[3]) == false);
        game.PlayRound(game.GetRounds()[2]);
        assert(game.CheckEarlyVictory(game.GetRounds()[2]) == false);
    }

    void TestGame() {
        TestGameBasicFunctionality();
        Print({"INFO:: All testcases for Game finished successfully!"});
    }
}