#pragma once

#include "Header.h"

// coin class, equivelent to ammo drops 
class Coin 
{
public:
Coin(float newRadius)
{
	coin.setRadius(newRadius);
	coin.setFillColor(sf::Color::Yellow);
}

void drawTo(sf::RenderWindow& window) 
{
	window.draw(coin);
}

void setPos(sf::Vector2f newPos) 
{
	coin.setPosition(newPos);
}

sf::FloatRect getGlobalBounds() 
{
	return coin.getGlobalBounds();
}

float respawnPositionX();
float respawnPositionY();

private:
	sf::CircleShape coin;
};

float respawnPositionX() 
{
	int x;
	do {
		x = (rand() % 1100) + 40.0;
	} while (x > 580 && x < 650);
	return x;
}

float respawnPositionY() 
{
	int y;
	
	do {
		y = (rand() % 600) + 100.0;
	} while (y > 330 && y < 400);
	return y;
}
