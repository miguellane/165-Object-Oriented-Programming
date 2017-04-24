#include "App.h"

App::App(const char* label, int x, int y, int w, int h) : GlutApp(label, x, y, w, h) {
	mx = 0.0;
	my = 0.0;
}

void App::draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	game.draw();

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
	float PI = 3.14159265359;
	float v = 0.00001f;
	switch (key) {
	case 27:	exit(0);	break;
	case ' ':	break;
	case 'w':	game.mc->direction = (float)(PI / 2); game.mc->velocity = v; break;
	case 'a':	game.mc->direction = (float)(PI); game.mc->velocity = v; break;
	case 's':	game.mc->direction = (float)((3*PI)/2); game.mc->velocity = v; break;
	case 'd':	game.mc->direction = (float)(2*PI); game.mc->velocity = v; break;
	}
	redraw();
}

void App::specialKeyPress(int key) {
	const float incf = 0.05f;
	float shiftx = 0, shifty = 0;
	switch (key) {
	case GLUT_KEY_LEFT:		shiftx -= incf; break;
	case GLUT_KEY_RIGHT:	shiftx += incf; break;
	case GLUT_KEY_UP:		shifty += incf; break;
	case GLUT_KEY_DOWN:		shifty -= incf; break;
	}
}
void App::idle() {
	game.update();
	draw();
}
