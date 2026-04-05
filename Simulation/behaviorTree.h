#pragma once

#include <vector>
#include "blackBoard.h"

class rootNode;
class node;

class behaviorTree
{
protected:
    blackBoard* internBlackBoard;
    rootNode* root = nullptr;
    std::vector<node*> allSubNodes;
public:
    behaviorTree();
    behaviorTree(blackBoard* _internBlackBoard);
    virtual ~behaviorTree();

    void beginExecute();
    void tick(float deltaTime);

    virtual void buildTree();
    void cleanTree();

    blackBoard* getBlackBoard();
};