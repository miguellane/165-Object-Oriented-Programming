#ifndef MOB_H
#define MOB_H

# include "Entity.h"
# include "Bullet.h"

class Mob : public Entity {

public:
	int health;
	int atk;
	float atkSpeed;
	int atkDamage;
	float atkCount;

	Mob(float x, float y, float d, float v, int mv, int atk, float aS);
	Mob(float x, float y, float w, float h, float d, float v, int mv, float r, float g, float b, int hp, int atk, int aD, float aS);
	std::vector<Bullet*> fire();

	std::vector<Bullet*> atk1();
	std::vector<Bullet*> atk2();
	std::vector<Bullet*> atk3();
	std::vector<Bullet*> atk4();
	std::vector<Bullet*> atk5();
};
#endif