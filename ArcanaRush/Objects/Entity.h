#ifndef ENTITY_H
#define ENTITY_H

class Entity{

public:
	float x, y;
	float w, h;
	float direction;
	float velocity;
	float acceleration;
	int movePattern;

	// float texture
	float r, g, b;

	Entity(float x, float y, float w, float h, float d, float v, float a, int mv, float r, float g, float b);
	void update();
	void draw();
};

class Mob : public Entity {

public:
	int health;
	float atkSpeed;
	float atkDamage;

	Mob(float x, float y, float w, float h, float d, float v, float a, int mv, float r, float g, float b, int hp, float aD, float aS);

	void mobAtk1();
	void mobAtk2();
	void mobAtk3();
};
#endif