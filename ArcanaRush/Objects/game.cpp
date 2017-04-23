#include "Game.h"
#include "GlutApp.h"
Game::Game(){
	score = 0;
	mc = new Character(0.0f, -0.5f, 0.001f, 0.001f, 0.0f, 0.0f);
}
void Game::update(){
	mc->update();
	for (int i = 0; i < mcShots.size(); i++)
		mcShots[i]->update();

	if (bossFight)
		boss->update();
	for (int i = 0; i < enemies.size(); i++)
		enemies[i]->update();
	for (int i = 0; i < shots.size(); i++)
		shots[i]->update();
}
void Game::draw() {
	mc->draw();
	for(int i = 0; i < mcShots.size(); i++)
		mcShots[i]->draw();

	if(bossFight)
		boss->draw();
	for (int i = 0; i < enemies.size(); i++)
		enemies[i]->draw();
	for (int i = 0; i < shots.size(); i++)
		shots[i]->draw();
}
