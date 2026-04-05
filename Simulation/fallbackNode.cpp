#include "fallbackNode.h"

fallbackNode::fallbackNode(behaviorTree* _tree, flowNode* _parent)
    : fallbackNode(_tree, _parent, {})
{
}

fallbackNode::fallbackNode(behaviorTree* _tree, flowNode* _parent, const std::vector<node*>& _children)
    : flowNode(_tree, _parent, _children)
{
}

void fallbackNode::onChildEnd(nodeState childState)
{
    if (childState == nodeState::failure)
    {
        flowNode::onChildEnd(childState);
    }
    else
    {
        returnToParent(nodeState::failure);
    }
}