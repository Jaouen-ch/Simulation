#pragma once

#include "blackBoard.h"

class customer;

class customerBlackboard : public blackBoard
{
public:
    customerBlackboard() = default;
    customerBlackboard(customer* _self);
    ~customerBlackboard() override = default;

    customer* self = nullptr;
};