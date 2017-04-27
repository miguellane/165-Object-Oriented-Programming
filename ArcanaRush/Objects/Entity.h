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

	Entity(float x, float y, float w, float h, float d, float v, int mv, float r, float g, float b);
	void update();
	void draw();
};

class Mob : public Entity {

public:
	int health;
	int atk;
	float atkSpeed;
	int atkDamage;

	Mob(float x, float y, float d, float v, int mv, int atk, float aS);
	Mob(float x, float y, float w, float h, float d, float v, int mv, float r, float g, float b, int hp, int atk, int aD, float aS);

	void fire();
	void atk1();
	void atk2();
	void atk3();
};
#endif