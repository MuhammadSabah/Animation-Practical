#include <GL/glut.h>
#include <cmath>

GLfloat rotationAngles[5] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f }; // One rotation angle for each triangle

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set the clear color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 100);
    gluLookAt(7, 2, 5, 0, 0, 0, 0, 1, 0);
}

void drawPyramid() {
    for (int i = 0; i < 5; i++) {
        glPushMatrix();
        glRotatef(rotationAngles[i], 0, 1, 0); // Rotate around the y-axis

        glBegin(GL_TRIANGLES);

        // Define gradient colors for each triangle
        if (i == 0) {
            glColor3f(1.0, 0.0, 0.0); // Red at the top
            glVertex3f(0, 2, 0);

            glColor3f(0.7, 0.0, 0.0); // Darker red at the vertices
            glVertex3f(-1, 0, 1);

            glColor3f(0.3, 0.0, 0.0); // Even darker red at the vertices
            glVertex3f(-1, 0, -1);
        }
        else if (i == 1) {
            glColor3f(0.0, 1.0, 0.0); // Green at the top
            glVertex3f(0, 2, 0);

            glColor3f(0.0, 0.7, 0.0); // Darker green at the vertices
            glVertex3f(-1, 0, -1);

            glColor3f(0.0, 0.3, 0.0); // Even darker green at the vertices
            glVertex3f(1, 0, -1);
        }
        else if (i == 2) {
            glColor3f(0.0, 0.0, 1.0); // Blue at the top
            glVertex3f(0, 2, 0);

            glColor3f(0.0, 0.0, 0.7); // Darker blue at the vertices
            glVertex3f(-1, 0, 1);

            glColor3f(0.0, 0.0, 0.3); // Even darker blue at the vertices
            glVertex3f(1, 0, 1);
        }
        else if (i == 3) {
            glColor3f(1.0, 1.0, 0.0); // Yellow at the top
            glVertex3f(0, 2, 0);

            glColor3f(0.7, 0.7, 0.0); // Darker yellow at the vertices
            glVertex3f(1, 0, 1);

            glColor3f(0.3, 0.3, 0.0); // Even darker yellow at the vertices
            glVertex3f(1, 0, -1);
        }
        else if (i == 4) {
            glColor3f(1.0, 1.0, 1.0); // White for the base
            glVertex3f(1, 0, 1);

            glColor3f(1.0, 1.0, 1.0); // White for the base
            glVertex3f(1, 0, -1);

            glColor3f(1.0, 1.0, 1.0); // White for the base
            glVertex3f(-1, 0, 1);

            glColor3f(1.0, 1.0, 1.0); // White for the base
            glVertex3f(-1, 0, -1);
        }

        glEnd();

        glPopMatrix();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawPyramid();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'q') {
        for (int i = 0; i < 5; i++) {
            rotationAngles[i] += 2.0;
        }
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("3D Pyramid");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}
