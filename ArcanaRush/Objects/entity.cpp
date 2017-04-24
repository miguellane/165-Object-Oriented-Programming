#include "Entity.h"
#include "GlutApp.h"

Entity::Entity(float x, float y, float w, float h, float d, float v, float r, float g, float b){
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->direction = d;
	this->velocity = v;
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

//MOB SUBCLASS IS DEFINED HERE
Mob::Mob(float x, float y, float w, float h, float d, float v, float r, float g, float b, int hp, float aD, float aS)
	: Entity( x, y, w, h, d, v, r, g, b)
{
	this->health = hp;
	this->atkSpeed = aD;
	this->atkDamage = aS;

}