#include "merchant.h"

#include "merchantBlackboard.h"
#include "random.h"

merchant::merchant(sf::RenderWindow& _window, textures gameTextures, sf::Vector2f _location, products _product, timeOfDay& currentTime)
	: window(_window)
	, location(_location)
	, product(_product)
{
	switch (product)
	{
	case products::bread:
		texture = gameTextures.getTexture(textures::texturesIndices::breadMerchant);
		break;
	case products::armor:
		texture = gameTextures.getTexture(textures::texturesIndices::armorMerchant);
		break;
	case products::sword:
		texture = gameTextures.getTexture(textures::texturesIndices::swordMerchant);
		break;
	}
	rect = sf::RectangleShape({200, 200});
	rect.setPosition(location);
	rect.setTexture(&texture);

	money = newRandom::getRandomNumber(100, 200);
	productPrice = newRandom::getRandomNumber(10, 30);
	rawMaterialsPrice = newRandom::getRandomNumber(5, 15);

	auto* treeBlackBoard = new merchantBlackboard(this, currentTime);
	tree = new merchantBehaviorTree(treeBlackBoard);
	tree->buildTree();
	tree->beginExecute();
}

merchant::~merchant()
{
	delete tree;
	tree = nullptr;
}


void merchant::update(float deltaTime)
{
	tree->tick(deltaTime);
}

void merchant::draw()
{
	window.draw(rect);
}

bool merchant::sale(int nbSold)
{
	if (nbSold > nbProducts)
	{
		money += productPrice * nbSold;
		nbProducts -= nbSold;
		return true;
	}
	deficit += nbSold;
	return false;
}

int merchant::getMoney()
{
	return money;
}

void merchant::setMoney(int newMoney)
{
	money = newMoney;
}

int merchant::getRent()
{
	return rent;
}

int merchant::getDeficit()
{
	return deficit;
}

void merchant::setDeficit(int newDeficit)
{
	deficit = newDeficit;
}

int merchant::getRawMaterialsPrice()
{
	return rawMaterialsPrice;
}

void merchant::setRawMaterialsPrice(int newRawMaterialsPrice)
{
	rawMaterialsPrice = newRawMaterialsPrice;
}

int merchant::getNbRawMaterials()
{
	return nbRawMaterials;
}

void merchant::setNbRawMaterials(int newNbRawMaterials)
{
	nbRawMaterials = newNbRawMaterials;
}

bool merchant::isBankruptcy()
{
	return bankruptcy;
}

void merchant::setBankruptcy(bool newBankruptcy)
{
	bankruptcy = newBankruptcy;
}

int merchant::getNbProducts()
{
	return nbProducts;
}


void merchant::setNbProducts(int newNbProducts)
{
	nbProducts = newNbProducts;
}

int merchant::getNbRandom()
{
	return nbRandom;
}

void merchant::setNbRandom(int newNbRandom)
{
	nbRandom = newNbRandom;
}

products merchant::getProduct()
{
	return product;
}

int merchant::getProductPrice()
{
	return productPrice;
}

void merchant::setProductPrice(int newProductPrice)
{
	productPrice = newProductPrice;
}

bool merchant::getEndTasks()
{
	return endTasks;
}

void merchant::setEndTasks(bool newEndTasks)
{
	endTasks = newEndTasks;
}

sf::Vector2f merchant::getLocation()
{
	return location;
}