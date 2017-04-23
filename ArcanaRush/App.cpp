#include "App.h"

App::App(const char* label, int x, int y, int w, int h) : GlutApp(label, x, y, w, h) {
	// Initialize state variables
	mx = 0.0;
	my = 0.0;
	mode = 0;
}

void App::draw() {
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Set background color to black
	glClearColor(0.0, 0.0, 0.0, 1.0);
	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	game.draw();

	// We have been drawing everything to the back buffer
	// Swap the buffers to see the result of what we drew
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
	switch (key) {
	case ' ':	game = Board(); break;
	case 27:	exit(0);	break;
	case 'q':	mode = 0;	game = Board();		break;
	case 'a':	mode = 1;	game = Board();		break;
	case 'w':	game = Board();	game.aiTurn();	break;
	case 's':	game = Board();						break;
	}
	redraw();
}

void App::specialKeyPress(int key) {
	const float incf = 0.05f;
	float shiftx = 0, shifty = 0;
	switch (key) {
	case GLUT_KEY_LEFT:		shiftx -= incf; break;
	case GLUT_KEY_RIGHT:	shiftx += incf; break;
	case GLUT_KEY_UP:			shifty += incf; break;
	case GLUT_KEY_DOWN:   shifty -= incf; break;
	}
}
