#ifndef PLAYER_H
#define PLAYER_H
#include "scene.h"
#include "texturemanager.h"

enum class side {
    LEFT, RIGHT, NONE
};

class Player : public Scene
{
private:
    side playerSide;
public:
    void init();
    bool isActive();
    void update();
    void draw(sf::RenderWindow &render);
    void setPlayerSide(side pos);
};

#endif // PLAYER_H
