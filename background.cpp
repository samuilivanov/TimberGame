#include "background.h"

void Background::init()
{
    texure = TextureManager::loadTexture("assets/graphics/background.png");
    sprite.setTexture(texure);
    sprite.setPosition(0, 0);
}

bool Background::isActive()
{
    return true;
}

void Background::update()
{

}

void Background::draw(sf::RenderWindow &render)
{
    TextureManager::drawTexture(render, sprite);
}
