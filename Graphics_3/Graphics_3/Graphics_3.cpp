#include <stdlib.h>
#include <GL\glut.h>
#include <math.h>
#include <iostream>
static int window;
static int menu_id;
static int submenu_id;
static int value = 0;
using namespace std;

// GIORGOS STAMOULOS AEM:64 & CHRISTOS KORGIALAS AEM:56 (MSC DMCI)

int i = 0;
float j = 0;
float k = 0;

// External Product of two Vectors that are at the Level of the Polygon (Cross-Product)
float* Built(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3) {

	float Ux, Uy, Uz;
	float Vx, Vy, Vz;
	float Nx, Ny, Nz;
	float Normalized_N[3];
	float Length;

	Ux = x2 - x1;
	Uy = y2 - y1;
	Uz = z2 - z1;
	Vx = x3 - x1;
	Vy = y3 - y1;
	Vz = z3 - z1;

	Nx = Uy * Vz - Uz * Vy;
	Ny = Uz * Vx - Ux * Vz;
	Nz = Ux * Vy - Uy * Vx;

	Length = sqrt(Nx * Nx + Ny * Ny + Nz * Nz);

	Normalized_N[0] = Nx / Length;
	Normalized_N[1] = Ny / Length;
	Normalized_N[2] = Nz / Length;

	return Normalized_N;
}

void display() {

	glEnable(GL_LIGHTING);

	//Light Position
	GLfloat LIGHTPOSITION[] = { -50 * cos(j * 0.0245436718), -50 * sin(j * 0.0245436718), 0.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, LIGHTPOSITION);

	//Light Ambient
	GLfloat LIGHTAMBIENT[] = { 0.3, 0.3, 0.3 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, LIGHTAMBIENT);

	//Light Diffusion
	GLfloat LIGHTDIFFUSE[] = { 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LIGHTDIFFUSE);

	//Light Specular
	GLfloat LIGHTSPECULAR[] = { 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_SPECULAR, LIGHTSPECULAR);

	glShadeModel(GL_SMOOTH);

	glEnable(GL_LIGHT0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//House Ambient
	GLfloat HOUSEAMBIENT[] = { 0.5, 0.35, 0.05, 0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, HOUSEAMBIENT);

	//House Diffusion
	GLfloat HOUSEDIFFUSE[] = { 0.5, 0.35, 0.05, 0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, HOUSEDIFFUSE);

	//House Specular
	GLfloat HOUSESPECULAR[] = { 0, 0, 0, 0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, HOUSESPECULAR);

	float* Front_Wall;
	//Front House - Square
	Front_Wall = Built(-10, 0, 20, 10, 20, 20, -10, 20, 20);

	glBegin(GL_POLYGON);
	glNormal3f(Front_Wall[0], Front_Wall[1], Front_Wall[2]);
	glVertex3f(-10, 0, 20);
	glNormal3f(Front_Wall[0], Front_Wall[1], Front_Wall[2]);
	glVertex3f(-10, 20, 20);
	glNormal3f(Front_Wall[0], Front_Wall[1], Front_Wall[2]);
	glVertex3f(10, 20, 20);
	glNormal3f(Front_Wall[0], Front_Wall[1], Front_Wall[2]);
	glVertex3f(10, 0, 20);
	glEnd();

	float* Front_Triangle;
	//Front House - Triangle
	Front_Triangle = Built(0, 40, 20, -10, 20, 20, 10, 20, 20);

	glBegin(GL_POLYGON);
	glNormal3f(Front_Triangle[0], Front_Triangle[1], Front_Triangle[2]);
	glVertex3f(-10, 20, 20);
	glNormal3f(Front_Triangle[0], Front_Triangle[1], Front_Triangle[2]);
	glVertex3f(0, 40, 20);
	glNormal3f(Front_Triangle[0], Front_Triangle[1], Front_Triangle[2]);
	glVertex3f(10, 20, 20);
	glEnd();

	float* Back_Square;
	//Back House - Square
	Back_Square = Built(-10, 0, -20, -10, 20, -20, 10, 20, -20);

	glBegin(GL_POLYGON);
	glNormal3f(Back_Square[0], Back_Square[1], Back_Square[2]);
	glVertex3f(-10, 0, -20);
	glNormal3f(Back_Square[0], Back_Square[1], Back_Square[2]);
	glVertex3f(-10, 20, -20);
	glNormal3f(Back_Square[0], Back_Square[1], Back_Square[2]);
	glVertex3f(10, 20, -20);
	glNormal3f(Back_Square[0], Back_Square[1], Back_Square[2]);
	glVertex3f(10, 0, -20);
	glEnd();

	float* Back_Triangle;
	//Back House - Triangle
	Back_Triangle = Built(-10, 0, -20, 0, 40, -20, 10, 20, -20);

	glBegin(GL_POLYGON);
	glNormal3f(Back_Triangle[0], Back_Triangle[1], Back_Triangle[2]);
	glVertex3f(-10, 20, -20);
	glNormal3f(Back_Triangle[0], Back_Triangle[1], Back_Triangle[2]);
	glVertex3f(0, 40, -20);
	glNormal3f(Back_Triangle[0], Back_Triangle[1], Back_Triangle[2]);
	glVertex3f(10, 20, -20);
	glEnd();

	float* Right_Wall;
	//Right Wall
	Right_Wall = Built(10, 0, 20, 10, 20, -20, 10, 20, 20);

	glBegin(GL_POLYGON);
	glNormal3f(Right_Wall[0], Right_Wall[1], Right_Wall[2]);
	glVertex3f(10, 0, 20);
	glNormal3f(Right_Wall[0], Right_Wall[1], Right_Wall[2]);
	glVertex3f(10, 20, 20);
	glNormal3f(Right_Wall[0], Right_Wall[1], Right_Wall[2]);
	glVertex3f(10, 20, -20);
	glNormal3f(Right_Wall[0], Right_Wall[1], Right_Wall[2]);
	glVertex3f(10, 0, -20);
	glEnd();

	float* Left_Wall;
	//Left Wall
	Left_Wall = Built(-10, 0, 20, -10, 20, 20, -10, 20, -20);

	glBegin(GL_POLYGON);
	glNormal3f(Left_Wall[0], Left_Wall[1], Left_Wall[2]);
	glVertex3f(-10, 0, 20);
	glNormal3f(Left_Wall[0], Left_Wall[1], Left_Wall[2]);
	glVertex3f(-10, 20, 20);
	glNormal3f(Left_Wall[0], Left_Wall[1], Left_Wall[2]);
	glVertex3f(-10, 20, -20);
	glNormal3f(Left_Wall[0], Left_Wall[1], Left_Wall[2]);
	glVertex3f(-10, 0, -20);
	glEnd();

	//Roof Ambient
	GLfloat ROOFAMBIENT[] = { 0.7, 0.7, 0.7, 0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ROOFAMBIENT);

	//Roof Diffusion
	GLfloat ROOFDIFFUSE[] = { 0.7, 0.7, 0.7, 0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, ROOFDIFFUSE);

	//Roof Specular
	GLfloat ROOFSPECULAR[] = { 1, 1, 1, 0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ROOFSPECULAR);

	//Roof Shining
	GLfloat SHINING[] = { 100 };
	glMaterialfv(GL_FRONT, GL_SHININESS, SHINING);

	float* Left_Roof;
	//Left Roof
	Left_Roof = Built(-10, 20, 20, 0, 40, 20, 0, 40, -20);

	glBegin(GL_POLYGON);
	glNormal3f(-1, 1, 0);
	glVertex3f(-10, 20, 20);
	glNormal3f(-1, 1, 0);
	glVertex3f(0, 40, 20);
	glNormal3f(-1, 1, 0);
	glVertex3f(0, 40, -20);
	glNormal3f(-1, 1, 0);
	glVertex3f(-10, 20, -20);
	glEnd();

	float* Right_Roof;
	//Right Roof
	Right_Roof = Built(10, 20, 20, 0, 40, -20, 0, 40, 20);

	glBegin(GL_POLYGON);
	glNormal3f(Right_Roof[0], Right_Roof[1], Right_Roof[2]);
	glVertex3f(10, 20, 20);
	glNormal3f(Right_Roof[0], Right_Roof[1], Right_Roof[2]);
	glVertex3f(0, 40, 20);
	glNormal3f(Right_Roof[0], Right_Roof[1], Right_Roof[2]);
	glVertex3f(0, 40, -20);
	glNormal3f(Right_Roof[0], Right_Roof[1], Right_Roof[2]);
	glVertex3f(10, 20, -20);
	glEnd();

	//Grass Ambient
	GLfloat GRASSAMBIENT[] = { 0, 0.5, 0, 0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, GRASSAMBIENT);

	//Grass Diffusion
	GLfloat GRASSDIFFUSE[] = { 0, 0.5, 0, 0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, GRASSDIFFUSE);

	//Grass Specular
	GLfloat GRASSSPECULAR[] = { 1, 1, 1, 0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, GRASSSPECULAR);

	float* Grass;
	//Grass
	Grass = Built(-150, 0, 100, 150, 0, -100, -150, 0, -100);

	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(-100, 0, 150);
	glNormal3f(0, 1, 0);
	glVertex3f(-100, 0, -150);
	glNormal3f(0, 1, 0);
	glVertex3f(100, 0, -150);
	glNormal3f(0, 1, 0);
	glVertex3f(100, 0, 150);
	glEnd();

	//Sun Ambient
	GLfloat SUNAMBIENT[] = { 1, 1, 0, 0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, SUNAMBIENT);

	//Sun Diffusion
	GLfloat SUNDIFFUSE[] = { 1, 1, 0, 0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, SUNDIFFUSE);

	//Sun Specular
	GLfloat SUNSPECULAR[] = { 1, 1, 1, 0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, SUNSPECULAR);

	glPushMatrix();
	glTranslatef(-50 * cos(k * 0.0245436718), -50 * sin(k * 0.0245436718), 0.0);
	glutSolidSphere(4, 50, 50);
	glPopMatrix();

	glutSwapBuffers();
}

void idle() {
	j = j - 0.1;
	k = k - 0.1;

	if (k == -100)
	{
		j = -1;
		k = -1;
	}
	glutPostRedisplay();
}

void demo_menu(int id)
{
	if (id == 1)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-40, 40, -40, 40, -70, 70);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	if (id == 2)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-40, 40, -40, 40, -70, 70);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glRotatef(180, 0, 1, 0);
	}
	glutPostRedisplay();
}

void special(int key, int x, int y) {

	if (key == GLUT_KEY_RIGHT)
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(70 * sin(i * 0.1), 70, 70 * cos(i * 0.1), 0, 0, 0, 0, 40, 0);
		i = i + 1;
	}

	if (key == GLUT_KEY_LEFT)
	{
		i = i - 1;
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(70 * sin(i * 0.1), 70, 70 * cos(i * 0.1), 0, 0, 0, 0, 40, 0);

	}
	glutPostRedisplay();
}

void menu(int num) {

	if (num == 0) {
		glutDestroyWindow(window);
		exit(0);
	}
	else if (num == 1) {
		glEnable(GL_LIGHT0);
		GLfloat LIGHT1POSITION[] = { 0.0, 0.0, 2.0, 1.0 };
		glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30.0);
		glLightfv(GL_LIGHT0, GL_POSITION, LIGHT1POSITION);
	}
	else if (num == 2) {
		glDisable(GL_LIGHT0);
	}
	else if (num == 5) {
		glShadeModel(GL_SMOOTH);
	}
	else if (num == 6) {
		glShadeModel(GL_FLAT);
	}
	glutPostRedisplay();
}
void createMenu(void) {

	submenu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Enable_Spot_Cut-off", 1);
	glutAddMenuEntry("Disable_Spot_Cut-off", 2);
	glutAddMenuEntry("Enable_Polygon_Fill", 3);
	glutAddMenuEntry("Disable_Polygon_Fill", 4);
	glutAddMenuEntry("Smooth_Shade", 5);
	glutAddMenuEntry("Flat_Shade", 6);
	glutAddMenuEntry("Quit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("The House");
	createMenu();

	glClearColor(0, 0, 0, 0);

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100, 100, -100, 100, -200, 200);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0, 40, 40, 0, 0, 0, 0, 1, 0);

	glutDisplayFunc(display);

	glutSpecialFunc(special);

	glutIdleFunc(idle);

	glutMainLoop();

	return 0;
}