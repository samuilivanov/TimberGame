#include "clouds.h"

void Clouds::init()
{
    texure = TextureManager::loadTexture("assets/graphics/cloud.png");
    sprCloud01.setTexture(texure);
    sprCloud02.setTexture(texure);
    sprCloud03.setTexture(texure);
}

bool Clouds::isActive()
{
    return cloud1Active;
}

void Clouds::draw(sf::RenderWindow &render)
{
    TextureManager::drawTexture(render, sprCloud01);
    TextureManager::drawTexture(render, sprCloud02);
    TextureManager::drawTexture(render, sprCloud03);
}

void Clouds::update()
{
    dt = clock.restart();
    if (!cloud1Active) {
        srand(static_cast<unsigned int>(time(nullptr) * 10));
        cloud1Speed = (rand() % 200);
        srand(static_cast<unsigned int>(time(nullptr) * 10));
        height = (rand() % 150);
        sprCloud01.setPosition(-200, height);
        cloud1Active = true;
    } else {
        sprCloud01.setPosition(sprCloud01.getPosition().x +
                               (cloud1Speed * dt.asSeconds()),
                               sprCloud01.getPosition().y);
        if (sprCloud01.getPosition().x > 1920) {
            cloud1Active = false;
        }
    }

    if (!cloud2Active) {
        srand(static_cast<unsigned int>(time(nullptr) * 20));
        cloud2Speed = (rand() % 200);
        srand(static_cast<unsigned int>(time(nullptr) * 20));
        height = (rand() % 300) - 150;
        sprCloud02.setPosition(-200, height);
        cloud2Active = true;
    } else {
        sprCloud02.setPosition(sprCloud02.getPosition().x +
                               (cloud2Speed * dt.asSeconds()),
                               sprCloud02.getPosition().y);
        if (sprCloud02.getPosition().x > 1920) {
            cloud2Active = false;
        }
    }

    if (!cloud3Active) {
        srand(static_cast<unsigned int>(time(nullptr) * 30));
        cloud3Speed = (rand() % 200);
        srand(static_cast<unsigned int>(time(nullptr) * 30));
        height = (rand() % 450) - 150;
        sprCloud03.setPosition(-200, height);
        cloud3Active = true;
    } else {
        sprCloud03.setPosition(sprCloud03.getPosition().x +
                               (cloud3Speed * dt.asSeconds()),
                               sprCloud03.getPosition().y);
        if (sprCloud03.getPosition().x > 1920) {
            cloud3Active = false;
        }
    }
}
