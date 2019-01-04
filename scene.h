#ifndef SCENE_H
#define SCENE_H
#include <SFML/Graphics.hpp>

// This class will be virtual
// It will contain
// Sprites to create, textures to create, and update, draw,...
class Scene
{
public:
    sf::Sprite sprite;
    sf::Texture texure;
    virtual bool isActive() = 0;
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow &render) = 0;
};

#endif // SCENE_H
