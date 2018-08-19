#include "plataforma.h"
#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

void Plataforma::draw()
{
	glColor3f(0, 0, 1);

	 glPushMatrix();
         glScalef(1,0.15,1.3);
         glTranslatef(0,0, 0);
         glutSolidCube(0.75);

     glPopMatrix();
}

Plataforma::Plataforma()
{
}
