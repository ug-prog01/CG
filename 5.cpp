#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>

using namespace std;

void init();
void display();
void cube();
void polygon(int a, int b, int c, int d);
void spinCube();

float vertex[][3] = {{-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1}, {-1, -1, 1}, {1, -1, 1}, {1, 1, 1}, {-1, 1, 1}};
float color[][3] = {{0, 0, 0}, {1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {1, 1, 0}, {1, 0, 1}, {1, 1, 1}, {0, 1, 1}};

int axis = 2;
float theta[3] = {60, 60, 60};

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB| GLUT_DEPTH);
	glutCreateWindow("Utkarsh (65)");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(spinCube);
	glutMainLoop();
}

void spinCube()
{
    theta[axis] += 1;
    if(theta[axis] > 360)
        theta[axis] -= 360;
    glutPostRedisplay();
}

void cube()
{
    polygon(0, 1, 2, 3);
    polygon(0, 1, 5, 4);
    polygon(2, 3, 7, 6);
    polygon(4, 5, 6, 7);
    polygon(5, 1, 2, 6);
    polygon(4, 0, 3, 7);
}

void polygon(int a, int b, int c, int d)
{
    glBegin(GL_POLYGON);
    glColor3fv(color[a]);
    glVertex3fv(vertex[a]);
    glColor3fv(color[b]);
    glVertex3fv(vertex[b]);
    glColor3fv(color[c]);
    glVertex3fv(vertex[c]);
    glColor3fv(color[d]);
    glVertex3fv(vertex[d]);
    glEnd();
    glFlush();
}

void init()
{
	glClearColor(1, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-2, 2, -2, 2, -2, 2);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);
    cube();
	glFlush();
	glutSwapBuffers();
}
