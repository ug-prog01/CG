#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>

using namespace std;

void init();
void display();
void dda(float, float, float, float);
void bressen(float);

float a1, b1, a2, b2;
int dx, dy, x, y, len, i;

int main(int argc, char **argv)
{
	cout<<"Enter co-ordinates for starting point:";
	cin>>a1>>b1;
	cout<<"Enter co-ordinates for end point:";
	cin>>a2>>b2;
	glutInit(&argc,argv);
	glutCreateWindow("Utkarsh (65)");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

void init()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-100, 100, -100, 100);
}

void display()
{
	dda(a1, b1, a1, b2);
	dda(a1, b1, a2, b1);
	dda(a2, b1, a2, b2);
	dda(a1, b2, a2, b2);
	dda((a1+a2)/2, b1, a2, (b2+b1)/2);
	dda((a1+a2)/2, b1, a1, (b2+b1)/2);
	dda(a1,(b1+b2)/2,(a1+a2)/2,b2);
	dda((b1+b2)/2, a2, b2, (a2+a1)/2);
	dda((a1+(a1+a2)/2)/2, (b1 + (b1+b2)/2)/2, (a1 + (a1+a2)/2)/2, (b2 +(b1+b2)/2)/2);
	dda((a1+(a1+a2)/2)/2, (b1 + (b1+b2)/2)/2, (a2 + (a1+a2)/2)/2, (b1 +(b1+b2)/2)/2);
	dda((a2+(a1+a2)/2)/2, (b1 + (b1+b2)/2)/2, (a2 + (a1+a2)/2)/2, (b2 +(b1+b2)/2)/2);
	dda((a1+(a1+a2)/2)/2, (b2 + (b1+b2)/2)/2, (a2 + (a1+a2)/2)/2, (b2 +(b1+b2)/2)/2);
	glFlush();
}

void dda(float a1, float b1, float a2, float b2)
{
	dx = abs(a2 - a1);
	dy = abs(b2 - b1);
	
	if(dx >= dy)
	{
		len = dx;
	}
	else
	{
		len = dy;
	}
	
	dx = (a2 - a1)/len;
	dy = (b2 - b1)/len;
	
	x = a1;
	y = b1;
	i = 1;
	while(i<=len)
	{
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
		x = x + dx;
		y = y + dy;
		i = i + 1;
	}
}
