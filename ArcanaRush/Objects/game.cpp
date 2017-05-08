#include "Game.h"
#include "GlutApp.h"
Game::Game() {
	score = 0;
	bossFight = false;
	mc = new Character();

}
void Game::update() {
	size_t i;
	size_t j;
	std::vector<Bullet *> t;
	float x;
	dummy = new Mob(x, 0.5f, 0.03f, 0.03f, 0.0f, 0.0f, 1, 1.0f, 1.0f, 1.0f, 1000, 2, 1, 1.0f);

	if (enemies.size() < 1) {
			enemies.push_back(dummy);
	}

	//updates mc
	mc->update();
		
	//updates boss fight
	if (bossFight){
		boss->update();
		t = boss->fire();
		for (i = 0; i < t.size(); i++)
			shots.push_back(t[i]);
	}

	//updates enemies
	for (i = 0; i < enemies.size(); i++)
		enemies[i]->update();

	//updates mcShots
	for (i = 0; i < mcShots.size(); i++)
		mcShots[i]->update();

	//updates enemies shots
	for (i = 0; i < shots.size(); i++)
		shots[i]->update();

	//mc shots
	t = mc->fire();
	for (i = 0; i < t.size(); i++)
		mcShots.push_back(t[i]);

<<<<<<< HEAD

/*	if (bossFight){
		t = boss->fire();
		for (i = 0; i < t.size(); i++)
			shots.push_back(t[i]);
	}*/
	for (i = 0; i < enemies.size(); i++){
		t = enemies[i]->fire();
		for (i = 0; i < t.size(); i++)
			shots.push_back(t[i]);
	}	
=======
	//enemies shots
	for (i = 0; i < enemies.size();i++) {
		t = enemies[i]->fire();
		for (i = 0; i < t.size(); i++)
			shots.push_back(t[i]);
	}
>>>>>>> refs/remotes/origin/master

	//collision between mcshots and enemies
	for (i = 0; i < mcShots.size(); i++) {
<<<<<<< HEAD
		for (int j = 0; j < enemies.size(); j++) {
			if (checkCollisions(*mcShots[i], *enemies[j])) {
				mcShots.erase(mcShots.begin() + i);
				i--;
				enemies.erase(enemies.begin() + j);
				j--;
				if (j == 0)
					break;
			}
		}
		if (mcShots.size() < 1)
			break;
		else if (/*checkCollisions(*mcShots[i], *mc2) || */checkBounds(mcShots[i]->x, mcShots[i]->y)) {
			mcShots.erase(mcShots.begin() + i);
			i--;
		}
		
		else
			mcShots[i]->update();
=======
		for (j = 0; j < enemies.size(); j++) {
			if (!enemies.empty() && checkCollisions(*mcShots[i], *enemies[j])) {
				mcShots.erase(mcShots.begin() + i);
				enemies.erase(enemies.begin() + j);
				j--;
				if (i == 0)
					break;
				else
					i--;
			}
		}
	}

	//collision between enemies shots and mc
	for (i = 0; i < shots.size(); i++) {
		if (!shots.empty() && checkCollisions(*shots[i], *mc)) {
			mc->health--;
			if (mc->health < 0) {
				mc->lives--;
				if (mc->lives == 0)
					delete mc;
				else {
					mc->x = 0.0f; 
					mc->y = -0.5f;
				}
			}
		}
	}

	//Deletes enemies that go out of bound
	for (i = 0; i < enemies.size(); i++) {
		if (checkBounds(enemies[i]->x, enemies[i]->y)) {
			enemies.erase(enemies.begin() + i);
			i--;
		}
>>>>>>> refs/remotes/origin/master
	}

	//Deletes mcshots that go out of bound
	for (i = 0; i < mcShots.size(); i++) {
		if (checkBounds(mcShots[i]->x, mcShots[i]->y)) {
			mcShots[i] = mcShots.back();
			mcShots.pop_back();
			i--;
		}
	}

	//Deletes enemies shots that go out of bound
	for (i = 0; i < shots.size(); i++) {
<<<<<<< HEAD
		if (checkCollisions(*shots[i], *mc)) {
			mc->lives--;
			shots.erase(shots.begin() + i);
			i--;
		}
		else if (/* checkCollisions(*shots[i], *mc2)|| */checkBounds(shots[i]->x, shots[i]->y)) {
			shots.erase(shots.begin() + i);
=======
		if (checkBounds(shots[i]->x, shots[i]->y)) {
			shots[i] = shots.back();
			shots.pop_back();
>>>>>>> refs/remotes/origin/master
			i--;
		}
	}

}

bool Game::checkCollisions(const Entity & obj1, const Entity & obj2) {

	bool collisionX = obj1.x + obj1.w >= obj2.x && obj2.x + obj2.w >= obj1.x;
	bool collisionY = obj1.y + obj1.h >= obj2.y && obj2.y + obj2.h >= obj1.y;

	return collisionX && collisionY;
}

bool Game::checkBounds(float x, float y) {
	if (x >= 2.0 || x <= -2.0 || y >= 2.0 || y <= -2.0)
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

	for (i = 0; i < mcShots.size(); i++)
		mcShots[i]->draw();
	for (i = 0; i < shots.size(); i++)
		shots[i]->draw();
}
