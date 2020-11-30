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

#include <vector>

using VertexVector = std::vector<std::vector<double>>;
using FaceVector = std::vector<std::vector<int>>;
using NormalVector = std::vector<std::vector<double>>;
using ColorVector = std::vector<std::vector<float>>;

struct Model
{
	VertexVector & vertices;
	FaceVector & faces;
	NormalVector & normals;
	ColorVector & colors;
};

class GLDemoWindow: public Window
{
protected:
	double _turn_angle;
	double _tilt_phase;

	void draw_model(Model &model);
public:
	GLDemoWindow(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	virtual ~GLDemoWindow() = default;

	virtual void setup() override;
	virtual void render() override;
	virtual void do_logic() override;
};

#endif /* GLDEMOWINDOW_H_ */
