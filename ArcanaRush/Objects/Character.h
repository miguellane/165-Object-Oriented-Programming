#ifndef CHARACTER_H
#define CHARACTER_H

# include "Mob.h"
# include "Bullet.h"

class Character : public Mob{

public:
	int lives;
	int bombs;
	bool bombsDeploy;
	void fire(std::vector<Bullet*>& t);

	void  Character::atk1(std::vector<Bullet*>& t);
	void  Character::atk2(std::vector<Bullet*>& t);
	void  Character::atk3(std::vector<Bullet*>& t);
	void  Character::atk8(std::vector<Bullet*>& t);
	void  Character::atk9(std::vector<Bullet*>& t);
	Character();

};
#endif