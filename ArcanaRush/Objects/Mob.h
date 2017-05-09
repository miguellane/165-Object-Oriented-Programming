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
	void fire(std::vector<Bullet*>& t);

	void atk1(std::vector<Bullet*>& t);
	void atk2(std::vector<Bullet*>& t);
	void atk3(std::vector<Bullet*>& t);
	void atk4(std::vector<Bullet*>& t);
	void atk5(std::vector<Bullet*>& t);
	void atk6(std::vector<Bullet*>& t);

};
#endif