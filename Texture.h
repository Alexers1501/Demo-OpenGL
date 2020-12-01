/*
 * Texture.h
 *
 *  Created on: 1 дек. 2020 г.
 *      Author: Alexers1501
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <GL/gl.h>
#include <GL/glu.h>

class Texture
{
protected:
	GLuint _texture;
public:
	Texture( const char * filename);
	virtual ~Texture();

	void bind();
};

#endif /* TEXTURE_H_ */
