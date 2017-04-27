#include "Mob.h"
#include "GlutApp.h"

Mob::Mob(float x, float y, float d, float v, int mv, int atk, float aS)
	: Entity(x, y, 0.1f, 0.1f, d, v, mv, 0.0f, 1.0f, 0.0f)
{
	this->health = 5;
	this->atk = atk;
	this->atkDamage = 1;
	this->atkSpeed = aS;

}
Mob::Mob(float x, float y, float w, float h, float d, float v, int mv, float r, float g, float b, int hp, int atk, int aD, float aS)
	: Entity( x, y, w, h, d, v, mv, r, g, b)
{
	this->health = hp;
	this->atk = atk;
	this->atkDamage = aD;
	this->atkSpeed = aS;
}

std::vector<Bullet*> Mob::atk1() {
	std::vector<Bullet *> t;
	Bullet* shot = new Bullet(x, y, 0.01f, 0.01f, PI / 2, 0.001f, 1, atkDamage);
	t.push_back(shot);
	return t;
}