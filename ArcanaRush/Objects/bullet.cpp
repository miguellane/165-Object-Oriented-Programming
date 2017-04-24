#include "Bullet.h"
#include "GlutApp.h"

Bullet::Bullet(float x, float y, float w, float h, float d, float v, float dmg)
	: Entity(x, y, w, h, d, v, 1.0f, 1.0f, 1.0f)
{
	this->damage = dmg;
}