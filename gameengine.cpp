#include "gameengine.h"
#include "texturemanager.h"
#include "bee.h"
#include "clouds.h"

static Bee bee = Bee();
static Clouds clouds = Clouds();

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

void GameEngine::update()
{
    bee.update();
    clouds.update();
}

void GameEngine::draw()
{
    window.clear();
    TextureManager::drawTexture(&window, sprBackground);

    TextureManager::drawTexture(&window, clouds.sprCloud01);
    TextureManager::drawTexture(&window, clouds.sprCloud02);
    TextureManager::drawTexture(&window, clouds.sprCloud03);

    TextureManager::drawTexture(&window, sprTree);
    sprbee = bee.getSprite();
    TextureManager::drawTexture(&window, sprbee);

    TextureManager::drawTexture(&window, sprPlayer);
}
// TODO :: separete class TextureManager - all the loading textures to go throu this class
// TODO :: separete class for the position of the media for now I am moving it here
void GameEngine::loadMedia()
{
    texBackground = TextureManager::loadTexture("assets/graphics/background.png");
    texTree = TextureManager::loadTexture("assets/graphics/tree.png");
    texPlayer = TextureManager::loadTexture("assets/graphics/player.png");
// TODO :: class sprite

    sprBackground.setTexture(texBackground);

    sprTree.setTexture(texTree);

    sprPlayer.setTexture(texPlayer);

    sprPlayer.setPosition(580, 720);
    sprBackground.setPosition(0, 0);
    sprTree.setPosition(810, 0);
}
