#include "gameengine.h"
#include "texturemanager.h"


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
// TODO :: separete class TextureManager - all the loading textures to go throu this class
// TODO :: separete class for the position of the media for now I am moving it here
void GameEngine::loadMedia()
{
    TextureManager::loadTexture(&texBackground, "assets/graphics/background.png");
    TextureManager::loadTexture(&texCloud, "assets/graphics/cloud.png");
    TextureManager::loadTexture(&texTree, "assets/graphics/tree.png");
    TextureManager::loadTexture(&texBee, "assets/graphics/bee.png");
    TextureManager::loadTexture(&texPlayer, "assets/graphics/player.png");
// TODO :: class sprite

    sprBackground.setTexture(texBackground);
    sprCloud01.setTexture(texCloud);
    sprCloud02.setTexture(texCloud);
    sprCloud03.setTexture(texCloud);
    sprTree.setTexture(texTree);
    sprBee.setTexture(texBee);
    sprPlayer.setTexture(texPlayer);

    sprPlayer.setPosition(580, 720);
    sprBackground.setPosition(0, 0);
    sprTree.setPosition(810, 0);
    sprBee.setPosition(0, 800);
}
