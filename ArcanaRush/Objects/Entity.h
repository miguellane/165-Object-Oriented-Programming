#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "RgbImage.h"
#include "TexRect.hpp"

const double PI = (float)3.14159265359;

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
	void drawTex();
	bool contains(float x, float y, float w, float h);
};

#endif