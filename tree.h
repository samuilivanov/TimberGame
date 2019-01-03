#ifndef TREE_H
#define TREE_H
#include <SFML/Graphics.hpp>
#include "texturemanager.h"

class Tree
{
private:
    sf::Texture texTree;
    sf::Sprite sprTree;


    sf::Texture texLog;
    //texLog.loadFromFile("assets/graphics/log.png");
    sf::Sprite sprLog;
    //sprLog.setTexture(texLog);
    //sprLog.setPosition(810, 720);
    bool logActive = false;
    float logSpeedX = 1000;
    float logSpeedY = -1500;


public:
    Tree();
};

#endif // TREE_H
