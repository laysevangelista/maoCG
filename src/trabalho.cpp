#include "plataforma.h"
#include "arm.h"
#include "camera.h"
#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif
#include <math.h>
#include <stdio.h>
#include <iostream>

#define VERSION "1.0"


class Trabalho
{
    public:
        static void run(int argc, char* argv[]);
    private:
        static int currentPart;

        static Plataforma plat;
        static Arm arm;

        static void configure();
        static void keyboardCallBack(unsigned char key, int x, int y);
        static void specialKeysCallBack(int key, int x, int y);
        static void displayCallBack();
        static void reshapeCallBack(int width, int height);
};

int Trabalho::currentPart = 1;

Plataforma Trabalho::plat;
Arm Trabalho::arm;

void Trabalho::run(int argc, char* argv[])
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowPosition(0,0);
    glutCreateWindow("Trabalho de Computacao Gráfica - 2017.2");


    configure();

    glutDisplayFunc(displayCallBack);
    glutKeyboardFunc(keyboardCallBack);
    glutSpecialFunc(specialKeysCallBack);
    glutReshapeFunc(reshapeCallBack);

    
    glutMainLoop();
}

void Trabalho::configure()
{
    GLfloat placeLight[4]={0.65,0.65,0.25,1.0};
    GLfloat diffusedLight[4]={0.5,0.5,0.5,1.0};
    GLfloat specularLight[4]={1.0, 1.0, 1.0, 1.0};
    GLfloat lightPosition[4]={10.0, 10.0, 1.0, 1.0};

    GLfloat specularity[4]={1.0,1.0,1.0,1.0};
    GLint materialSpecularity = 60;

    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT,GL_SPECULAR, specularity);
    
    glMateriali(GL_FRONT,GL_SHININESS,materialSpecularity);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, placeLight);

    glLightfv(GL_LIGHT0, GL_AMBIENT, placeLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffusedLight );
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight );
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition );

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_CULL_FACE);
}


void Trabalho::keyboardCallBack (unsigned char key, int x, int y)
{
    switch( key )
	{
		case 27: // ESC
			exit(0);
			break;
        case ' ': // ESPAÇO
            Camera::riseAngle();
			break;

        case 49: // 1 EM ASCII
            currentPart = 1;
            break;
        case 50: // 2 EM ASCII
            currentPart = 2;

            break;
        case 51: //3 EM ASCII
            currentPart = 3;

            break;
        case 'r': //RESETAR A CAMERA
            arm.reset();
            Camera::resetCamera();
            break;
    }
    glutPostRedisplay();
}

void Trabalho::specialKeysCallBack(int key, int x, int y)
{
    int modifier = glutGetModifiers();

    switch( key )
    {
        case GLUT_KEY_LEFT:
            if( modifier & GLUT_ACTIVE_CTRL )
                arm.moveLeft();
            
            else
                arm.rotateCounterClockwise(currentPart);
            break;

        case GLUT_KEY_RIGHT:
            if( modifier & GLUT_ACTIVE_CTRL )
                arm.moveRight();
            
            else
                arm.rotateClockwise(currentPart);
            break;

       case GLUT_KEY_UP:
            if( modifier & GLUT_ACTIVE_CTRL )
                arm.moveUp();
            
            else if(Camera::getZoom() > 1)
                Camera::zoomUp();
            break;

       case GLUT_KEY_DOWN:
            if( modifier & GLUT_ACTIVE_CTRL )
                arm.moveDown();
            
            else if(Camera::getZoom() < 20)
                Camera::zoomDown();
            break;
    }
    glutPostRedisplay(); 
}

void Trabalho::displayCallBack()
{
    glClear ( GL_COLOR_BUFFER_BIT ) ;
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    Camera::updateCamera(arm.getXarm(), arm.getYarm(), arm.getZarm());
    plat.draw();
    arm.draw();

    glutSwapBuffers();
}

void Trabalho::reshapeCallBack(int width, int height)
{
    glViewport (0, 0, (GLsizei) width, (GLsizei) height);
    float ratio = (float)width / (float)height;
    Camera::setWindowRatio(ratio);
    Camera::updateCamera(arm.getXarm(), arm.getYarm(), arm.getZarm());
}


int main(int argc, char** argv)
{
	Trabalho::run(argc,argv);
	return 0;
}
