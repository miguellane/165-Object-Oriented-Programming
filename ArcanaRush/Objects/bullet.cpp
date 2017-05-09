#include "Bullet.h"
#include "GlutApp.h"

Bullet::Bullet(float x, float y, float w, float h, float d, float v, int mv, int dmg)
	: Entity( x, y, w, h, d, v, mv, 1.0f, 1.0f, 1.0f)
{
	this->damage = dmg;
}

Bullet::Bullet(float x, float y, float w, float h, float d, float v, int mv, int dmg, float r, float g, float b)
	: Entity(x, y, w, h, d, v, mv, r, g, b)
{
	this->damage = dmg;
}