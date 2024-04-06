#pragma once
#include "Header.h"
#include "Character.h"
#include "bullet.h"

class Zombie : public Character
{
public:
	Zombie(float newRadius) : Character(newRadius), currentVelocity(0.f, 0.f), maxSpeed(2.3f)
	{
	}
	
	bool CollidingWithBullet(Bullet shape) 
	{
		if (character.getGlobalBounds().intersects(shape.getGlobalBounds())) {
			return true;
		}
		return false;
	}

	 bool CollidingWithCoin(Coin* coin) 
	 {
		if (character.getGlobalBounds().intersects(coin->getGlobalBounds())) {

			return true;
		}
		return false;
	}
	
	sf::FloatRect getGlobalBounds() 
	{
		return this->getGlobalBounds();
	}

	bool CollidingWithZombie(Character user) 
	{
		if (character.getGlobalBounds().intersects(user.getGlobalBounds())) {
			return true;
		}
		return false;
	}

	float ZombieMovement(Zombie zomb, float playerDirection);

	float maxSpeed;

	sf::Vector2f currentVelocity;
	sf::Vector2f zombCenter;
	sf::Vector2f zombiePath;
	sf::Vector2f zombiePathNorm; // normal line
	std::vector<Zombie> ZombieVector;	
};


sf::Vector2f ZombieMovement(Zombie zomb, sf::Vector2f playerDirection) 
{
	zomb.zombCenter = sf::Vector2f(zomb.getPos().x + 30, zomb.getPos().y + 30);
	zomb.zombiePath = playerDirection - zomb.zombCenter;
	zomb.zombiePathNorm = zomb.zombiePath / sqrtf(pow(zomb.zombiePath.x, 2) + pow(zomb.zombiePath.y, 2));
	zomb.currentVelocity = zomb.zombiePathNorm * zomb.maxSpeed;
	return zomb.currentVelocity;
}