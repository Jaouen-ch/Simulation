#include "sequenceNode.h"

sequenceNode::sequenceNode(behaviorTree* _tree, flowNode* _parent)
    : sequenceNode(_tree, _parent, {})
{
}

sequenceNode::sequenceNode(behaviorTree* _tree, flowNode* _parent, const std::vector<node*>& _children)
    : flowNode(_tree, _parent, _children)
{
}

void sequenceNode::onChildEnd(nodeState childState)
{
    if (childState == nodeState::success)
    {
        flowNode::onChildEnd(childState);
    }
    else
    {
        returnToParent(nodeState::failure);
    }
}