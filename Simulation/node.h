#pragma once

#include "blackBoard.h"
#include "behaviorTree.h"

class flowNode;

enum class nodeState {
    unknown = 0,
    success = 1,
    failure = 2,
};

class node
{
protected:
    behaviorTree* tree;
    flowNode* parent;

public:
    node() = default;
    node(behaviorTree* _tree, flowNode* parent);
    virtual ~node() = default;

    virtual void beginExecute();
    virtual void tick(float deltaTime);
    virtual void endExecute();

    blackBoard* getBlackBoard();
    behaviorTree* getBehaviorTree();
};