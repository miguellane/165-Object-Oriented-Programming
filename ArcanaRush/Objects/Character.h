#ifndef CHARACTER_H
#define CHARACTER_H

# include "Mob.h"
# include "Bullet.h"

class Character : public Mob{

public:
	int lives;
	int bombs;

	Character();

};
#endif