#ifndef CLOUDS_H
#define CLOUDS_H
#include <SFML/Graphics.hpp>
#include "texturemanager.h"

class Clouds
{
private:
    sf::Texture texCloud;
    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;
    sf::Time dt;
    sf::Clock clock;
public:
    sf::Sprite sprCloud01;
    sf::Sprite sprCloud02;
    sf::Sprite sprCloud03;
    Clouds();
    void update();
};

#endif // CLOUDS_H
