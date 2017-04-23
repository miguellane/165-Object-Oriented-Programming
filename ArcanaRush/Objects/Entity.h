#ifndef ENTITY_H
#define ENTITY_H

class Entity{
	
public:
	float x, y;
	float w, h;
	float direction;
	float velocity;

//	int movePattern;
// float texture
	float r, g, b;

	void update();
	void draw();
};

class Mob : public Entity {

public:
	int health;
	float atkSpeed;
	float atkDamage;
	float moveSpeed;
};
#endif