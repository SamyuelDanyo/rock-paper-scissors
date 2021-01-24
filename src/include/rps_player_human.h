#ifndef RPS_PLAYER_HUMAN_H
#define RPS_PLAYER_HUMAN_H

#include <random>
#include <string>
#include <memory>

#include "rps_util.h"
#include "rps_player.h"

namespace rock_paper_scissors {
    class PlayerHuman : public Player {
    public:
        PlayerHuman();
        PlayerHuman(const std::string &player_name);
        std::string GetSymbol() override;
    };
}
#endif // RPS_PLAYER_HUMAN_H