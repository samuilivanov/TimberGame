#include "gameengine.h"


GameEngine::GameEngine()
{

}

bool GameEngine::init(uint32_t width, uint32_t height, bool fullscreen)
{

    sf::VideoMode vm(width, height);
    window.create(vm, "Timber!!!", sf::Style::Fullscreen);

    if (window.isOpen()) {

        running = true;
        loadMedia();
        return true;
    } else {
        running = false;
        return false;
    }
}

bool GameEngine::isRunning()
{
    return running;
}

void GameEngine::display()
{
    window.display();
}

void GameEngine::eventHandle()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        running = false;
        window.close();
    }
}

void GameEngine::draw()
{
    window.clear();
    window.draw(sprBackground);
    window.draw(sprCloud01);
    window.draw(sprCloud02);
    window.draw(sprCloud03);
    window.draw(sprTree);
    window.draw(sprPlayer);
}

void GameEngine::loadMedia()
{

    texBackground.loadFromFile("assets/graphics/background.png");
    texCloud.loadFromFile("assets/graphics/cloud.png");
    texTree.loadFromFile("assets/graphics/tree.png");
    texBee.loadFromFile("assets/graphics/bee.png");
    texPlayer.loadFromFile("assets/graphics/player.png");

    sprBackground.setTexture(texBackground);
    sprCloud01.setTexture(texCloud);
    sprCloud02.setTexture(texCloud);
    sprCloud03.setTexture(texCloud);
    sprTree.setTexture(texTree);
    sprBee.setTexture(texBee);
    sprPlayer.setTexture(texPlayer);

    sprPlayer.setPosition(580, 720);
}
