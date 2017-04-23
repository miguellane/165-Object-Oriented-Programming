#include "Game.h"
#include "Character.h"

Character::Character(float x, float y, float w, float h, float d, float v){
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->direction = d;
	this->velocity = v;
	this->r = 1.0f;
	this->g = 0.0f;
	this->b = 0.0f;

	this->health = 1;
	this->atkSpeed = 1;
	this->atkDamage = 1;
	this->moveSpeed = 1;

	this->lives = 3;
	this->bombs = 3;
}