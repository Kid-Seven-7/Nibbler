/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StartEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 08:58:33 by amatshiy          #+#    #+#             */
/*   Updated: 2018/08/12 08:33:28 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/StartEngine.hpp"
#include "../include/Nibbler.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>

//Defines for directions
#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3
//Timestamp defines
#define DTTMFMT "%H:%M:%S "
#define DTTMSZ 9

StartEngine::StartEngine() {}

StartEngine::StartEngine(int height, int width, int libChoice, std::string name)
		: _libChoice(libChoice), _height(height), _width(width), _name(name), _sound()
{
	// this->_dl_handler = dlopen("bin/glfw.so", RTLD_LAZY | RTLD_LOCAL);
}

StartEngine::StartEngine(StartEngine const &src)
{
	*this = src;
}

StartEngine::~StartEngine() {
	this->_sound.join();
}

StartEngine const &StartEngine::operator=(StartEngine const &rhs)
{
	(void)rhs;
	return *this;
}

void *StartEngine::switchLib(int libChoice)
{
	std::string lib_path[] = {"bin/sfml.so", "bin/sdl.so", "bin/glfw.so"};

	//choosing which lib to use
	if (libChoice == 2)
		return dlopen(lib_path[sdl_path].c_str(), RTLD_LAZY | RTLD_LOCAL);
	else if (libChoice == 3)
		return dlopen(lib_path[glfw_path].c_str(), RTLD_LAZY | RTLD_LOCAL);
	else
		return dlopen(lib_path[sfml_path].c_str(), RTLD_LAZY | RTLD_LOCAL);
}

static char *getDtTm(char *buff)
{
	time_t t = time(0);
	strftime(buff, DTTMSZ, DTTMFMT, localtime(&t));
	buff[8] = 0;
	return buff;
}

void 	StartEngine::setScore(std::string name, int score)
{
	this->_sound = (std::thread([=]() {gonBeThread();}));
	char buff[DTTMSZ];
	std::ofstream file;

	std::cout << "Pulling highscores..." << '\n';
	system("git -C highscore pull");

	file.open("highscore/highscores.txt", std::ios_base::ate | std::ios_base::app);
	file << getDtTm(buff) << " Name : " << name << ", Score : " << score << "\n";
	file.close();

	// std::cout << "Updating highscores..." << '\n';
	// system("git -C highscore add .");
	// system("git -C highscore commit -m \"new score\"");
	// system("git -C highscore push");

	system("clear && echo Highscores");
	system("cat highscore/highscores.txt");
}

void	StartEngine::gonBeThread()
{
	system("afplay Assets/sound/death.wav");
}

void StartEngine::mainControl()
{
	clock_t start, end;
	int direction = 0;
	int score = 0;
	int level = 1;
	int speed = 100000;
	std::string window[] = {"createSFMLWindow", "createSDLWindow", "createGLFWWindow"};

	//choosing lib to call
	if (!this->_dl_handler)
		this->_dl_handler = switchLib(this->_libChoice);
	else
		this->_dl_handler = switchLib(this->_libChoice);

	//checking dl_handler
	if (!this->_dl_handler)
		dlerror_wrapper();

	IGraphicsMain *(*WindowCreator)(std::string, int width, int height);
	WindowCreator = (IGraphicsMain * (*)(std::string, int width, int height)) dlsym(this->_dl_handler, window[this->_libChoice - 1].c_str());

	if (!WindowCreator)
		dlerror_wrapper();

	IGraphicsMain *newWindow;
	newWindow = WindowCreator("Nibbler_42", this->_height, this->_width);
	Snake_class test(this->_height, this->_width);
	std::vector<Part> Snake;
	newWindow->createWindow();

	int food_x, food_y;
	static bool foodOnScreen = false;

	while (true)
	{ //Game loop
		start = clock();
		usleep(speed);
		//Get vector
		Snake = test.getVector();

		//validate return
		if (!(foodOnScreen))
		{
			test.generateFood(this->_width, this->_height, food_x, food_y, Snake);
			foodOnScreen = true;
		}

		direction = newWindow->updateWindow(Snake, food_x, food_y);
		//Error occurred
		if (direction == -1)
			break;
		//food eaten
		if (direction == 200)
		{
			test.addPart();
			Snake = test.getVector();
			test.setVector(Snake);
			score += 10;
			foodOnScreen = false;
			if (score % 50 == 0 && speed > 0)
			{
				speed -= 10000;
				level++;
			}
			std::string libs[] = {"SFML", "SDL", "GLFW"};
			system("clear");
			system("printf '%*s\n' \"${COLUMNS:-$(tput cols)}\" '' | tr ' ' =");
			std::cout << "\033[0;34mInstructions:\033[0m" << std::endl;
			system("printf '%*s\n' \"${COLUMNS:-$(tput cols)}\" '' | tr ' ' =");
			std::cout << "Use F1, F3 or F3 to switch between libraries." << std::endl;
			std::cout << "\033[0;32mF1 = SFML\033[0m" << std::endl;
			std::cout << "\033[0;32mF2 = SDL\033[0m" << std::endl;
			std::cout << "\033[0;32mF3 = GLFW\033[0m" << std::endl;
			system("printf '%*s\n' \"${COLUMNS:-$(tput cols)}\" '' | tr ' ' =");
			std::cout << "\033[0;31mScore:\033[0m " << score << '\n';
			std::cout << "\033[0;31mLevel:\033[0m " << level << '\n';
			system("printf '%*s\n' \"${COLUMNS:-$(tput cols)}\" '' | tr ' ' =");
			std::cout << "\033[0;33mCurrent library:\033[0m " << libs[this->_libChoice - 1] << std::endl;
			system("printf '%*s\n' \"${COLUMNS:-$(tput cols)}\" '' | tr ' ' =");
			end = clock();
			std::cout << "\033[0;33mTime between targets:\033[0m " << ((double)(end - start)/CLOCKS_PER_SEC) << std::endl;
			system("printf '%*s\n' \"${COLUMNS:-$(tput cols)}\" '' | tr ' ' =");
		}
		else if (direction > 200 && direction < 404)
		{
			newWindow->destroyWindow();
			void (*WindowDestructor)(IGraphicsMain *);
			WindowDestructor = (void (*)(IGraphicsMain *))dlsym(this->_dl_handler, "deleteWindow");

			if (!WindowDestructor)
				dlerror_wrapper();

			std::cout << "Releasing resources..." << std::endl;
			WindowDestructor(newWindow);
			dlclose(this->_dl_handler);
			if (direction == 300)
			{
				//sfml things
				std::cout << "Starting SFML..." << std::endl;
				this->_libChoice = 1;
				foodOnScreen = false;
				this->mainControl();
			}
			else if (direction == 301)
			{
				std::cout << "Starting SDL..." << std::endl;
				this->_libChoice = 2;
				foodOnScreen = false;
				this->mainControl();
			}
			else if (direction == 302)
			{
				std::cout << "Starting GLFW..." << std::endl;
				this->_libChoice = 3;
				foodOnScreen = false;
				this->mainControl();
			}
			system("clear");
		}
		else if (direction == 404)
		{
			setScore(this->_name, score);
			// newWindow->destroyWindow();
			exit(0);
		};
		
		
		//Set direction from lib
		test.setDirection(direction);

		//Move snake head
		Snake.at(0).y -= (test.getDirection() == UP) ? 20 : 0;
		Snake.at(0).y += (test.getDirection() == DOWN) ? 20 : 0;
		Snake.at(0).x -= (test.getDirection() == LEFT) ? 20 : 0;
		Snake.at(0).x += (test.getDirection() == RIGHT) ? 20 : 0;

		//check if snake head is out of bounds
		if (this->_libChoice != 3)
		{
			if ((Snake[0].y < -20 || Snake[0].y > this->_height) ||
					(Snake[0].x < -20 || Snake[0].x > this->_width))
			{
				setScore(this->_name, score);
				newWindow->destroyWindow();
				exit(0);
			}
		}

		//Update snake parts
		for (size_t i = 1; i < Snake.size(); ++i)
		{
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
		if (!(test.collision()))
		{
			setScore(this->_name, score);
			newWindow->destroyWindow();
			exit(0);
		}

		//Update vector
		test.setVector(Snake);
	}

	void (*WindowDestructor)(IGraphicsMain *);
	WindowDestructor = (void (*)(IGraphicsMain *))dlsym(this->_dl_handler, "deleteWindow");

	if (!WindowDestructor)
		dlerror_wrapper();

	WindowDestructor(newWindow);
	dlclose(this->_dl_handler);
}

void StartEngine::dlerror_wrapper(void)
{
	std::cout << "Error: " << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}
