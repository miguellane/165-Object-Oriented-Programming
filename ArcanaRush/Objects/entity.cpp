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
	float dTweak = 0.000125f;
	float vTweak = 0.00001f;
	float aTweak = 0.0000000001f;
	float inflate = 0.000005f;

	switch(movePattern){
		case 0: velocity = 0; acceleration = 0; break;
		case 1: break;
		case 2: velocity += vTweak; break;
		case 3: if(velocity > 0) velocity -= vTweak; else velocity = 0; break;
		case 4: direction += dTweak; break;
		case 5: direction -= dTweak; break;
		case 6: acceleration += aTweak; break;
		case 7: acceleration -= aTweak; break;
		case 8: w += inflate; h += inflate; break;
		case 9: direction += dTweak * 2; break;
	}

	x += velocity * cos(direction);
	y += velocity * sin(direction);
	velocity += acceleration;
}

void Entity::draw() {
	glColor3f(r, g, b);
	glBegin(GL_TRIANGLES);
	glVertex2f(x, y);
	glVertex2f(x + w, y);
	glVertex2f(x + w, y - h);


	glVertex2f(x, y - h);
	glVertex2f(x, y);
	glVertex2f(x + w, y - h);
	glEnd();
}

void Entity::drawTex(){
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glColor3f(r,g,b);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(x, y);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(x + w, y);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(x + w, y - h);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(x, y - h);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

bool Entity::contains(float x, float y, float w, float h) {

	return false;
}
