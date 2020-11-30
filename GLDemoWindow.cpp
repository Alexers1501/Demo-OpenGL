/*
 * GLDemoWindow.cpp
 *
 *  Created on: 29 но€б. 2020 г.
 *      Author: Alexers1501
 */

#include "GLDemoWindow.h"

GLDemoWindow::GLDemoWindow(int width, int height)
: Window (width, height)
{
	SDL_GL_SetSwapInterval(1); //1- VSync синхронизаци€ с обновлением экрана
//	SDL_GL_SetSwapInterval(0); //0-немедленна€ отрисовка
//	SDL_GL_SetSwapInterval(-1); //-1-адаптивный VSync
	_turn_angle = 0.;
}

void GLDemoWindow::setup()
{
//	glEnable(GL_DEPTH_TEST);//проверка буфера глубины
//	glDisable(GL_DEPTH_TEST);//выулючает глубину

	glClearColor(0.1f, 0.3f, 0.4f, 1.f) ;

	glMatrixMode(GL_PROJECTION);//матрица проекций
	gluPerspective(45.0, double (getWidth()) / double (getHeight()), 0.01, 30.0);
	glMatrixMode(GL_MODELVIEW);//матрица моделей вида MV
}

void GLDemoWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT );

	glLoadIdentity(); //Identity - единчна€ матрица
	gluLookAt(3.0, 2.0, 2.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0);//камера
	//1-расположение, 2-где центр, 3-направление вверх

//	glTranslated(0.7, 0.7, 0.0);
	glRotated(_turn_angle, 0.0, 0.0, 1.0);
//	glScaled(0.4, 0.8, 1.0);

//	рисуем треугольник
//	заливка происходит по методу Gourad
	glBegin(GL_TRIANGLES);

	glColor3d(1.000, 0.000, 0.000);
	glVertex2d(0.0, 0.8);
	glColor3d(0.000, 1.000, 0.000);
	glVertex2d(0.8, -0.8);
	glColor3d(0.000, 0.000, 1.000);
	glVertex2d(-0.8, -0.8);

//	glEnd();

//	//рисуем куб
//	glBegin(GL_QUADS);
//
//	//рисуем грани
//	glColor3d(0.000, 0.000, 1.000);
//	glVertex3d(1.0, 1.0 ,0.0);//нижн€€ грань
//	glVertex3d(-1.0, 1.0 ,0.0);
//	glVertex3d(-1.0, -1.0 ,0.0);
//	glVertex3d(1.0, -1.0 ,0.0);
//
//	glColor3d(1.000, 1.000, 0.000);//верхн€€ грань
//	glVertex3d(1.0, 1.0 ,2.0);
//	glVertex3d(1.0, -1.0 ,2.0);
//	glVertex3d(-1.0, -1.0 ,2.0);
//	glVertex3d(-1.0, 1.0 ,2.0);
//
//	glColor3d(0.000, 1.000, 1.000);
//	glVertex3d(1.0, -1.0 ,2.0);//передн€€ грань
//	glVertex3d(1.0, 1.0 ,2.0);
//	glVertex3d(1.0, 1.0 ,0.0);
//	glVertex3d(1.0, -1.0 ,0.0);
//
//	glEnd();
}

void GLDemoWindow::do_logic()
{
	_turn_angle += 2.;
	if (_turn_angle >= 360.)
		_turn_angle -= 360.;
}
