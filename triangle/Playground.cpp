#include <GL/glut.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -200, 200);
}

void axis() {
    glBegin(GL_LINES);
    glVertex2i(-100, 0); // x axis
    glVertex2i(100, 0);
    glVertex2i(0, 100); // y axis
    glVertex2i(0, -100);
    glEnd();
}

void Triang1() {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(50, 40); // v0
    glVertex2i(90, 40); // v1
    glVertex2i(70, 90); // v2
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(-50, 100); // v3
    glColor3f(1.0, 1.0, 0.0);
    glVertex2i(-100, 90); // v4
    glEnd();
}

void TrianglLINE() {
    glBegin(GL_LINE_LOOP);
    glVertex2i(50, 40); // v0
    glVertex2i(90, 40); // v1
    glVertex2i(70, 90); // v2
    glVertex2i(-50, 100); // v3
    glVertex2i(-100, 90); // v4
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(50, 40); // v0
    glVertex2i(70, 90); // v1
    glVertex2i(50, 40); // v2
    glVertex2i(-50, 100); // v3
    glEnd();
}

void myDisp() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    axis();
    glColor3f(1.0, 0.0, 1.0);
    Triang1();
    glColor3f(0.0, 0.0, 0.0);
    TrianglLINE();
    glFlush();
}

void main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Viewing Transformation");
    init();
    glutDisplayFunc(myDisp);
    glutMainLoop();
}
