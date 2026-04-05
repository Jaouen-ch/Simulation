#include "game.h"

game::game(sf::RenderWindow& _window, int _windowWidth, int _windowHeight)
    : window(_window)
    , windowWidth(_windowWidth)
    , windowHeight(_windowHeight)
    , gameMenu(gameTextures)
{
    texture = gameTextures.getTexture(textures::texturesIndices::background);
    backgroundRect = sf::RectangleShape({1000, 1000});
    backgroundRect.setTexture(&texture);

    auto* m = new merchant(window, gameTextures, {100.0f, 100.0f}, products::bread, currentTime);
    tabMerchants.push_back(m);
    m = new merchant(window, gameTextures, {400.0f, 100.0f}, products::sword, currentTime);
    tabMerchants.push_back(m);
    m = new merchant(window, gameTextures, {700.0f, 100.0f}, products::armor, currentTime);
    tabMerchants.push_back(m);
    m = new merchant(window, gameTextures, {100.0f, 600.0f}, products::sword, currentTime);
    tabMerchants.push_back(m);
    m = new merchant(window, gameTextures, {400.0f, 600.0f}, products::armor, currentTime);
    tabMerchants.push_back(m);
    m = new merchant(window, gameTextures, {700.0f, 600.0f}, products::bread, currentTime);
    tabMerchants.push_back(m);

    auto* treeBlackBoard = new gameBlackBoard(this, currentTime);
    tree = new gameBehaviorTree(treeBlackBoard);
    tree->buildTree();
    tree->beginExecute();
}

game::~game()
{
    delete tree;
    tree = nullptr;
    for (auto merchant : tabMerchants)
    {
        delete merchant;
        merchant = nullptr;
    }
    for (auto customer : tabCustomers)
    {
        delete customer;
        customer = nullptr;
    }
}


void game::update()
{
    if (inMenu)
    {
        if (gameMenu.getStartClicked())
        {
            inMenu = false;
            numberCustomers = gameMenu.getNumberCustomers();
            speedCustomers = gameMenu.getSpeedCustomers();
            now = clock.getElapsedTime();
        }
    }
    else
    {
        lastTime = now;
        now = clock.getElapsedTime();
        deltaTime = now.asSeconds() - lastTime.asSeconds();

        tree->tick(deltaTime);

        for (auto m : tabMerchants)
        {
            m->update(deltaTime);
            if (m->isBankruptcy())
            {
                delete m;
                m = nullptr;
            }
        }
        std::vector<customer*> erase = {};
        for (auto c : tabCustomers)
        {
            c->update(deltaTime);
            if (!c->isAlive())
            {
                erase.push_back(c);
            }
        }
        for (auto c : erase)
        {
            tabCustomers.erase(std::remove(tabCustomers.begin(), tabCustomers.end(), c), tabCustomers.end());
            delete c;
            c = nullptr;
        }
    }
}

void game::draw()
{
    if (inMenu)
    {
        gameMenu.draw(window);
	}
    else
    {
        window.draw(backgroundRect);
        for (auto merchant : tabMerchants)
        {
            if (merchant != nullptr)
            {
                merchant->draw();
            }
        }
        for (auto customer : tabCustomers)
        {
            customer->draw();
        }
    }
}

void game::handleEvents(const std::optional<sf::Event>& event)
{
    if (inMenu)
    {
        gameMenu.inputHandler(event, window);
    }
}

sf::RenderWindow& game::getWindow()
{
    return window;
}

textures& game::getGameTextures()
{
    return gameTextures;
}

std::vector<merchant*>& game::getTabMerchants()
{
    return tabMerchants;
}

void game::setTabMerchants(std::vector<merchant*> newTabMerchants)
{
    tabMerchants = newTabMerchants;
}

std::vector<customer*>& game::getTabCustomers()
{
    return tabCustomers;
}

void game::setTabCustomers(std::vector<customer*> newTabCustomers)
{
    tabCustomers = newTabCustomers;
}

int game::getNumberCustomers()
{
    return numberCustomers;
}

int game::getSpeedCustomers()
{
    return speedCustomers;
}