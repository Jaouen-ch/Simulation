#include "merchantBehaviorTree.h"

#include "fallbackNode.h"
#include "sequenceNode.h"
#include "rootNode.h"
#include "merchantNodes.h"

merchantBehaviorTree::merchantBehaviorTree(blackBoard* _internBlackBoard)
    : behaviorTree(_internBlackBoard)
{
}

void merchantBehaviorTree::buildTree()
{
    behaviorTree::buildTree();
    auto* merchant = new fallbackNode(this, nullptr);
    auto* morning = new sequenceNode(this, merchant);
    auto* day = new sequenceNode(this, merchant);
    auto* evening = new sequenceNode(this, merchant);
    root->setChild(merchant);
    merchant->addChild(morning);
    merchant->addChild(day);
    merchant->addChild(evening);
    allSubNodes.push_back(merchant);
    allSubNodes.push_back(morning);
    allSubNodes.push_back(day);
    allSubNodes.push_back(evening);

    auto* isMorning = new isMorningNode(this, morning);
    auto* setVariablesMorning = new setVariablesMorningNode(this, morning);
    auto* receiveRawMaterials = new fallbackNode(this, morning);
    morning->addChild(isMorning);
    morning->addChild(setVariablesMorning);
    morning->addChild(receiveRawMaterials);
    allSubNodes.push_back(isMorning);
    allSubNodes.push_back(setVariablesMorning);
    allSubNodes.push_back(receiveRawMaterials);

    auto* payRawMaterials = new payRawMaterialsNode(this, receiveRawMaterials);
    auto* destroyMerchant = new destroyMerchantNode(this, receiveRawMaterials);
    receiveRawMaterials->addChild(payRawMaterials);
    receiveRawMaterials->addChild(destroyMerchant);
    allSubNodes.push_back(payRawMaterials);
    allSubNodes.push_back(destroyMerchant);

    auto* isDay = new isDayNode(this, day);
    auto* events = new fallbackNode(this, day);
    day->addChild(isDay);
    day->addChild(events);
    allSubNodes.push_back(isDay);
    allSubNodes.push_back(events);

    auto* fireEvent = new fireEventNode(this, events);
    auto* theftEvent = new theftEventNode(this, events);
    auto* defaultEvent = new defaultEventNode(this, events);
    events->addChild(fireEvent);
    events->addChild(theftEvent);
    events->addChild(defaultEvent);
    allSubNodes.push_back(fireEvent);
    allSubNodes.push_back(theftEvent);
    allSubNodes.push_back(defaultEvent);

    auto* isEvening = new isEveningNode(this, evening);
    auto* setVariablesEvening = new setVariablesEveningNode(this, evening);
    auto* buy = new sequenceNode(this, evening);
    evening->addChild(isEvening);
    evening->addChild(setVariablesEvening);
    evening->addChild(buy);
    allSubNodes.push_back(isEvening);
    allSubNodes.push_back(setVariablesEvening);
    allSubNodes.push_back(buy);

    auto* positiveDeficit = new fallbackNode(this, buy);
    auto* negativeDeficit = new fallbackNode(this, buy);
    buy->addChild(positiveDeficit);
    buy->addChild(negativeDeficit);
    allSubNodes.push_back(positiveDeficit);
    allSubNodes.push_back(negativeDeficit);

    auto* orderMore = new orderMoreNode(this, positiveDeficit);
    auto* increasePrice = new increasePriceNode(this, positiveDeficit);
    positiveDeficit->addChild(orderMore);
    positiveDeficit->addChild(increasePrice);
    allSubNodes.push_back(orderMore);
    allSubNodes.push_back(increasePrice);

    auto* orderLess = new orderLessNode(this, negativeDeficit);
    auto* reducePrice = new reducePriceNode(this, negativeDeficit);
    negativeDeficit->addChild(orderLess);
    negativeDeficit->addChild(reducePrice);
    allSubNodes.push_back(orderLess);
    allSubNodes.push_back(reducePrice);
}
