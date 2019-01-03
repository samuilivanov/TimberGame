#include "bee.h"

void Bee::init()
{
    //texure = TextureManager::loadTexture("assets/graphics/bee.png");
    texBee = TextureManager::loadTexture("assets/graphics/bee.png");
    sprBee.setTexture(texBee);
    sprBee.setPosition(0, 800);
    dt = clock.restart();
}

bool Bee::isActive()
{
    return beeActive;
}

sf::Sprite Bee::getSprite()
{
    return sprBee;
}

void Bee::update()
{
    if (!beeActive) {
        srand(static_cast<unsigned int>(time(nullptr) * 10));
        beeSpeed = (rand() % 200) + 200;
        srand(static_cast<unsigned int>(time(nullptr) * 10));
        float height = (rand() % 500) + 500;
        sprBee.setPosition(2000, height);
        beeActive = true;
    } else {
        sprBee.setPosition(sprBee.getPosition().x -
                           (beeSpeed * dt.asSeconds()),
                           sprBee.getPosition().y);
        if (sprBee.getPosition().x < -100) {
            beeActive = false;
        }
    }
}
