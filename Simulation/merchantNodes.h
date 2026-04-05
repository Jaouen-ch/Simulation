#pragma once

#include "merchantBlackboard.h"
#include "taskNode.h"

class isMorningNode : public taskNode
{
public:
    isMorningNode() = default;
    isMorningNode(behaviorTree* _tree, flowNode* _parent);
    ~isMorningNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    merchantBlackboard* _blackboard = nullptr;
};

class setVariablesMorningNode : public taskNode
{
public:
    setVariablesMorningNode() = default;
    setVariablesMorningNode(behaviorTree* _tree, flowNode* _parent);
    ~setVariablesMorningNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    merchantBlackboard* _blackboard = nullptr;
};

class payRawMaterialsNode : public taskNode
{
public:
    payRawMaterialsNode() = default;
    payRawMaterialsNode(behaviorTree* _tree, flowNode* _parent);
    ~payRawMaterialsNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    merchantBlackboard* _blackboard = nullptr;
};

class destroyMerchantNode : public taskNode
{
public:
    destroyMerchantNode() = default;
    destroyMerchantNode(behaviorTree* _tree, flowNode* _parent);
    ~destroyMerchantNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    merchantBlackboard* _blackboard = nullptr;
};

class isDayNode : public taskNode
{
public:
    isDayNode() = default;
    isDayNode(behaviorTree* _tree, flowNode* _parent);
    ~isDayNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    merchantBlackboard* _blackboard = nullptr;
};

class fireEventNode : public taskNode
{
public:
    fireEventNode() = default;
    fireEventNode(behaviorTree* _tree, flowNode* _parent);
    ~fireEventNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    merchantBlackboard* _blackboard = nullptr;
    int nbRandom = 0;
};

class theftEventNode : public taskNode
{
public:
    theftEventNode() = default;
    theftEventNode(behaviorTree* _tree, flowNode* _parent);
    ~theftEventNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    merchantBlackboard* _blackboard = nullptr;
    int nbRandom = 0;
};

class defaultEventNode : public taskNode
{
public:
    defaultEventNode() = default;
    defaultEventNode(behaviorTree* _tree, flowNode* _parent);
    ~defaultEventNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    merchantBlackboard* _blackboard = nullptr;
};

class isEveningNode : public taskNode
{
public:
    isEveningNode() = default;
    isEveningNode(behaviorTree* _tree, flowNode* _parent);
    ~isEveningNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    merchantBlackboard* _blackboard = nullptr;
};

class setVariablesEveningNode : public taskNode
{
public:
    setVariablesEveningNode() = default;
    setVariablesEveningNode(behaviorTree* _tree, flowNode* _parent);
    ~setVariablesEveningNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    merchantBlackboard* _blackboard = nullptr;
};

class orderMoreNode : public taskNode
{
public:
    orderMoreNode() = default;
    orderMoreNode(behaviorTree* _tree, flowNode* _parent);
    ~orderMoreNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    merchantBlackboard* _blackboard = nullptr;
};

class increasePriceNode : public taskNode
{
public:
    increasePriceNode() = default;
    increasePriceNode(behaviorTree* _tree, flowNode* _parent);
    ~increasePriceNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    merchantBlackboard* _blackboard = nullptr;
};

class orderLessNode : public taskNode
{
public:
    orderLessNode() = default;
    orderLessNode(behaviorTree* _tree, flowNode* _parent);
    ~orderLessNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    merchantBlackboard* _blackboard = nullptr;
};

class reducePriceNode : public taskNode
{
public:
    reducePriceNode() = default;
    reducePriceNode(behaviorTree* _tree, flowNode* _parent);
    ~reducePriceNode() override = default;

    void beginExecute() override;
    void tick(float deltaTime) override;
    void endExecute() override;

private:
    merchantBlackboard* _blackboard = nullptr;
};