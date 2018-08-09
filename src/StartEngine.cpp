/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StartEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 08:58:33 by amatshiy          #+#    #+#             */
/*   Updated: 2018/08/04 13:15:59 by amatshiy         ###   ########.fr       */
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
	int direction = 0;
	int score = 0;
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

	while(true){ //Game loop
		//Get vector
		if (this->_libChoice == 3)
			std::cout << "Boom" << std::endl;
		Snake = test.getVector();

		//validate return
		direction = newWindow->updateWindow(Snake);
		//Error occurred
		if (direction == -1)
			break;
		//food eaten
		if (direction == 200){
			test.addPart();
			Snake = test.getVector();
			test.setVector(Snake);
			score += 10;
			system("clear");
			std::cout << "Score: " <<score<< '\n';
		}

		//Set direction from lib
		test.setDirection(direction);

		//Move snake head
		Snake.at(0).y += (test.getDirection() == UP) ? -20 : 0;
		Snake.at(0).y += (test.getDirection() == DOWN) ? 20 : 0;
		Snake.at(0).x += (test.getDirection() == LEFT) ? -20 : 0;
		Snake.at(0).x += (test.getDirection() == RIGHT) ? 20 : 0;

		//check if snake head is out of bounds
		// if ((Snake[0].y < -20 || Snake[0].y > this->_height)
		// ||(Snake[0].x < -20 || Snake[0].x > this->_width))
		// 	newWindow->destroyWindow();

		//Update snake parts
		for(size_t i = 1; i < Snake.size(); ++i){
			//Prev x & y = Current x & y
			Snake.at(i).prevX = Snake.at(i).x;
			Snake.at(i).prevY = Snake.at(i).y;
			//Current x & y = next x & y
			Snake.at(i).x = Snake.at(i).nextX;
			Snake.at(i).y = Snake.at(i).nextY;
			//Next x & y = current x & y of node in front
			Snake.at(i).nextX = Snake.at(i - 1).x;
			Snake.at(i).nextY = Snake.at(i - 1).y;
		}

		//Collision check
		if (!(test.collision())){
			test.reset();
			newWindow->destroyWindow();
		}

		//Update vector
		test.setVector(Snake);
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