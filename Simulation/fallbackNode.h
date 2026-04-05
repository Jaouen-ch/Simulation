#pragma once

#include "flowNode.h"

class fallbackNode : public flowNode
{
public:
    fallbackNode() = default;
    fallbackNode(behaviorTree* _tree, flowNode* _parent);
    fallbackNode(behaviorTree* _tree, flowNode* _parent, const std::vector<node*>& _children);
    virtual ~fallbackNode() override = default;

    virtual void onChildEnd(nodeState childState) override;
};