#ifndef BULLET_H
#define BULLET_H

# include "Entity.h";
class Bullet : public Entity {

public:
	float damage;
};

class Beam : public Bullet{

};
class Orb : public Bullet{

};
class Tracer : public Bullet{

};
#endif