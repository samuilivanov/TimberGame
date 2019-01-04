#include "player.h"

void Player::init()
{
    texure = TextureManager::loadTexture("assets/graphics/player.png");
    sprite.setTexture(texure);
    playerSide = side::LEFT;
    sprite.setPosition(580, 720);
}

bool Player::isActive()
{
    return true;
}

void Player::setPlayerSide(side pos)
{
    playerSide = pos;
}

void Player::update()
{
    if (playerSide == side::RIGHT) {
        sprite.setPosition(1200, 720);
    } else {
        sprite.setPosition(580, 720);
    }
}

void Player::draw(sf::RenderWindow &render)
{
    TextureManager::drawTexture(render, sprite);
}
