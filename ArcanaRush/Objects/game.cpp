#include "Game.h"
#include "GlutApp.h"
Game::Game(){
	score = 0;
	bossFight = false;
	mc = new Character();
}
void Game::update(){
	size_t i;
	std::vector<Bullet *> t;

	mc->update();
	if (bossFight)
		boss->update();
	for (i = 0; i < enemies.size(); i++)
		enemies[i]->update();


	t = mc->fire();
	for(i = 0; i < t.size(); i++)
		mcShots.push_back(t[i]);


/*	if (bossFight){
		t = boss->fire();
		for (i = 0; i < t.size(); i++)
			shots.push_back(t[i]);
	}
	for (i = 0; i < enemies.size(); i++){
		t = enemies[i]->fire();
		for (i = 0; i < t.size(); i++)
			shots.push_back(t[i]);
	}*/


	

	for (i = 0; i < mcShots.size(); i++) {
		//if (checkCollisions(*mcShots[i], *enemies[i])) delete mcShots[i];
		//if (checkBounds(mcShots[i]->x, mcShots[i]->y)) delete mcShots[i]; //std::cout << "out of bounds" << std::endl;
		mcShots[i]->update();
	}
		
	for (i = 0; i < shots.size(); i++)
		shots[i]->update();
}

bool Game::checkCollisions(const Entity & obj1, const Entity & obj2){
	
	bool collisionX = obj1.x + obj1.w >= obj2.x && obj2.x + obj2.w >= obj1.x;
	bool collisionY = obj1.y + obj1.h >= obj2.y && obj2.y + obj2.h >= obj1.y;
	
	return collisionX && collisionY;
}

bool Game::checkBounds(float x, float y) {
	if (x >= 1 || x <= -1 || y >= 1 || y <= -1) 
		return true;
	else 
		return false;
}

void Game::draw() {
	size_t i;

	mc->draw();
	if (bossFight)
		boss->draw();
	for (i = 0; i < enemies.size(); i++)
		enemies[i]->draw();

	for(i = 0; i < mcShots.size(); i++)
		mcShots[i]->draw();
	for (i = 0; i < shots.size(); i++)
		shots[i]->draw();
}
