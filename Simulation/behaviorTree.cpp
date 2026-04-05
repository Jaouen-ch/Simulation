#include "behaviorTree.h"

#include "rootNode.h"

behaviorTree::behaviorTree()
    : behaviorTree(nullptr)
{
}

behaviorTree::behaviorTree(blackBoard* _internBlackBoard)
    : internBlackBoard(_internBlackBoard)
{
}

behaviorTree::~behaviorTree()
{
    cleanTree();
}


void behaviorTree::beginExecute()
{
    root->beginExecute();
}

void behaviorTree::tick(float deltaTime)
{
    root->tick(deltaTime);
}

void behaviorTree::buildTree()
{
    root = new rootNode();
    allSubNodes.push_back(root);
}

void behaviorTree::cleanTree()
{
    for (auto node : allSubNodes)
    {
        delete node;
        node = nullptr;
    }
    allSubNodes.clear();
}

blackBoard* behaviorTree::getBlackBoard()
{
    return internBlackBoard;
}