#include "merchantNodes.h"

#include "random.h"
#include "flowNode.h"
#include "merchant.h"

isMorningNode::isMorningNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void isMorningNode::beginExecute()
{
    _blackboard = static_cast<merchantBlackboard*>(getBlackBoard());
}

void isMorningNode::tick(float deltaTime)
{
    endExecute();
}

void isMorningNode::endExecute()
{
    if (_blackboard->currentTime == timeOfDay::morning)
    {
        parent->onChildEnd(nodeState::success);
    }
    else
    {
        parent->onChildEnd(nodeState::failure);
    }
}


setVariablesMorningNode::setVariablesMorningNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void setVariablesMorningNode::beginExecute()
{
    _blackboard = static_cast<merchantBlackboard*>(getBlackBoard());
}


void setVariablesMorningNode::tick(float deltaTime)
{
    _blackboard->self->setMoney(_blackboard->self->getMoney() - _blackboard->self->getRent());
    _blackboard->self->setDeficit(0);
    endExecute();
}

void setVariablesMorningNode::endExecute()
{
    parent->onChildEnd(nodeState::success);
}


payRawMaterialsNode::payRawMaterialsNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void payRawMaterialsNode::beginExecute()
{
    _blackboard = static_cast<merchantBlackboard*>(getBlackBoard());
}

void payRawMaterialsNode::tick(float deltaTime)
{
    _blackboard->self->setMoney(_blackboard->self->getMoney() - (_blackboard->self->getRawMaterialsPrice() * _blackboard->self->getNbRawMaterials()));
    if (_blackboard->self->getMoney() >= 0)
    {
        _blackboard->self->setEndTasks(true);
    }
    endExecute();
}

void payRawMaterialsNode::endExecute()
{
    if (_blackboard->self->getMoney() < 0)
    {
        parent->onChildEnd(nodeState::failure);
    }
    else
    {
        parent->onChildEnd(nodeState::success);
    }
}


destroyMerchantNode::destroyMerchantNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void destroyMerchantNode::beginExecute()
{
    _blackboard = static_cast<merchantBlackboard*>(getBlackBoard());
}

void destroyMerchantNode::tick(float deltaTime)
{
    _blackboard->self->setBankruptcy(true);
    _blackboard->self->setEndTasks(true);
    endExecute();
}

void destroyMerchantNode::endExecute()
{
    parent->onChildEnd(nodeState::success);
}


isDayNode::isDayNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void isDayNode::beginExecute()
{
    _blackboard = static_cast<merchantBlackboard*>(getBlackBoard());
}

void isDayNode::tick(float deltaTime)
{
    endExecute();
}

void isDayNode::endExecute()
{
    if (_blackboard->currentTime == timeOfDay::day)
    {
        parent->onChildEnd(nodeState::success);
    }
    else
    {
        parent->onChildEnd(nodeState::failure);
    }
}


fireEventNode::fireEventNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void fireEventNode::beginExecute()
{
    _blackboard = static_cast<merchantBlackboard*>(getBlackBoard());
}

void fireEventNode::tick(float deltaTime)
{
    nbRandom = newRandom::getRandomNumber(1,100);
    if (nbRandom <= 5)
    {
        if (_blackboard->self->getNbProducts() >= 10)
        {
            _blackboard->self->setNbProducts(_blackboard->self->getNbProducts() - 10);
        }
        else
        {
            _blackboard->self->setNbProducts(0);
        }
        _blackboard->self->setEndTasks(true);
    }
    endExecute();
}

void fireEventNode::endExecute()
{
    if (nbRandom <= 5)
    {
        parent->onChildEnd(nodeState::success);
    }
    else
    {
        parent->onChildEnd(nodeState::failure);
    }
}


theftEventNode::theftEventNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void theftEventNode::beginExecute()
{
    _blackboard = static_cast<merchantBlackboard*>(getBlackBoard());
}

void theftEventNode::tick(float deltaTime)
{
    nbRandom = newRandom::getRandomNumber(1,100);
    if (nbRandom <= 5)
    {
        _blackboard->self->setMoney(_blackboard->self->getMoney() - newRandom::getRandomNumber(1,5));
        _blackboard->self->setEndTasks(true);
    }
    endExecute();
}

void theftEventNode::endExecute()
{
    if (nbRandom <= 5)
    {
        parent->onChildEnd(nodeState::success);
    }
    else
    {
        parent->onChildEnd(nodeState::failure);
    }
}


defaultEventNode::defaultEventNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void defaultEventNode::beginExecute()
{
    _blackboard = static_cast<merchantBlackboard*>(getBlackBoard());
}

void defaultEventNode::tick(float deltaTime)
{
    _blackboard->self->setEndTasks(true);
    endExecute();
}

void defaultEventNode::endExecute()
{
    parent->onChildEnd(nodeState::success);
}


isEveningNode::isEveningNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void isEveningNode::beginExecute()
{
    _blackboard = static_cast<merchantBlackboard*>(getBlackBoard());
}

void isEveningNode::tick(float deltaTime)
{
    endExecute();
}

void isEveningNode::endExecute()
{
    if (_blackboard->currentTime == timeOfDay::evening)
    {
        parent->onChildEnd(nodeState::success);
    }
    else
    {
        parent->onChildEnd(nodeState::failure);
    }
}


setVariablesEveningNode::setVariablesEveningNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void setVariablesEveningNode::beginExecute()
{
    _blackboard = static_cast<merchantBlackboard*>(getBlackBoard());
}

void setVariablesEveningNode::tick(float deltaTime)
{
    _blackboard->self->setNbProducts(0);
    _blackboard->self->setNbRandom(newRandom::getRandomNumber(1,2));
    endExecute();
}

void setVariablesEveningNode::endExecute()
{
    parent->onChildEnd(nodeState::success);
}


orderMoreNode::orderMoreNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void orderMoreNode::beginExecute()
{
    _blackboard = static_cast<merchantBlackboard*>(getBlackBoard());
}

void orderMoreNode::tick(float deltaTime)
{
    if (_blackboard->self->getDeficit() > 0 && _blackboard->self->getNbRandom() == 1)
    {
        _blackboard->self->setNbRawMaterials( _blackboard->self->getNbRawMaterials() +  _blackboard->self->getDeficit());
        _blackboard->self->setEndTasks(true);
    }
    endExecute();
}

void orderMoreNode::endExecute()
{
    if (_blackboard->self->getDeficit() > 0 && _blackboard->self->getNbRandom() == 1)
    {
        parent->onChildEnd(nodeState::success);
    }
    else
    {
        parent->onChildEnd(nodeState::failure);
    }
}


increasePriceNode::increasePriceNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void increasePriceNode::beginExecute()
{
    _blackboard = static_cast<merchantBlackboard*>(getBlackBoard());
}

void increasePriceNode::tick(float deltaTime)
{
    if (_blackboard->self->getDeficit() > 0 && _blackboard->self->getNbRandom() == 2)
    {
        _blackboard->self->setProductPrice(_blackboard->self->getProductPrice() + newRandom::getRandomNumber(1,5));
        _blackboard->self->setEndTasks(true);
    }
    endExecute();
}

void increasePriceNode::endExecute()
{
    if (_blackboard->self->getDeficit() > 0 && _blackboard->self->getNbRandom() == 2)
    {
        parent->onChildEnd(nodeState::success);
    }
    else
    {
        parent->onChildEnd(nodeState::failure);
    }
}


orderLessNode::orderLessNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void orderLessNode::beginExecute()
{
    _blackboard = static_cast<merchantBlackboard*>(getBlackBoard());
}

void orderLessNode::tick(float deltaTime)
{
    if (_blackboard->self->getDeficit() == 0 && _blackboard->self->getNbRandom() == 1)
    {
        _blackboard->self->setNbRawMaterials( _blackboard->self->getNbRawMaterials() -  _blackboard->self->getNbProducts());
        _blackboard->self->setEndTasks(true);
    }
    endExecute();
}

void orderLessNode::endExecute()
{
    if (_blackboard->self->getDeficit() == 0 && _blackboard->self->getNbRandom() == 1)
    {
        parent->onChildEnd(nodeState::success);
    }
    else
    {
        parent->onChildEnd(nodeState::failure);
    }
}


reducePriceNode::reducePriceNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void reducePriceNode::beginExecute()
{
    _blackboard = static_cast<merchantBlackboard*>(getBlackBoard());
}

void reducePriceNode::tick(float deltaTime)
{
    if (_blackboard->self->getDeficit() == 0 && _blackboard->self->getNbRandom() == 2)
    {
        _blackboard->self->setProductPrice(_blackboard->self->getProductPrice() - newRandom::getRandomNumber(1,5));
        _blackboard->self->setEndTasks(true);
    }
    endExecute();
}

void reducePriceNode::endExecute()
{
    if (_blackboard->self->getDeficit() == 0 && _blackboard->self->getNbRandom() == 2)
    {
        parent->onChildEnd(nodeState::success);
    }
    else
    {
        parent->onChildEnd(nodeState::failure);
    }
}