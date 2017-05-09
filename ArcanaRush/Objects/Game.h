
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
	std::vector<Bullet*> mcShots;
	Boss* boss;
	std::vector<Mob*> enemies;
	std::vector<Bullet*> shots;

//	float timer; maybe
//	float background;

	Game();
	void update();
	void draw();
	bool checkCollisions(const Entity *bull, const Entity *mob);
	bool outBoundsOuter(float x, float y);
	bool outBoundsInner(float x, float y);
	bool mcDeath();
	bool pause;

	void DrawString(void *font, const char s[], float x, float y);

	void wave1();
	void wave2();
	void wave3();
	void wave4();
	void wave5();
	void wave6();
	void wave7();
	//void midBoss();
	void finBoss();

	int waveCounter;
};
#endif