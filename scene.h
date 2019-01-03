#ifndef SCENE_H
#define SCENE_H
#include <SFML/Graphics.hpp>

// This class will be virtual
// It will contain
// Sprites to create, textures to create, and update, draw,...
class Scene
{
private:
    sf::Sprite sprite;
    sf::Texture texure;
public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
};

#endif // SCENE_H
