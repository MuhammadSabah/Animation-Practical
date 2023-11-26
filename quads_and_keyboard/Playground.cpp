#include <iostream>
#include <GL/glut.h>
#include <cmath>

GLfloat TranslateV = 0;
GLfloat TransalteH = 0;
GLfloat rotationAngle = 0;  // Added for rotation
bool rotateFlag = false;  // Flag to control rotation

void Quad() {
	glBegin(GL_QUADS);
	glVertex2i(-12, 15);
	glVertex2i(12, 15);
	glVertex2i(12, -15);
	glVertex2i(-12, -15);
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

	glColor3f(1.0, 1.0, 0.0);

	// Apply translation
	glTranslatef(-45.0 + TransalteH, 0.0 + TranslateV, 0.0);

	// Apply rotation
	glRotatef(rotationAngle, 0, 0, 1);

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

void GL_keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
		TranslateV += 1;
		break;

	case 's':
		TranslateV -= 1;
		break;

	case 'd':
		TransalteH += 1;
		break;

	case 'a':
		TransalteH -= 1;
		break;

	case 'e':  // Rotate to the right
		rotationAngle += 5;  // You can adjust the angle increment as desired
		break;

	case 'q':  // Rotate to the left
		rotationAngle -= 5;  // You can adjust the angle increment as desired
		break;

	case 'r':
		rotateFlag = true;
		break;

	case 'n':
		rotateFlag = false;
		break;

	case 27:
		exit(0);
	}
	glutPostRedisplay();
}


void GL_idle() {
	if (rotateFlag) {
		rotationAngle += 0.05;

		glutPostRedisplay();
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("User Controlled Transformations");
	init();
	glutDisplayFunc(GL_display);
	glutReshapeFunc(GL_reshape);
	glutKeyboardFunc(GL_keyboard);
	glutIdleFunc(GL_idle);
	glutMainLoop();
	return 0;
}
