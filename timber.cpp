#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <sstream>
#include <cstdint>
#include <iostream>

#include "gameengine.h"

void updateBranches(uint32_t seed);
const int32_t NUM_BRANCHES = 6;
sf::Sprite branches[NUM_BRANCHES];
enum class side {
    LEFT, RIGHT, NONE
};
side branchPos[NUM_BRANCHES];

//GameEngine:
//* created and run inside the main()
//* handles my scenes under a state pattern so I know which one to run, and whether I should switch to an other one
//* handles the sf::RenderWindow and all the global SFML stuff
//* the run() method contains the classic SFML pollEvent() loop

//Scene:
//* created/updated/displayed/destroyed by the GameEngine
//* implements sf::Drawable according to a composite pattern (i.e. contains sub-sprites and other drawable elements)
//* contains an OnUpdate(sf::Time elapsedTime) method to update the physics engine (if any) or any entity of the scene (charac animation, menu cursor blink, etc).
//* Concrete implementations could be: TitleScene, SettingsMenuScene, WorldmapScene, Level1Scene, etc

//GameEvent:
//* Similar to sf::Event but with my own events
//* Used along an observer pattern
//* Example: TitleScene uses a GameEvent to notify its subscribers that the "New game" button has been pressed. GameEngine is notified and updates its state diagram accordingly.



int main(void)
{
    GameEngine *game = new GameEngine();
    uint32_t width = 1920;
    uint32_t height = 1080;
    if (!(game->init(width, height, true)))
    {
        std::cout << "Can not create window\n";
    } else {
        std::cout << "SFML initialized!\n";
    }

    while (game->isRunning()){
        game->eventHandle();
        game->draw();


        game->display();
    }

    /*
    sf::SoundBuffer chopBuffer;
    chopBuffer.loadFromFile("assets/sound/chop.wav");
    sf::Sound chop;
    chop.setBuffer(chopBuffer);

    sf::SoundBuffer deathBuffer;
    deathBuffer.loadFromFile("assets/sound/death.wav");
    sf::Sound death;
    death.setBuffer(deathBuffer);

    sf::SoundBuffer ootBuffer;
    ootBuffer.loadFromFile("assets/sound/out_of_time.wav");
    sf::Sound outOfTime;
    outOfTime.setBuffer(ootBuffer);


    sf::Texture texBackground;
    sf::Texture texTree;
    sf::Texture texBee;
    sf::Texture texCloud;
    texCloud.loadFromFile("assets/graphics/cloud.png");
    texBee.loadFromFile("assets/graphics/bee.png");
    texTree.loadFromFile("assets/graphics/tree.png");
    texBackground.loadFromFile("assets/graphics/background.png");
    sf::Sprite sprBackground;
    sf::Sprite sprTree;
    sf::Sprite sprBee;
    sf::Sprite sprCloud01;
    sf::Sprite sprCloud02;
    sf::Sprite sprCloud03;
    sprCloud01.setTexture(texCloud);
    sprCloud02.setTexture(texCloud);
    sprCloud03.setTexture(texCloud);
    sf::Texture texPlayer;
    texPlayer.loadFromFile("assets/graphics/player.png");

    sf::Sprite sprPlayer;
    sprPlayer.setTexture(texPlayer);
    sprPlayer.setPosition(580, 720);

    side playerSide = side::LEFT;

    sf::Texture texRIP;
    texRIP.loadFromFile("assets/graphics/rip.png");
    sf::Sprite sprRIP;
    sprRIP.setTexture(texRIP);
    sprRIP.setPosition(600, 860);

    sf::Texture texAxe;
    texAxe.loadFromFile("assets/graphics/axe.png");
    sf::Sprite sprAxe;
    sprAxe.setTexture(texAxe);
    sprAxe.setPosition(700, 830);

    const float AXE_POS_LEFT = 700;
    const float AXE_POS_RIGHT = 1075;

    sf::Texture texLog;
    texLog.loadFromFile("assets/graphics/log.png");
    sf::Sprite sprLog;
    sprLog.setTexture(texLog);
    sprLog.setPosition(810, 720);
    bool logActive = false;
    float logSpeedX = 1000;
    float logSpeedY = -1500;

    sprBackground.setTexture(texBackground);
    sprBackground.setPosition(0, 0);
    sprTree.setTexture(texTree);
    sprTree.setPosition(810, 0);
    sprBee.setTexture(texBee);
    sprBee.setPosition(0, 800);
    bool beeAct = false;
    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;
    float beeSpeed = 0.0f;
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;
    sf::Clock clock;

    sf::RectangleShape timeBar;
    float timeBarStartWidth = 400;
    float timeBarHeight = 80;
    timeBar.setSize(sf::Vector2f(timeBarStartWidth, timeBarHeight));
    timeBar.setFillColor(sf::Color::Red);
    timeBar.setPosition((1920 / 2) - timeBarStartWidth / 2, 980);

    sf::Time gameTimeTotal;
    float timeRem = 6.0f;
    float timeBarWidthPerSec = timeBarStartWidth / timeRem;

    bool paused = true;

    uint32_t score = 0;
    sf::Text msgText;
    sf::Text scText;
    sf::Text fpsText;

    sf::Font font;
    font.loadFromFile("assets/fonts/KOMIKAP_.ttf");

    msgText.setFont(font);
    scText.setFont(font);
    fpsText.setFont(font);

    msgText.setString("Press Enter to start!");
    scText.setString("Score = 0");

    msgText.setCharacterSize(75);
    scText.setCharacterSize(100);
    msgText.setFillColor(sf::Color::White);
    scText.setFillColor(sf::Color::White);

    sf::FloatRect textRect = msgText.getLocalBounds();
    msgText.setOrigin(textRect.left +
                      textRect.width / 2.0f,
                      textRect.top +
                      textRect.height / 2.0f);
    msgText.setPosition(1920 / 2.0f, 1000 / 2.0f);
    scText.setPosition(20, 20);

    sf::Texture texBranch;
    texBranch.loadFromFile("assets/graphics/branch.png");
    for (size_t i = 0; i < NUM_BRANCHES; ++i) {
        branches[i].setTexture(texBranch);
        branches[i].setPosition(-2000, -2000);
        branches[i].setOrigin(220, 20);
    }

    bool acceptInput = false;

    while (window.isOpen()) {
        // Handle players input
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyReleased && !paused) {
                acceptInput = true;
                sprAxe.setPosition(2000,
                                   sprAxe.getPosition().y);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            paused = false;
            score = 0;
            timeRem = 6;

            for (size_t i = 1; i < NUM_BRANCHES; ++i) {
                branchPos[i] = side::NONE;
            }
            sprRIP.setPosition(675, 2000);
            sprPlayer.setPosition(580, 720);
            acceptInput = true;
        }

        if (acceptInput) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                playerSide = side::RIGHT;
                score++;
                timeRem += static_cast<float>((2 / score) + 0.15);
                sprAxe.setPosition(AXE_POS_RIGHT,
                                   sprAxe.getPosition().y);
                sprPlayer.setPosition(1200, 720);

                updateBranches(score);

                sprLog.setPosition(810, 720);
                logSpeedX = -5000;
                logActive = true;
                acceptInput = false;
                chop.play();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                playerSide = side::LEFT;
                score++;
                timeRem += static_cast<float>((2 / score) + 0.15);
                sprAxe.setPosition(AXE_POS_LEFT,
                                   sprAxe.getPosition().y);
                sprPlayer.setPosition(580, 720);
                updateBranches(score);
                sprLog.setPosition(810, 720);
                logSpeedX = 5000;
                logActive = true;
                acceptInput = false;
                chop.play();
            }
        }
        // Update scene
        if (!paused) {
            sf::Time dt = clock.restart();
            timeRem -= dt.asSeconds();
            timeBar.setSize(sf::Vector2f(timeBarWidthPerSec *
                                        timeRem, timeBarHeight));
            if (timeRem <= 0.0f) {
                paused = true;
                msgText.setString("Out of time!!");
                sf::FloatRect textRect = msgText.getLocalBounds();
                msgText.setOrigin(textRect.left +
                                  textRect.width / 2.0f,
                                  textRect.top +
                                  textRect.height / 2.0f);
                outOfTime.play();
            }
            if (!beeAct) {
                srand(static_cast<unsigned int>(time(nullptr) * 10));
                beeSpeed = (rand() % 200) + 200;
                srand(static_cast<unsigned int>(time(nullptr) * 10));
                float height = (rand() % 500) + 500;
                sprBee.setPosition(2000, height);
                beeAct = true;
            } else {
                sprBee.setPosition(sprBee.getPosition().x -
                                   (beeSpeed * dt.asSeconds()),
                                   sprBee.getPosition().y);
                if (sprBee.getPosition().x < -100) {
                    beeAct = false;
                }
            }

            if (!cloud1Active) {
                srand(static_cast<unsigned int>(time(nullptr) * 10));
                cloud1Speed = (rand() % 200);
                srand(static_cast<unsigned int>(time(nullptr) * 10));
                float height = (rand() % 150);
                sprCloud01.setPosition(-200, height);
                cloud1Active = true;
            } else {
                sprCloud01.setPosition(sprCloud01.getPosition().x +
                                       (cloud1Speed * dt.asSeconds()),
                                       sprCloud01.getPosition().y);
                if (sprCloud01.getPosition().x > 1920) {
                    cloud1Active = false;
                }
            }

            if (!cloud2Active) {
                srand(static_cast<unsigned int>(time(nullptr) * 20));
                cloud2Speed = (rand() % 200);
                srand(static_cast<unsigned int>(time(nullptr) * 20));
                float height = (rand() % 300) - 150;
                sprCloud02.setPosition(-200, height);
                cloud2Active = true;
            } else {
                sprCloud02.setPosition(sprCloud02.getPosition().x +
                                       (cloud2Speed * dt.asSeconds()),
                                       sprCloud02.getPosition().y);
                if (sprCloud02.getPosition().x > 1920) {
                    cloud2Active = false;
                }
            }

            if (!cloud3Active) {
                srand(static_cast<unsigned int>(time(nullptr) * 30));
                cloud3Speed = (rand() % 200);
                srand(static_cast<unsigned int>(time(nullptr) * 30));
                float height = (rand() % 450) - 150;
                sprCloud03.setPosition(-200, height);
                cloud3Active = true;
            } else {
                sprCloud03.setPosition(sprCloud03.getPosition().x +
                                       (cloud3Speed * dt.asSeconds()),
                                       sprCloud03.getPosition().y);
                if (sprCloud03.getPosition().x > 1920) {
                    cloud3Active = false;
                }
            }
            std::stringstream ss;
            ss << "Score = " << score;
            scText.setString((ss.str()));

            for (size_t i = 0; i < NUM_BRANCHES; ++i) {
                float height = i * 150;
                if (branchPos[i] == side::LEFT) {
                    branches[i].setPosition(610, height);
                    branches[i].setRotation(180);
                } else if (branchPos[i] == side::RIGHT) {
                    branches[i].setPosition(1330, height);
                    branches[i].setRotation(0);
                } else {
                    branches[i].setPosition(3000, height);
                }
            }

            if (logActive) {
                sprLog.setPosition(
                            sprLog.getPosition().x +
                            (logSpeedX * dt.asSeconds()),
                            sprLog.getPosition().y +
                            (logSpeedY * dt.asSeconds()));
            }
            if (sprLog.getPosition().x < - 100 ||
                    sprLog.getPosition().x > 2000) {
                logActive = false;
                sprLog.setPosition(810, 720);
            }
            if (branchPos[5] == playerSide) {
                paused = true;
                acceptInput = false;
                sprRIP.setPosition(525, 760);
                sprPlayer.setPosition(2000, 660);
                msgText.setString("SQUISHED!");
                sf::FloatRect textRect = msgText.getLocalBounds();
                msgText.setOrigin(textRect.left + textRect.width / 2.0f,
                                  textRect.top + textRect.height / 2.0f);
                msgText.setPosition(1920 / 2.0f, 1080 / 2.0f);
                death.play();
            }
        }
        // Draw scene
        window.clear();
        window.draw(sprBackground);
        window.draw(sprCloud01);
        window.draw(sprCloud02);
        window.draw(sprCloud03);

        for (size_t i = 0; i < NUM_BRANCHES; ++i) {
            window.draw(branches[i]);
        }

        window.draw(sprTree);

        window.draw(sprPlayer);
        window.draw(sprAxe);
        window.draw(sprLog);
        window.draw(sprRIP);
        window.draw(sprBee);
        window.draw(scText);
        window.draw(timeBar);
        if (paused) {
            window.draw(msgText);
        }
        // Show everything
        window.display();
    }
    return 0;
}

    */
}
void updateBranches(uint32_t seed)
{
    for (size_t i = NUM_BRANCHES - 1; i > 0; --i) {
        branchPos[i] = branchPos[i - 1];
    }
    srand(static_cast<unsigned int>(time(nullptr) + seed));
    size_t r = (rand() % 5);
    switch (r) {
    case 0:
        branchPos[0] = side::LEFT;
        break;
    case 1:
        branchPos[0] = side::RIGHT;
        break;
    default:
        branchPos[0] = side::NONE;
        break;
    }
}
