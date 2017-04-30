#include "Game.h"
#include "Character.h"

Character::Character()
	: Mob( 0.0f, -0.5f, 0.01f, 0.01f, 0.0f, 0.0f, 1, 1.0f, 0.0f, 0.0f, 1, 1, 2, 1.0f)
{
	this->lives = 3;
	this->bombs = 3;
}

std::vector<Bullet*> Character::fire(){
	std::vector<Bullet *> t;
	switch(atk){
		case 1: t = atk1(); break;
	}
	return t;
}