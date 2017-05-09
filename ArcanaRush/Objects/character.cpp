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

