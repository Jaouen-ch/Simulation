#pragma once

#include "behaviorTree.h"

class gameBehaviorTree : public behaviorTree
{
public:
    gameBehaviorTree() = default;
    gameBehaviorTree(blackBoard* _internBlackBoard);
    ~gameBehaviorTree() override = default;

    void buildTree() override;
};