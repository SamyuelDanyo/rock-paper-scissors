#include <algorithm>
#include <cassert>


#include "rps_test_round.h"
#include "src/include/rps_round.h"
#include "src/include/rps_util.h"

namespace rock_paper_scissors {
    void TestRoundBasicFunctionality() {
        PlayerHuman player1("TestHuman");
        PlayerComputer player2("TestComputer");
        Round round(7, player1, player2);
        assert(round.GetId() == 7);
        assert(round.IsPlayed() == false);
    }

    void TestRoundPlay() {
        PlayerHuman player1("TestHuman");
        PlayerComputer player2("TestComputer");
        Round round(7, player1, player2);
        round.Play();
        assert(round.IsPlayed() == true);
        round.Play();
    }

    void TestRoundReview() {
        PlayerHuman player1("TestHuman");
        PlayerComputer player2("TestComputer");
        Round round(7, player1, player2);
        round.Review();
        round.Play();
        round.Review();
    }

    void TestRound() {
        TestRoundBasicFunctionality();
        TestRoundPlay();
        TestRoundReview();
        Print({"INFO:: All testcases for Round finished successfully!"});
    }
}