#include <iostream>
#include <GL/glut.h>

GLfloat TranslateV = 0;
GLfloat TransalteH = 0;

void Quad() {
	glBegin(GL_QUADS);
	glVertex2i(-12, 15);
	glVertex2i(12, 15);
	glVertex2i(12, -15);
	glVertex2i(-12, -15);
	glEnd();
}

void QuadStrip() {
	glBegin(GL_QUAD_STRIP);

	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(-15, 15);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(15, 15);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(-15, -15);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2i(15, -15);

	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(-10 + TransalteH, 10 + TranslateV);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(10 + TransalteH, 10 + TranslateV);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(-10 + TransalteH, -10 + TranslateV);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2i(10 + TransalteH, -10 + TranslateV);

	glEnd();
}



void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void GL_display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();

	glLineWidth(2);


	QuadStrip();

	glColor3f(1.0, 1.0, 0.0); 
	glTranslatef(-45.0, 0.0, 0.0);
	Quad();

	glPushMatrix();
	glTranslatef(12.0, -15.0, 0.0);
	glRotatef(160.0, 0.0, 0.0, 1.0);
	glTranslatef(-12.0, 15.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	Quad();
	glPopMatrix();


	glTranslatef(-12.0, 15.0, 0.0);
	glScalef(-0.5,- 0.5, 1.0);
	glColor3f(1.0, 0.0, 1.0);
	glTranslatef(12.0, -15.0, 0.0);
	Quad();


	glPopMatrix();
	glutSwapBuffers();
}



void GL_reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-70, 70, -70, 70);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void GL_kryboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
		TranslateV += 1;
		glutPostRedisplay();
		break;

	case 's':
		TranslateV -= 1;
		glutPostRedisplay();
		break;

	case 'd':
		TransalteH += 1;
		glutPostRedisplay();
		break;

	case 'a':
		TransalteH -= 1;
		glutPostRedisplay();
		break;

	case 27:
		exit(0);
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("User Controlled Transformations");
	init();
	glutDisplayFunc(GL_display);
	glutReshapeFunc(GL_reshape);
	glutKeyboardFunc(GL_kryboard);
	glutMainLoop();
}
