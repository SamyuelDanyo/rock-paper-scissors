#include <algorithm>
#include <cassert>


#include "rps_test_player.h"
#include "src/include/rps_player_human.h"
#include "src/include/rps_player_computer.h"
#include "src/include/rps_util.h"

namespace rock_paper_scissors {
    void TestBasicFunctionalityPlayerComputer() {
        PlayerComputer player("TestComputer");
        assert(player.GetName() == "TestComputer");
        player.ResetWins();
        assert(player.GetWins() == 0);
        int wins_before_increment = player.GetWins();
        player.IncrementWins();
        assert(player.GetWins() == wins_before_increment+1);
        player.DecrementWins();
        assert(player.GetWins() == wins_before_increment);
    }

    void TestGetSymbolPlayerComputer() {
        PlayerComputer player("test");
        auto symbol {player.GetSymbol()};
        assert( std::find(symbols.begin(), symbols.end(), symbol) != symbols.end() );
    }

    void TestMakeSymbolPlayerComputer() {
        PlayerComputer player("test");
        auto symbol {player.MakeSymbol()};
        assert( std::find(symbols.begin(), symbols.end(), symbol) != symbols.end() );
    }

    void TestPlayerComputer() {
        TestBasicFunctionalityPlayerComputer();
        TestGetSymbolPlayerComputer();
        TestMakeSymbolPlayerComputer();
        Print({"INFO:: All testcases for PlayerComputer finished successfully!"});
    }

    void TestBasicFunctionalityPlayerHuman() {
        PlayerHuman player("TestHuman");
        assert(player.GetName() == "TestHuman");
        player.ResetWins();
        assert(player.GetWins() == 0);
        int wins_before_increment = player.GetWins();
        player.IncrementWins();
        assert(player.GetWins() == wins_before_increment+1);
        player.DecrementWins();
        assert(player.GetWins() == wins_before_increment);
    }

    void TestGetSymbolPlayerHuman() {
        PlayerHuman player("test");
        auto symbol {player.GetSymbol()};
        assert( std::find(symbols.begin(), symbols.end(), symbol) != symbols.end() );
    }

    void TestMakeSymbolPlayerHuman() {
        PlayerHuman player("test");
        auto symbol {player.MakeSymbol()};
        assert( std::find(symbols.begin(), symbols.end(), symbol) != symbols.end() );
    }

    void TestPlayerHuman() {
        TestBasicFunctionalityPlayerHuman();
        TestGetSymbolPlayerHuman();
        TestMakeSymbolPlayerHuman();
        Print({"INFO:: All testcases for PlayerHuman finished successfully!"});
    }
}