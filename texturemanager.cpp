#include "texturemanager.h"
#include "gameengine.h"
#include <SFML/Graphics.hpp>

sf::Texture TextureManager::loadTexture(std::string path)
{
    sf::Texture tex;
    if (!(tex.loadFromFile(path))) {
        std::cout << "Can't load texture\n";
        // TODO :: End the game, SFML throws error when can't load texture
    } else {
        std::cout << "Texture loaded successfully\n";
    }

    return tex;

}
void TextureManager::drawTexture(sf::RenderWindow &window, sf::Sprite &sprite)
{
    window.draw(sprite);
}
