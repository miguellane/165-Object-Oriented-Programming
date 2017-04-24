#include "Game.h"
#include "GlutApp.h"
Game::Game(){
	score = 0;
	bossFight = false;
	mc = new Character(0.0f, -0.5f, 0.01f, 0.01f, 0.0f, 0.0f);
}
void Game::update(){
	size_t i;

	mc->update();
	for (i = 0; i < mcShots.size(); i++)
		mcShots[i]->update();

	if (bossFight)
		boss->update();
	for (i = 0; i < enemies.size(); i++)
		enemies[i]->update();
	for (i = 0; i < shots.size(); i++)
		shots[i]->update();

}
void Game::draw() {
	size_t i;

	mc->draw();
	for(i = 0; i < mcShots.size(); i++)
		mcShots[i]->draw();

	if(bossFight)
		boss->draw();
	for (i = 0; i < enemies.size(); i++)
		enemies[i]->draw();
	for (i = 0; i < shots.size(); i++)
		shots[i]->draw();
}
