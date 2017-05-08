#include "Game.h"
#include "GlutApp.h"
Game::Game() {
	score = 0;
	bossFight = false;
	mc = new Character();
	waveCounter = 1;
	
}
void Game::update() {
	size_t i;
	size_t j;
	std::vector<Bullet *> t; //mc and boss
	std::vector<Bullet *> e; //enemies

	//manages the waves
	if (enemies.size() == 0 && bossFight == false) {
		switch (waveCounter) {

			case 1: wave1(); waveCounter++;  break;
			case 2: wave2(); waveCounter++; break;
			case 3: midBoss(); waveCounter++; break;
			case 4: wave3(); waveCounter++; break;
			case 5: finBoss(); bossFight = true; break;

		}
	}

	//updates mc
	mc->update();
		
	//updates boss fight, boss bullets, and mc to boss collision
	if (bossFight){

		boss->update();
		t = boss->fire();
		for (i = 0; i < t.size(); i++)
			shots.push_back(t[i]);

		for (i = 0; i < mcShots.size(); i++) {
			if (!mcShots.empty() && checkCollisions(*mcShots[i], *boss)) {
				//does damage
				boss->health -= mcShots[i]->damage;
				
				//deletes bullet
				mcShots[i] = mcShots.back();
				mcShots.pop_back();
				i--;
				if (i < 0)
					break;

				//kills boss when hp is low
				if (boss->health < 0) delete boss;

				//Game over you win!
			}
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

	//mc shots
	t = mc->fire();
	for (i = 0; i < t.size(); i++)
		mcShots.push_back(t[i]);

	//enemies shots
	for (i = 0; i < enemies.size();i++) {
		e = enemies[i]->fire();
		for (i = 0; i < e.size(); i++)
			shots.push_back(e[i]);
	}

	//collision between mcshots and enemies
	for (i = 0; i < mcShots.size(); i++) {
		for (j = 0; j < enemies.size(); j++) {
			if (!enemies.empty() && checkCollisions(*mcShots[i], *enemies[j])) {
				mcShots[i] = mcShots.back();
				mcShots.pop_back();
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
			mc->health-= shots[i]->damage;
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
		if (checkBounds(shots[i]->x, shots[i]->y)) {
			shots[i] = shots.back();
			shots.pop_back();
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

void Game::wave1()
{
	enemies.push_back(new Mob(0.5f, 0.4f, 0.0f, 0.0f, 1, 2, 1.0f));

}

void Game::wave2()
{
	enemies.push_back(new Mob(0.0f, 0.0f, 0.0f, 0.0f, 1, 3, 1.0f));

}

void Game::midBoss()
{
	enemies.push_back(new Mob(0.3f, 0.0f, 0.0f, 0.0f, 1, 3, 1.0f));

}


void Game::wave3()
{
	enemies.push_back(new Mob(0.6f, 0.1f, 0.0f, 0.0f, 1, 4, 1.0f));

}

void Game::finBoss()
{
	//enemies.push_back(new Mob(0.0f, 0.0f, 0.0f, 0.0f, 1, 2, 1.0f));
	boss = new Boss(100);

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
