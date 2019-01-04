#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "gameengine.h"
#include <string>
#include <iostream>

class TextureManager
{
public:
    static sf::Texture loadTexture(std::string path);
    static void drawTexture(sf::RenderWindow &window, sf::Sprite &sprite);
};

#endif // TEXTUREMANAGER_H
