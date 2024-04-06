#include "gameTile.h"

// GameTile constructor
GameTile::GameTile(string textureName, float x, float y, bool passable, bool exit)
{
	if (!setUpSprite(textureName))
	{
		return;
	}
	pos = sf::Vector2f(x, y);
	sprite.setPosition(pos);

	isPassable = passable;
	isExit = exit;
}

// sets up sprite image
bool GameTile::setUpSprite(string textureName)
{
	if (!texture.loadFromFile(textureName))
	{
		return false;
	}
	texture.setSmooth(true); // makes edges of tile smooth so not blurry
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 50, 50)); // sprite texture 50 x 50 allowing for square tiles 
	return true;
}

bool isPassable; // can move through it or if wall
bool isExit; // exits and starts new game

sf::Vector2f pos; // contains x and y values
sf::Texture texture;
sf::Sprite sprite;

