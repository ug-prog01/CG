#include<windows.h>
#include<iostream>
#include<glut.h>
#include<glu.h>
#include<math.h>

using namespace std;

void init();
void display();
void dda(float, float, float, float);
void ddas(float, float, float, float);
void ddat(float, float, float, float);
void ddar(float, float, float, float);
void ddare(float, float, float, float);
void ddash(float, float, float, float);

float a1, b1, a2, b2, r;
float dx, dy, x, y, len, i;

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Utkarsh (65)");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

void init()
{
	glClearColor(1, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-300, 300, -300, 300);
}

void display()
{
	dda(300, 0, -300, 0);
	dda(0, 300, 0, -300);
	glFlush();
	int ch;
	do{
	cout<<"Main Menu:\n1. Triangle\n2. Rhombus\n3. Exit\nEnter your choice:";
	cout<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"Y-coordinate";
			cin>>r;
			ddat(1.5*r, 3*r, 0, 0);
			ddat(0, 0, 3*r, 0);
			ddat(3*r, 0,  1.5*r, 3*r);

			ddas(1.5*r, 3*r, 0, 0);
			ddas(0, 0, 3*r, 0);
			ddas(3*r, 0,  1.5*r, 3*r);

			ddar(1.5*r, 3*r, 0, 0);
			ddar(0, 0, 3*r, 0);
			ddar(3*r, 0,  1.5*r, 3*r);

			ddare(1.5*r, 3*r, 0, 0);
			ddare(0, 0, 3*r, 0);
			ddare(3*r, 0,  1.5*r, 3*r);

			ddash(1.5*r, 3*r, 0, 0);
			ddash(0, 0, 3*r, 0);
			ddash(3*r, 0,  1.5*r, 3*r);

			glFlush();
			break;
		case 2:
			cout<<"Y-coordinate";
			cin>>r;
			ddat(0, 3*r, 3*r, 6*r);
			ddat(3*r, 6*r,  6*r, 3*r);
			ddat(3*r, 0,  6*r, 3*r);
			ddat(3*r, 0, 0, 3*r);

			ddas(0, 3*r, 3*r, 6*r);
			ddas(3*r, 6*r,  6*r, 3*r);
			ddas(3*r, 0,  6*r, 3*r);
			ddas(3*r, 0, 0, 3*r);

			ddash(0, 3*r, 3*r, 6*r);
			ddash(3*r, 6*r,  6*r, 3*r);
			ddash(3*r, 0,  6*r, 3*r);
			ddash(3*r, 0, 0, 3*r);

			ddar(0, 3*r, 3*r, 6*r);
			ddar(3*r, 6*r,  6*r, 3*r);
			ddar(3*r, 0,  6*r, 3*r);
			ddar(3*r, 0, 0, 3*r);

			ddare(0, 3*r, 3*r, 6*r);
			ddare(3*r, 6*r,  6*r, 3*r);
			ddare(3*r, 0,  6*r, 3*r);
			ddare(3*r, 0, 0, 3*r);

			glFlush();
			break;
		case 3:
			cout<<"Have a good one!!\n";
			break;
		default:
			cout<<"Invalid!!";
			break;
	}}while(ch!=3);
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

void ddas(float a1, float b1, float a2, float b2)
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
		glVertex2i(-2*x, 2*y);
		glEnd();
		x = x + dx;
		y = y + dy;
		i = i + 1;
	}
}

void ddat(float a1, float b1, float a2, float b2)
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
		glVertex2i(x+150, y+150);
		glEnd();
		x = x + dx;
		y = y + dy;
		i = i + 1;
	}
}

void ddar(float a1, float b1, float a2, float b2)
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
		glVertex2i(x*cos(60) - y*sin(60),  x*sin(60) + y*cos(60));
		glEnd();
		x = x + dx;
		y = y + dy;
		i = i + 1;
	}
}

void ddare(float a1, float b1, float a2, float b2)
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
		glVertex2i(x, -y);
		glEnd();
		x = x + dx;
		y = y + dy;
		i = i + 1;
	}
}

void ddash(float a1, float b1, float a2, float b2)
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
		//glVertex2i(x*2, y);
		glVertex2i(x + y*1.5 , y);
		glEnd();
		x = x + dx;
		y = y + dy;
		i = i + 1;
	}
}
