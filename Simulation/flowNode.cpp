#include "flowNode.h"

flowNode::flowNode(behaviorTree* _tree, flowNode* _parent)
    : flowNode(_tree, _parent, {})
{
}

flowNode::flowNode(behaviorTree* _tree, flowNode* _parent, const std::vector<node*>& _children)
    : node(_tree, _parent)
    , children(_children)
{
}

void flowNode::addChild(node* child)
{
    children.push_back(child);
}

void flowNode::returnToParent(nodeState state)
{
    if (parent != nullptr)
    {
        parent->onChildEnd(state);
        currentExecuteChild = nullptr;
    }
    else
    {
        currentExecuteChild = *children.begin();
        currentExecuteChild->beginExecute();
    }
}

void flowNode::onChildEnd(nodeState childState)
{
    auto iterator = std::find(children.begin(), children.end(), currentExecuteChild);
    if (iterator != children.end())
    {
        int index = std::distance(children.begin(), iterator) + 1;
        if (index < children.size())
        {
            currentExecuteChild = children[index];
            currentExecuteChild->beginExecute();
        }
        else
        {
            returnToParent(nodeState::success);
        }
    }
}

void flowNode::beginExecute()
{
    currentExecuteChild = *children.begin();
    if (currentExecuteChild != nullptr)
    {
        currentExecuteChild->beginExecute();
    }
}

void flowNode::tick(float deltaTime)
{
    if (currentExecuteChild != nullptr)
    {
        currentExecuteChild->tick(deltaTime);
    }
}
