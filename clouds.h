#ifndef CLOUDS_H
#define CLOUDS_H
#include <SFML/Graphics.hpp>
#include "texturemanager.h"
#include "scene.h"

class Clouds : public Scene
{
private:
    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;
    float height;
    sf::Time dt;
    sf::Clock clock;
public:
    sf::Sprite sprCloud01;
    sf::Sprite sprCloud02;
    sf::Sprite sprCloud03;
    bool isActive();
    void init();
    void update();
    void draw(sf::RenderWindow &render);

};

#endif // CLOUDS_H
