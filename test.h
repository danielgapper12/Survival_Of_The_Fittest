#pragma once
#include "Header.h"
#include "test.h"
#include "gameTile.h"
#include "gameWorld.h"
#include "character.h" 
#include "Zombie.h"

// test class
class Test
{
public:
	// tests if ammo respawns location is valid
	void testAmmoRespawn(float ammoSpawnXcoor, float ammoSpawnYcoor);

	// tests if sprite is successfully set up
	void testSpriteSetup(GameTile& testGameWorld, string testTextureName);

	// tests if sfml window is successfully opened
	void testWindowOpen(sf::RenderWindow& testWindow);

	// tests if user location is valid
	void testUserLocation(Character& testUser);

	// tests if zombie hit by bullet
	void testZombieKilled(Zombie& testZombie, Bullet& testUser);
};

// tests if ammo respawns location is valid
void Test::testAmmoRespawn(float ammoSpawnXcoor, float ammoSpawnYcoor)
{
	if (ammoSpawnXcoor > 0.0 && ammoSpawnXcoor < 1200.0 && ammoSpawnYcoor > 50.0 && ammoSpawnYcoor < 750.0)
	{
		cout << "new ammo drop within bounds!  \n\ncoordinates of new ammo drop: " << ammoSpawnXcoor << ", " << ammoSpawnYcoor << endl;

	}
	else
	{
		cout << "ammo drop invalid. \n\ncoordinates of new ammo drop: " << ammoSpawnXcoor << ", " << ammoSpawnYcoor << endl;
	}
}

// tests if sprite is successfully set up
void Test::testSpriteSetup(GameTile& testGameWorld, string testTextureName)
{
	if (testGameWorld.setUpSprite(testTextureName) == true)
	{
		cout << "successfully set up sprite!" << endl;
	}
	else
	{
		cout << "sprite set up failed!" << endl;
	}
}

// tests if sfml window is successfully opened
void Test::testWindowOpen(sf::RenderWindow& testWindow)
{
	if (testWindow.isOpen() == true)
	{
		cout << "window successfully opened!" << endl;
	}
	else {
		cout << "window opening failed." << endl;
	}
}

// tests if user location is valid
void Test::testUserLocation(Character& testUser)
{
	if (testUser.getPos().x > 0.0 && testUser.getPos().x < 1200.0 && testUser.getPos().y > 50.0 && testUser.getPos().y < 750.0)
	{
		cout << "user within bounds!  \n\ncoordinates of user: " << testUser.getPos().x << ", " << testUser.getPos().y << endl;

	}
	else
	{
		cout << "ammo drop invalid. \n\ncoordinates of new ammo drop: " << testUser.getPos().x << ", " << testUser.getPos().y << endl;
	}
}

// tests if zombie hit by bullet
void Test::testZombieKilled(Zombie& testZombie, Bullet& testUser)
{
	if (testZombie.CollidingWithBullet(testUser) == true)
	{
		cout << "zombie hit by bullet!" << endl;
	}
	else {
		cout << "zombie not hit by bullet." << endl;
	}
}

