#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "scene.h"
#include "texturemanager.h"

class Background : public Scene
{
private:

public:
    bool isActive();
    void init();
    void update();
    void draw(sf::RenderWindow &render);
};

#endif // BACKGROUND_H
