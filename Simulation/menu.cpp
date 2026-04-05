#include "menu.h"
#include <string>

Menu::Menu(textures gameTextures)
	: font(sf::Font("assets/OldeTome.ttf"))
	, startText(sf::Text(font, "Play", 10))
{	
	playTexture = gameTextures.getTexture(textures::texturesIndices::play);
	buttonTexture = gameTextures.getTexture(textures::texturesIndices::more);

	startClicked = false;
	playRectangle = sf::RectangleShape({ 300.f, 150.f });
	playRectangle.setPosition({ 10.f, 70.f });
	playRectangle.setTexture(&playTexture);


	moreRectangle = sf::RectangleShape({ 80.f, 80.f });
	moreRectangle.setPosition({ 195.f, 365.f });
	moreRectangle.setTexture(&buttonTexture);

	lessRectangle = sf::RectangleShape({ 80.f, 80.f });
	lessRectangle.setPosition({ 75.f, 365.f });
	lessRectangle.setTexture(&buttonTexture);

	moreSpeedRectangle = sf::RectangleShape({ 80.f, 80.f });
	moreSpeedRectangle.setPosition({ 195.f, 565.f });
	moreSpeedRectangle.setTexture(&buttonTexture);

	lessSpeedRectangle = sf::RectangleShape({ 80.f, 80.f });
	lessSpeedRectangle.setPosition({ 75.f, 565.f });
	lessSpeedRectangle.setTexture(&buttonTexture);

	quitRectangle = sf::RectangleShape({ 225.f, 150.f });
	quitRectangle.setPosition({ 10.f, 755.f });
	quitRectangle.setTexture(&playTexture);

	texture = gameTextures.getTexture(textures::texturesIndices::menuBackground);
	backgroundRect = sf::RectangleShape({ 1000, 1000 });
	backgroundRect.setTexture(&texture);
}


bool Menu::getStartClicked()
{
	return startClicked;
}

bool Menu::lessClicked()
{
	return LessClicked;
}

bool Menu::moreClicked()
{
	return MoreClicked;
}



void Menu::inputHandler(const std::optional<sf::Event>& event, sf::RenderWindow& window)
{
	if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
	{
		if (mouseButtonPressed->button == sf::Mouse::Button::Left)
		{
			std::cout << "mouse x: " << mouseButtonPressed->position.x << std::endl;
			std::cout << "mouse y: " << mouseButtonPressed->position.y << std::endl;

			if (mouseButtonPressed->position.x >= playRectangle.getPosition().x && mouseButtonPressed->position.y >= playRectangle.getPosition().y && mouseButtonPressed->position.x <= playRectangle.getPosition().x + 200 && mouseButtonPressed->position.y <= playRectangle.getPosition().y + 100)
			{
				startClicked = true;
			}

			if (mouseButtonPressed->position.x >= moreRectangle.getPosition().x && mouseButtonPressed->position.y >= moreRectangle.getPosition().y && mouseButtonPressed->position.x <= moreRectangle.getPosition().x + 50 && mouseButtonPressed->position.y <= moreRectangle.getPosition().y + 50)
			{
				numberCustomers++;
			}

			if (mouseButtonPressed->position.x >= lessRectangle.getPosition().x && mouseButtonPressed->position.y >= lessRectangle.getPosition().y && mouseButtonPressed->position.x <= lessRectangle.getPosition().x + 50 && mouseButtonPressed->position.y <= lessRectangle.getPosition().y + 50)
			{
				if (numberCustomers > 0)
				{
					numberCustomers--;
				}
			}

			if (mouseButtonPressed->position.x >= moreSpeedRectangle.getPosition().x && mouseButtonPressed->position.y >= moreSpeedRectangle.getPosition().y && mouseButtonPressed->position.x <= moreSpeedRectangle.getPosition().x + 50 && mouseButtonPressed->position.y <= moreSpeedRectangle.getPosition().y + 50)
			{
					speedCustomers += 10;
			}

			if (mouseButtonPressed->position.x >= lessSpeedRectangle.getPosition().x && mouseButtonPressed->position.y >= lessSpeedRectangle.getPosition().y && mouseButtonPressed->position.x <= lessSpeedRectangle.getPosition().x + 50 && mouseButtonPressed->position.y <= lessSpeedRectangle.getPosition().y + 50)
			{
				if (speedCustomers >= 10)
				{
					speedCustomers -= 10;
				}
			}

			if (mouseButtonPressed->position.x >= quitRectangle.getPosition().x && mouseButtonPressed->position.y >= quitRectangle.getPosition().y && mouseButtonPressed->position.x <= quitRectangle.getPosition().x + 200 && mouseButtonPressed->position.y <= quitRectangle.getPosition().y + 100)
			{
				window.close();
			}
		}
	}
}




void Menu::draw(sf::RenderWindow& window)
{

	sf::Text play(font); 
	play.setString("Play");
	play.setCharacterSize(80);
	play.setFillColor(sf::Color::White);
	play.setPosition({ 40.f, 105.f });

	sf::Text number(font);
	number.setString("Number of customers per day : " + std::to_string(numberCustomers));
	number.setCharacterSize(45);
	number.setFillColor(sf::Color::White);
	number.setPosition({ 10.f, 300.f });

	sf::Text more(font);
	more.setString("+");
	more.setCharacterSize(65);
	more.setFillColor(sf::Color::White);
	more.setPosition({ 220.f, 360.f });

	sf::Text less(font);
	less.setString("-");
	less.setCharacterSize(65);
	less.setFillColor(sf::Color::White);
	less.setPosition({ 100.f, 360.f });

	sf::Text speed(font);
	speed.setString("Speed of the customers : " + std::to_string(speedCustomers));
	speed.setCharacterSize(45);
	speed.setFillColor(sf::Color::White);
	speed.setPosition({ 10.f, 500.f });

	sf::Text moreSpeed(font);
	moreSpeed.setString("+");
	moreSpeed.setCharacterSize(65);
	moreSpeed.setFillColor(sf::Color::White);
	moreSpeed.setPosition({ 220.f, 560.f });

	sf::Text lessSpeed(font);
	lessSpeed.setString("-");
	lessSpeed.setCharacterSize(65);
	lessSpeed.setFillColor(sf::Color::White);
	lessSpeed.setPosition({ 100.f, 560.f });

	sf::Text quit(font);
	quit.setString("Quit");
	quit.setCharacterSize(65);
	quit.setFillColor(sf::Color::White);
	quit.setPosition({ 40.f, 800.f });


	window.draw(backgroundRect);
	window.draw(playRectangle);
	window.draw(moreRectangle);
	window.draw(lessRectangle);
	window.draw(moreSpeedRectangle);
	window.draw(lessSpeedRectangle);
	window.draw(quitRectangle);
	window.draw(play);
	window.draw(number);
	window.draw(more);
	window.draw(less);
	window.draw(moreSpeed);
	window.draw(lessSpeed);
	window.draw(speed);
	window.draw(quit);
}

int Menu::getNumberCustomers()
{
	return numberCustomers;
}

int Menu::getSpeedCustomers()
{
	return speedCustomers;
}