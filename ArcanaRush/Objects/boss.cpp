#include "Boss.h"
#include "GlutApp.h"

Boss::Boss(int hp)
	: Mob(0.0f, 0.5f, 0.1f, 0.1f, 0.0f, 0.0f, 0, 0.0f, 0.0f, 1.0f, hp, 0, 1, 1.0f)
{
}

std::vector<Bullet*> Boss::fire()
{
	atkCount += 0.001f;
	std::vector<Bullet *> t;
	if (atkCount / atkSpeed >= 1) {
		atkCount -= atkSpeed;
		if (health < 20) t = atk6(); else
		if (health < 40) t = atk5(); else
		if (health < 60) t = atk4(); else
		if (health < 80) t = atk3(); else
		t = atk2();
	}
	return t;
}
