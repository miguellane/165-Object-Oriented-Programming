#include "Boss.h"
#include "GlutApp.h"

Boss::Boss(float x, float y, float w, float h, int hp, float aD, float aS)
	: Mob(x, y, w, h, 0.0f, 0.0f, 0.0f, 0, 0.0f, 0.0f, 1.0f, hp, aD, aS)
{
}