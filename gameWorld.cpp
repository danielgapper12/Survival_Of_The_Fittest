#include "gameWorld.h"

// GameWorld constructor 
GameWorld::GameWorld()
{
	gridLength = 25;
	gridHeight = 16;
	setUpInitialState();
}

// set up exit and player position 
void GameWorld::setUpInitialState()
{
	playerPos = sf::Vector2i(gridLength - 1, gridHeight - 1);
	setUpTiles();
}

// sets up gameboard tiles, one row at a time  
void GameWorld::setUpTiles()
{
	tiles.clear();

	vector<GameTile*> firstRow; // ptr allows reference to specific tile
	firstRow.push_back(new GameTile("grass.png", 0, 0, false, false)); // not passable and not exit 
	firstRow.push_back(new GameTile("grass.png", 50, 0, false, false)); // door, passable and not exit 
	firstRow.push_back(new GameTile("grass.png", 100, 0, false, false)); // not passable and not exit    
	firstRow.push_back(new GameTile("grass.png", 150, 0, false, false)); // not passable and not exit 
	firstRow.push_back(new GameTile("grass.png", 200, 0, false, false)); // not passable and not exit 
	firstRow.push_back(new GameTile("grass.png", 250, 0, false, false)); // not passable and not exit 
	firstRow.push_back(new GameTile("grass.png", 300, 0, false, false)); // not passable and not exit 
	firstRow.push_back(new GameTile("grass.png", 350, 0, false, false)); // not passable and not exit 

	firstRow.push_back(new GameTile("grass.png", 400, 0, false, false)); // door, passable and exit 
	firstRow.push_back(new GameTile("grass.png", 450, 0, false, false)); // door, passable and exit 
	firstRow.push_back(new GameTile("grass.png", 500, 0, false, false)); // not passable and not exit    
	firstRow.push_back(new GameTile("grass.png", 550, 0, false, false)); // not passable and not exit 
	firstRow.push_back(new GameTile("wall.png", 600, 0, false, false)); // not passable and not exit 
	firstRow.push_back(new GameTile("wall.png", 650, 0, false, false)); // not passable and not exit 
	firstRow.push_back(new GameTile("wall.png", 700, 0, false, false)); // door, passable and exit 
	firstRow.push_back(new GameTile("wall.png", 750, 0, false, false)); // not passable and not exit 

	firstRow.push_back(new GameTile("wall.png", 800, 0, false, false)); // door, passable and exit 
	firstRow.push_back(new GameTile("wall.png", 850, 0, false, false)); // door, passable and exit 
	firstRow.push_back(new GameTile("wall.png", 900, 0, false, false)); // not passable and not exit    
	firstRow.push_back(new GameTile("wall.png", 950, 0, false, false)); // not passable and not exit 
	firstRow.push_back(new GameTile("wall.png", 1000, 0, false, false)); // not passable and not exit 
	firstRow.push_back(new GameTile("wall.png", 1050, 0, false, false)); // not passable and not exit 
	firstRow.push_back(new GameTile("wall.png", 1100, 0, false, false)); // door, passable and exit 
	firstRow.push_back(new GameTile("wall.png", 1150, 0, false, false)); // not passable and not exit 
	firstRow.push_back(new GameTile("wall.png", 1200, 0, false, false)); // not passable and not exit 

	tiles.push_back(firstRow);

	vector<GameTile*> secondRow; // ptr allows reference to specific tile
	secondRow.push_back(new GameTile("grass.png", 0, 50, false, false)); // not passable and not exit 
	secondRow.push_back(new GameTile("grass.png", 50, 50, true, false)); // passable and not exit
	secondRow.push_back(new GameTile("grass.png", 100, 50, true, false)); // passable and not exit 
	secondRow.push_back(new GameTile("grass.png", 150, 50, true, false)); // passable and not exit 
	secondRow.push_back(new GameTile("grass.png", 200, 50, true, false)); // passable and not exit 
	secondRow.push_back(new GameTile("grass.png", 250, 50, true, false)); // passable and not exit 
	secondRow.push_back(new GameTile("grass.png", 300, 50, true, false)); // passable and exit 
	secondRow.push_back(new GameTile("grass.png", 350, 50, true, false)); // passable and not exit 

	secondRow.push_back(new GameTile("grass.png", 400, 50, true, false)); // not passable and not exit 
	secondRow.push_back(new GameTile("grass.png", 450, 50, true, false)); // passable and not exit
	secondRow.push_back(new GameTile("grass.png", 500, 50, true, false)); // passable and not exit 
	secondRow.push_back(new GameTile("grass.png", 550, 50, true, false)); // passable and not exit 
	secondRow.push_back(new GameTile("wall.png", 600, 50, true, false)); // passable and not exit 
	secondRow.push_back(new GameTile("floor.png", 650, 50, true, false)); // passable and not exit 
	secondRow.push_back(new GameTile("floor.png", 700, 50, true, false)); // passable and exit 
	secondRow.push_back(new GameTile("floor.png", 750, 50, true, false)); // passable and not exit 

	secondRow.push_back(new GameTile("floor.png", 800, 50, true, false)); // not passable and not exit 
	secondRow.push_back(new GameTile("floor.png", 850, 50, true, false)); // passable and not exit
	secondRow.push_back(new GameTile("floor.png", 900, 50, true, false)); // passable and not exit 
	secondRow.push_back(new GameTile("floor.png", 950, 50, true, false)); // passable and not exit 
	secondRow.push_back(new GameTile("floor.png", 1000, 50, true, false)); // passable and not exit 
	secondRow.push_back(new GameTile("floor.png", 1050, 50, true, false)); // passable and not exit 
	secondRow.push_back(new GameTile("floor.png", 1100, 50, true, false)); // passable and exit 
	secondRow.push_back(new GameTile("floor.png", 1150, 50, true, false)); // passable and not exit 
	secondRow.push_back(new GameTile("wall.png", 1200, 50, false, false)); // not passable and not exit 


	tiles.push_back(secondRow);

	vector<GameTile*> thirdRow; // ptr allows reference to specific tile
	thirdRow.push_back(new GameTile("grass.png", 0, 100, false, false)); // not passable and not exit 
	thirdRow.push_back(new GameTile("grass.png", 50, 100, true, false)); // passable and not exit 
	thirdRow.push_back(new GameTile("grass.png", 100, 100, true, false)); // passable and not exit 
	thirdRow.push_back(new GameTile("grass.png", 150, 100, true, false)); // passable and not exit 
	thirdRow.push_back(new GameTile("grass.png", 200, 100, true, false)); // passable and not exit 
	thirdRow.push_back(new GameTile("grass.png", 250, 100, true, false)); // passable and not exit 
	thirdRow.push_back(new GameTile("grass.png", 300, 100, true, false)); // passable and not exit 
	thirdRow.push_back(new GameTile("grass.png", 350, 100, true, false)); // passable and not exit 

	thirdRow.push_back(new GameTile("grass.png", 400, 100, true, false)); // not passable and not exit 
	thirdRow.push_back(new GameTile("grass.png", 450, 100, true, false)); // passable and not exit 
	thirdRow.push_back(new GameTile("grass.png", 500, 100, true, false)); // passable and not exit 
	thirdRow.push_back(new GameTile("grass.png", 550, 100, true, false)); // passable and not exit 
	thirdRow.push_back(new GameTile("floor.png", 600, 100, true, false)); // passable and not exit 
	thirdRow.push_back(new GameTile("floor.png", 650, 100, true, false)); // passable and not exit 
	thirdRow.push_back(new GameTile("floor.png", 700, 100, true, false)); // passable and not exit 
	thirdRow.push_back(new GameTile("floor.png", 750, 100, true, false)); // passable and not exit 

	thirdRow.push_back(new GameTile("floor.png", 800, 100, true, false)); // not passable and not exit 
	thirdRow.push_back(new GameTile("floor.png", 850, 100, true, false)); // passable and not exit 
	thirdRow.push_back(new GameTile("floor.png", 900, 100, true, false)); // passable and not exit 
	thirdRow.push_back(new GameTile("floor.png", 950, 100, true, false)); // passable and not exit 
	thirdRow.push_back(new GameTile("floor.png", 1000, 100, true, false)); // passable and not exit 
	thirdRow.push_back(new GameTile("floor.png", 1050, 100, true, false)); // passable and not exit 
	thirdRow.push_back(new GameTile("floor.png", 1100, 100, true, false)); // passable and not exit 
	thirdRow.push_back(new GameTile("floor.png", 1150, 100, true, false)); // passable and not exit 
	thirdRow.push_back(new GameTile("wall.png", 1200, 100, false, false)); // not passable and not exit 


	tiles.push_back(thirdRow);


	vector<GameTile*> fourthRow; // ptr allows reference to specific tile
	fourthRow.push_back(new GameTile("grass.png", 0, 150, false, false)); // not passable and not exit 
	fourthRow.push_back(new GameTile("grass.png", 50, 150, true, false)); // passable and not exit 
	fourthRow.push_back(new GameTile("grass.png", 100, 150, true, false)); // passable and not exit 
	fourthRow.push_back(new GameTile("grass.png", 150, 150, true, false)); // passable and not exit 
	fourthRow.push_back(new GameTile("grass.png", 200, 150, true, false)); // passable and not exit 
	fourthRow.push_back(new GameTile("grass.png", 250, 150, true, false)); // passable and not exit 
	fourthRow.push_back(new GameTile("grass.png", 300, 150, true, false)); // passable and exit 
	fourthRow.push_back(new GameTile("grass.png", 350, 150, true, false)); // passable and not exit 

	fourthRow.push_back(new GameTile("grass.png", 400, 150, true, false)); // not passable and not exit 
	fourthRow.push_back(new GameTile("grass.png", 450, 150, true, false)); // passable and not exit 
	fourthRow.push_back(new GameTile("grass.png", 500, 150, true, false)); // passable and not exit 
	fourthRow.push_back(new GameTile("grass.png", 550, 150, true, false)); // passable and not exit 
	fourthRow.push_back(new GameTile("floor.png", 600, 150, true, false)); // passable and not exit 
	fourthRow.push_back(new GameTile("floor.png", 650, 150, true, false)); // passable and not exit 
	fourthRow.push_back(new GameTile("floor.png", 700, 150, true, false)); // passable and exit 
	fourthRow.push_back(new GameTile("floor.png", 750, 150, true, false)); // passable and not exit 

	fourthRow.push_back(new GameTile("floor.png", 800, 150, true, false)); // not passable and not exit 
	fourthRow.push_back(new GameTile("floor.png", 850, 150, true, false)); // passable and not exit 
	fourthRow.push_back(new GameTile("floor.png", 900, 150, true, false)); // passable and not exit 
	fourthRow.push_back(new GameTile("floor.png", 950, 150, true, false)); // passable and not exit 
	fourthRow.push_back(new GameTile("floor.png", 1000, 150, true, false)); // passable and not exit 
	fourthRow.push_back(new GameTile("floor.png", 1050, 150, true, false)); // passable and not exit 
	fourthRow.push_back(new GameTile("floor.png", 1100, 150, true, false)); // passable and exit 
	fourthRow.push_back(new GameTile("floor.png", 1150, 150, true, false)); // passable and not exit 
	fourthRow.push_back(new GameTile("wall.png", 1200, 150, false, false)); // not passable and not exit 


	tiles.push_back(fourthRow);

	vector<GameTile*> fifthRow; // ptr allows reference to specific tile
	fifthRow.push_back(new GameTile("grass.png", 0, 200, false, false)); // not passable and not exit 
	fifthRow.push_back(new GameTile("grass.png", 50, 200, true, false)); // passable and not exit 
	fifthRow.push_back(new GameTile("grass.png", 100, 200, true, false)); // passable and not exit 
	fifthRow.push_back(new GameTile("grass.png", 150, 200, true, false)); // passable and not exit 
	fifthRow.push_back(new GameTile("grass.png", 200, 200, true, false)); // passable and not exit 
	fifthRow.push_back(new GameTile("grass.png", 250, 200, true, false)); // passable and not exit 
	fifthRow.push_back(new GameTile("grass.png", 300, 200, true, false)); // passable and exit 
	fifthRow.push_back(new GameTile("grass.png", 350, 200, true, false)); // passable and not exit 

	fifthRow.push_back(new GameTile("grass.png", 400, 200, true, false)); // not passable and not exit 
	fifthRow.push_back(new GameTile("grass.png", 450, 200, true, false)); // passable and not exit 
	fifthRow.push_back(new GameTile("grass.png", 500, 200, true, false)); // passable and not exit 
	fifthRow.push_back(new GameTile("grass.png", 550, 200, true, false)); // passable and not exit 
	fifthRow.push_back(new GameTile("floor.png", 600, 200, true, false)); // passable and not exit 
	fifthRow.push_back(new GameTile("floor.png", 650, 200, true, false)); // passable and not exit 
	fifthRow.push_back(new GameTile("floor.png", 700, 200, true, false)); // passable and exit 
	fifthRow.push_back(new GameTile("floor.png", 750, 200, true, false)); // passable and not exit 

	fifthRow.push_back(new GameTile("floor.png", 800, 200, true, false)); // not passable and not exit 
	fifthRow.push_back(new GameTile("floor.png", 850, 200, true, false)); // passable and not exit 
	fifthRow.push_back(new GameTile("floor.png", 900, 200, true, false)); // passable and not exit 
	fifthRow.push_back(new GameTile("floor.png", 950, 200, true, false)); // passable and not exit 
	fifthRow.push_back(new GameTile("floor.png", 1000, 200, true, false)); // passable and not exit 
	fifthRow.push_back(new GameTile("floor.png", 1050, 200, true, false)); // passable and not exit 
	fifthRow.push_back(new GameTile("floor.png", 1100, 200, true, false)); // passable and exit 
	fifthRow.push_back(new GameTile("floor.png", 1150, 200, true, false)); // passable and not exit 
	fifthRow.push_back(new GameTile("wall.png", 1200, 200, false, false)); // not passable and not exit 



	tiles.push_back(fifthRow);

	vector<GameTile*> sixthRow; // ptr allows reference to specific tile
	sixthRow.push_back(new GameTile("grass.png", 0, 250, false, false)); // not passable and not exit 
	sixthRow.push_back(new GameTile("grass.png", 50, 250, true, false)); // passable and not exit 
	sixthRow.push_back(new GameTile("grass.png", 100, 250, true, false)); // passable and not exit 
	sixthRow.push_back(new GameTile("grass.png", 150, 250, true, false)); // passable and not exit 
	sixthRow.push_back(new GameTile("grass.png", 200, 250, true, false)); // passable and not exit 
	sixthRow.push_back(new GameTile("grass.png", 250, 250, true, false)); // passable and not exit 
	sixthRow.push_back(new GameTile("grass.png", 300, 250, true, false)); // passable and exit 
	sixthRow.push_back(new GameTile("grass.png", 350, 250, true, false)); // passable and not exit 

	sixthRow.push_back(new GameTile("grass.png", 400, 250, true, false)); // not passable and not exit 
	sixthRow.push_back(new GameTile("grass.png", 450, 250, true, false)); // passable and not exit 
	sixthRow.push_back(new GameTile("grass.png", 500, 250, true, false)); // passable and not exit 
	sixthRow.push_back(new GameTile("grass.png", 550, 250, true, false)); // passable and not exit 
	sixthRow.push_back(new GameTile("wall.png", 600, 250, true, false)); // passable and not exit 
	sixthRow.push_back(new GameTile("floor.png", 650, 250, true, false)); // passable and not exit 
	sixthRow.push_back(new GameTile("floor.png", 700, 250, true, false)); // passable and exit 
	sixthRow.push_back(new GameTile("floor.png", 750, 250, true, false)); // passable and not exit 

	sixthRow.push_back(new GameTile("floor.png", 800, 250, true, false)); // not passable and not exit 
	sixthRow.push_back(new GameTile("floor.png", 850, 250, true, false)); // passable and not exit 
	sixthRow.push_back(new GameTile("floor.png", 900, 250, true, false)); // passable and not exit 
	sixthRow.push_back(new GameTile("floor.png", 950, 250, true, false)); // passable and not exit 
	sixthRow.push_back(new GameTile("floor.png", 1000, 250, true, false)); // passable and not exit 
	sixthRow.push_back(new GameTile("floor.png", 1050, 250, true, false)); // passable and not exit 
	sixthRow.push_back(new GameTile("floor.png", 1100, 250, true, false)); // passable and exit 
	sixthRow.push_back(new GameTile("floor.png", 1150, 250, true, false)); // passable and not exit 
	sixthRow.push_back(new GameTile("wall.png", 1200, 250, false, false)); // not passable and not exit 


	tiles.push_back(sixthRow);


	vector<GameTile*> seventhRow; // ptr allows reference to specific tile
	seventhRow.push_back(new GameTile("grass.png", 0, 300, false, false)); // not passable and not exit 
	seventhRow.push_back(new GameTile("grass.png", 50, 300, true, false)); // passable and not exit 
	seventhRow.push_back(new GameTile("grass.png", 100, 300, true, false)); // passable and not exit 
	seventhRow.push_back(new GameTile("grass.png", 150, 300, true, false)); // passable and not exit 
	seventhRow.push_back(new GameTile("grass.png", 200, 300, true, false)); // passable and not exit 
	seventhRow.push_back(new GameTile("grass.png", 250, 300, true, false)); // passable and not exit 
	seventhRow.push_back(new GameTile("grass.png", 300, 300, true, false)); // passable and exit 
	seventhRow.push_back(new GameTile("grass.png", 350, 300, true, false)); // passable and not exit 

	seventhRow.push_back(new GameTile("grass.png", 400, 300, true, false)); // not passable and not exit 
	seventhRow.push_back(new GameTile("grass.png", 450, 300, true, false)); // passable and not exit 
	seventhRow.push_back(new GameTile("grass.png", 500, 300, true, false)); // passable and not exit 
	seventhRow.push_back(new GameTile("grass.png", 550, 300, true, false)); // passable and not exit 
	seventhRow.push_back(new GameTile("wall.png", 600, 300, true, false)); // passable and not exit 
	seventhRow.push_back(new GameTile("floor.png", 650, 300, true, false)); // passable and not exit 
	seventhRow.push_back(new GameTile("floor.png", 700, 300, true, false)); // passable and exit 
	seventhRow.push_back(new GameTile("floor.png", 750, 300, true, false)); // passable and not exit 

	seventhRow.push_back(new GameTile("floor.png", 800, 300, true, false)); // not passable and not exit 
	seventhRow.push_back(new GameTile("floor.png", 850, 300, true, false)); // passable and not exit 
	seventhRow.push_back(new GameTile("floor.png", 900, 300, true, false)); // passable and not exit 
	seventhRow.push_back(new GameTile("floor.png", 950, 300, true, false)); // passable and not exit 
	seventhRow.push_back(new GameTile("floor.png", 1000, 300, true, false)); // passable and not exit 
	seventhRow.push_back(new GameTile("floor.png", 1050, 300, true, false)); // passable and not exit 
	seventhRow.push_back(new GameTile("floor.png", 1100, 300, true, false)); // passable and exit 
	seventhRow.push_back(new GameTile("floor.png", 1150, 300, true, false)); // passable and not exit 
	seventhRow.push_back(new GameTile("wall.png", 1200, 300, false, false)); // not passable and not exit 


	tiles.push_back(seventhRow);

	vector<GameTile*> eigthRow; // ptr allows reference to specific tile
	eigthRow.push_back(new GameTile("grass.png", 0, 350, false, false)); // not passable and not exit 
	eigthRow.push_back(new GameTile("grass.png", 50, 350, true, false)); // passable and not exit 
	eigthRow.push_back(new GameTile("grass.png", 100, 350, true, false)); // passable and not exit 
	eigthRow.push_back(new GameTile("grass.png", 150, 350, true, false)); // passable and not exit 
	eigthRow.push_back(new GameTile("grass.png", 200, 350, true, false)); // passable and not exit 
	eigthRow.push_back(new GameTile("grass.png", 250, 350, true, false)); // passable and not exit 
	eigthRow.push_back(new GameTile("grass.png", 300, 350, true, false)); // passable and exit 
	eigthRow.push_back(new GameTile("grass.png", 350, 350, true, false)); // passable and not exit 

	eigthRow.push_back(new GameTile("grass.png", 400, 350, true, false)); // not passable and not exit 
	eigthRow.push_back(new GameTile("grass.png", 450, 350, true, false)); // passable and not exit 
	eigthRow.push_back(new GameTile("grass.png", 500, 350, true, false)); // passable and not exit 
	eigthRow.push_back(new GameTile("grass.png", 550, 350, true, false)); // passable and not exit 
	eigthRow.push_back(new GameTile("wall.png", 600, 350, false, false)); // passable and not exit 
	eigthRow.push_back(new GameTile("wall.png", 650, 350, false, false)); // passable and not exit 
	eigthRow.push_back(new GameTile("wall.png", 700, 350, false, false)); // passable and exit 
	eigthRow.push_back(new GameTile("wall.png", 750, 350, false, false)); // passable and not exit 

	eigthRow.push_back(new GameTile("wall.png", 800, 350, false, false)); // not passable and not exit 
	eigthRow.push_back(new GameTile("wall.png", 850, 350, false, false)); // passable and not exit 
	eigthRow.push_back(new GameTile("wall.png", 900, 350, false, false)); // passable and not exit 
	eigthRow.push_back(new GameTile("wall.png", 950, 350, false, false)); // passable and not exit 
	eigthRow.push_back(new GameTile("wall.png", 1000, 350, false, false)); // passable and not exit 
	eigthRow.push_back(new GameTile("floor.png", 1050, 350, true, false)); // passable and not exit 
	eigthRow.push_back(new GameTile("floor.png", 1100, 350, true, false)); // passable and exit 
	eigthRow.push_back(new GameTile("floor.png", 1150, 350, true, false)); // passable and not exit 
	eigthRow.push_back(new GameTile("wall.png", 1200, 350, false, false)); // not passable and not exit 


	tiles.push_back(eigthRow);

	// rows 9 - 16

	vector<GameTile*> ninthRow; // ptr allows reference to specific tile
	ninthRow.push_back(new GameTile("grass.png", 0, 400, false, false)); // not passable and not exit 
	ninthRow.push_back(new GameTile("grass.png", 50, 400, true, false)); // door, passable and not exit 
	ninthRow.push_back(new GameTile("grass.png", 100, 400, true, false)); // not passable and not exit    
	ninthRow.push_back(new GameTile("grass.png", 150, 400, true, false)); // not passable and not exit 
	ninthRow.push_back(new GameTile("grass.png", 200, 400, true, false)); // not passable and not exit 
	ninthRow.push_back(new GameTile("grass.png", 250, 400, true, false)); // not passable and not exit 
	ninthRow.push_back(new GameTile("grass.png", 300, 400, true, false)); // not passable and not exit 
	ninthRow.push_back(new GameTile("grass.png", 350, 400, true, false)); // not passable and not exit 

	ninthRow.push_back(new GameTile("grass.png", 400, 400, true, false)); // door, passable and not exit 
	ninthRow.push_back(new GameTile("grass.png", 450, 400, true, false)); // door, passable and not exit 
	ninthRow.push_back(new GameTile("grass.png", 500, 400, true, false)); // not passable and not exit    
	ninthRow.push_back(new GameTile("grass.png", 550, 400, true, false)); // not passable and not exit 
	ninthRow.push_back(new GameTile("wall.png", 600, 400, false, false)); // not passable and not exit 
	ninthRow.push_back(new GameTile("floor.png", 650, 400, true, false)); // not passable and not exit 
	ninthRow.push_back(new GameTile("floor.png", 700, 400, true, false)); // door, passable and exit 
	ninthRow.push_back(new GameTile("floor.png", 750, 400, true, false)); // not passable and not exit 

	ninthRow.push_back(new GameTile("floor.png", 800, 400, true, false)); // door, passable and not exit 
	ninthRow.push_back(new GameTile("floor.png", 850, 400, true, false)); // door, passable and not exit 
	ninthRow.push_back(new GameTile("floor.png", 900, 400, true, false)); // not passable and not exit    
	ninthRow.push_back(new GameTile("floor.png", 950, 400, true, false)); // not passable and not exit 
	ninthRow.push_back(new GameTile("floor.png", 1000, 400, true, false)); // not passable and not exit 
	ninthRow.push_back(new GameTile("floor.png", 1050, 400, true, false)); // not passable and not exit 
	ninthRow.push_back(new GameTile("floor.png", 1100, 400, true, false)); // door, passable and exit 
	ninthRow.push_back(new GameTile("floor.png", 1150, 400, true, false)); // not passable and not exit 
	ninthRow.push_back(new GameTile("wall.png", 1200, 400, false, false)); // not passable and not exit 


	tiles.push_back(ninthRow);

	vector<GameTile*> tenthRow; // ptr allows reference to specific tile
	tenthRow.push_back(new GameTile("grass.png", 0, 450, false, false)); // not passable and not exit 
	tenthRow.push_back(new GameTile("grass.png", 50, 450, true, false)); // passable and not exit
	tenthRow.push_back(new GameTile("grass.png", 100, 450, true, false)); // passable and not exit 
	tenthRow.push_back(new GameTile("grass.png", 150, 450, true, false)); // passable and not exit 
	tenthRow.push_back(new GameTile("grass.png", 200, 450, true, false)); // passable and not exit 
	tenthRow.push_back(new GameTile("grass.png", 250, 450, true, false)); // passable and not exit 
	tenthRow.push_back(new GameTile("grass.png", 300, 450, true, false)); // passable and not exit 
	tenthRow.push_back(new GameTile("grass.png", 350, 450, true, false)); // passable and not exit 

	tenthRow.push_back(new GameTile("grass.png", 400, 450, true, false)); // not passable and not exit 
	tenthRow.push_back(new GameTile("grass.png", 450, 450, true, false)); // passable and not exit
	tenthRow.push_back(new GameTile("grass.png", 500, 450, true, false)); // passable and not exit 
	tenthRow.push_back(new GameTile("grass.png", 550, 450, true, false)); // passable and not exit 
	tenthRow.push_back(new GameTile("wall.png", 600, 450, false, false)); // passable and not exit 
	tenthRow.push_back(new GameTile("floor.png", 650, 450, true, false)); // passable and not exit 
	tenthRow.push_back(new GameTile("floor.png", 700, 450, true, false)); // passable and not exit 
	tenthRow.push_back(new GameTile("floor.png", 750, 450, true, false)); // passable and not exit 

	tenthRow.push_back(new GameTile("floor.png", 800, 450, true, false)); // not passable and not exit 
	tenthRow.push_back(new GameTile("floor.png", 850, 450, true, false)); // passable and not exit
	tenthRow.push_back(new GameTile("floor.png", 900, 450, true, false)); // passable and not exit 
	tenthRow.push_back(new GameTile("floor.png", 950, 450, true, false)); // passable and not exit 
	tenthRow.push_back(new GameTile("floor.png", 1000, 450, true, false)); // passable and not exit 
	tenthRow.push_back(new GameTile("floor.png", 1050, 450, true, false)); // passable and not exit 
	tenthRow.push_back(new GameTile("floor.png", 1100, 450, true, false)); // passable and not exit 
	tenthRow.push_back(new GameTile("floor.png", 1150, 450, true, false)); // passable and not exit 
	tenthRow.push_back(new GameTile("wall.png", 1200, 450, false, false)); // not passable and not exit 


	tiles.push_back(tenthRow);

	vector<GameTile*> eleventhRow; // ptr allows reference to specific tile
	eleventhRow.push_back(new GameTile("grass.png", 0, 500, false, false)); // not passable and not exit 
	eleventhRow.push_back(new GameTile("grass.png", 50, 500, true, false)); // passable and not exit 
	eleventhRow.push_back(new GameTile("grass.png", 100, 500, true, false)); // passable and not exit 
	eleventhRow.push_back(new GameTile("grass.png", 150, 500, true, false)); // passable and not exit 
	eleventhRow.push_back(new GameTile("grass.png", 200, 500, true, false)); // passable and not exit 
	eleventhRow.push_back(new GameTile("grass.png", 250, 500, true, false)); // passable and not exit 
	eleventhRow.push_back(new GameTile("grass.png", 300, 500, true, false)); // passable and not exit 
	eleventhRow.push_back(new GameTile("grass.png", 350, 500, true, false)); // passable and not exit 

	eleventhRow.push_back(new GameTile("grass.png", 400, 500, true, false)); // not passable and not exit 
	eleventhRow.push_back(new GameTile("grass.png", 450, 500, true, false)); // passable and not exit 
	eleventhRow.push_back(new GameTile("grass.png", 500, 500, true, false)); // passable and not exit 
	eleventhRow.push_back(new GameTile("grass.png", 550, 500, true, false)); // passable and not exit 
	eleventhRow.push_back(new GameTile("floor.png", 600, 500, true, false)); // passable and not exit 
	eleventhRow.push_back(new GameTile("floor.png", 650, 500, true, false)); // passable and not exit 
	eleventhRow.push_back(new GameTile("floor.png", 700, 500, true, false)); // passable and not exit 
	eleventhRow.push_back(new GameTile("floor.png", 750, 500, true, false)); // passable and not exit 

	eleventhRow.push_back(new GameTile("floor.png", 800, 500, true, false)); // not passable and not exit 
	eleventhRow.push_back(new GameTile("floor.png", 850, 500, true, false)); // passable and not exit 
	eleventhRow.push_back(new GameTile("floor.png", 900, 500, true, false)); // passable and not exit 
	eleventhRow.push_back(new GameTile("floor.png", 950, 500, true, false)); // passable and not exit 
	eleventhRow.push_back(new GameTile("floor.png", 1000, 500, true, false)); // passable and not exit 
	eleventhRow.push_back(new GameTile("floor.png", 1050, 500, true, false)); // passable and not exit 
	eleventhRow.push_back(new GameTile("floor.png", 1100, 500, true, false)); // passable and not exit 
	eleventhRow.push_back(new GameTile("floor.png", 1150, 500, true, false)); // passable and not exit 
	eleventhRow.push_back(new GameTile("wall.png", 1200, 500, false, false)); // not passable and not exit 


	tiles.push_back(eleventhRow);


	vector<GameTile*> twelthRow; // ptr allows reference to specific tile
	twelthRow.push_back(new GameTile("grass.png", 0, 550, false, false)); // not passable and not exit 
	twelthRow.push_back(new GameTile("grass.png", 50, 550, true, false)); // passable and not exit 
	twelthRow.push_back(new GameTile("grass.png", 100, 550, true, false)); // passable and not exit 
	twelthRow.push_back(new GameTile("grass.png", 150, 550, true, false)); // passable and not exit 
	twelthRow.push_back(new GameTile("grass.png", 200, 550, true, false)); // passable and not exit 
	twelthRow.push_back(new GameTile("grass.png", 250, 550, true, false)); // passable and not exit 
	twelthRow.push_back(new GameTile("grass.png", 300, 550, true, false)); // passable and exit 
	twelthRow.push_back(new GameTile("grass.png", 350, 550, true, false)); // passable and not exit 

	twelthRow.push_back(new GameTile("grass.png", 400, 550, true, false)); // not passable and not exit 
	twelthRow.push_back(new GameTile("grass.png", 450, 550, true, false)); // passable and not exit 
	twelthRow.push_back(new GameTile("grass.png", 500, 550, true, false)); // passable and not exit 
	twelthRow.push_back(new GameTile("grass.png", 550, 550, true, false)); // passable and not exit 
	twelthRow.push_back(new GameTile("floor.png", 600, 550, true, false)); // passable and not exit 
	twelthRow.push_back(new GameTile("floor.png", 650, 550, true, false)); // passable and not exit 
	twelthRow.push_back(new GameTile("floor.png", 700, 550, true, false)); // passable and exit 
	twelthRow.push_back(new GameTile("floor.png", 750, 550, true, false)); // passable and not exit 

	twelthRow.push_back(new GameTile("floor.png", 800, 550, true, false)); // not passable and not exit 
	twelthRow.push_back(new GameTile("floor.png", 850, 550, true, false)); // passable and not exit 
	twelthRow.push_back(new GameTile("floor.png", 900, 550, true, false)); // passable and not exit 
	twelthRow.push_back(new GameTile("floor.png", 950, 550, true, false)); // passable and not exit 
	twelthRow.push_back(new GameTile("floor.png", 1000, 550, true, false)); // passable and not exit 
	twelthRow.push_back(new GameTile("floor.png", 1050, 550, true, false)); // passable and not exit 
	twelthRow.push_back(new GameTile("floor.png", 1100, 550, true, false)); // passable and exit 
	twelthRow.push_back(new GameTile("floor.png", 1150, 550, true, false)); // passable and not exit 
	twelthRow.push_back(new GameTile("wall.png", 1200, 550, false, false)); // not passable and not exit 


	tiles.push_back(twelthRow);

	vector<GameTile*> thirteenthRow; // ptr allows reference to specific tile
	thirteenthRow.push_back(new GameTile("grass.png", 0, 600, false, false)); // not passable and not exit 
	thirteenthRow.push_back(new GameTile("grass.png", 50, 600, true, false)); // passable and not exit 
	thirteenthRow.push_back(new GameTile("grass.png", 100, 600, true, false)); // passable and not exit 
	thirteenthRow.push_back(new GameTile("grass.png", 150, 600, true, false)); // passable and not exit 
	thirteenthRow.push_back(new GameTile("grass.png", 200, 600, true, false)); // passable and not exit 
	thirteenthRow.push_back(new GameTile("grass.png", 250, 600, true, false)); // passable and not exit 
	thirteenthRow.push_back(new GameTile("grass.png", 300, 600, true, false)); // passable and exit 
	thirteenthRow.push_back(new GameTile("grass.png", 350, 600, true, false)); // passable and not exit 

	thirteenthRow.push_back(new GameTile("grass.png", 400, 600, true, false)); // not passable and not exit 
	thirteenthRow.push_back(new GameTile("grass.png", 450, 600, true, false)); // passable and not exit 
	thirteenthRow.push_back(new GameTile("grass.png", 500, 600, true, false)); // passable and not exit 
	thirteenthRow.push_back(new GameTile("grass.png", 550, 600, true, false)); // passable and not exit 
	thirteenthRow.push_back(new GameTile("floor.png", 600, 600, true, false)); // passable and not exit 
	thirteenthRow.push_back(new GameTile("floor.png", 650, 600, true, false)); // passable and not exit 
	thirteenthRow.push_back(new GameTile("floor.png", 700, 600, true, false)); // passable and exit 
	thirteenthRow.push_back(new GameTile("floor.png", 750, 600, true, false)); // passable and not exit 

	thirteenthRow.push_back(new GameTile("floor.png", 800, 600, true, false)); // not passable and not exit 
	thirteenthRow.push_back(new GameTile("floor.png", 850, 600, true, false)); // passable and not exit 
	thirteenthRow.push_back(new GameTile("floor.png", 900, 600, true, false)); // passable and not exit 
	thirteenthRow.push_back(new GameTile("floor.png", 950, 600, true, false)); // passable and not exit 
	thirteenthRow.push_back(new GameTile("floor.png", 1000, 600, true, false)); // passable and not exit 
	thirteenthRow.push_back(new GameTile("floor.png", 1050, 600, true, false)); // passable and not exit 
	thirteenthRow.push_back(new GameTile("floor.png", 1100, 600, true, false)); // passable and exit 
	thirteenthRow.push_back(new GameTile("floor.png", 1150, 600, true, false)); // passable and not exit 
	thirteenthRow.push_back(new GameTile("wall.png", 1200, 600, false, false)); // not passable and not exit 



	tiles.push_back(thirteenthRow);

	vector<GameTile*> fourteenthRow; // ptr allows reference to specific tile
	fourteenthRow.push_back(new GameTile("grass.png", 0, 650, false, false)); // not passable and not exit 
	fourteenthRow.push_back(new GameTile("grass.png", 50, 650, true, false)); // passable and not exit 
	fourteenthRow.push_back(new GameTile("grass.png", 100, 650, true, false)); // passable and not exit 
	fourteenthRow.push_back(new GameTile("grass.png", 150, 650, true, false)); // passable and not exit 
	fourteenthRow.push_back(new GameTile("grass.png", 200, 650, true, false)); // passable and not exit 
	fourteenthRow.push_back(new GameTile("grass.png", 250, 650, true, false)); // passable and not exit 
	fourteenthRow.push_back(new GameTile("grass.png", 300, 650, true, false)); // passable and exit 
	fourteenthRow.push_back(new GameTile("grass.png", 350, 650, true, false)); // passable and not exit 

	fourteenthRow.push_back(new GameTile("grass.png", 400, 650, true, false)); // not passable and not exit 
	fourteenthRow.push_back(new GameTile("grass.png", 450, 650, true, false)); // passable and not exit 
	fourteenthRow.push_back(new GameTile("grass.png", 500, 650, true, false)); // passable and not exit 
	fourteenthRow.push_back(new GameTile("grass.png", 550, 650, true, false)); // passable and not exit 
	fourteenthRow.push_back(new GameTile("wall.png", 600, 650, false, false)); // passable and not exit 
	fourteenthRow.push_back(new GameTile("floor.png", 650, 650, true, false)); // passable and not exit 
	fourteenthRow.push_back(new GameTile("floor.png", 700, 650, true, false)); // passable and exit 
	fourteenthRow.push_back(new GameTile("floor.png", 750, 650, true, false)); // passable and not exit 

	fourteenthRow.push_back(new GameTile("floor.png", 800, 650, true, false)); // not passable and not exit 
	fourteenthRow.push_back(new GameTile("floor.png", 850, 650, true, false)); // passable and not exit 
	fourteenthRow.push_back(new GameTile("floor.png", 900, 650, true, false)); // passable and not exit 
	fourteenthRow.push_back(new GameTile("floor.png", 950, 650, true, false)); // passable and not exit 
	fourteenthRow.push_back(new GameTile("floor.png", 1000, 650, true, false)); // passable and not exit 
	fourteenthRow.push_back(new GameTile("floor.png", 1050, 650, true, false)); // passable and not exit 
	fourteenthRow.push_back(new GameTile("floor.png", 1100, 650, true, false)); // passable and exit 
	fourteenthRow.push_back(new GameTile("floor.png", 1150, 650, true, false)); // passable and not exit 
	fourteenthRow.push_back(new GameTile("wall.png", 1200, 650, false, false)); // not passable and not exit 

	tiles.push_back(fourteenthRow);


	vector<GameTile*> fiftheenthRow; // ptr allows reference to specific tile
	fiftheenthRow.push_back(new GameTile("grass.png", 0, 700, false, false)); // not passable and not exit 
	fiftheenthRow.push_back(new GameTile("grass.png", 50, 700, true, false)); // passable and not exit 
	fiftheenthRow.push_back(new GameTile("grass.png", 100, 700, true, false)); // passable and not exit 
	fiftheenthRow.push_back(new GameTile("grass.png", 150, 700, true, false)); // passable and not exit 
	fiftheenthRow.push_back(new GameTile("grass.png", 200, 700, true, false)); // passable and not exit 
	fiftheenthRow.push_back(new GameTile("grass.png", 250, 700, true, false)); // passable and not exit 
	fiftheenthRow.push_back(new GameTile("grass.png", 300, 700, true, false)); // passable and exit 
	fiftheenthRow.push_back(new GameTile("grass.png", 350, 700, true, false)); // passable and not exit 

	fiftheenthRow.push_back(new GameTile("grass.png", 400, 700, true, false)); // not passable and not exit 
	fiftheenthRow.push_back(new GameTile("grass.png", 450, 700, true, false)); // passable and not exit 
	fiftheenthRow.push_back(new GameTile("grass.png", 500, 700, true, false)); // passable and not exit 
	fiftheenthRow.push_back(new GameTile("grass.png", 550, 700, true, false)); // passable and not exit 
	fiftheenthRow.push_back(new GameTile("wall.png", 600, 700, false, false)); // passable and not exit 
	fiftheenthRow.push_back(new GameTile("floor.png", 650, 700, true, false)); // passable and not exit 
	fiftheenthRow.push_back(new GameTile("floor.png", 700, 700, true, false)); // passable and exit 
	fiftheenthRow.push_back(new GameTile("floor.png", 750, 700, true, false)); // passable and not exit 

	fiftheenthRow.push_back(new GameTile("floor.png", 800, 700, true, false)); // not passable and not exit 
	fiftheenthRow.push_back(new GameTile("floor.png", 850, 700, true, false)); // passable and not exit 
	fiftheenthRow.push_back(new GameTile("floor.png", 900, 700, true, false)); // passable and not exit 
	fiftheenthRow.push_back(new GameTile("floor.png", 950, 700, true, false)); // passable and not exit 
	fiftheenthRow.push_back(new GameTile("floor.png", 1000, 700, true, false)); // passable and not exit 
	fiftheenthRow.push_back(new GameTile("floor.png", 1050, 700, true, false)); // passable and not exit 
	fiftheenthRow.push_back(new GameTile("floor.png", 1100, 700, true, false)); // passable and exit 
	fiftheenthRow.push_back(new GameTile("floor.png", 1150, 700, true, false)); // passable and not exit 
	fiftheenthRow.push_back(new GameTile("wall.png", 1200, 700, false, false)); // not passable and not exit 


	tiles.push_back(fiftheenthRow);

	vector<GameTile*> sixteenthRow; // ptr allows reference to specific tile
	sixteenthRow.push_back(new GameTile("grass.png", 0, 750, false, false)); // not passable and not exit 
	sixteenthRow.push_back(new GameTile("grass.png", 50, 750, false, false)); // passable and not exit 
	sixteenthRow.push_back(new GameTile("grass.png", 100, 750, false, false)); // passable and not exit 
	sixteenthRow.push_back(new GameTile("grass.png", 150, 750, false, false)); // passable and not exit 
	sixteenthRow.push_back(new GameTile("grass.png", 200, 750, false, false)); // passable and not exit 
	sixteenthRow.push_back(new GameTile("grass.png", 250, 750, false, false)); // passable and not exit 
	sixteenthRow.push_back(new GameTile("grass.png", 300, 750, false, false)); // passable and exit 
	sixteenthRow.push_back(new GameTile("grass.png", 350, 750, false, false)); // passable and not exit 

	sixteenthRow.push_back(new GameTile("grass.png", 400, 750, false, false)); // not passable and not exit 
	sixteenthRow.push_back(new GameTile("grass.png", 450, 750, false, false)); // passable and not exit 
	sixteenthRow.push_back(new GameTile("grass.png", 500, 750, false, false)); // passable and not exit 
	sixteenthRow.push_back(new GameTile("grass.png", 550, 750, false, false)); // passable and not exit 
	sixteenthRow.push_back(new GameTile("wall.png", 600, 750, false, false)); // passable and not exit 
	sixteenthRow.push_back(new GameTile("wall.png", 650, 750, false, false)); // passable and not exit 
	sixteenthRow.push_back(new GameTile("wall.png", 700, 750, false, false)); // passable and exit 
	sixteenthRow.push_back(new GameTile("wall.png", 750, 750, false, false)); // passable and not exit 

	sixteenthRow.push_back(new GameTile("wall.png", 800, 750, false, false)); // not passable and not exit 
	sixteenthRow.push_back(new GameTile("wall.png", 850, 750, false, false)); // passable and not exit 
	sixteenthRow.push_back(new GameTile("wall.png", 900, 750, false, false)); // passable and not exit 
	sixteenthRow.push_back(new GameTile("wall.png", 950, 750, false, false)); // passable and not exit 
	sixteenthRow.push_back(new GameTile("wall.png", 1000, 750, false, false)); // passable and not exit 
	sixteenthRow.push_back(new GameTile("wall.png", 1050, 750, false, false)); // passable and not exit 
	sixteenthRow.push_back(new GameTile("wall.png", 1100, 750, false, false)); // passable and exit 
	sixteenthRow.push_back(new GameTile("wall.png", 1150, 750, false, false)); // passable and not exit 
	sixteenthRow.push_back(new GameTile("wall.png", 1200, 750, false, false)); // not passable and not exit 

	tiles.push_back(sixteenthRow);
}