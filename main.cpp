/*
 * main.cpp
 *
 *  Created on: 29 ����. 2020 �.
 *      Author: Alexers1501
 */

#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>

#include "GLDemoWindow.h"

int main (int, char **)
{
	SDL_Init(SDL_INIT_EVERYTHING);//�������������

	try{
		GLDemoWindow w;

		w.main_loop();
	}catch (const std::exception &e){
		std::cerr <<"��� ���������� ��������� ��������� ������: "
				<< std::endl
				<<e.what()
				<<std::endl;
		return 1;
	}catch (...){
		std::cerr <<"��� ���������� ��������� ��������� ����������� ������!"
				<< std::endl;
		return 1;
	}

	return 0;
}

