
#ifndef GAME_H
#define GAME_H

class Game{

public:
	float score;
	int enemyCount;

//	float timer; maybe
	
//	float background;
	Game();
	void update();
	void draw();
};
#endif