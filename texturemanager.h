#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "gameengine.h"
#include <string>
#include <iostream>

class TextureManager
{
public:
    static void loadTexture(sf::Texture *texture, std::string path);
};

#endif // TEXTUREMANAGER_H
