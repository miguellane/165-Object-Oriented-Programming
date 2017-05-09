#ifndef BOSS_H
#define BOSS_H

# include "Mob.h"
# include "Bullet.h"

class Boss : public Mob{

public:
	Boss(int hp);
	void fire(std::vector<Bullet*>& t);
};

#endif