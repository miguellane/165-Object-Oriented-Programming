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
		case 5: t = atk5(); break;
		case 6: t = atk6(); break;
		}
	}
	return t;
}

std::vector<Bullet*> Mob::atk1() {//upward
	float gunx = x + w / 2;
	float guny = y;
	std::vector<Bullet *> t;
	t.push_back(new Bullet(x, y, 0.01f, 0.01f, PI / 2, 0.001f, 1, atkDamage));
	return t;
}

std::vector<Bullet*> Mob::atk2() {//downward
	float gunx = x ;
	float guny = y - h / 2;
	std::vector<Bullet *> t;
	t.push_back(new Bullet(gunx, guny, 0.01f, 0.01f, 3*PI / 2, 0.001f, 1, atkDamage));
	return t;
}

std::vector<Bullet*> Mob::atk3() {// full flower
	std::vector<Bullet *> t;

	float v = 0.0001f;
	float gunx = x + w / 2;
	float guny = y - h/2;
	for (int i = 0; i < 360; i += 15) 
		t.push_back(new Bullet(gunx, guny, 0.01f, 0.01f, i * PI/180, v, 1, atkDamage));
	
	return t;
}

std::vector<Bullet*> Mob::atk4() {// lower half flower
	std::vector<Bullet *> t;
	float gunx = x + w / 2;
	float guny = y - h;

	float v = 0.0001f;
	for (int i = 180; i <= 360; i += 15) {
		t.push_back(new Bullet(gunx, guny, 0.01f, 0.01f, i * PI/180, v, 1, atkDamage));
	}
	return t;
}

std::vector<Bullet*> Mob::atk5() {// spiral flower
	std::vector<Bullet *> t;

	float v = 0.0001f;
	float gunx = x + w / 2;
	float guny = y - h / 2;
	for (int i = 0; i < 360; i += 15)
		t.push_back(new Bullet(gunx, guny, 0.01f, 0.01f, i * PI / 180, v, 4, atkDamage));

	return t;
}
std::vector<Bullet*> Mob::atk6() {// lower half flower
	std::vector<Bullet *> t;
	float gunx = x + w / 2;
	float guny = y - h;

	float v = 0.0001f;
	for (int i = 180; i <= 360; i += 15) {
		if(i%2==0)
			t.push_back(new Bullet(gunx, guny, 0.01f, 0.01f, i * PI / 180, v, 4, atkDamage));
		else
			t.push_back(new Bullet(gunx, guny, 0.01f, 0.01f, i * PI / 180, v, 5, atkDamage));
	}
	return t;
}