#include "tree.h"

void Tree::init()
{
    texure = TextureManager::loadTexture("assets/graphics/tree.png");
    sprite.setTexture(texure);
    sprite.setPosition(810, 0);
}

bool Tree::isActive()
{
    return true;
}

void Tree::update()
{

}

void Tree::draw(sf::RenderWindow &render)
{
    TextureManager::drawTexture(render, sprite);
}
