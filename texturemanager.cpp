#include "texturemanager.h"

void TextureManager::loadTexture(sf::Texture *texture, std::string path)
{
    if (!(texture->loadFromFile(path))) {
        std::cout << "Can't load texture\n";
        // TODO :: End the game, SFML throws error when can't load texture
    } else {
        std::cout << "Texture loaded successfully\n";
    }
}
