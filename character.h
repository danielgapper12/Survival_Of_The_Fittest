#pragma once
#include "Header.h"
#include <iostream>
#include "Coin.h"

class Character
{
public:
	Character(float newRadius)
	{
		character.setRadius(newRadius);
	}

	void drawTo(sf::RenderWindow & window) 
	{
		window.draw(character);
	}

	void setColor(sf::Texture *color) 
	{
		character.setTexture(color);
	}

	void move(sf::Vector2f distance) 
	{
		character.move(distance);
	}

	void setPos(sf::Vector2f newPos) 
	{
		character.setPosition(newPos);
	}

	virtual bool CollidingWithCoin(Coin * coin) 
	{
		if (character.getGlobalBounds().intersects(coin->getGlobalBounds())) 
		{
			return true;
		} else
		{
			return false;
		}
	}

	sf::FloatRect getGlobalBounds() 
	{
		return character.getGlobalBounds();
	}

	sf::Vector2f getPos() 
	{
		return character.getPosition();
	}

	void playerMovement(Character user, float speed, float diagonalSpeed);

	sf::Texture zombieTexture;
	sf::Sprite zombieSprite;
	sf::CircleShape character;
};
