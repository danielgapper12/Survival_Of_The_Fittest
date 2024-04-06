#pragma once
#include "Header.h"

// bullet class
class Bullet 
{
public:
	Bullet(float radius = 5.f) : currentVelocity(0.f,0.f), maxSpeed(40.f) 
	{	
		this->shape.setRadius(radius);
		this->shape.setFillColor(sf::Color::Magenta);
	};

	sf::FloatRect getGlobalBounds() 
	{
		return shape.getGlobalBounds();
	}
	
	sf::CircleShape shape;
	sf::Vector2f currentVelocity;
	float maxSpeed;
};







