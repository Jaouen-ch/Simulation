#include "rootNode.h"

#include "flowNode.h"

rootNode::rootNode(behaviorTree* _tree, flowNode* _child)
    : node(_tree, nullptr)
    , child(_child)
{
}

void rootNode::beginExecute()
{
    if (child != nullptr)
    {
        child->beginExecute();
    }
}

void rootNode::tick(float deltaTime)
{
    if (child != nullptr)
    {
        child->tick(deltaTime);
    }
}

void rootNode::setChild(flowNode* rootsChild)
{
    child = rootsChild;
}