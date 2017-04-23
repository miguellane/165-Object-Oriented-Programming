#ifndef CHARACTER_H
#define CHARACTER_H

# include "Entity.h";

class Character : public Mob{

public:
	int lives;
	int bombs;
//	int arcanaType;

	Character(float x, float y, float w, float h, float d, float v);
};
#endif