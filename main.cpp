#include "Header.h"
#include "character.h"
#include "coin.h"
#include "bullet.h"
#include "Zombie.h"
#include "gameTile.h"
#include "gameWorld.h"


int main(void)
{
	// initializes window 
	sf::RenderWindow window(sf::VideoMode(1250, 800), "Trouble in P-Town!");
	window.setFramerateLimit(60);
	GameWorld gameWorld = GameWorld();

	// sprites
	sf::Texture andy;	// usersprite

	// loads file from resource files
	if (!andy.loadFromFile("Andycircle.PNG"))
	{
		std::cout << "could not load" << endl;
		return 0;
	}

	sf::Sprite userSprite;
	userSprite.setTexture(andy);
	userSprite.scale(sf::Vector2f(0.4,0.4));

	sf::Texture among;	// amoung us sprite
	
	// loads file from resource files
	if (!among.loadFromFile("AmongUsCharacter.PNG"))
	{
		std::cout << "could not load" << endl;
		return 0;
	}
	sf::Sprite amongSprite;
	amongSprite.setTexture(among);
	amongSprite.scale(sf::Vector2f(0.18, 0.18));

	sf::Texture gus;	// gus sprite

	// loads file from resource files
	if (!gus.loadFromFile("gus.PNG"))
	{
		std::cout << "could not load" << endl;
		return 0;
	}
	sf::Sprite gusSprite;
	gusSprite.setTexture(gus);
	gusSprite.scale(sf::Vector2f(0.21, 0.21));

	sf::Texture jimmy;	// playoff Jimmy Butler sprite

	// loads file from resource files
	if (!jimmy.loadFromFile("jimmy buckets.PNG"))
	{
		std::cout << "could not load" << endl;
		return 0;
	}
	sf::Sprite jimmySprite;
	jimmySprite.setTexture(jimmy);
	jimmySprite.scale(sf::Vector2f(0.11, 0.11));

	sf::Texture uw;		// uw husky sprite

	// loads file from resource files
	if (!uw.loadFromFile("husky.PNG"))
	{
		std::cout << "could not load" << endl;
		return 0;
	}
	sf::Sprite uwSprite;
	uwSprite.setTexture(uw);
	uwSprite.scale(sf::Vector2f(0.09, 0.09));

	sf::Texture john;		//fortnite john wick sprite

	// loads file from resource files
	if (!john.loadFromFile("johnwick.PNG"))
	{
		std::cout << "could not load" << endl;
		return 0;
	}
	sf::Sprite johnSprite;
	johnSprite.setTexture(john);
	johnSprite.scale(sf::Vector2f(0.22, 0.22));
	// user
	Character user({30.f});
	user.setPos({ 200,400 });
	
	// movement
	float userSpeed = 4.5f;
	float diagonalSpeed = 0.0f;
	float playerSpeedCap = 9.0;
	
	diagonalSpeed = sqrtf(powf(userSpeed,2.0) / 2.0);

	// Zombie

	float zombieSpeedCap = 3.5;
	Zombie zomb1({30.f});
	zomb1.setPos({500,-650});
	Zombie zomb2({ 30.f });
	zomb2.setPos({ -650,-100 });
	Zombie zomb3({ 30.f });
	zomb3.setPos({ 500,1450 });
	Zombie zomb4({ 30.f });
	zomb4.setPos({ -300,1240 });
	Zombie zomb5({ 30.f });
	zomb5.setPos({ -700,600 });

	// coin/ammo drop object
	std::vector<Coin*> coinVec;
	Coin coin1({ 10 });
	coinVec.push_back(&coin1);
	srand((unsigned int)time(NULL));
	float ammoSpawnX = 0.0;
	float ammoSpawnY = 0.0;
	ammoSpawnX = (rand() % 1100);
	ammoSpawnY = (rand() % 750);
	float whenAmmoRespawns = 0.0;
	coin1.setPos({ ammoSpawnX, ammoSpawnY });

	// score object
	sf::Font stencil;	// name of font
	stencil.loadFromFile("arial.ttf");
	int score = 0;
	int ammoCount = 8;
	sf::Text lblScore;
	sf::Text AmmoBoard;
	sf::Text GameOver;

	bool updateScore = false;

	std::ostringstream ssGameOver;
	std::ostringstream ssScore;
	std::ostringstream ssAmmo;
	ssScore << "Score: " << score;
	ssAmmo << "Ammo: " << ammoCount;
	ssGameOver << "GAME OVER";

	// scoreboard
	lblScore.setCharacterSize(30);
	lblScore.setPosition({ 10,10 });
	lblScore.setFont(stencil);
	lblScore.setString(ssScore.str());

	// ammo board
	AmmoBoard.setCharacterSize(30);
	AmmoBoard.setPosition({ 600,10 });
	AmmoBoard.setFont(stencil);
	AmmoBoard.setString(ssAmmo.str());
	
	// game over print
	GameOver.setCharacterSize(120);
	GameOver.setPosition({ 220,400 });
	GameOver.setFont(stencil);
	
	// bullet
	sf:: Vector2f playerCenter;
	sf::Vector2f MousePos;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
	Bullet b1;
	std::vector<Bullet> bullets;
	bullets.push_back(Bullet(b1));

	// game loop, runs while window is open 
	while (window.isOpen())
	{
		sf::Event event;
		 
		// user hits right wall
		if (user.getPos().x > 1150)
		{
			// user can not move right
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				user.move({ -userSpeed, 0.f });
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				user.move({ 0.f, -userSpeed });
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				user.move({ 0.f, userSpeed });
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				user.move({ -diagonalSpeed, -diagonalSpeed });
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				user.move({ -diagonalSpeed, diagonalSpeed });
			}
		}
		// user hits left boundary
		else if (user.getPos().x < 0)
		{
			// user can not move left
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				user.move({ userSpeed, 0.f });
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				user.move({ 0.f, -userSpeed });
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				user.move({ 0.f, userSpeed });
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				user.move({ diagonalSpeed, -diagonalSpeed });
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				user.move({ diagonalSpeed, diagonalSpeed });
			}
		}

		// user on left half of screen (outside)
		else if (user.getPos().x < 550)
		{
			// user hits bottom boundary
			if (user.getPos().y > 750)
			{
				// user can not move down
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					user.move({ 0.f, -userSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					user.move({ userSpeed, 0.f });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					user.move({ -userSpeed, 0.f });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					user.move({ -diagonalSpeed, -diagonalSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					user.move({ diagonalSpeed, -diagonalSpeed });
				}
			}
			// user hits top boundary
			else if (user.getPos().y < 0)
			{
				// user can not move up
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					user.move({ 0.f, userSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					user.move({ userSpeed, 0.f });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					user.move({ -userSpeed, 0.f });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					user.move({ -diagonalSpeed, diagonalSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					user.move({ diagonalSpeed, diagonalSpeed });
				}
			}
			else {
				// user can move in any direction
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					user.move({ 0.f, -userSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					user.move({ 0.f, userSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					user.move({ -userSpeed, 0.f });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					user.move({ userSpeed, 0.f });
				}

				// diagonal movement
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					user.move({ -diagonalSpeed, -diagonalSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					user.move({ diagonalSpeed, -diagonalSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					user.move({ diagonalSpeed, diagonalSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					user.move({ -diagonalSpeed, diagonalSpeed });
				}
			}
		}
		// user on right half of screen (inside) 
		else
		{
			// user hits right boundary
			if (user.getPos().x > 1150)
			{
				// user can not move right
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					user.move({ -userSpeed, 0.f });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					user.move({ 0.f, -userSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					user.move({ 0.f, userSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					user.move({ -diagonalSpeed, -diagonalSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					user.move({ -diagonalSpeed, diagonalSpeed });
				}
			}
			// user hits bottom boundary
			if (user.getPos().y > 700)
			{
				// user can not move down
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					user.move({ 0.f, -userSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					user.move({ userSpeed, 0.f });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					user.move({ -userSpeed, 0.f });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					user.move({ -diagonalSpeed, -diagonalSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					user.move({ diagonalSpeed, -diagonalSpeed });
				}
			}
			// user hits top boundary
			else if (user.getPos().y < 50)
			{
				// user can not move up
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					user.move({ 0.f, userSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					user.move({ userSpeed, 0.f });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					user.move({ -userSpeed, 0.f });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					user.move({ -diagonalSpeed, diagonalSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					user.move({ diagonalSpeed, diagonalSpeed });
				}
			}
			else {
				// user can move in any direction
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					user.move({ 0.f, -userSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					user.move({ 0.f, userSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					user.move({ -userSpeed, 0.f });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					user.move({ userSpeed, 0.f });
				}
				// diagonal movement
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					user.move({ -diagonalSpeed, -diagonalSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					user.move({ diagonalSpeed, -diagonalSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					user.move({ diagonalSpeed, diagonalSpeed });
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					user.move({ -diagonalSpeed, diagonalSpeed });
				}
			}
		}

		// event loop
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// update position
		playerCenter = sf::Vector2f(user.getPos().x + 30, user.getPos().y + 30); // locate the player
		MousePos = sf::Vector2f(sf::Mouse::getPosition(window));  //locate mouse position
		aimDir = MousePos - playerCenter;
		aimDirNorm = aimDir / sqrtf(pow(aimDir.x, 2) + pow(aimDir.y, 2));  //linear algebra to get the normal line for the aim direction 

		// zombie following logic 
		zomb1.character.move(ZombieMovement(zomb1, playerCenter));
		zomb2.character.move(ZombieMovement(zomb2, playerCenter));
		zomb3.character.move(ZombieMovement(zomb3, playerCenter));
		zomb4.character.move(ZombieMovement(zomb4, playerCenter));
		zomb5.character.move(ZombieMovement(zomb5, playerCenter));

		// sprite position
		userSprite.setPosition(user.getPos().x-10, user.getPos().y-10);
		amongSprite.setPosition(zomb1.getPos().x-6, zomb1.getPos().y-6);
		gusSprite.setPosition(zomb2.getPos().x-6, zomb2.getPos().y-6);
		jimmySprite.setPosition(zomb3.getPos().x-6, zomb3.getPos().y-6);
		uwSprite.setPosition(zomb4.getPos().x-6, zomb4.getPos().y-6);
		johnSprite.setPosition(zomb5.getPos().x - 6, zomb5.getPos().y - 6);
		//coin Logic:   
		for (int i = 0; i < coinVec.size(); i++) 
		{
			if (user.CollidingWithCoin(coinVec[i])) 
			{
				coinVec[i]->setPos({ 30000, 30000 });
				ammoCount = 8;
				ssAmmo.str("");
				ssAmmo << "Ammo: " << ammoCount;
				AmmoBoard.setString(ssAmmo.str());
				whenAmmoRespawns = (rand() % 4) + 4.0; //randomly choses when the next ammo drop is
				ammoSpawnX = respawnPositionX();
				ammoSpawnY = respawnPositionY();
			}

			// zombie hits coin
			if (zomb1.CollidingWithCoin(coinVec[i])) 
			{					  
				ammoSpawnX = respawnPositionX();
				ammoSpawnY = respawnPositionY();
				coin1.setPos({ ammoSpawnX, ammoSpawnY });
			}
			else if (zomb2.CollidingWithCoin(coinVec[i])) 
			{				
				ammoSpawnX = respawnPositionX();
				ammoSpawnY = respawnPositionY();
				coin1.setPos({ ammoSpawnX, ammoSpawnY });

			}
			else if (zomb3.CollidingWithCoin(coinVec[i])) 
			{				
				ammoSpawnX = respawnPositionX();
				ammoSpawnY = respawnPositionY();
				coin1.setPos({ ammoSpawnX, ammoSpawnY });				
			}
			else if (zomb4.CollidingWithCoin(coinVec[i])) 
			{				
				ammoSpawnX = respawnPositionX();
				ammoSpawnY = respawnPositionY();
				coin1.setPos({ ammoSpawnX, ammoSpawnY });
			}
			else if (zomb5.CollidingWithBullet(bullets[i])) 
			{
				ammoSpawnX = respawnPositionX();
				ammoSpawnY = respawnPositionY();
				coin1.setPos({ ammoSpawnX, ammoSpawnY });				
			}
		}
		
		// ammo respawn
		if (whenAmmoRespawns == ammoCount) 
		{
			coin1.setPos({ ammoSpawnX, ammoSpawnY });
		}

		// zombie respawn logic 
		for (size_t i = 0; i < bullets.size(); i++) 
		{
			if (zomb1.CollidingWithBullet(bullets[i])) 
			{
				zomb1.setPos({ 1300, 900 });		    // set zombie respawn location
				bullets.erase(bullets.begin() + i); // bullet disapears 
				updateScore = true;
				if (zomb1.maxSpeed < zombieSpeedCap) { //increase zombie speed if they die
					zomb1.maxSpeed = zomb1.maxSpeed + 0.05;
				}

			}
			else if (zomb2.CollidingWithBullet(bullets[i])) 
			{
				zomb2.setPos({ 1650, 100 });		    // set zombie respawn location
				bullets.erase(bullets.begin() + i); // bullet disapears 
				updateScore = true;
				if (zomb2.maxSpeed < zombieSpeedCap) {
					zomb2.maxSpeed = zomb2.maxSpeed + 0.05;
				}
			}
			else if (zomb3.CollidingWithBullet(bullets[i])) 
			{
				zomb3.setPos({ 400,-500 });		    // set zombie respawn location
				bullets.erase(bullets.begin() + i); // bullet disapears 
				updateScore = true;
				if (zomb3.maxSpeed < zombieSpeedCap) {
					zomb3.maxSpeed = zomb3.maxSpeed + 0.05;
				}
			}
			else if (zomb4.CollidingWithBullet(bullets[i])) 
			{
				zomb4.setPos({ -300, 100 });		    // set zombie respawn location
				bullets.erase(bullets.begin() + i); // bullet disapears 
				updateScore = true;
				if (zomb4.maxSpeed < zombieSpeedCap) {
					zomb4.maxSpeed = zomb4.maxSpeed + 0.05;
				}
			}
			else if (zomb5.CollidingWithBullet(bullets[i])) 
			{
				zomb5.setPos({ -300, 400 });		    // set zombie respawn location
				bullets.erase(bullets.begin() + i); // bullet disapears 
				updateScore = true;
				if (zomb5.maxSpeed < zombieSpeedCap) {
					zomb5.maxSpeed = zomb5.maxSpeed + 0.05;
				}
			}
		}

		if (updateScore == true) 
		{
			score = score + 100;    //updates the score
			ssScore.str("");
			ssScore << "Score: " << score;
			lblScore.setString(ssScore.str());
			updateScore = false;

			if(userSpeed > playerSpeedCap)  //increase speed of player based on score
			{	
				userSpeed = userSpeed + 0.03;
			}
		}

		// zombie hits the player ends game
		if (zomb1.CollidingWithZombie(user)|| zomb2.CollidingWithZombie(user)
			||zomb3.CollidingWithZombie(user)||zomb4.CollidingWithZombie(user)||zomb5.CollidingWithZombie(user)) 
			{
			GameOver.setString(ssGameOver.str());
			lblScore.setCharacterSize(80);
			lblScore.setPosition({ 250,100 });
			ssScore.str("");
			ssScore << "FINAL SCORE: " << score;
			lblScore.setString(ssScore.str());
			userSpeed = 0.0;   //changes speed to zero so you cannot move after game ends
			diagonalSpeed = 0.0;
			ammoCount = 0;
		}
		
		//shooting
		window.setKeyRepeatEnabled(false);
		static bool lock_click;

		if (event.type == sf::Event::MouseButtonPressed && ammoCount > 0) // Mouse button Pressed
		{
			if (event.mouseButton.button == sf::Mouse::Left && lock_click != true) 
			{
				b1.shape.setPosition(playerCenter);  //set the bullet to come from the player center
				b1.currentVelocity = aimDirNorm * b1.maxSpeed;  

				bullets.push_back(Bullet(b1));
				lock_click = true;
				ammoCount--;
				ssAmmo.str("");                         //ammo board update
				ssAmmo << "Ammo: " << ammoCount;
				AmmoBoard.setString(ssAmmo.str());
			}
		}

		if (event.type == sf::Event::MouseButtonReleased) // Mouse button Released 
		{
			if (event.mouseButton.button == sf::Mouse::Left) 
			{
				lock_click = false;
			}
		}

		for (size_t i = 0; i < bullets.size(); i++) 
		{   
			bullets[i].shape.move(bullets[i].currentVelocity); // fires the bullet

			if (bullets[i].shape.getPosition().x < 0 || bullets[i].shape.getPosition().y < 0 || 
				bullets[i].shape.getPosition().x > window.getSize().x ||
				bullets[i].shape.getPosition().x > window.getSize().x) 	//erases the bullet if it leaves the bounds 
				{
				bullets.erase(bullets.begin() + i);
			}
		}

		// draw
		window.clear();

		// prints gameboard with each tile
		for (int i = 0; i < gameWorld.gridHeight; i++)
		{
			for (int j = 0; j < gameWorld.gridLength; j++) 
			{
				window.draw(gameWorld.tiles[i][j]->sprite);
			}	
		}

		coin1.drawTo(window);
		window.draw(lblScore);
		window.draw(AmmoBoard);
		window.draw(GameOver);
		user.drawTo(window);
		zomb1.drawTo(window);
		zomb2.drawTo(window);
		zomb3.drawTo(window);
		zomb4.drawTo(window);
		zomb5.drawTo(window);
		window.draw(userSprite);
		window.draw(amongSprite);
		window.draw(gusSprite);
		window.draw(jimmySprite);
		window.draw(uwSprite);
		window.draw(johnSprite);
		// draw Bullets
		for (size_t i = 0; i < bullets.size(); i++) 
		{
			window.draw(bullets[i].shape);
		}

		// displays to window
		window.display();
	}

	return 0;
}





