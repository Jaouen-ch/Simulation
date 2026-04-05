#include "customer.h"
#include "customer.h"

#include "customerBlackboard.h"

customer::customer(sf::RenderWindow& _window, std::vector<merchant*>& _lstMerchants, textures gameTextures, int _speed)
    : window(_window)
    , lstMerchants(_lstMerchants)
    , speed(_speed)
{
    wantedMerchant = lstMerchants[0];
    wantedProduct = (products)newRandom::getRandomNumber(0,2);
    nbWantedProduct = newRandom::getRandomNumber(1,5);

    texture = gameTextures.getTexture(textures::texturesIndices::customer);
    rect = sf::RectangleShape({ 50, 50 });
    rect.setTexture(&texture);

    auto* treeBlackBoard = new customerBlackboard(this);
    tree = new customerBehaviorTree(treeBlackBoard);
    tree->buildTree();
    tree->beginExecute();
}

customer::~customer()
{
    delete tree;
    tree = nullptr;
}

void customer::update(float deltaTime)
{
    tree->tick(deltaTime);
}

void customer::draw()
{
    rect.setPosition(location);
    window.draw(rect);
}

bool customer::buy()
{
    return wantedMerchant->sale(nbWantedProduct);
}

void customer::goToMerchant(float deltaTime)
{
    if (location.x < wantedMerchant->getLocation().x + 100.0f)
    {
        location.x += speed * deltaTime;
        if (location.x > wantedMerchant->getLocation().x + 100.0f)
        {
            location.x = wantedMerchant->getLocation().x + 100.0f;
        }
    }
    else if (wantedMerchant->getLocation().y < 500)
    {
        if (location.y > wantedMerchant->getLocation().y + 200.0f)
        {
            location.y -= speed * deltaTime;
            if (location.y < wantedMerchant->getLocation().y + 200.0f)
            {
                location.y = wantedMerchant->getLocation().y + 200.0f;
            }
        }
    }
    else
    {
        if (location.y < wantedMerchant->getLocation().y)
        {
            location.y += speed * deltaTime;
            if (location.y > wantedMerchant->getLocation().y)
            {
                location.y = wantedMerchant->getLocation().y;
            }
        }
    }
}

void customer::leave(float deltaTime)
{
    if (wantedMerchant->getLocation().y < 500 && location.y < 500.0f)
    {
        location.y += speed * deltaTime;
        if (location.y > 500.0f)
        {
            location.y = 500.0f;
        }
    }
    else if (wantedMerchant->getLocation().y > 500 && location.y > 500.0f)
    {
        location.y -= speed * deltaTime;
        if (location.y < 500.0f)
        {
            location.y = 500.0f;
        }
    }
    else if (location.x < 1000.0f)
    {
        location.x += speed * deltaTime;
    }
}

sf::Vector2f customer::getLocation()
{
    return location;
}

std::vector<merchant*>& customer::getLstMerchants()
{
    return lstMerchants;
}

products customer::getWantedProduct()
{
    return wantedProduct;
}

merchant* customer::getWantedMerchant()
{
    return wantedMerchant;
}

void customer::setWantedMerchant(merchant* newMerchant)
{
    wantedMerchant = newMerchant;
}

int customer::getNbWantedProduct()
{
    return nbWantedProduct;
}

bool customer::isAlive()
{
    return alive;
}

void customer::setAlive(bool newAlive)
{
    alive = newAlive;
}
