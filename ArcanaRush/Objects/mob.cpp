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
void Mob::fire(std::vector<Bullet*>& t){
	atkCount += 0.001f;
	if (atkCount / atkSpeed >= 1) {
		atkCount -= atkSpeed;
		switch (atk) {
		case 1: atk1(t); break;
		case 2: atk2(t); break;
		case 3: atk3(t); break;
		case 4: atk4(t); break;
		case 5: atk5(t); break;
		case 6: atk6(t); break;
		}
	}
	return;
}
void  Mob::atk1(std::vector<Bullet*>& t){//upward
	float gunx = x + w / 2;
	float guny = y;
	t.push_back(new Bullet(x, y, 0.01f, 0.01f, PI / 2, 0.001f, 1, atkDamage));
}

void  Mob::atk2(std::vector<Bullet*>& t){//downward
	float gunx = x ;
	float guny = y - h / 2;
	t.push_back(new Bullet(gunx, guny, 0.01f, 0.01f, 3*PI / 2, 0.001f, 1, atkDamage));
}
void  Mob::atk3(std::vector<Bullet*>& t){// full flower
	float v = 0.0001f;
	float gunx = x + w / 2;
	float guny = y - h/2;
	for (int i = 0; i < 360; i += 15) 
		t.push_back(new Bullet(gunx, guny, 0.01f, 0.01f, i * PI/180, v, 1, atkDamage));
}

void Mob::atk4(std::vector<Bullet*>& t){// lower half flower
	float gunx = x + w / 2;
	float guny = y - h;

	float v = 0.0001f;
	for (int i = 180; i <= 360; i += 15) {
		t.push_back(new Bullet(gunx, guny, 0.01f, 0.01f, i * PI/180, v, 1, atkDamage));
	}
}

void Mob::atk5(std::vector<Bullet*>& t){// spiral flower
	float v = 0.0001f;
	float gunx = x + w / 2;
	float guny = y - h / 2;
	for (int i = 0; i < 360; i += 15)
		t.push_back(new Bullet(gunx, guny, 0.01f, 0.01f, i * PI / 180, v, 4, atkDamage));

}
void Mob::atk6(std::vector<Bullet*>& t){// lower half flower
	float gunx = x + w / 2;
	float guny = y - h;

	float v = 0.0001f;
	for (int i = 180; i <= 360; i += 15) {
		if(i%2==0)
			t.push_back(new Bullet(gunx, guny, 0.01f, 0.01f, i * PI / 180, v, 4, atkDamage));
		else
			t.push_back(new Bullet(gunx, guny, 0.01f, 0.01f, i * PI / 180, v, 5, atkDamage));
	}
}