#include "customerBehaviorTree.h"

#include "fallbackNode.h"
#include "sequenceNode.h"
#include "rootNode.h"
#include "customerNodes.h"

customerBehaviorTree::customerBehaviorTree(blackBoard* _internBlackBoard)
    : behaviorTree(_internBlackBoard)
{
}

void customerBehaviorTree::buildTree()
{
    behaviorTree::buildTree();
    auto* customer = new sequenceNode(this, nullptr);
    auto* goToMerchant = new sequenceNode(this, customer);
    auto* buy = new buyNode(this, customer);
    auto* leave = new leaveNode(this, customer);
    auto* destroy = new destroyNode(this, customer);
    root->setChild(customer);
    customer->addChild(goToMerchant);
    customer->addChild(buy);
    customer->addChild(leave);
    customer->addChild(destroy);
    allSubNodes.push_back(customer);
    allSubNodes.push_back(goToMerchant);
    allSubNodes.push_back(buy);
    allSubNodes.push_back(leave);
    allSubNodes.push_back(destroy);

    auto* chooseMerchant = new chooseMerchantNode(this, goToMerchant);
    auto* goTo = new goToNode(this, goToMerchant);
    goToMerchant->addChild(chooseMerchant);
    goToMerchant->addChild(goTo);
    allSubNodes.push_back(chooseMerchant);
    allSubNodes.push_back(goTo);
}