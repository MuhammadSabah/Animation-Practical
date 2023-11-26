#include <iostream>
#include<GL\glut.h>


void myInit(void) {
    glClearColor(0.8, 0.8, 1.0, 0.0);
    glPointSize(10.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 700, 0.0, 700);
}

void myDist() {

   glTranslatef(320, 400, 0);
   glColor3f(1.0, 0, 0);
   glBegin(GL_POLYGON);
   glVertex2f(0, 60);
   glVertex2f(40, 0);
   glVertex2f(80, 60);
   glVertex2f(40, 120);
   glEnd();

   glBegin(GL_POLYGON);
   glVertex2f(-60, -65);
   glVertex2f(5, -65 );
   glVertex2f(40, 0);
   glVertex2f(-30, 0 );
   glEnd();

   glBegin(GL_POLYGON);
   glVertex2f(40, 0);
   glVertex2f(105, 0);
   glVertex2f(140, -65);
   glVertex2f(70, -65);
   glEnd();
 
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Graphic Assignment");
    myInit();
    glutDisplayFunc(myDist);
    glutMainLoop();
    return 0;
}


