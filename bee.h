#ifndef BEE_H
#define BEE_H
#include <SFML/Graphics.hpp>
#include "texturemanager.h"
#include "scene.h"

class Bee : public Scene
{
private:
    bool beeActive = false;
    float beeSpeed = 0.0f;
    sf::Time dt;
    sf::Clock clock;
//    sf::Texture texBee;
//    sf::Sprite sprBee;

public:
    void init();
    void update();
    void draw(sf::RenderWindow &render);
    bool isActive();
    sf::Sprite getSprite();
};

#endif // BEE_H
