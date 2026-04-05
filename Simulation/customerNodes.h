#pragma once

#include "taskNode.h"
#include "customerBlackBoard.h"

class merchant;

class buyNode : public taskNode
{
public:
    buyNode() = default;
    buyNode(behaviorTree* _tree, flowNode* _parent);
    ~buyNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    customerBlackboard* _blackboard = nullptr;
    bool buySuccess = false;
};

class leaveNode : public taskNode
{
public:
    leaveNode() = default;
    leaveNode(behaviorTree* _tree, flowNode* _parent);
    ~leaveNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    customerBlackboard* _blackboard = nullptr;
};

class destroyNode : public taskNode
{
public:
    destroyNode() = default;
    destroyNode(behaviorTree* _tree, flowNode* _parent);
    ~destroyNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    customerBlackboard* _blackboard = nullptr;
};

class chooseMerchantNode : public taskNode
{
public:
    chooseMerchantNode() = default;
    chooseMerchantNode(behaviorTree* _tree, flowNode* _parent);
    ~chooseMerchantNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    customerBlackboard* _blackboard = nullptr;
    int nbRandom = 0;
    int bestPrice = 0;
    merchant* bestMerchant = nullptr;
    std::vector<merchant*> merchantPossible;
};

class goToNode : public taskNode
{
public:
    goToNode() = default;
    goToNode(behaviorTree* _tree, flowNode* _parent);
    ~goToNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    customerBlackboard* _blackboard = nullptr;
};