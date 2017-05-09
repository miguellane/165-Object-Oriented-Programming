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

	//manages the waves
	if (enemies.size() == 0 && bossFight == false) {
		switch (waveCounter) {
			case 1: wave1(); waveCounter++;  break;
			case 2: wave2(); waveCounter++; break;
			case 3: wave3(); waveCounter++;  break;
			case 4: wave4(); waveCounter++; break;
			case 5: wave5(); waveCounter++; break;
			case 6: finBoss(); bossFight = true; waveCounter++; break;
		}
	}

	//Update MC: Obj -> Fire -> Bullets[ If(OutBounds) ElseIf(BossCollide)] && EnemyCollision
	if (outBoundsInner(mc->x, mc->y))
		mcDeath();
	else {
		mc->update();
		mc->fire(mcShots);
		for (i = 0; i < mcShots.size(); i++) {
			if (outBoundsInner(mcShots[i]->x, mcShots[i]->y)) {
				mcShots[i] = mcShots.back();
				mcShots.pop_back();
				i--;
			} else if (bossFight && checkCollisions(mcShots[i], boss)) {
				boss->health -= mcShots[i]->damage;
				mcShots[i] = mcShots.back();
				mcShots.pop_back();
				i--;
				if (boss->health < 0) {
					delete boss;
					bossFight = false;
				}
			} else
				mcShots[i]->update();
		}
	}

	//Update Boss[ If(On) ]: Obj -> Fire
	if (bossFight){
		boss->update();
		boss->fire(shots);
	}

	//Update Enemies[ If(!OutBounds) ]: Obj -> Fire
	for (i = 0; i < enemies.size(); i++) {

		if (outBoundsOuter(enemies[i]->x, enemies[i]->y)) {
			enemies.erase(enemies.begin() + i);
			i--;
		} else {
			enemies[i]->update();
			enemies[i]->fire(shots);
		}
	}

	//Update EnemyShots: Obj[ If(OutBounds) ElseIf(Collide) ]
	for (i = 0; i < shots.size(); i++) {
		if (outBoundsInner(shots[i]->x, shots[i]->y)) {
			shots[i] = shots.back();
			shots.pop_back();
			i--;

		} else if (!shots.empty() && checkCollisions(shots[i], mc)) {
				mc->health -= shots[i]->damage;
				if (mc->health < 0) {
					mcDeath();
				}
		} else
			shots[i]->update();
	}

	//collision between mcshots and enemies
	for (i = 0; i < mcShots.size(); i++) {
		for (j = 0; j < enemies.size(); j++) {
			if (!enemies.empty() && checkCollisions(mcShots[i], enemies[j])) {
				mcShots[i] = mcShots.back();
				mcShots.pop_back();
				enemies[j] = enemies.back();
				enemies.pop_back();
				j--;
				if (i == 0)
					break;
				else
					i--;
			}
		}
	}
}

bool Game::mcDeath() {
	mc->lives--;
	std::cout << "YOU ARE DEAD!" << std::endl;
	if (mc->lives == 0)
		exit(0);
	else {
		mc->x = 0.0f;
		mc->y = -0.5f;
	}
	return true;
}

bool Game::checkCollisions(const Entity *obj1, const Entity *obj2) {
	bool collisionX = obj1->x + obj1->w >= obj2->x && obj2->x + obj2->w >= obj1->x;
	bool collisionY = obj1->y - obj1->h <= obj2->y && obj2->y - obj2->h <= obj1->y;

	return collisionX && collisionY;
}

bool Game::outBoundsOuter(float x, float y) {
	if (x >= 2.0 || x <= -2.0 || y >= 2.0 || y <= -2.0)
		return true;
	else
		return false;
}

bool Game::outBoundsInner(float x, float y) {
	if (x >= 1.0 || x <= -1.0 || y >= 1.0 || y <= -1.0)
		return true;
	else
		return false;
}

void Game::wave1()
{
	//inflates shot
	enemies.push_back(new Mob(0.3f,0.8f,0.0f,0.0f,1,10,1.5f));
	enemies.push_back(new Mob(-0.3f, 0.8f, 0.0f, 0.0f, 1, 10, 1.5f));

	//half circle
	enemies.push_back(new Mob(0.5f, 0.3f, 0.0f, 0.0f, 1, 4, 1.5f));
	enemies.push_back(new Mob(-0.5f, 0.3f, 0.0f, 0.0f, 1, 4, 1.5f));

}

void Game::wave2()
{
	enemies.push_back(new Mob(1.0f, 0.3f, (float)(PI), 0.0001f, 1, 3, 1.5f));
	enemies.push_back(new Mob(-1.0f, 0.5f, (float)(2*PI), 0.0001f, 1, 3, 1.5f));
	
	enemies.push_back(new Mob(1.0f, -0.3f, (float)(PI), 0.0001f, 1, 3, 1.5f));
	enemies.push_back(new Mob(-1.0f, -0.5f, (float)(2 * PI), 0.0001f, 1, 3, 1.5f));
	
}

void Game::wave3()
{
	enemies.push_back(new Mob(-0.5f, 0.5f, 0.0f, 0.0f, 1, 3, 1.0f));
	enemies.push_back(new Mob(0.5f, 0.5f, 0.0f, 0.0f, 1,3, 1.0f));
	enemies.push_back(new Mob(-0.5f, -0.5f, 0.0f, 0.0f, 1, 3, 1.0f));
	enemies.push_back(new Mob(0.5f, -0.5f, 0.0f, 0.0f, 1, 3, 1.0f));
	
}

void Game::wave4()
{
	enemies.push_back(new Mob(-0.5f, 0.0f, 0.0f, 0.0f, 1, 5, .5f));
	enemies.push_back(new Mob(0.5f, 0.0f, 0.0f, 0.0f, 1, 5, .5f));
	enemies.push_back(new Mob(0.0f, 0.5f, 0.0f, 0.0f, 1, 5, .5f));
	enemies.push_back(new Mob(0.0f, -0.5f, 0.0f, 0.0f, 1, 5, .5f));

}

void Game::wave5()
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
