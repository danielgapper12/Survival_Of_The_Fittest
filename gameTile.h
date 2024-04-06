#pragma once

#include "Header.h"

#ifndef GAMETILE_H // prevents annoying warnings
#define GAMETILE_H 

class GameTile
{
public:
	bool isPassable; // can move through it or if wall
	bool isExit; // exits and starts new game

	sf::Vector2f pos; // contains x and y values
	sf::Texture texture;
	sf::Sprite sprite;

	GameTile(string, float, float, bool, bool);

	bool setUpSprite(string);
};

#endif