#include "Game.h"
#include "GlutApp.h"
Game::Game() {
	score = 0;
	pause = false;
	godMode = false;
	ta = 2;
	bossFight = false;
	mc = new Character();
	boss = new Boss(100);
	waveCounter = 8;
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
			case 6: wave6(); waveCounter++; break;
			case 7: wave7(); waveCounter++; break;
			case 8: finBoss(); bossFight = true; waveCounter++; break;
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

		} else if (!godMode&&!shots.empty() && checkCollisions(shots[i], mc)) {
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
	if (mc->lives == 0) {
		delete mc;
		pause = true;
	}
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
	enemies.push_back(new Mob(-0.5f, 0.58f, 0.0f, 0.0f, 1, 2, 1.5f));

}

void Game::wave2()
{
	//half circle
	enemies.push_back(new Mob(-0.8f, 0.5f, (float)(PI), 0.0f, 1, 9, 1.5f));
	enemies.push_back(new Mob(0.5f, -0.6f, (float)(2 * PI), 0.0f, 1, 8, 1.5f));

	ta++;
	if (ta == 5)
		ta = 2;

}

void Game::wave3()
{
	//inflates shot
	//enemies.push_back(new Mob(0.3f,0.8f,0.0f,0.0f,1,10,1.5f));
	//enemies.push_back(new Mob(-0.3f, 0.8f, 0.0f, 0.0f, 1, 10, 1.5f));

	//half circle
	enemies.push_back(new Mob(0.7f, 0.7f, 0.0f, 0.0f, 1, 4, 1.5f));
	enemies.push_back(new Mob(-0.7f, 0.7f, 0.0f, 0.0f, 1, 4, 1.5f));

	ta++;
	if (ta == 5)
		ta = 2;

}

void Game::wave4()
{
	enemies.push_back(new Mob(1.0f, 0.3f, (float)(PI), 0.0001f, 1, 3, 1.5f));
	enemies.push_back(new Mob(-1.0f, 0.5f, (float)(2*PI), 0.0001f, 1, 3, 1.5f));
	
	enemies.push_back(new Mob(1.0f, -0.3f, (float)(PI), 0.0001f, 1, 3, 1.5f));
	enemies.push_back(new Mob(-1.0f, -0.5f, (float)(2 * PI), 0.0001f, 1, 3, 1.5f));

	ta++;
	if (ta == 5)
		ta = 2;
	
}

void Game::wave5()
{
	enemies.push_back(new Mob(-0.5f, 1.0f, (float)(3 * PI/2), 0.0001f, 1, 7, 1.5f));
	enemies.push_back(new Mob(0.5f, 1.0f, (float)(3 * PI/2), 0.0001f, 1, 7, 1.5f));

	enemies.push_back(new Mob(-0.5f, -1.0f, (float)(PI/2), 0.0001f, 1, 11, 1.5f));
	enemies.push_back(new Mob(0.5f, -1.0f, (float)(PI/2), 0.0001f, 1, 11, 1.5f));

	ta++;
	if (ta == 5)
		ta = 2;
	
}

void Game::wave6()
{
	enemies.push_back(new Mob(-0.5f, 0.0f, 0.0f, 0.0f, 1, 5, .5f));
	enemies.push_back(new Mob(0.5f, 0.0f, 0.0f, 0.0f, 1, 5, .5f));
	enemies.push_back(new Mob(0.0f, 0.5f, 0.0f, 0.0f, 1, 5, .5f));
	enemies.push_back(new Mob(0.0f, -0.5f, 0.0f, 0.0f, 1, 5, .5f));

	ta++;
	if (ta == 5)
		ta = 2;

}

void Game::wave7()
{
	enemies.push_back(new Mob(0.0f, 0.9f, 0.0f, 0.0f, 1, 10, 1.0f));

	ta++;
	if (ta == 5)
		ta = 2;

}

void Game::finBoss()
{
	//enemies.push_back(new Mob(0.0f, 0.0f, 0.0f, 0.0f, 1, 2, 1.0f));
	//boss = new Boss(100);

}

void Game::DrawString(void *font, const char s[], float x, float y)
{
	unsigned int i;
	glRasterPos2f(x, y);
	for (i = 0; i<strlen(s); i++)
	{
		glutBitmapCharacter(font, s[i]);
	}
}

void Game::draw() {
	size_t i;

	mc->draw();

	glColor3f(1.0, 0.0, 0.0);
	switch (mc->lives) {
	case 5:	DrawString(GLUT_BITMAP_HELVETICA_18, "Lives: 5", 0.7, 0.92);	break;
	case 4:	DrawString(GLUT_BITMAP_HELVETICA_18, "Lives: 4", 0.7, 0.92);	break;
	case 3:	DrawString(GLUT_BITMAP_HELVETICA_18, "Lives: 3", 0.7, 0.92);	break;
	case 2:	DrawString(GLUT_BITMAP_HELVETICA_18, "Lives: 2", 0.7, 0.92);	break;
	case 1:	DrawString(GLUT_BITMAP_HELVETICA_18, "Lives: 1", 0.7, 0.92);	break;
	case 0:	DrawString(GLUT_BITMAP_HELVETICA_18, "Lives: 0", 0.7, 0.92);	break;
	}

	if (mc->lives <= 0)
		DrawString(GLUT_BITMAP_HELVETICA_18, "YOU ARE DEAD!", -0.22, -0.5);

	glColor3f(0.0, 0.0, 1.0);
	if (boss->health < 0) {
		DrawString(GLUT_BITMAP_HELVETICA_18, "YOU HAVE DEFEATED ANGELO!", -0.45, -0.5);
		DrawString(GLUT_BITMAP_HELVETICA_18, "YOU WIN!", -0.15, -0.65);
	}

	if (bossFight) {
		glBindTexture(GL_TEXTURE_2D, 1);
		boss->drawTex();
		glDisable(GL_TEXTURE_2D);
	}
	for (i = 0; i < enemies.size(); i++) {
		glBindTexture(GL_TEXTURE_2D, ta);
		enemies[i]->drawTex();
		glDisable(GL_TEXTURE_2D);
	}

	for (i = 0; i < mcShots.size(); i++) {
		mcShots[i]->draw();
	}
	for (i = 0; i < shots.size(); i++) {
		shots[i]->draw();
	}
}
