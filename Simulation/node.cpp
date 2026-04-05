#include "node.h"

node::node(behaviorTree* _tree, flowNode* _parent)
    : tree(_tree)
    , parent(_parent)
{
}

void node::beginExecute()
{
}

void node::tick(float deltaTime)
{
}

void node::endExecute()
{
}

blackBoard* node::getBlackBoard()
{
    return tree->getBlackBoard();
}


behaviorTree* node::getBehaviorTree()
{
    return tree;
}
