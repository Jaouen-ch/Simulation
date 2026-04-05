#pragma once

#include "blackBoard.h"
#include "gameBlackBoard.h"

class merchant;

class merchantBlackboard : public blackBoard
{
public:
    merchantBlackboard() = default;
    merchantBlackboard(merchant* _self, timeOfDay& _currentTime);
    ~merchantBlackboard() override = default;

    merchant* self;
    timeOfDay& currentTime;
};