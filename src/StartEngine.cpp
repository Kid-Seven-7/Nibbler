/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StartEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 08:58:33 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/26 08:53:42 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/StartEngine.hpp"
#include "../include/Nibbler.hpp"
#include <iostream>
#include <unistd.h>

# define UP 0
# define DOWN 1
# define RIGHT 2
# define LEFT 3

StartEngine::StartEngine()
{}

StartEngine::StartEngine(int height, int width, int libChoice)
:_libChoice(libChoice), _height(height), _width(width)
{}

StartEngine::StartEngine(StartEngine const & src){
	*this = src;
}

StartEngine::~StartEngine()
{}

StartEngine const & StartEngine::operator=(StartEngine const & rhs){
  (void)rhs;
  return *this;
}

void *StartEngine::switchLib(int libChoice){
  std::string lib_path[] = {"bin/sfml.so", "bin/sdl.so", "bin/glfw.so"};

  //choosing which lib to use
  if(libChoice == 2)
    return dlopen(lib_path[sdl_path].c_str(), RTLD_LAZY | RTLD_LOCAL);
  else if(libChoice == 3)
    return dlopen(lib_path[glfw_path].c_str(), RTLD_LAZY | RTLD_LOCAL);
  else
    return dlopen(lib_path[sfml_path].c_str(), RTLD_LAZY | RTLD_LOCAL);
}

void StartEngine::mainControl(){
  void *dl_handler;
	int dir = 200;
  std::string window[] = {"createSFMLWindow", "createSDLWindow", "createGLFWWindow"};

  //choosing lib to call
  dl_handler = switchLib(this->_libChoice);
  //checking dl_handler
  if (!dl_handler)
    dlerror_wrapper();

  IGraphicsMain *(*WindowCreator)(std::string, int width, int height);
  WindowCreator = (IGraphicsMain *(*)(std::string, int width, int height)) dlsym(dl_handler, window[this->_libChoice - 1].c_str());

  if (!WindowCreator)
    dlerror_wrapper();

  IGraphicsMain *newWindow;
	newWindow = WindowCreator("Nibbler_42", this->_height, this->_width);
	Snake_class test(this->_height, this->_width);
	std::vector<Part> Snake;
	newWindow->createWindow();
	while(true){
	// for (int i = 0; i < 10; ++i){
		// usleep(1000);
		Snake = test.getVector();
		// dir = newWindow->updateWindow(Snake);
		test.setDirection(newWindow->updateWindow(Snake));
		if (test.getDirection() == UP)
			Snake.at(0).y -= 20;
		if (test.getDirection() == DOWN)
			Snake.at(0).y += 20;
		if(test.getDirection() == LEFT)
			Snake.at(0).x -= 20;
		if(test.getDirection() == RIGHT)
			Snake.at(0).x += 20;

		for(size_t i = 1; i < Snake.size(); ++i){
			if (i == Snake.size() - 1){
				std::cout << '\n';
			}
			Snake.at(i).prevX = Snake.at(i).x;
			Snake.at(i).prevY = Snake.at(i).y;
			Snake.at(i).x = Snake.at(i).nextX;
			Snake.at(i).y = Snake.at(i).nextY;
			Snake.at(i).nextX = Snake.at(i - 1).x;
			Snake.at(i).nextY = Snake.at(i - 1).y;
		}

		test.setVector(Snake);
		if (!(test.collision())){
			while (true){
				newWindow->destroyWindow();
			}
			// break;
		}
	}

  void(*WindowDestructor)(IGraphicsMain *);
  WindowDestructor = (void(*)(IGraphicsMain *)) dlsym(dl_handler, "deleteWindow");

  if(!WindowDestructor)
    dlerror_wrapper();

  WindowDestructor(newWindow);
  dlclose(dl_handler);
}

void StartEngine::dlerror_wrapper(void){
  std::cout << "Error: " << dlerror() << std::endl;
  exit(EXIT_FAILURE);
}
