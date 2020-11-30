/*
 * GLDemoWindow.cpp
 *
 *  Created on: 29 нояб. 2020 г.
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
	SDL_GL_SetSwapInterval(1); //1- VSync синхронизация с обновлением экрана
//	SDL_GL_SetSwapInterval(0); //0-немедленная отрисовка
//	SDL_GL_SetSwapInterval(-1); //-1-адаптивный VSync
	_turn_angle = 0.;
	_tilt_phase = 0.;
}

void GLDemoWindow::setup()
{
	glEnable(GL_DEPTH_TEST);//проверка буфера глубины
//	glDisable(GL_DEPTH_TEST);//выулючает глубину

	glEnable(GL_LIGHTING);//рсчет освещенности
	glEnable(GL_LIGHT0);//включаем источник света

	glClearColor(0.1f, 0.3f, 0.4f, 1.f) ;

	glMatrixMode(GL_PROJECTION);//матрица проекций
	gluPerspective(45.0, double (getWidth()) / double (getHeight()), 0.01, 30.0);
	glMatrixMode(GL_MODELVIEW);//матрица моделей вида MV

	//повышаем в 2 раза производительность
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);//не рисует задние грани
	glFrontFace(GL_CW);
}

void GLDemoWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity(); //Identity - единчная матрица
	gluLookAt(3.0, 3.0, 3.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0);//камера
	//1-расположение, 2-где центр, 3-направление вверх

//	glTranslated(0.7, 0.7, 0.0);
	glRotated(45. * sin(_tilt_phase), 0.7, -0.7, 0.0);
	glRotated(_turn_angle, 0.0, 0.0, 1.0);
//	glScaled(0.4, 0.8, 1.0);

	//рисуем треугольник
	//заливка происходит по методу Gourad
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

//	//рисуем куб
//	glBegin(GL_QUADS);
//
//	//рисуем грани
//	glColor3d(0.000, 0.000, 1.000);
//	glNormal3d(0.0, 0.0, -1.0);//координаты вектора нормали для освещения
//	glVertex3d(1.0, 1.0 ,0.0);//нижняя грань
//	glVertex3d(-1.0, 1.0 ,0.0);
//	glVertex3d(-1.0, -1.0 ,0.0);
//	glVertex3d(1.0, -1.0 ,0.0);
//
//	glColor3d(1.000, 1.000, 0.000);//верхняя грань
//	glNormal3d(0.0, 0.0, 1.0);
//	glVertex3d(1.0, 1.0 ,2.0);
//	glVertex3d(1.0, -1.0 ,2.0);
//	glVertex3d(-1.0, -1.0 ,2.0);
//	glVertex3d(-1.0, 1.0 ,2.0);
//
//	glColor3d(0.000, 1.000, 1.000);
//	glNormal3d(	1.0, 0.0, 0.0);
//	glVertex3d(1.0, -1.0 ,2.0);//передняя грань
//	glVertex3d(1.0, 1.0 ,2.0);
//	glVertex3d(1.0, 1.0 ,0.0);
//	glVertex3d(1.0, -1.0 ,0.0);
//
//	glColor3d(1.000, 0.000, 0.000);
//	glNormal3d(-1.0, 0.0, 0.0);
//	glVertex3d(-1.0, 1.0 ,2.0);//задняя грань
//	glVertex3d(-1.0, -1.0 ,2.0);
//	glVertex3d(-1.0, -1.0 ,0.0);
//	glVertex3d(-1.0, 1.0 ,0.0);
//
//	glColor3d(0.000, 1.000, 0.000);
//	glNormal3d(0.0, -1.0, 0.0);
//	glVertex3d(-1.0, -1.0 ,2.0);//левая грань
//	glVertex3d(1.0, -1.0 ,2.0);
//	glVertex3d(1.0, -1.0 ,0.0);
//	glVertex3d(-1.0, -1.0 ,0.0);
//
//	glColor3d(1.000, 0.000, 1.000);
//	glNormal3d(0.0, 1.0, 0.0);
//	glVertex3d(1.0, 1.0 ,2.0);//правая грань
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
