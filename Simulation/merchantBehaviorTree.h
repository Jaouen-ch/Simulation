#pragma once

#include "behaviorTree.h"

class merchantBehaviorTree : public behaviorTree
{
public:
    merchantBehaviorTree() = default;
    merchantBehaviorTree(blackBoard* _internBlackBoard);
    ~merchantBehaviorTree() override = default;

    void buildTree() override;
};