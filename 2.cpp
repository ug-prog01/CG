#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>

using namespace std;

void init();
void display();
void dda(float, float, float, float);
void bressen(float);

float a1, b1, a2, b2, r;
float dx, dy, x, y, len, i;

int main(int argc, char **argv)
{
	cout<<"Enter radius:";
	cin>>r;
	glutInit(&argc,argv);
	glutCreateWindow("Utkarsh (65)");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

void init()
{
	glClearColor(1, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-100, 100, -100, 100);
}

void display()
{
	bressen(r);
	bressen(2*r);
	dda(0, 2*r, -1.71*r, -r);
	dda(-1.71*r, -r, 1.71*r, -r);
	dda(1.71*r, -r, 0, 2*r);
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

void bressen(float r)
{
	float d = 3 - (2*r);
	float x = 0;
	float y = r;
	
	do
	{
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glVertex2i(x, -y);
		glVertex2i(-x, y);
		glVertex2i(-x, -y);
		glVertex2i(y, x);
		glVertex2i(y, -x);
		glVertex2i(-y, x);
		glVertex2i(-y, -x);
		glEnd();
		if(d<0)
		{
			d = d + (4*x) + 6;
		}
		else
		{
			d = d + (4*(x - y)) + 10;
			y = y - 1;
		}
		x = x + 1;
	}while(x<y);
}
