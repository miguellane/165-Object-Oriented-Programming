#include "App.h"

App::App(const char* label, int x, int y, int w, int h) : GlutApp(label, x, y, w, h) {
	mx = 0.0;
	my = 0.0;

	// Load Textures
	kyrilov = loadTexture("..\\kyrilov.bmp");
	wei = loadTexture("..\\wei.bmp");
	shang = loadTexture("..\\shang.bmp");
	xin = loadTexture("..\\xin.bmp");
	galaxy = loadTexture("..\\galaxy.bmp");

	background = new TexRect(-1.0, 1.0, 2.0, 2.0);
}

GLuint App::loadTexture(const char *filename) {
	GLuint texture_id;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap(filename);

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(),
		GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());

	return texture_id;
}

void App::draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	game.draw();

	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, 5);
	background->draw();
	glDisable(GL_TEXTURE_2D);

	glFlush();
	glutSwapBuffers();
}

void App::mouseDown(float x, float y) {
	mx = x;
	my = y;
}

void App::mouseDrag(float x, float y) {
	mx = x;
	my = y;
}

void App::keyPress(unsigned char key) {
	float v = 0.001f;
	switch (key) {
	case 27:	exit(0);	break;
	case 'p':	game.pause = !game.pause;
	case 'z': game.godMode = !game.godMode;	break;
	case 'e':	game.mc->bombsDeploy = !game.mc->bombsDeploy;	break;
	case 'w':	game.mc->direction = (float)(PI / 2); game.mc->velocity = v; break;
	case 'a':	game.mc->direction = (float)(PI); game.mc->velocity = v; break;
	case 's':	game.mc->direction = (float)((3 * PI) / 2); game.mc->velocity = v; break;
	case 'd':	game.mc->direction = (float)(2 * PI); game.mc->velocity = v; break;


	case 'i':	game.mc->direction = (float)(PI / 2); game.mc->velocity = v; break;
	case 'j':	game.mc->direction = (float)(PI); game.mc->velocity = v; break;
	case 'k':	game.mc->direction = (float)((3 * PI) / 2); game.mc->velocity = v; break;
	case 'l':	game.mc->direction = (float)(2 * PI); game.mc->velocity = v; break;

	}
	redraw();
}

void App::specialKeyPress(int key) {
	const float incf = 0.05f;
	float shiftx = 0, shifty = 0;
	switch (key) {
	case GLUT_KEY_LEFT:		game.mc->atk = 3; break;
	case GLUT_KEY_RIGHT:	game.mc->atk = 4; break;
	case GLUT_KEY_UP:		game.mc->atk = 1; break;
	case GLUT_KEY_DOWN:		game.mc->atk = 2; break;
	
	}
}
void App::idle() {
	if (!game.pause)
		game.update();
	draw();
}
