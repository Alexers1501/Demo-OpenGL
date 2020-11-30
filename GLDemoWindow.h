/*
 * GLDemoWindow.h
 *
 *  Created on: 29 но€б. 2020 г.
 *      Author: User
 */

#ifndef GLDEMOWINDOW_H_
#define GLDEMOWINDOW_H_

#include <GL/gl.h>
#include <GL/glu.h>

#include "Window.h"

class GLDemoWindow: public Window
{
protected:
	double _turn_angle;
	double _tilt_phase;
public:
	GLDemoWindow(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	virtual ~GLDemoWindow() = default;

	virtual void setup() override;
	virtual void render() override;
	virtual void do_logic() override;
};

#endif /* GLDEMOWINDOW_H_ */
