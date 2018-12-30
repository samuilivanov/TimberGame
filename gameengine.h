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
    GameEngine();
    bool init(uint32_t width, uint32_t heigth, bool fullscreen);
    bool isRunning();
    void display();
    void eventHandle();
    void draw();
    void loadMedia();
};

#endif // GAMEENGINE_H
