#ifndef BEE_H
#define BEE_H
#include <SFML/Graphics.hpp>
#include "texturemanager.h"
#include "scene.h"
class Bee : public Scene
{
private:
    bool beeActive = false;
    sf::Texture texBee;
    sf::Sprite sprBee;
    float beeSpeed = 0.0f;
    sf::Time dt;
    sf::Clock clock;

public:
    void init();
    void update();
    void draw();
    bool isActive();
    sf::Sprite getSprite();
};

#endif // BEE_H
