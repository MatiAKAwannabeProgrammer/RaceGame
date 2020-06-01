#include "player.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/GlResource.hpp>
#include <SFML/Window/Keyboard.hpp>

Player::Player()
{
    texture.loadFromFile("./content/car.png");
    player.setTexture(texture);
    player.setPosition(sf::Vector2f(50.f, 700.f));
    player.setOrigin(texture.getSize().x /2, texture.getSize().y /2);
    player.setRotation(0);
    float sSpeed = 0.f;
    float wSpeed = 0.f;
}

void Player::playerMovement(float& deltaTime)
{
    // If W is pressed.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        if (sSpeed > 0){
            player.move(cos(player.getRotation() * 3.14 / 180) * -sSpeed * deltaTime, -sin(player.getRotation() * 3.14 / 180) * sSpeed * deltaTime);
            sSpeed -= 5.f;
        }
        else{
            player.move(cos(player.getRotation() * 3.14 / 180) * wSpeed * deltaTime, -sin(player.getRotation() * 3.14 / 180) * -wSpeed * deltaTime);
            if (wSpeed <= 250.f){
                wSpeed += 2.f;
            }
        }
    }
    // If S is pressed.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        if (wSpeed > 0){
            player.move(cos(player.getRotation() * 3.14 / 180) * wSpeed * deltaTime, -sin(player.getRotation() * 3.14 / 180)* -wSpeed * deltaTime);
            wSpeed -= 5.f;
        }
        if (wSpeed <= 0){
            player.move(cos(player.getRotation() * 3.14 / 180) * -sSpeed * deltaTime, -sin(player.getRotation() * 3.14 / 180)* sSpeed * deltaTime);
            if (sSpeed <= 100.f){
                sSpeed += 2.f;
            }
        }
    }
    // Rotations.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        if (wSpeed > 0){
            player.rotate(-2.f);
        }
        if (sSpeed > 0){
            player.rotate(2.f);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if (wSpeed > 0){
            player.rotate(2.f);
        }
        if (sSpeed > 0){
            player.rotate(-2.f);
        }
    }
    // Deceleration.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) == false && sf::Keyboard::isKeyPressed(sf::Keyboard::S) == false){
        if (wSpeed > 0){
            player.move(cos(player.getRotation() * 3.14 /180) * wSpeed * deltaTime, -sin(player.getRotation() * 3.14 / 180)* -wSpeed * deltaTime); 
            wSpeed -= 2.f;
        }
        if (sSpeed > 0){
            player.move(cos(player.getRotation() * 3.14 /180) * -sSpeed * deltaTime, -sin(player.getRotation() * 3.14 / 180)* sSpeed * deltaTime);
            sSpeed -= 2.f;
        } 
    } 
}

void Player::drawPlayer(sf::RenderWindow& window)
{
    window.draw(player);
}
