#pragma once

#include "behaviorTree.h"

class customerBehaviorTree : public behaviorTree
{
public:
    customerBehaviorTree() = default;
    customerBehaviorTree(blackBoard* _internBlackBoard);
    ~customerBehaviorTree() override = default;

    void buildTree() override;
};