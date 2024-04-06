#pragma once
#include "Header.h"
#include "gameTile.h"

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

class GameWorld
{
public:
	vector< vector<GameTile*> > tiles;
	
	int gridLength;
	int gridHeight;

	GameWorld();

	static sf::Texture& GetTexture(string const& filename);

private:
	sf::Vector2i exitPos;
	sf::Vector2i playerPos;
	vector<sf::Vector2i> enemyPos;
	
	void setUpInitialState();

	void setUpTiles();
};

#endif