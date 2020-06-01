#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>

class Player
{
private:
    sf::Sprite player;
    sf::Texture texture;
    sf::Vector2f playerPos;
    float a, b, angle;
    float wSpeed, sSpeed;

public:
    Player();
    void playerMovement(float& deltaTime);
    void drawPlayer(sf::RenderWindow& window);
    void getPlayerPos();
    
};
#endif
