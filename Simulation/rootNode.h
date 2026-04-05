#pragma once

#include "node.h"

class rootNode : public node
{
private:
    flowNode* child;
public:
    rootNode() = default;
    rootNode(behaviorTree* _tree, flowNode* _child);
    ~rootNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;

    void setChild(flowNode* rootsChild);
};