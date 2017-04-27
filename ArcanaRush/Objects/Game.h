
#ifndef GAME_H
#define GAME_H

# include <vector>

# include "Entity.h"
# include "Character.h"
# include "Boss.h"
# include "Bullet.h"

const double PI = (float)3.14159265359;

class Game{
	float score;
	bool bossFight;
public:
	Character* mc;
	std::vector<Bullet*> mcShots;
	Boss* boss;
	std::vector<Mob*> enemies;
	std::vector<Bullet*> shots;

//	float timer; maybe
//	float background;

	Game();
	void update();
	void draw();

	void wave1();
	void wave2();
	void midBoss();
	void wave3();
	void finBoss();
};
#endif