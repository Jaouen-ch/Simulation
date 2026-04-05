#include "customerNodes.h"

#include "flowNode.h"
#include "customer.h"

buyNode::buyNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void buyNode::beginExecute()
{
    _blackboard = static_cast<customerBlackboard*>(getBlackBoard());
}

void buyNode::tick(float deltaTime)
{
    buySuccess = _blackboard->self->buy();
    endExecute();
}

void buyNode::endExecute()
{
    if (buySuccess)
    {
        parent->onChildEnd(nodeState::success);
    }
    else
    {
        parent->onChildEnd(nodeState::failure);
    }
}

leaveNode::leaveNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void leaveNode::beginExecute()
{
    _blackboard = static_cast<customerBlackboard*>(getBlackBoard());
}

void leaveNode::tick(float deltaTime)
{
    _blackboard->self->leave(deltaTime);
    if (_blackboard->self->getLocation().x >= 1000)
    {
        endExecute();
    }
}

void leaveNode::endExecute()
{
    parent->onChildEnd(nodeState::success);
}


destroyNode::destroyNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void destroyNode::beginExecute()
{
    _blackboard = static_cast<customerBlackboard*>(getBlackBoard());
}

void destroyNode::tick(float deltaTime)
{
    _blackboard->self->setAlive(false);
    endExecute();
}

void destroyNode::endExecute()
{
    parent->onChildEnd(nodeState::success);
}


chooseMerchantNode::chooseMerchantNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void chooseMerchantNode::beginExecute()
{
    _blackboard = static_cast<customerBlackboard*>(getBlackBoard());
    bestPrice = std::numeric_limits<int>::max(); //maximum int possible
    bestMerchant = nullptr;
    merchantPossible.clear();
}

void chooseMerchantNode::tick(float deltaTime)
{
    nbRandom = newRandom::getRandomNumber(1, 100);
    for (merchant* merch : _blackboard->self->getLstMerchants())
    {
        if (merch->getProduct() == _blackboard->self->getWantedProduct())
        {
            if (merch->getProductPrice() < bestPrice)
            {
                merchantPossible.push_back(merch);
                bestPrice = merch->getProductPrice();
                bestMerchant = merch;
            }
        }
    }
    if (nbRandom <= 50)
    {
        _blackboard->self->setWantedMerchant(bestMerchant);
    }
    else
    {
        nbRandom = newRandom::getRandomNumber(0, merchantPossible.size() - 1);
        _blackboard->self->setWantedMerchant(merchantPossible[nbRandom]);
    }
    endExecute();
}

void chooseMerchantNode::endExecute()
{
    parent->onChildEnd(nodeState::success);
}


goToNode::goToNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void goToNode::beginExecute()
{
    _blackboard = static_cast<customerBlackboard*>(getBlackBoard());
}

void goToNode::tick(float deltaTime)
{
    _blackboard->self->goToMerchant(deltaTime);
    if (_blackboard->self->getWantedMerchant()->getLocation().y < 500)
    {
        if (_blackboard->self->getLocation() == sf::Vector2f(_blackboard->self->getWantedMerchant()->getLocation().x + 100.0f, _blackboard->self->getWantedMerchant()->getLocation().y + 200.0f))
        {
            endExecute();
        }
    }
    else
    {
        if (_blackboard->self->getLocation() == sf::Vector2f(_blackboard->self->getWantedMerchant()->getLocation().x + 100.0f, _blackboard->self->getWantedMerchant()->getLocation().y))
        {
            endExecute();
        }
    }
}

void goToNode::endExecute()
{
    parent->onChildEnd(nodeState::success);
}