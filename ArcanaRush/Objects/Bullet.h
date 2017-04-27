#ifndef BULLET_H
#define BULLET_H

# include "Entity.h"

class Bullet : public Entity {

public:
	int damage;

	Bullet(float x, float y, float w, float h, float d, float v, int mv, int dmg);

};


class Beam : public Bullet{

};
class Orb : public Bullet{

};
class Tracer : public Bullet{

};
#endif