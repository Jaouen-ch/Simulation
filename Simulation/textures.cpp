#include "textures.h"

void textures::loadTexture(texturesIndices _index, const char* fileName)
{
    sf::Texture texture(fileName);

    auto index = (int)_index;
    if (index >= tabTextures.size())
    {
        tabTextures.resize(index+1);
    }

    tabTextures[index] = texture;
}

textures::textures()
{
    loadTexture(texturesIndices::customer, "assets/customer.png");
    loadTexture(texturesIndices::breadMerchant, "assets/bread.png");
    loadTexture(texturesIndices::swordMerchant, "assets/sword.png");
    loadTexture(texturesIndices::armorMerchant, "assets/armor.png");
    loadTexture(texturesIndices::background, "assets/background.png");
    loadTexture(texturesIndices::menuBackground, "assets/Back.png");
    loadTexture(texturesIndices::play, "assets/play.png");
    loadTexture(texturesIndices::more, "assets/more.png");

}

sf::Texture textures::getTexture(texturesIndices index)
{
    return tabTextures[(int)index];
}
