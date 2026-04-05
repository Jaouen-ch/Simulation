#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "merchant.h"
#include "customerBehaviorTree.h"
#include "random.h"

#define customerW 40
#define customerH 40

class customer
{
private:
    sf::Vector2f location = sf::Vector2f(-50.0f, 500.0f);
    sf::RenderWindow& window;
    sf::Texture texture;
    sf::RectangleShape rect;

    customerBehaviorTree* tree;

    std::vector<merchant*>& lstMerchants;
    products wantedProduct;
    int nbWantedProduct;
    merchant* wantedMerchant = nullptr;
    bool alive = true;

    int speed = 150.0f;

public:
    customer(sf::RenderWindow& _window, std::vector<merchant*>& _lstMerchants, textures gameTextures, int _speed);
    ~customer();

    void update(float deltaTime);
    void draw();
    bool buy();

    void goToMerchant(float deltaTime);
    void leave(float deltaTime);

    sf::Vector2f getLocation();
    std::vector<merchant*>& getLstMerchants();
    products getWantedProduct();
    merchant* getWantedMerchant();
    void setWantedMerchant(merchant* newWantedMerchant);
    int getNbWantedProduct();
    bool isAlive();
    void setAlive(bool newAlive);
};