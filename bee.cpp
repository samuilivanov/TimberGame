#include "bee.h"

void Bee::init()
{
    texure = TextureManager::loadTexture("assets/graphics/bee.png");
    sprite.setTexture(texure);
    sprite.setPosition(0, 800);
}

bool Bee::isActive()
{
    return beeActive;
}

void Bee::update()
{
    dt = clock.restart();
    if (!beeActive) {
        srand(static_cast<unsigned int>(time(nullptr) * 10));
        beeSpeed = (rand() % 200) + 200;
        srand(static_cast<unsigned int>(time(nullptr) * 10));
        float height = (rand() % 500) + 500;
        sprite.setPosition(2000, height);
        beeActive = true;
    } else {
        sprite.setPosition(sprite.getPosition().x -
                           (beeSpeed * dt.asSeconds()),
                           sprite.getPosition().y);
        if (sprite.getPosition().x < -100) {
            beeActive = false;
        }
    }
}

void Bee::draw(sf::RenderWindow &render)
{
    TextureManager::drawTexture(render, sprite);
}
