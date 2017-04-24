#ifndef BULLET_H
#define BULLET_H

# include "Entity.h"
class Bullet : public Entity {

public:
	float damage;

	Bullet(float x, float y, float w, float h, float d, float v, float dmg);

};


class Beam : public Bullet{

};
class Orb : public Bullet{

};
class Tracer : public Bullet{

};
#endif