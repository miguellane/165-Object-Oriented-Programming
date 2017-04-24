#ifndef BOSS_H
#define BOSS_H

# include "Entity.h"

class Boss : public Mob{

public:
	
	Boss(float x, float y, float w, float h, float d, float v, int hp, float aD, float aS);
};

#endif