#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "gameBehaviorTree.h"
#include "gameBlackBoard.h"
#include "merchant.h"
#include "textures.h"
#include "customer.h"
#include "menu.h"

class game {
private:
    sf::RenderWindow& window;
    int windowWidth;
    int windowHeight;
    textures gameTextures = textures();
    sf::RectangleShape backgroundRect;
    sf::Texture texture;

    gameBehaviorTree* tree;

    bool inMenu = true;

    sf::Clock clock;
    sf::Time now = clock.getElapsedTime();
    sf::Time lastTime;
    float deltaTime = 0.0f;

    timeOfDay currentTime = timeOfDay::morning;
    std::vector<merchant*> tabMerchants;
    std::vector<customer*> tabCustomers;

    Menu gameMenu;
    int numberCustomers = 0;
    int speedCustomers = 0;

public:
    game(sf::RenderWindow& _window, int _windowWidth, int _windowHeight);
    ~game();

    void update();
    void draw();

    void handleEvents(const std::optional<sf::Event>& event);

    sf::RenderWindow& getWindow();
    textures& getGameTextures();
    std::vector<merchant*>& getTabMerchants();
    void setTabMerchants(std::vector<merchant*> newTabMerchants);
    std::vector<customer*>& getTabCustomers();
    void setTabCustomers(std::vector<customer*> newTabCustomers);
    int getNumberCustomers();
    int getSpeedCustomers();
};