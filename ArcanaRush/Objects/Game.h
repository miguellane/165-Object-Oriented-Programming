
#ifndef GAME_H
#define GAME_H

# include <vector>

# include "Entity.h"
# include "Character.h"
# include "Boss.h"
# include "Bullet.h"

class Game{
	float score;
	bool bossFight;
public:
	Character* mc;
	Mob* dummy;
	std::vector<Bullet*> mcShots;
	Boss* boss;
	std::vector<Mob*> enemies;
	std::vector<Bullet*> shots;

//	float timer; maybe
//	float background;

	Game();
	void update();
	void draw();
	bool checkCollisions(const Entity& bull, const Entity& mob);
	bool checkBounds(float x, float y);

	void wave1();
	void wave2();
	void midBoss();
	void wave3();
	void finBoss();
};
#endif