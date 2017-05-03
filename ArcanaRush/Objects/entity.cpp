#include "Entity.h"
#include "GlutApp.h"

Entity::Entity(float x, float y, float w, float h, float d, float v, int mv, float r, float g, float b){
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->direction = d;
	this->velocity = v;
	this->acceleration = 0;
	this->movePattern = mv;
	this->r = r;
	this->g = g;
	this->b = b;

	/* Load Textures
	#if defined WIN32
	monalisa = loadTexture("..\\monalisa.bmp");
	kyrilov = loadTexture("..\\kyrilov.bmp");
	#else
	monalisa = loadTexture("monalisa.bmp");
	kyrilov = loadTexture("kyrilov.bmp");
	#endif

	boss1 = new TexRect(-1, 1, 2, 2);
	boss2 = new TexRect(0, 0.67, 0.5, 0.67);
	*/
}

GLuint Entity::loadTexture(const char *filename) {
	GLuint texture_id;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap(filename);

	// Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
	//    Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(),
		GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());

	return texture_id;
}

void Entity::update(){
	float dTweak = 0.001f;
	float vTweak = 0.00001f;
	float aTweak = 0.001f;

	switch(movePattern){
		case 0: velocity = 0; acceleration = 0; break;
		case 1: break;
		case 2: velocity += vTweak; break;
		case 3: if(velocity > 0) velocity -= vTweak; else velocity = 0; break;
		case 4: direction += dTweak; break;
		case 5: direction -= dTweak; break;
		case 6: acceleration += aTweak; break;
		case 7: acceleration -= aTweak; break;
	}


	x += velocity * cos(direction);
	y += velocity * sin(direction);
	velocity += acceleration;
}

void Entity::draw(){
	glColor3f(r, g, b);
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + w, y);
	glVertex2f(x + w, y - h);
	glVertex2f(x, y - h);
	glEnd();

	/* Bind and Draw Textures
	glColor3d(1.0, 1.0, 1.0);

	glBindTexture(GL_TEXTURE_2D, monalisa);
	boss1->draw();

	glBindTexture(GL_TEXTURE_2D, kyrilov);
	boss2->draw();

	glDisable(GL_TEXTURE_2D);
	*/
}

bool Entity::contains(float x, float y, float w, float h) {
	;

	return false;
}
