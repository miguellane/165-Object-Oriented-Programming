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
	float dTweak = 0.001f;
	float vTweak = 0.001f;
	float aTweak = 0.001f;

	switch(movePattern){
		case 0: velocity = 0; acceleration = 0; break;
		case 1: break;
		case 2: velocity += vTweak; break;
		case 3: velocity -= vTweak; break;
		case 4: direction += dTweak; break;
		case 5: direction -= dTweak; break;
		case 6: acceleration += aTweak; break;
		case 7: acceleration -= aTweak; break;
	}


	x += velocity * cos(direction);
	y += velocity * sin(direction);
	velocity += acceleration;
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
