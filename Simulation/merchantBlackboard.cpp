#include "merchantBlackboard.h"

merchantBlackboard::merchantBlackboard(merchant* _self, timeOfDay& _currentTime)
    : self(_self)
    , currentTime(_currentTime)
{
}