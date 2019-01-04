#include "gameengine.h"
#include "texturemanager.h"
#include "bee.h"
#include "clouds.h"
#include "tree.h"
#include "player.h"
#include "background.h"

static Bee bee;
static Clouds clouds;
static Tree tree;
static Player player;
static Background background;

GameEngine::GameEngine()
{
    paused = false;
    score = 0;
    acceptInput = false;
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
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyReleased && !paused) {
            acceptInput = true;
            //sprAxe.setPosition(2000, sprAxe.getPosition().y);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        running = false;
        window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        paused = false;
        score = 0;
        //timeRem = 6;

//        for (size_t i = 1; i < NUM_BRANCHES; ++i) {
//            branchPos[i] = side::NONE;
//        }
//        sprRIP.setPosition(675, 2000);
//        sprPlayer.setPosition(580, 720);
        acceptInput = true;
    }
    if (acceptInput) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.setPlayerSide(side::RIGHT);
            score++;
//            timeRem += static_cast<float>((2 / score) + 0.15);
//            sprAxe.setPosition(AXE_POS_RIGHT,
//                               sprAxe.getPosition().y);
//            sprPlayer.setPosition(1200, 720);

//            updateBranches(score);

//            sprLog.setPosition(810, 720);
//            logSpeedX = -5000;
//            logActive = true;
            acceptInput = false;
//            chop.play();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.setPlayerSide(side::LEFT);
            score++;
//            timeRem += static_cast<float>((2 / score) + 0.15);
//            sprAxe.setPosition(AXE_POS_LEFT,
//                               sprAxe.getPosition().y);
//            sprPlayer.setPosition(580, 720);
//            updateBranches(score);
//            sprLog.setPosition(810, 720);
//            logSpeedX = 5000;
//            logActive = true;
            acceptInput = false;
//            chop.play();
        }
    }
}

void GameEngine::update()
{
    bee.update();
    clouds.update();
    player.update();
}

void GameEngine::draw()
{
    window.clear();
    background.draw(window);
    clouds.draw(window);
    tree.draw(window);
    bee.draw(window);
    player.draw(window);
}

void GameEngine::loadMedia()
{
    background.init();
    bee.init();
    clouds.init();
    tree.init();
    player.init();
}
