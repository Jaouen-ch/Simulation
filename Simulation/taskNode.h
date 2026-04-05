#pragma once

#include "node.h"

class taskNode : public node
{
public:
    taskNode() = default;
    taskNode(behaviorTree* _tree, flowNode* _parent);
    virtual ~taskNode() override = default;
};