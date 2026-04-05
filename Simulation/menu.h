#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "textures.h"


class Menu
{
private:
	sf::RectangleShape startButton;
	sf::Font font;
	sf::Text startText;
	sf::Texture texture;
	sf::Texture playTexture;
	sf::Texture buttonTexture;
	sf::RectangleShape backgroundRect;

	bool startClicked;
	bool MoreClicked;
	bool LessClicked;
	bool MoreSpeedClicked;
	bool LessSpeedClicked;
	sf::Vector2f playButton{ 200.f, 100.f };
	sf::RectangleShape playRectangle;
	sf::RectangleShape moreRectangle;
	sf::RectangleShape lessRectangle;
	sf::RectangleShape moreSpeedRectangle;
	sf::RectangleShape lessSpeedRectangle;
	sf::RectangleShape quitRectangle;

	int numberCustomers = 1;
	int speedCustomers = 150;

public:
	Menu(textures gameTextures);
	~Menu() = default;

	bool getStartClicked();
	bool lessClicked();
	bool moreClicked();
	void inputHandler(const std::optional<sf::Event>& event, sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	int getNumberCustomers();
	int getSpeedCustomers();
};


