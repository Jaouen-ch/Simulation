#include "gameBehaviorTree.h"

#include "fallbackNode.h"
#include "sequenceNode.h"
#include "rootNode.h"
#include "gameNodes.h"

gameBehaviorTree::gameBehaviorTree(blackBoard* _internBlackBoard)
    : behaviorTree(_internBlackBoard)
{
}

void gameBehaviorTree::buildTree()
{
    behaviorTree::buildTree();
    auto* game = new sequenceNode(this, nullptr);
    auto* morning = new sequenceNode(this, game);
    auto* day = new sequenceNode(this, game);
    auto* evening = new sequenceNode(this, game);
    root->setChild(game);
    game->addChild(morning);
    game->addChild(day);
    game->addChild(evening);
    allSubNodes.push_back(game);
    allSubNodes.push_back(morning);
    allSubNodes.push_back(day);
    allSubNodes.push_back(evening);

    auto* createMerchants = new createMerchantsNode(this, morning);
    auto* morningActionsFinished = new morningActionsFinishedNode(this, morning);
    auto* dayTime = new dayTimeNode(this, morning);
    morning->addChild(createMerchants);
    morning->addChild(morningActionsFinished);
    morning->addChild(dayTime);
    allSubNodes.push_back(createMerchants);
    allSubNodes.push_back(morningActionsFinished);
    allSubNodes.push_back(dayTime);

    auto* createCustomers = new createCustomersNode(this, day);
    auto* dayActionsFinished = new dayActionsFinishedNode(this, day);
    auto* events = new fallbackNode(this, day);
    day->addChild(createCustomers);
    day->addChild(dayActionsFinished);
    day->addChild(events);
    allSubNodes.push_back(createCustomers);
    allSubNodes.push_back(dayActionsFinished);
    allSubNodes.push_back(events);

    auto* inflationEvent = new inflationEventNode(this, events);
    auto* eveningTime1 = new eveningTimeNode(this, events);
    events->addChild(inflationEvent);
    events->addChild(eveningTime1);
    allSubNodes.push_back(inflationEvent);
    allSubNodes.push_back(eveningTime1);

    auto* eveningTime2 = new eveningTimeNode(this, evening);
    auto* eveningActionsFinished = new eveningActionsFinishedNode(this, evening);
    auto* morningTime = new morningTimeNode(this, evening);
    evening->addChild(eveningTime2);
    evening->addChild(eveningActionsFinished);
    evening->addChild(morningTime);
    allSubNodes.push_back(eveningTime2);
    allSubNodes.push_back(eveningActionsFinished);
    allSubNodes.push_back(morningTime);
}