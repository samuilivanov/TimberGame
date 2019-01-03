#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class GameEngine
{
private:
    bool running;
    sf::RenderWindow window;

    // TODO :: move these to separate class
    sf::Sprite sprBackground;
    sf::Sprite sprTree;
    sf::Sprite sprPlayer;
    sf::Sprite sprbee;
    sf::Texture texBackground;
    sf::Texture texTree;
    sf::Texture texPlayer;

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
