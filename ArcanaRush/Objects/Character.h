#ifndef CHARACTER_H
#define CHARACTER_H

# include "Entity.h"
# include "Bullet.h"

class Character : public Mob{

public:
	int lives;
	int bombs;

	Character();
	std::vector<Bullet*> fire();

	std::vector<Bullet*> atk1();
};
#endif