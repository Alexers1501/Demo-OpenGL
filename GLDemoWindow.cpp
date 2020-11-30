/*
 * GLDemoWindow.cpp
 *
 *  Created on: 29 ����. 2020 �.
 *      Author: Alexers1501
 */

#include <cmath>
#include "GLDemoWindow.h"

static constexpr double Pi = acos(-1.);

GLDemoWindow::GLDemoWindow(int width, int height)
: Window (width, height)
{
	SDL_GL_SetSwapInterval(1); //1- VSync ������������� � ����������� ������
//	SDL_GL_SetSwapInterval(0); //0-����������� ���������
//	SDL_GL_SetSwapInterval(-1); //-1-���������� VSync
	_turn_angle = 0.;
	_tilt_phase = 0.;
}

void GLDemoWindow::setup()
{
	glEnable(GL_DEPTH_TEST);//�������� ������ �������
//	glDisable(GL_DEPTH_TEST);//��������� �������

	glClearColor(0.1f, 0.3f, 0.4f, 1.f) ;

	glMatrixMode(GL_PROJECTION);//������� ��������
	gluPerspective(45.0, double (getWidth()) / double (getHeight()), 0.01, 30.0);
	glMatrixMode(GL_MODELVIEW);//������� ������� ���� MV
}

void GLDemoWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity(); //Identity - �������� �������
	gluLookAt(3.0, 3.0, 3.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0);//������
	//1-������������, 2-��� �����, 3-����������� �����

//	glTranslated(0.7, 0.7, 0.0);
	glRotated(45. * sin(_tilt_phase), 0.7, -0.7, 0.0);
	glRotated(_turn_angle, 0.0, 0.0, 1.0);
//	glScaled(0.4, 0.8, 1.0);

	//������ �����������
	//������� ���������� �� ������ Gourad
//	glBegin(GL_TRIANGLES);
//
//	glColor3d(1.000, 0.000, 0.000);
//	glVertex2d(0.0, 0.8);
//	glColor3d(0.000, 1.000, 0.000);
//	glVertex2d(0.8, -0.8);
//	glColor3d(0.000, 0.000, 1.000);
//	glVertex2d(-0.8, -0.8);
//
//	glEnd();

	//������ ���
	glBegin(GL_QUADS);

	//������ �����
	glColor3d(0.000, 0.000, 1.000);
	glVertex3d(1.0, 1.0 ,0.0);//������ �����
	glVertex3d(-1.0, 1.0 ,0.0);
	glVertex3d(-1.0, -1.0 ,0.0);
	glVertex3d(1.0, -1.0 ,0.0);

	glColor3d(1.000, 1.000, 0.000);//������� �����
	glVertex3d(1.0, 1.0 ,2.0);
	glVertex3d(1.0, -1.0 ,2.0);
	glVertex3d(-1.0, -1.0 ,2.0);
	glVertex3d(-1.0, 1.0 ,2.0);

	glColor3d(0.000, 1.000, 1.000);
	glVertex3d(1.0, -1.0 ,2.0);//�������� �����
	glVertex3d(1.0, 1.0 ,2.0);
	glVertex3d(1.0, 1.0 ,0.0);
	glVertex3d(1.0, -1.0 ,0.0);

	glColor3d(1.000, 0.000, 0.000);
	glVertex3d(-1.0, 1.0 ,2.0);//������ �����
	glVertex3d(-1.0, -1.0 ,2.0);
	glVertex3d(-1.0, -1.0 ,0.0);
	glVertex3d(-1.0, 1.0 ,0.0);

	glColor3d(0.000, 1.000, 0.000);
	glVertex3d(-1.0, -1.0 ,2.0);//����� �����
	glVertex3d(1.0, -1.0 ,2.0);
	glVertex3d(1.0, -1.0 ,0.0);
	glVertex3d(-1.0, -1.0 ,0.0);

	glColor3d(1.000, 0.000, 1.000);
	glVertex3d(1.0, 1.0 ,2.0);//������ �����
	glVertex3d(-1.0, 1.0 ,2.0);
	glVertex3d(-1.0, 1.0 ,0.0);
	glVertex3d(1.0, 1.0 ,0.0);

	glEnd();
}

void GLDemoWindow::do_logic()
{
	_turn_angle += 2.;
	if (_turn_angle >= 360.)
		_turn_angle -= 360.;

	_tilt_phase += Pi / 200.;
	if (_tilt_phase >= Pi * 2.)
		_tilt_phase -= Pi * 2.;
}
