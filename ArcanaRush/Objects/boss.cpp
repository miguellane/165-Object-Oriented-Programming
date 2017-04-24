#include "Boss.h"
#include "GlutApp.h"

Boss::Boss(float x, float y, float w, float h, float d, float v, int hp, float aD, float aS)
	: Mob(x, y, w, h, d, v, 1.0f, 0.0f, 0.0f, hp, aD, aS)
{
}