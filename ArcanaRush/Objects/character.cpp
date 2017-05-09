#include "Game.h"
#include "Character.h"

Character::Character()
	: Mob( 0.0f, -0.5f, 0.01f, 0.01f, 0.0f, 0.0f, 3, 1.0f, 0.0f, 0.0f, 1, 1, 2, 1.0f)
{
	this->lives = 5;
	this->bombs = 3;

	bombsDeploy = true;
}

void Character::fire(std::vector<Bullet*>& t)
{
	atkCount += 0.001f;
	if (atkCount / atkSpeed >= 1) {
		atkCount -= atkSpeed;
		switch (atk) {
			case 1: atk1(t); break;
			case 2: atk2(t); break;
			case 3: atk8(t); break;
			case 4: atk9(t); break;
		}
		if (!bombsDeploy && (bombs > 0)) {
			atk3(t);
			bombs--;
			bombsDeploy = true;
		}
	}
}

void  Character::atk1(std::vector<Bullet*>& t) {//upward
	float gunx = x + w / 2;
	float guny = y;
	t.push_back(new Bullet(x, y, 0.01f, 0.01f, PI / 2, 0.001f, 1, atkDamage, 1.0f, 1.0f, 0.0f));
}

void  Character::atk2(std::vector<Bullet*>& t) {//downward
	float gunx = x + w / 2;
	float guny = y - h / 2;
	t.push_back(new Bullet(gunx, guny, 0.01f, 0.01f, (float)(3 * PI / 2), 0.001f, 1, atkDamage, 1.0f, 1.0f, 0.0f));
}

void  Character::atk3(std::vector<Bullet*>& t) {// full flower
	float v = 0.0001f;
	float gunx = x + w / 2;
	float guny = y - h / 2;
	for (int i = 0; i < 360; i += 15)
		t.push_back(new Bullet(gunx, guny, 0.01f, 0.01f, (float)(i * PI / 180), v, 7, atkDamage, 1.0f, 1.0f, 0.0f));
}

void  Character::atk8(std::vector<Bullet*>& t) {//left
	float gunx = x;
	float guny = y - h / 2;
	t.push_back(new Bullet(gunx, guny, 0.01f, 0.01f, PI, 0.001f, 1, atkDamage, 1.0f, 1.0f, 0.0f));
}

void  Character::atk9(std::vector<Bullet*>& t) {//right
	float gunx = x + w;
	float guny = y - h / 2;
	t.push_back(new Bullet(gunx, guny, 0.01f, 0.01f, (float)(2 * PI), 0.001f, 1, atkDamage, 1.0f, 1.0f, 0.0f));
}
