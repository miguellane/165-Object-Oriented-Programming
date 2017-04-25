#include "Game.h"
#include "Character.h"

Character::Character(float x, float y, float w, float h)
	: Mob( x, y, w, h, 0.0f, 0.0f, 0.0f, 1, 1.0f, 0.0f, 0.0f, 1, 1.0f, 1.0f)
{
	this->lives = 3;
	this->bombs = 3;
}

std::vector<Bullet*> Character::atk(){
	switch(1){
		case 1: return atk1(); break;
	}
}

std::vector<Bullet*> Character::atk1(){
	std::vector<Bullet *> t;
	Bullet* shot = new Bullet(x, y, 0.01f, 0.01f, PI/2, 0.001f, 1, atkDamage);
	t.push_back(shot);
	return t;
}