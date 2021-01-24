#ifndef RPS_PLAYER_H
#define RPS_PLAYER_H

#include <random>
#include <string>
#include <memory>

#include "rps_util.h"

namespace rock_paper_scissors {
    class Player {
    public:
        Player();
        Player(const std::string &player_name);
        std::string GetName() const;
        int GetWins() const;
        void IncrementWins();
        void DecrementWins();
        void ResetWins();
        virtual std::string GetSymbol() = 0;
        std::string MakeSymbol();

    protected:
        const std::string name_;
        int wins_ {0};
    };
}
#endif // RPS_PLAYER_H