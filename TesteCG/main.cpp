
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
// #include <GLUT/glut.h>  usado no MacOs
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string.h>


#define Pi 3.14

using namespace std;
static float zoom = 3,
xtrans = 0.1,
ytrans = 0.0,
ztrans = 0.0,
angle = 65.0,
eyeX = 0.1,
eyeY = 0.1,
eyeZ = 0.1,
windowRatio = 1;
static int
spin_z = 0, //cotovelo
spin_x = 0,
mao = 0,
fumb = 0,
point = 0,
middle = 0,
ring = 0,
tiny = 0,
largura = 1200,
altura = 600;
void zoomUp()
{
    zoom -= 0.1;

}
void zoomDown()
{
    zoom += 0.1;

}

void riseAngle() {
    angle++;

}
void init(void)
{
    glClearColor(0, 0, 0, 1);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
}

void robotarm(void)
{
    glClear(GL_DEPTH_BUFFER_BIT);

    //base do cotovelo
    glTranslatef(xtrans, ytrans, ztrans);
    glRotatef((GLfloat)spin_z, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)spin_x, 1.0, 0.0, 0.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glColor3f(0.3, 0, 0.5);
    glScalef(1.5, 0.4, 1.0);
    glutSolidCube(1);
    glPopMatrix();

    //mao
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)mao, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.0);
    glPushMatrix();
    glColor3f(0.3, 0, 0.5);
    glScalef(1.0, 0.5, 1.0);
    glutSolidCube(1);
    glPopMatrix();


    //dedao
    glPushMatrix();
    glTranslatef(0.0, 0.125, -0.2);
    glRotatef((GLfloat)fumb, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.8);
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glScalef(0.5, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();

    glTranslatef(0.15, 0.0, -0.8);
    glRotatef((GLfloat)fumb, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.8);
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glScalef(0.5, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();
    glPopMatrix();


    //dedo indicador
    glPushMatrix();
    glTranslatef(0.4, 0.1, 0.0);
    glRotatef((GLfloat)point, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.4);
    glPushMatrix();
    glColor3f(0.8, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)point, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.0);
    glPushMatrix();
    glColor3f(0.8, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)point, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.0);
    glPushMatrix();
    glColor3f(0.8, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();
    glPopMatrix();



    //dedo do meio
    glPushMatrix();
    glTranslatef(0.5, 0.10, 0.0);
    glRotatef((GLfloat)middle, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.0);
    glPushMatrix();
    glColor3f(0.65, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)middle, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.0);
    glPushMatrix();
    glColor3f(0.65, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();
    
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)middle, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.0);
    glPushMatrix();
    glColor3f(0.65, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();
    glPopMatrix();


    //anelar
    glPushMatrix();
    glTranslatef(0.5, 0.1, 0.0);
    glRotatef((GLfloat)ring, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, -0.4);
    glPushMatrix();
    glColor3f(0.5, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();

    glTranslatef(0.5, 0.1, 0.0);
    glRotatef((GLfloat)ring, 0.0, 0.0, 1.0);
    glTranslatef(0.0, -0.1, 0.0);
    glPushMatrix();
    glColor3f(0.5, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();
    
    glTranslatef(0.5, 0.1, 0.0);
    glRotatef((GLfloat)ring, 0.0, 0.0, 1.0);
    glTranslatef(0.0, -0.1, 0.0);
    glPushMatrix();
    glColor3f(0.5, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();
    glPopMatrix();


    //dedo mindinho
    glPushMatrix();
    glTranslatef(0.2, 0.1, 0.0);
    glRotatef((GLfloat)tiny, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, -0.6);
    glPushMatrix();
    glColor3f(0.35, 0.0, 0.0);
    glScalef(0.5, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();

    glTranslatef(0.4, 0.1, 0.0);
    glRotatef((GLfloat)tiny, 0.0, 0.0, 1.0);
    glTranslatef(0.0, -0.1, 0.0);
    glPushMatrix();
    glColor3f(0.35, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();
    
    glTranslatef(0.4, 0.1, 0.0);
    glRotatef((GLfloat)tiny, 0.0, 0.0, 1.0);
    glTranslatef(0.0, -0.1, 0.0);
    glPushMatrix();
    glColor3f(0.35, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();

}

void getwh(int w, int h)
{
    largura = w;
    altura = h;
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 0; i <= 4; i++) {
        if (i == 0) {
            glViewport(0, altura / 2, largura / 2, altura / 2);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(angle, (GLfloat)largura / (GLfloat)altura, 1.0, 20.0);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glTranslatef(0.0, 0.0, -5.0);
            robotarm();
        }
        else if (i == 1) {
            glViewport(largura, altura, largura / 2, altura / 2);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(angle, (GLfloat)largura / (GLfloat)altura, 1.0, 20.0);
            gluLookAt(6, 0, -5.0, 0, 0, -5.0, 0, 1, 0);
            glLoadIdentity();
            glTranslatef(0.0, 0.0, -5.0);
            robotarm();
        }
        else if (i == 2) {
            glViewport(largura / 2, 0, largura / 2, altura / 2);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(angle, (GLfloat)largura / (GLfloat)altura, 1.0, 20.0);
            gluLookAt(6, 6, -0.0, 0, 0, -5.0, 0, 1, 0);
            glLoadIdentity();
            glTranslatef(0.0, 0.0, -5.0);
            robotarm();
        }
        else if (i == 3) {
            glViewport(0, 0, largura / 2, altura / 2);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(angle, (GLfloat)largura / (GLfloat)altura, 1.0, 20.0);
            gluLookAt(6, 0, -5.0, 0, 0, -5.0, 0, -1, 0);
            glLoadIdentity();
            glTranslatef(0.0, 0.0, -5.0);
            robotarm();
        }
    }
    glFlush();
    glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y)
{
    switch (key) {

    case ' ': // ESPACE key
        riseAngle();
        break;
    case 'w':
        if (angle >= 10) angle -= 5;
        xtrans -= 0.2;
        glutPostRedisplay();
        break;
    case 's':
        if (angle <= 130) angle += 5;
        xtrans += 0.2;
        glutPostRedisplay();
        break;
    case 'j':
        if (spin_z < 180)
            spin_z = (spin_z + 5) % 360;
        glutPostRedisplay();
        break;
    case 'l':
        if (spin_z>0)
            spin_z = (spin_z - 5) % 360;
        glutPostRedisplay();
        break;
    case 'i':
        if (spin_x < 180)
            spin_x = (spin_x + 5) % 360;
        glutPostRedisplay();
        break;
    case 'k':
        if (spin_x>0)
            spin_x = (spin_x - 5) % 360;
        glutPostRedisplay();
        break;
    case 't':
        ytrans += 0.1;
        glutPostRedisplay();
        break;

    case 'g':
        ytrans -= 0.1;
        glutPostRedisplay();
        break;

    case 'f':
        xtrans -= 0.1;
        glutPostRedisplay();
        break;
    case 'h':
        xtrans += 0.1;
        glutPostRedisplay();
        break;
        //mao
    case 'm':
        if (mao < 90)
            mao = (mao + 3) % 360;
        glutPostRedisplay();
        break;
    case 'n':
        if (mao > -90)
            mao = (mao - 3) % 360;
        glutPostRedisplay();
        break;
        //dedao
    case 49: //ascii 1
        if (fumb < 90)
            fumb = (fumb + 5) % 360;
        glutPostRedisplay();
        break;
        //Pointer Finger
    case 50://2
        if (point < 90)
            point = (point + 5) % 360;
        glutPostRedisplay();
        break;
        //dedo do meio
    case 51://3
        if (middle < 90)
            middle = (middle + 5) % 360;
        glutPostRedisplay();
        break;
        //anelar
    case 52://4
        if (ring < 90)
            ring = (ring + 5) % 360;
        glutPostRedisplay();
        break;
        //dedo mindinho
    case 53://5
        if (tiny < 90)
            tiny = (tiny + 5) % 360;
        glutPostRedisplay();
        break;
        // mao toda fechada
    case 'd':
        if (fumb < 90)
            fumb = (fumb + 5) % 360;
        if (point < 90)
            point = (point + 5) % 360;
        if (middle < 90)
            middle = (middle + 5) % 360;
        if (ring < 90)
            ring = (ring + 5) % 360;
        if (tiny < 90)
            tiny = (tiny + 5) % 360;
        glutPostRedisplay();
        break;
    case 'a'://mao toda aberta
        if (fumb > 0)
            fumb = (fumb - 5) % 360;
        if (point > 0)
            point = (point - 5) % 360;
        if (middle > 0)
            middle = (middle - 5) % 360;
        if (ring > 0)
            ring = (ring - 5) % 360;
        if (tiny > 0)
            tiny = (tiny - 5) % 360;
        glutPostRedisplay();
        break;
    case 27: // esc
        exit(0);
        break;
    default:
        break;
    }
}






int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(largura, altura);
    glutInitWindowPosition(80, 80);
    glutCreateWindow("Trabalho de Computacao Gráfica - 2017.2");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(getwh);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
