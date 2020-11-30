/*
 * GLDemoWindow.cpp
 *
 *  Created on: 29 ����. 2020 �.
 *      Author: Alexers1501
 */

#include <cmath>
#include "GLDemoWindow.h"

static constexpr double Pi = acos(-1.);

static VertexVector s_cube_vertices {
	{  1.0, 1.0, 2.0 },
	{  1.0, -1.0, 2.0 },
	{  -1.0, -1.0, 2.0 },
	{ - 1.0, 1.0, 2.0 },
	{  1.0, 1.0, 0.0 },
	{  1.0, -1.0, 0.0 },
	{  -1.0, -1.0, 0.0 },
	{  -1.0, 1.0, 0.0 }
};

static FaceVector s_cube_faces {
	{ 4, 0, 1, 2, 3 },
	{ 4, 7, 6, 5, 4 },
	{ 4, 1, 0, 4, 5 },
	{ 4, 3, 2, 6, 7 },
	{ 4, 0, 3, 7, 4 },
	{ 4, 2, 1, 5, 6 }
};

static NormalVector s_cube_normals {
	{  0.0, 0.0, 1.0 },
	{  0.0, 0.0, -1.0 },
	{  1.0, 0.0, 0.0 },
	{  -1.0, 0.0, 0.0 },
	{  0.0, 1.0, 0.0 },
	{  0.0, -1.0, 0.0 },
};

static ColorVector s_cube_colors {
	{  1.0f, 1.0f, 0.0f },
	{  0.0f, 0.0f, 1.0f },
	{  0.0f, 1.0f, 1.0f },
	{  1.0f, 0.0f, 0.0f },
	{  1.0f, 0.0f, 1.0f },
	{  0.0f, 1.0f, 0.0f },
};

Model cube
{
	s_cube_vertices, s_cube_faces, s_cube_normals, s_cube_colors
};



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

	glEnable(GL_LIGHTING);//����� ������������
	glEnable(GL_LIGHT0);//�������� �������� �����

	glClearColor(0.1f, 0.3f, 0.4f, 1.f) ;

	glMatrixMode(GL_PROJECTION);//������� ��������
	gluPerspective(45.0, double (getWidth()) / double (getHeight()), 0.01, 30.0);
	glMatrixMode(GL_MODELVIEW);//������� ������� ���� MV

	//�������� � 2 ���� ������������������
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);//�� ������ ������ �����
	glFrontFace(GL_CW);
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

//	//������ ���
//	glBegin(GL_QUADS);
//
//	//������ �����
//	glColor3d(0.000, 0.000, 1.000);
//	glNormal3d(0.0, 0.0, -1.0);//���������� ������� ������� ��� ���������
//	glVertex3d(1.0, 1.0 ,0.0);//������ �����
//	glVertex3d(-1.0, 1.0 ,0.0);
//	glVertex3d(-1.0, -1.0 ,0.0);
//	glVertex3d(1.0, -1.0 ,0.0);
//
//	glColor3d(1.000, 1.000, 0.000);//������� �����
//	glNormal3d(0.0, 0.0, 1.0);
//	glVertex3d(1.0, 1.0 ,2.0);
//	glVertex3d(1.0, -1.0 ,2.0);
//	glVertex3d(-1.0, -1.0 ,2.0);
//	glVertex3d(-1.0, 1.0 ,2.0);
//
//	glColor3d(0.000, 1.000, 1.000);
//	glNormal3d(	1.0, 0.0, 0.0);
//	glVertex3d(1.0, -1.0 ,2.0);//�������� �����
//	glVertex3d(1.0, 1.0 ,2.0);
//	glVertex3d(1.0, 1.0 ,0.0);
//	glVertex3d(1.0, -1.0 ,0.0);
//
//	glColor3d(1.000, 0.000, 0.000);
//	glNormal3d(-1.0, 0.0, 0.0);
//	glVertex3d(-1.0, 1.0 ,2.0);//������ �����
//	glVertex3d(-1.0, -1.0 ,2.0);
//	glVertex3d(-1.0, -1.0 ,0.0);
//	glVertex3d(-1.0, 1.0 ,0.0);
//
//	glColor3d(0.000, 1.000, 0.000);
//	glNormal3d(0.0, -1.0, 0.0);
//	glVertex3d(-1.0, -1.0 ,2.0);//����� �����
//	glVertex3d(1.0, -1.0 ,2.0);
//	glVertex3d(1.0, -1.0 ,0.0);
//	glVertex3d(-1.0, -1.0 ,0.0);
//
//	glColor3d(1.000, 0.000, 1.000);
//	glNormal3d(0.0, 1.0, 0.0);
//	glVertex3d(1.0, 1.0 ,2.0);//������ �����
//	glVertex3d(-1.0, 1.0 ,2.0);
//	glVertex3d(-1.0, 1.0 ,0.0);
//	glVertex3d(1.0, 1.0 ,0.0);
//
//	glEnd();

//	glPushMatrix();
//	glPopMatrix();

	draw_model(cube);
}

void GLDemoWindow::draw_model(Model &model)
{
	for (unsigned i =0; i < model.faces.size(); ++i){
		int count = model.faces[i][0];
		if (count == 3)
			glBegin(GL_TRIANGLES);
		else if (count == 4)
			glBegin(GL_QUADS);
		else
			glBegin(GL_POLYGON);

		glNormal3dv(&model.normals[i][0]);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, &model.colors[i][0]);
		for (int j = 1; j <= count; ++j){
			glVertex3dv(&model.vertices[model.faces[i][j]][0]);
		}

		glEnd();
	}
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
