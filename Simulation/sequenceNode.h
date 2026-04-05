#pragma once

#include "flowNode.h"

class sequenceNode : public flowNode
{
public:
    sequenceNode() = default;
    sequenceNode(behaviorTree* _tree, flowNode* _parent);
    sequenceNode(behaviorTree* _tree, flowNode* _parent, const std::vector<node*>& _children);
    virtual ~sequenceNode() override = default;

    virtual void onChildEnd(nodeState childState) override;
};