#ifndef CHARACTER_H
#define CHARACTER_H

# include "Entity.h"
# include "Bullet.h"

class Character : public Mob{

public:
	int lives;
	int bombs;
//	int arcanaType;

	Character(float x, float y, float w, float h);
	std::vector<Bullet*> atk();

	std::vector<Bullet*> atk1();
};
#endif