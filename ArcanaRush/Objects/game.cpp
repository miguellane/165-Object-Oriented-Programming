#include "Game.h"
#include "GlutApp.h"
Game::Game(){
	score = 0;
	bossFight = false;
	mc = new Character();
<<<<<<< HEAD

=======
	enemies.push_back(new Mob(-0.6f,0.1f,0.0f,0.0f,1,1,0.0f));// #bottom left
	enemies.push_back(new Mob(-0.3f, 0.4f, 0.0f, 0.0f, 1, 1, 0.0f));// #top left
	/*enemies.push_back(new Mob(0.3f, 0.1f, 0.0f, 0.0f, 1, 1, 0.0f)); //bottom right
	enemies.push_back(new Mob(0.6f, 0.4f, 0.0f, 0.0f, 1, 1, 0.0f)); //top right
	enemies.push_back(new Mob(0.0f, 0.4f, 0.0f, 0.0f, 1, 1, 0.0f)); //top right
	enemies.push_back(new Mob(0.0f, 0.7f, 0.0f, 0.0f, 1, 1, 0.0f)); //top right
	enemies.push_back(new Mob(0.1f, 0.7f, 0.0f, 0.0f, 1, 1, 0.0f)); //top right*/
>>>>>>> origin/Jon
}
void Game::update(){
	size_t i;
	size_t j;
	std::vector<Bullet *> t;

	mc->update();

	if (bossFight)
		boss->update();

	t = mc->fire();
	for (i = 0; i < t.size(); i++) 
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

<<<<<<< HEAD
	//collision between mcshots and enemies
	for (i = 0; i < mcShots.size(); i++) {
		for (j = 0; j < enemies.size(); j++) {
			if (!enemies.empty() && checkCollisions(*mcShots[i], *enemies[j]) ) {
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
	
	/*//collision between enemies shots and mc
	for (i = 0; i < shots.size(); i++) {
		if (!shots.empty() && checkCollisions(*mcShots[i], *mc)) {
			mc->health--;
			//if (mc->health < 0)
				//delete mc some how
		}
	}*/

	//Deletes enemies that go out of bound
	for (i = 0; i < enemies.size(); i++) {
		if (checkBounds(enemies[i]->x, enemies[i]->y)) {
			enemies.erase(enemies.begin() + i);
			i--;
		}
	}

	//Deletes mcshots that go out of bound
	for (i = 0; i < mcShots.size(); i++) {
		if (checkBounds(mcShots[i]->x, mcShots[i]->y)) {
			mcShots[i] = mcShots.back();
			mcShots.pop_back();
			i--;
		}
	}

	//Deletes enemies that go out of bound
	for (i = 0; i < shots.size(); i++) {
		if (checkBounds(shots[i]->x, shots[i]->y)) {
			shots[i] = shots.back();
			shots.pop_back();
			i--;
		}
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
=======
	/*for (i = 0; i < mcShots.size(); i++) {
		if (/*checkCollisions(*mcShots[i], *mc2) || checkBounds(mcShots[i]->x, mcShots[i]->y)) {
			mcShots.erase(mcShots.begin() + i);
			i--;
		}
		else
			mcShots[i]->update();
	}*/

	//first shot doesn't work
	//both lefts can't be destroyed one after the other in sesession first

	for (i = 0; i < mcShots.size(); i++) {
		for (j = 0; j < enemies.size(); j++) {
			if (!enemies.empty() && checkCollisions(*mcShots[i], *enemies[j])) {
				mcShots.erase(mcShots.begin() + i);
				enemies.erase(enemies.begin() + j);
				i--;
				j--;
				std::cout << "# of enemies: " << enemies.size() << std::endl;
			}
		}
	}

	for (i = 0; i < mcShots.size(); i++) {
		if (checkBounds(mcShots[i]->x, mcShots[i]->y)) {
			mcShots.erase(mcShots.begin() + i);
			i--;

			std::cout << "# of bullets: " << mcShots.size() << std::endl;
		}
	}

	for (i = 0; i < enemies.size(); i++)
		enemies[i]->update();

	for (i = 0; i < mcShots.size(); i++)
		mcShots[i]->update();


	/*for (i = 0; i < shots.size(); i++) {
		if (/*checkCollisions(*shots[i], *mc2) || checkBounds(shots[i]->x, shots[i]->y)) {
			shots.erase(shots.begin() + i);
			i--;
		}
		else
			shots[i]->update();
	}*/
>>>>>>> origin/Jon
		
}

bool Game::checkCollisions(const Entity & obj1, const Entity & obj2){
	
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

	for(i = 0; i < mcShots.size(); i++)
		mcShots[i]->draw();
	for (i = 0; i < shots.size(); i++)
		shots[i]->draw();
}
