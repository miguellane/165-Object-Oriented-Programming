#ifndef App_hpp
#define App_hpp

# include "GlutApp.h"
# include "Objects/Game.h"

class App : public GlutApp {
	float mx;
	float my;
	Game game;

public:
	App(const char* label, int x, int y, int w, int h);

	void draw();
	void keyPress(unsigned char key);
	void mouseDown(float x, float y);
	void mouseDrag(float x, float y);
	void specialKeyPress(int key);
	void idle();

	GLuint loadTexture(const char* filename);

	GLuint monalisa;
	GLuint kyrilov;

	TexRect* boss1;
	TexRect* boss2;
};

#endif
