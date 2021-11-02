#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


// GIORGOS STAMOULOS AEM:64 & CHRISTOS KORGIALAS AEM:56 (MSC DMCI)


//Initial Scaling and Rotation Parameters
static GLfloat angle = 0.0;
static GLfloat s = 1.0;
static GLint scale = 1;


void draw() {
	glBegin(GL_POLYGON);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();
}


void cube() {


	glPushMatrix();
	glColor3f(0.7, 1, 0.6);
	glTranslatef(0, 1, 0);
	glRotatef(90, 1, 0, 0);
	draw();
	glPopMatrix();

	// Create Faces

	// DOWN 
	glPushMatrix();
	glColor3f(0.9, 0.5, 0.1);
	glTranslatef(0, -1, 0);
	glRotatef(90, 1, 0, 0);
	draw();
	glPopMatrix();

	// RIGHT 
	glPushMatrix();
	glColor3f(0.4, 1, 0.8);
	glTranslatef(1, 0, 0);
	glRotatef(90, 0, 1, 0);
	draw();
	glPopMatrix();

	// LEFT
	glPushMatrix();
	glColor3f(0.7, 0.4, 0.6);
	glTranslatef(-1, 0, 0);
	glRotatef(90, 0, 1, 0);
	draw();
	glPopMatrix();

	// FRONT
	glPushMatrix();
	glColor3f(0.3, 0.5, 0);
	glTranslatef(0, 0, 1);
	draw();
	glPopMatrix();

	// BACK 
	glPushMatrix();
	glColor3f(0.5, 0, 0.7);
	glTranslatef(0, 0, -1);
	draw();
	glPopMatrix();

}

void cube_move_display() {

	glClearColor(1, 0.5, 0.5, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Clipping Plane Coordinates
	glOrtho(-100.0, 100.0, -100.0, 100.0, 20.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0, 0, -110);
	//a=6
	glScalef(3.0, 3.0, 3.0);

	// Draw Cube
	glPushMatrix();

	//Rotate Around it Self	
	glRotatef(angle, 1.0, 1.0, 1.0);
	glScalef(s, s, s);
	cube();
	glPopMatrix();


	glFlush();
	glutSwapBuffers();
}

// Rotation and Scaling Adjustments
void idle(void)
{
	angle += 0.2;

	if (scale == 0)
	{
		if (s >= 1)
			s -= 0.03;
		else
			scale = 1;
	}

	if (scale == 1)
	{
		if (s < 2)
			s += 0.03;
		else
			scale = 0;
	}

	glutPostRedisplay();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("The Cube");

	glutDisplayFunc(cube_move_display);
	glutIdleFunc(idle);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}