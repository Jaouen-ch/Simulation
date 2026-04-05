#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class textures
{
private:
    std::vector<sf::Texture> tabTextures;

public:
    enum class texturesIndices
    {
        customer,
        breadMerchant,
        swordMerchant,
        armorMerchant,
        background,
        menuBackground,
        play,
        more,
    };

    textures() ;
    ~textures() = default;

    sf::Texture getTexture(texturesIndices index);

private:
    void loadTexture(texturesIndices _index, const char* filename);
};