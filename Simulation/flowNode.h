#pragma once

#include <vector>
#include "node.h"

class flowNode : public node
{
protected:
    std::vector<node*> children;
    node* currentExecuteChild = nullptr;

    void returnToParent(nodeState state);

public:
    flowNode() = default;
    flowNode(behaviorTree* _tree, flowNode* _parent);
    flowNode(behaviorTree* _tree, flowNode* _parent, const  std::vector<node*>& _children);
    virtual ~flowNode() override = default;

    void addChild(node* child);

    virtual void onChildEnd(nodeState childState);

    virtual void beginExecute() override;
    virtual void tick(float deltaTime) override;
};