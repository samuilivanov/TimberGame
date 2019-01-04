#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class GameEngine
{
private:
    bool running;
    // TODO :: move these to separate class
    sf::Sprite sprBackground;
    sf::Texture texBackground;
    sf::RenderWindow window;
    bool paused;
    bool acceptInput;
    uint32_t score;

public:

    GameEngine();
    bool init(uint32_t width, uint32_t heigth, bool fullscreen);
    bool isRunning();
    void display();
    void eventHandle();
    void update();
    void draw();
    void loadMedia();
};

#endif // GAMEENGINE_H
