#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>
#include<math.h>

using namespace std;

struct abc
{
	int x4;
	int y4;
}vertex[1];
int point=0;

struct Color
{
    float r;
    float g;
    float b;
}fillcolor;

void init();
void display();
void dda(float, float, float, float);
void mouseR(int button, int state, int x4, int y4);

void keyR(unsigned char key, int x4, int y4);
int startx, starty;
float a1, b1, a2, b2, r;
float dx, dy, x, y, len, i;

Color getPixelColor(int x, int y)
{
    Color color;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
    return color;
}

void setPixelColor(int x, int y, Color color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void floodFill(int x, int y, Color oldColor, Color newColor)
{
	Color color;
	color= getPixelColor(x,y);
	if(color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b)
		{
			setPixelColor(x,y, newColor);
			floodFill(x+1,y, oldColor, newColor);
			floodFill(x,y+1, oldColor, newColor);
			floodFill(x-1,y, oldColor, newColor);
			floodFill(x,y-1, oldColor, newColor);
		}
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Utkarsh (65)");
	init();
	
	glutMouseFunc(mouseR);
	glutKeyboardFunc(keyR);
	glutDisplayFunc(display);
	
	glutMainLoop();
}

void keyR(unsigned char key, int x4, int y4)
{
		dda(vertex[0].x4, vertex[0].y4, startx, starty);
	    point = 2;
}

void mouseR(int button, int state, int x4, int y4)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(point == 0)
		{
			vertex[0].x4 = x4;
			vertex[0].y4 = 500-y4;
			startx = x4;
			starty = 500-y4;
			point=1;
		}
		else if(point == 1)
		{
			dda(vertex[0].x4, vertex[0].y4, x4, 500-y4);
			vertex[0].x4 = x4;
			vertex[0].y4 = 500-y4;
		}
        else if(point == 2)
        {
            fillcolor = getPixelColor(x4, 500 - y4);
            point = 3;
        }
        else if(point == 3)
        { 
            Color newColor = {fillcolor.r, fillcolor.g, fillcolor.b};
            Color oldColor = {0.0f, 0.0f, 0.0f};
            floodFill(x4, 500 - y4, oldColor, newColor);
            point = 2;
        }
	}
	
}

void init()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0, 500, 0, 500);
}

void display()
{
   	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glRecti(10, 30, 60, 10);
    glColor3f(0.0, 1.0, 0.0);
    glRecti(90, 30, 140, 10);
    glColor3f(0.0, 0.0, 1.0);
    glRecti(170, 30, 220, 10);
    glColor3f(0.0, 1.0, 1.0);
    glRecti(250, 30, 300, 10);
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
	glFlush();
}
