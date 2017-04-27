#include "Entity.h"
#include "GlutApp.h"

Entity::Entity(float x, float y, float w, float h, float d, float v, int mv, float r, float g, float b){
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->direction = d;
	this->velocity = v;
	this->acceleration = 0;
	this->movePattern = mv;
	this->r = r;
	this->g = g;
	this->b = b;
}

void Entity::update(){
	x += velocity * cos(direction);
	y += velocity * sin(direction);
}
void Entity::draw(){
	glColor3f(r, g, b);
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + w, y);
	glVertex2f(x + w, y - h);
	glVertex2f(x, y - h);
	glEnd();
}
//----------------------------------------------------------------------------------------------------
//MOB SUBCLASS IS DEFINED HERE
Mob::Mob(float x, float y, float d, float v, int mv, int atk, float aS)
	: Entity(x, y, 0.1f, 0.1f, d, v, mv, 0.0f, 1.0f, 0.0f)
{
	this->health = 5;
	this->atk = atk;
	this->atkDamage = 1;
	this->atkSpeed = aS;

}
Mob::Mob(float x, float y, float w, float h, float d, float v, int mv, float r, float g, float b, int hp, int atk, int aD, float aS)
	: Entity( x, y, w, h, d, v, mv, r, g, b)
{
	this->health = hp;
	this->atk = atk;
	this->atkDamage = aD;
	this->atkSpeed = aS;
}