#pragma once
#include <random>

class newRandom
{
public:
    newRandom() = default;
    ~newRandom() = default;

    static int getRandomNumber(int min, int max);
};