#ifndef CHARACTER_H
#define CHARACTER_H

# include "Mob.h"
# include "Bullet.h"

class Character : public Mob{

public:
	int lives;
	int bombs;

	Character();
	std::vector<Bullet*> fire();

	std::vector<Bullet*> atk4();
	std::vector<Bullet*> atk5();
	std::vector<Bullet*> atk6();
};
#endif