#pragma once

#include "taskNode.h"
#include "gameBlackBoard.h"

enum class products;
class customer;

class createMerchantsNode : public taskNode
{
public:
    createMerchantsNode() = default;
    createMerchantsNode(behaviorTree* _tree, flowNode* _parent);
    ~createMerchantsNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    gameBlackBoard* _blackboard = nullptr;
    std::vector<products> productsOnSale;
    std::vector<products> productsTypes;
    products* newMerchantProduct = nullptr;
};

class morningActionsFinishedNode : public taskNode
{
public:
    morningActionsFinishedNode() = default;
    morningActionsFinishedNode(behaviorTree* _tree, flowNode* _parent);
    ~morningActionsFinishedNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    gameBlackBoard* _blackboard = nullptr;
    bool allActionsFinished = true;
};

class dayTimeNode : public taskNode
{
public:
    dayTimeNode() = default;
    dayTimeNode(behaviorTree* _tree, flowNode* _parent);
    ~dayTimeNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    gameBlackBoard* _blackboard = nullptr;
};

class createCustomersNode : public taskNode
{
public:
    createCustomersNode() = default;
    createCustomersNode(behaviorTree* _tree, flowNode* _parent);
    ~createCustomersNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    gameBlackBoard* _blackboard = nullptr;
    customer* c = nullptr;
    float time = 0.0f;
};

class dayActionsFinishedNode : public taskNode
{
public:
    dayActionsFinishedNode() = default;
    dayActionsFinishedNode(behaviorTree* _tree, flowNode* _parent);
    ~dayActionsFinishedNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    gameBlackBoard* _blackboard = nullptr;
    bool allActionsFinished = true;
};

class inflationEventNode : public taskNode
{
public:
    inflationEventNode() = default;
    inflationEventNode(behaviorTree* _tree, flowNode* _parent);
    ~inflationEventNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    gameBlackBoard* _blackboard = nullptr;
    int nbRandom = 0;
};

class eveningTimeNode : public taskNode
{
public:
    eveningTimeNode() = default;
    eveningTimeNode(behaviorTree* _tree, flowNode* _parent);
    ~eveningTimeNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    gameBlackBoard* _blackboard = nullptr;
};

class eveningActionsFinishedNode : public taskNode
{
public:
    eveningActionsFinishedNode() = default;
    eveningActionsFinishedNode(behaviorTree* _tree, flowNode* _parent);
    ~eveningActionsFinishedNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    gameBlackBoard* _blackboard = nullptr;
    bool allActionsFinished = true;
};

class morningTimeNode : public taskNode
{
public:
    morningTimeNode() = default;
    morningTimeNode(behaviorTree* _tree, flowNode* _parent);
    ~morningTimeNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    gameBlackBoard* _blackboard = nullptr;
};