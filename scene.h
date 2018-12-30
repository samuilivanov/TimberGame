#ifndef SCENE_H
#define SCENE_H
#include <SFML/Graphics.hpp>

class Scene
{
private:
    sf::Sprite sprBackground;
    sf::Sprite sprTree;
    sf::Sprite sprBee;
    sf::Sprite sprCloud01;
    sf::Sprite sprCloud02;
    sf::Sprite sprCloud03;
    sf::Sprite sprPlayer;
    sf::Texture texBackground;
    sf::Texture texTree;
    sf::Texture texBee;
    sf::Texture texCloud;
    sf::Texture texPlayer;
public:
    Scene();

};

#endif // SCENE_H
