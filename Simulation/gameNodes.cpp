#include "gameNodes.h"

#include "random.h"
#include "flowNode.h"
#include "game.h"
#include "merchant.h"

createMerchantsNode::createMerchantsNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void createMerchantsNode::beginExecute()
{
    _blackboard = static_cast<gameBlackBoard*>(getBlackBoard());
    productsTypes = {products::bread, products::sword, products::armor};
}

void createMerchantsNode::tick(float deltaTime)
{
    std::vector<merchant*> newTabMerchant = _blackboard->self->getTabMerchants();
    for (int i = 0; i < newTabMerchant.size(); i++)
    {
        if (newTabMerchant[i] == nullptr)
        {
            for (merchant* merch : _blackboard->self->getTabMerchants())
            {
                productsOnSale.push_back(merch->getProduct());
            }
            for (products prod : productsOnSale)
            {
                auto iterator = std::find(productsOnSale.begin(), productsOnSale.end(), prod);
                if (iterator == productsOnSale.end())
                {
                    newMerchantProduct = new products(prod);
                }
            }
            if (i < 3)
            {
                newTabMerchant[i] = new merchant(_blackboard->self->getWindow(), _blackboard->self->getGameTextures(), {100.0f + (300.0f * i), 100.0f}, *newMerchantProduct, _blackboard->currentTime);
            }
            else
            {
                newTabMerchant[i] = new merchant(_blackboard->self->getWindow(), _blackboard->self->getGameTextures(), {100.0f + (300.0f * i), 600.0f}, *newMerchantProduct, _blackboard->currentTime);
            }
        }
    }
    delete newMerchantProduct;
    newMerchantProduct = nullptr;
    endExecute();
}

void createMerchantsNode::endExecute()
{
    parent->onChildEnd(nodeState::success);
}


morningActionsFinishedNode::morningActionsFinishedNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void morningActionsFinishedNode::beginExecute()
{
    _blackboard = static_cast<gameBlackBoard*>(getBlackBoard());
}

void morningActionsFinishedNode::tick(float deltaTime)
{
    allActionsFinished = true;
    for (int i = 0; i < _blackboard->self->getTabMerchants().size(); ++i)
    {
        if (!_blackboard->self->getTabMerchants()[i]->getEndTasks())
        {
            allActionsFinished = false;
        }
    }
    if (allActionsFinished)
    {
        endExecute();
    }
}

void morningActionsFinishedNode::endExecute()
{
    parent->onChildEnd(nodeState::success);
}


dayTimeNode::dayTimeNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void dayTimeNode::beginExecute()
{
    _blackboard = static_cast<gameBlackBoard*>(getBlackBoard());
}

void dayTimeNode::tick(float deltaTime)
{
    _blackboard->currentTime = timeOfDay::day;
    for (merchant* merch : _blackboard->self->getTabMerchants())
    {
        merch->setEndTasks(false);
    }
    endExecute();
}

void dayTimeNode::endExecute()
{
    parent->onChildEnd(nodeState::success);
}


createCustomersNode::createCustomersNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void createCustomersNode::beginExecute()
{
    _blackboard = static_cast<gameBlackBoard*>(getBlackBoard());
    time = 0.0f;
}

void createCustomersNode::tick(float deltaTime)
{
    time += deltaTime;
    if (time > 1.0f)
    {
        c = new customer(_blackboard->self->getWindow(), _blackboard->self->getTabMerchants(), _blackboard->self->getGameTextures(), _blackboard->self->getSpeedCustomers());
        _blackboard->self->getTabCustomers().push_back(c);
        c = nullptr;
        time = 0.0f;
    }
    if (_blackboard->self->getTabCustomers().size() == _blackboard->self->getNumberCustomers())
    {
        endExecute();
    }
}

void createCustomersNode::endExecute()
{
    parent->onChildEnd(nodeState::success);
}


dayActionsFinishedNode::dayActionsFinishedNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void dayActionsFinishedNode::beginExecute()
{
    _blackboard = static_cast<gameBlackBoard*>(getBlackBoard());
}

void dayActionsFinishedNode::tick(float deltaTime)
{
    allActionsFinished = true;
    for (int i = 0; i < _blackboard->self->getTabMerchants().size(); ++i)
    {
        if (!_blackboard->self->getTabMerchants()[i]->getEndTasks())
        {
            allActionsFinished = false;
        }
    }
    if (allActionsFinished && _blackboard->self->getTabCustomers().empty())
    {
        endExecute();
    }
}

void dayActionsFinishedNode::endExecute()
{
    parent->onChildEnd(nodeState::success);
}


inflationEventNode::inflationEventNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void inflationEventNode::beginExecute()
{
    _blackboard = static_cast<gameBlackBoard*>(getBlackBoard());
}

void inflationEventNode::tick(float deltaTime)
{
    nbRandom = newRandom::getRandomNumber(1,100);
    if (nbRandom <= 5)
    {
        for (merchant* m : _blackboard->self->getTabMerchants())
        {
            m->setRawMaterialsPrice(m->getRawMaterialsPrice() + newRandom::getRandomNumber(1,3));
        }
    }
    endExecute();
}

void inflationEventNode::endExecute()
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


eveningTimeNode::eveningTimeNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void eveningTimeNode::beginExecute()
{
    _blackboard = static_cast<gameBlackBoard*>(getBlackBoard());
}

void eveningTimeNode::tick(float deltaTime)
{
    _blackboard->currentTime = timeOfDay::evening;
    for (merchant* merch : _blackboard->self->getTabMerchants())
    {
        merch->setEndTasks(false);
    }
    endExecute();
}

void eveningTimeNode::endExecute()
{
    parent->onChildEnd(nodeState::success);
}


eveningActionsFinishedNode::eveningActionsFinishedNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void eveningActionsFinishedNode::beginExecute()
{
    _blackboard = static_cast<gameBlackBoard*>(getBlackBoard());
}

void eveningActionsFinishedNode::tick(float deltaTime)
{
    allActionsFinished = true;
    for (int i = 0; i < _blackboard->self->getTabMerchants().size(); ++i)
    {
        if (!_blackboard->self->getTabMerchants()[i]->getEndTasks())
        {
            allActionsFinished = false;
        }
    }
    if (allActionsFinished)
    {
        endExecute();
    }
}

void eveningActionsFinishedNode::endExecute()
{
    parent->onChildEnd(nodeState::success);
}


morningTimeNode::morningTimeNode(behaviorTree* _tree, flowNode* _parent)
    : taskNode(_tree, _parent)
{
}

void morningTimeNode::beginExecute()
{
    _blackboard = static_cast<gameBlackBoard*>(getBlackBoard());
}

void morningTimeNode::tick(float deltaTime)
{
    _blackboard->currentTime = timeOfDay::morning;
    for (merchant* merch : _blackboard->self->getTabMerchants())
    {
        merch->setEndTasks(false);
    }
    endExecute();
}

void morningTimeNode::endExecute()
{
    parent->onChildEnd(nodeState::success);
}