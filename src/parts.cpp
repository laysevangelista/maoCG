#include "parts.h"
#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

Parts::Parts()
{
    handRotation    = 0;
    topPartRadius   = 0.03;
    fingerAngle     = 0;

}

void Parts::pushParts()
{
    glPushMatrix();
        drawPart(armRotation);
            drawJoint();
    
            glPushMatrix();
            glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}


void Parts::setArmRotation(float rotation)
{
    armRotation = rotation;
}

void Parts::setForeArmRotation(float rotation)
{
    foreArmRotation = rotation;
}

void Parts::drawPart(float rotation)
{
    glRotatef(rotation, 0, 1, 0);
    glColor3f(1,1,1.5);
    gluCylinder(gluNewQuadric(), 0.09, topPartRadius,
                                                0.18, 70.0, 70.0);
}

void Parts::setFingerAngle(float angle)
{
    fingerAngle = angle;
}

void Parts::rotateHand()
{
    handRotation += 10;
}

void Parts::drawJoint()
{
    glColor3f(0,0,1);
    glTranslatef(0, 0, 0.18 + 0.025);
    glRotatef(handRotation, 0, 0, 1);
    glutSolidSphere(0.025, 70.0, 70.0);
}

void Parts::drawHand()
{
    glColor3f(1,1,1);
    glRotatef(50,0,1,0);
    gluCylinder(gluNewQuadric(), 0.01, 0.01, 0.1, 70.0, 70.0);
    glTranslatef(0,0,0.1);

    glRotatef(-fingerAngle,0,1,0);
    glutSolidCone(0.008, 0.1,70.0, 70.0);
    glRotatef(fingerAngle,0,1,0);

    glTranslatef(0,0,-0.1);

    glRotatef(-100,0,1,0);
    gluCylinder(gluNewQuadric(), 0.008, 0.008, 0.1, 70.0, 70.0);
    glTranslatef(0,0,0.1);
    glRotatef(fingerAngle,0,1,0);
    glutSolidCone(0.008, 0.1,70.0, 70.0);
    glRotatef(-fingerAngle,0,1,0);
    glTranslatef(0,0,-0.1);
}

void Parts::closeHand()
{
    if( fingerAngle < 120 )
        fingerAngle += 10;
}

void Parts::openHand()
{
    if( fingerAngle >= 0 )
        fingerAngle -= 10;
}
