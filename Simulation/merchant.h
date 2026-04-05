#pragma once

#include <SFML/Graphics.hpp>

#include "gameBlackBoard.h"
#include "textures.h"
#include "merchantBehaviorTree.h"

enum class products
{
	bread,
	sword,
	armor
};

class merchant
{
private:
	sf::Vector2f location;

	sf::RenderWindow& window;
	sf::RectangleShape rect;
	sf::Texture texture;

	merchantBehaviorTree* tree;

	bool bankruptcy = false;
	bool endTasks = true;
	products product;
	int rent = 15;
	int money;
	int rawMaterialsPrice;
	int productPrice;
	int nbRawMaterials = 0;
	int nbProducts = 0;
	int deficit = 0;
	bool open = false;
	int nbRandom = 0;

public:
	merchant(sf::RenderWindow& _window, textures gameTextures, sf::Vector2f _location, products _product, timeOfDay& currentTime);
	~merchant();

	void update(float deltaTime);
	void draw();

	bool sale(int nbSold);

	int getMoney();
	void setMoney(int newMoney);
	int getRent();
	int getDeficit();
	void setDeficit(int newDeficit);
	int getRawMaterialsPrice();
	void setRawMaterialsPrice(int newRawMaterialsPrice);
	int getNbRawMaterials();
	void setNbRawMaterials(int newNbRawMaterials);
	bool isBankruptcy();
	void setBankruptcy(bool newBankruptcy);
	int getNbProducts();
	void setNbProducts(int newNbProducts);
	int getNbRandom();
	void setNbRandom(int newNbRandom);
	products getProduct();
	int getProductPrice();
	void setProductPrice(int newProductPrice);
	bool getEndTasks();
	void setEndTasks(bool newEndTasks);
	sf::Vector2f getLocation();
};