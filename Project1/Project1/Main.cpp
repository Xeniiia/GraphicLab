// try1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "glut.h"
#include "math.h"
#define pi 3.14159265

float r = 200.0;
float Angle = 0.0;



void Timer(int) {
	glutPostRedisplay();
	glutTimerFunc(50, Timer, 0);

	/*for (float phi = 0; phi <= pi; phi += pi / 360) {
		glBegin(GL_LINE_STRIP);
		//float phi = 0;
		glVertex2f((r - 50) * cos(phi), (r - 50) * sin(phi));
		glVertex2f((r - 200) * cos(phi), (r - 200) * sin(phi));
		glEnd();
	}*/
}

void Keyboard(unsigned char key, int x, int y) {
	if (key == 'w') { if (Angle < 180.0) Angle++; }
	if (key == 's') { if (Angle > 0.0) Angle--; }
}


void myDisplay() {
	//����������:
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	for (float phi = 0; phi <= pi; phi += pi / 200) {
		glVertex2f(r * cos(phi), r * sin(phi));
	}
	glEnd();

	//������� �� ����������:
	for (float phi = 0; phi <= pi; phi += pi / 6) {
		glBegin(GL_LINE_STRIP);
		glVertex2f((r + 20) * cos(phi), (r + 20) * sin(phi));
		glVertex2f((r - 20) * cos(phi), (r - 20) * sin(phi));
		glEnd();
	}

	glPushMatrix();
	glRotatef(Angle, 0.0, 0.0, 1.0);
	//�������:
	//for (float phi = 0; phi <= pi; phi += pi / 360){
	glBegin(GL_LINE_STRIP);
	float phi = 0;
	glVertex2f((r - 50) * cos(phi), (r - 50) * sin(phi));
	glVertex2f((r - 200) * cos(phi), (r - 200) * sin(phi));
	glEnd();
	//}

	glPopMatrix();
	glutSwapBuffers();
}

void myInit() {
	glClearColor(0, 0, 0, 0);
	glColor3f(1, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-320, 320, -320, 320);

}

void main(int argc, char** argv) {
	glutInit(&argc, argv); //�������������� glut
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //������������� ����� �������
	glutInitWindowSize(640, 640); //������������� ������ ����
	glutCreateWindow("OpenGL example"); //��������� ���� �� ������
	glutDisplayFunc(myDisplay); //������������ ������� ��������� ������
	glutTimerFunc(50, Timer, 0);
	glutKeyboardFunc(Keyboard);
	myInit();
	glutMainLoop(); //������ � ����������� ����
}



