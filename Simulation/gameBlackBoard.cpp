#include "gameBlackBoard.h"

#include "game.h"

gameBlackBoard::gameBlackBoard(game* _self, timeOfDay& _currentTime)
    : self(_self)
    , currentTime(_currentTime)
{
}