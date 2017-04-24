#include "Game.h"
#include "Character.h"

Character::Character(float x, float y, float w, float h)
	: Mob( x, y, w, h, 0.0f, 0.0f, 0.0f, 1, 1.0f, 0.0f, 0.0f, 1, 1.0f, 1.0f)
{
	this->lives = 3;
	this->bombs = 3;
}