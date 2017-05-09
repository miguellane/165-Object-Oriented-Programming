#include "Boss.h"
#include "GlutApp.h"

Boss::Boss(int hp)
	: Mob(-0.1f, 0.3f, 0.2f, 0.25f, 0.0f, 0.0001f, 9, 1.0f, 1.0f, 1.0f, hp, 1, 1, 1.0f)
{
}

void Boss::fire(std::vector<Bullet*>& t)
{
	atkCount += 0.001f;
	if (atkCount / atkSpeed >= 1) {
		atkCount -= atkSpeed;
		if (health < 20) atk6(t); else
		if (health < 40) atk5(t); else
		if (health < 60) atk6(t); else
		if (health < 80) atk5(t); else
		atk3(t);
	}
}
