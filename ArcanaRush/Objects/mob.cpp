#include "Mob.h"
#include "GlutApp.h"

Mob::Mob(float x, float y, float d, float v, int mv, int atk, float aS)
	: Entity(x, y, 0.1f, 0.1f, d, v, mv, 0.0f, 1.0f, 0.0f)
{
	this->health = 5;
	this->atk = atk;
	this->atkDamage = 1;
	this->atkSpeed = aS;
	this->atkCount = 0;
}
Mob::Mob(float x, float y, float w, float h, float d, float v, int mv, float r, float g, float b, int hp, int atk, int aD, float aS)
	: Entity( x, y, w, h, d, v, mv, r, g, b)
{
	this->health = hp;
	this->atk = atk;
	this->atkDamage = aD;
	this->atkSpeed = aS;
	this->atkCount = 0;
}
std::vector<Bullet*> Mob::fire() {
	atkCount += 0.001f;
	std::vector<Bullet *> t;

	if (atkCount / atkSpeed >= 1) {
		atkCount -= atkSpeed;
		switch (atk) {
		case 1: t = atk1(); break;
		case 2: t = atk2(); break;
		case 3: t = atk3(); break;
		case 4: t = atk4(); break;
		}
	}
	return t;
}

std::vector<Bullet*> Mob::atk1() {//upward
	std::vector<Bullet *> t;
	Bullet* shot = new Bullet(x, y, 0.01f, 0.01f, PI / 2, 0.001f, 1, atkDamage);
	t.push_back(shot);
	return t;
}

std::vector<Bullet*> Mob::atk2() {//downward
	std::vector<Bullet *> t;
	Bullet* shot = new Bullet(x, y, 0.01f, 0.01f, 3*PI / 2, 0.001f, 1, atkDamage);
	t.push_back(shot);
	return t;
}

std::vector<Bullet*> Mob::atk3() {// full flower
	std::vector<Bullet *> t;

	float v = 0.0001f;
	//quadrant 1
	Bullet* shot0 = new Bullet(x, y, 0.01f, 0.01f, 2*PI , v, 1, atkDamage);	
	Bullet* shot1 = new Bullet(x, y, 0.01f, 0.01f, PI/6, v, 1, atkDamage);
	Bullet* shot2 = new Bullet(x, y, 0.01f, 0.01f, PI / 4, v, 1, atkDamage);
	Bullet* shot3 = new Bullet(x, y, 0.01f, 0.01f, PI / 3, v, 1, atkDamage);
	Bullet* shot4 = new Bullet(x, y, 0.01f, 0.01f, PI/2, v, 1, atkDamage);
	
	//quadrant 2
	Bullet* shot5 = new Bullet(x, y, 0.01f, 0.01f, 2*PI/ 3, v, 1, atkDamage);
	Bullet* shot6 = new Bullet(x, y, 0.01f, 0.01f, 2 * PI / 3, v, 1, atkDamage);
	Bullet* shot7 = new Bullet(x, y, 0.01f, 0.01f, 3 * PI / 4, v, 1, atkDamage);
	Bullet* shot8 = new Bullet(x, y, 0.01f, 0.01f, 5 * PI / 6, v, 1, atkDamage);
	Bullet* shot9 = new Bullet(x, y, 0.01f, 0.01f, PI, v, 1, atkDamage);

	//quadrant 3
	Bullet* shot10 = new Bullet(x, y, 0.01f, 0.01f, 7*PI/6, v, 1, atkDamage);
	Bullet* shot11 = new Bullet(x, y, 0.01f, 0.01f, 5 * PI / 4, v, 1, atkDamage);
	Bullet* shot12 = new Bullet(x, y, 0.01f, 0.01f, 4 * PI / 3, v, 1, atkDamage);
	Bullet* shot13 = new Bullet(x, y, 0.01f, 0.01f, 3 * PI / 2, v, 1, atkDamage);

	//quadrant 4
	Bullet* shot14 = new Bullet(x, y, 0.01f, 0.01f, 5 * PI / 3, v, 1, atkDamage);
	Bullet* shot15 = new Bullet(x, y, 0.01f, 0.01f, 7 * PI / 4, v, 1, atkDamage);
	Bullet* shot16 = new Bullet(x, y, 0.01f, 0.01f, 11 * PI / 6, v, 1, atkDamage);
	
	t.push_back(shot0);
	t.push_back(shot1);
	t.push_back(shot2);
	t.push_back(shot3);
	t.push_back(shot4);
	
	t.push_back(shot5);
	t.push_back(shot6);
	t.push_back(shot7);
	t.push_back(shot8);
	t.push_back(shot9);
	
	t.push_back(shot10);
	t.push_back(shot11);
	t.push_back(shot12);
	t.push_back(shot13);
	
	t.push_back(shot14);
	t.push_back(shot15);
	t.push_back(shot16);
	return t;
}

std::vector<Bullet*> Mob::atk4() //bottom half flower
{

	std::vector<Bullet *> t;	

	//quadrant 3
	Bullet* shot10 = new Bullet(x, y, 0.01f, 0.01f, 7 * PI / 6, 0.001f, 1, atkDamage);
	Bullet* shot11 = new Bullet(x, y, 0.01f, 0.01f, 5 * PI / 4, 0.001f, 1, atkDamage);
	Bullet* shot12 = new Bullet(x, y, 0.01f, 0.01f, 4 * PI / 3, 0.001f, 1, atkDamage);
	Bullet* shot13 = new Bullet(x, y, 0.01f, 0.01f, 3 * PI / 2, 0.001f, 1, atkDamage);

	//quadrant 4
	Bullet* shot14 = new Bullet(x, y, 0.01f, 0.01f, 5 * PI / 3, 0.001f, 1, atkDamage);
	Bullet* shot15 = new Bullet(x, y, 0.01f, 0.01f, 7 * PI / 4, 0.001f, 1, atkDamage);
	Bullet* shot16 = new Bullet(x, y, 0.01f, 0.01f, 11 * PI / 6, 0.001f, 1, atkDamage);

	t.push_back(shot10);
	t.push_back(shot11);
	t.push_back(shot12);
	t.push_back(shot13);
	
	t.push_back(shot14);
	t.push_back(shot15);
	t.push_back(shot16);
	
	return t;
}

std::vector<Bullet*> Mob::atk5()
{
	std::vector<Bullet *> t;
	return t;
}
