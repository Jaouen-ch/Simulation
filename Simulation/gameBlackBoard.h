#pragma once

#include "blackBoard.h"

enum class timeOfDay
{
    morning,
    day,
    evening,
};

class game;

class gameBlackBoard : public blackBoard
{
public:
    gameBlackBoard(game* _self, timeOfDay& _currentTime);
    ~gameBlackBoard() override = default;

    game* self;
    timeOfDay& currentTime;
};