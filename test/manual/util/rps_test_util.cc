#include <cassert>

#include "rps_test_util.h"
#include "src/include/rps_util.h"

namespace rock_paper_scissors {
    void TestGetWinnerName() {
        assert(GetWinnerName("rock", "paper") == "player2");
        assert(GetWinnerName("paper", "rock") == "player1");
        assert(GetWinnerName("rock", "scissors") == "player1");
        assert(GetWinnerName("scissors", "rock") == "player2");
        assert(GetWinnerName("paper", "scissors") == "player2");
        assert(GetWinnerName("scissors", "paper") == "player1");
        assert(GetWinnerName("rock", "rock") == "draw");
        assert(GetWinnerName("scissors", "scissors") == "draw");
        assert(GetWinnerName("paper", "paper") == "draw");
        assert(GetWinnerName("foo", "bar") == "none");
        assert(GetWinnerName("foo", "foo") == "none");
    }

    void TestUtil() {
        TestGetWinnerName();
        Print({"INFO:: All testcases for UTIL finished successfully!"});
    }
}