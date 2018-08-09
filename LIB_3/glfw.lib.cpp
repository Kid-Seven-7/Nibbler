/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfw.lib.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:50:59 by jngoma            #+#    #+#             */
/*   Updated: 2018/08/09 08:48:44 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glfw.lib.hpp"
#include <unistd.h>

// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"

// static int CreateShader(std::string& vertexShader, std::string& fragmentShader)
// {

// }

Glfw_Class::Glfw_Class(std::string name, int width, int height)
{
	this->_name = name;
	this->_height = height;
	this->_width = width;
	std::cout << "GLFW Running now..." << std::endl;
}

Glfw_Class::~Glfw_Class() {}

int				Glfw_Class::getWidth() const
{
	return this->_width;
}

int				Glfw_Class::getHeight() const
{
	return this->_height;
}

std::string		Glfw_Class::getName() const
{
	return this->_name;
}

void			Glfw_Class::processInput()
{
	if (glfwGetKey(this->_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(this->_window, true);
		glfwTerminate();
		exit(0);
	}
	if (glfwGetKey(this->_window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		this->_ret = RIGHT;
	}
	if (glfwGetKey(this->_window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		this->_ret = LEFT;
	}
	else if (glfwGetKey(this->_window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		this->_ret = DOWN;
	}
	else if (glfwGetKey(this->_window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		this->_ret = UP;
	}
}

void			Glfw_Class::drawCell(float x, float y)
{
	std::cout << "Called" << std::endl;
	glBegin(GL_QUADS);
				// x // y
	glColor3f  (0.20, 0.60, 0.20);

	glVertex2f(x, y); //top left 
	glVertex2f(x, y - 0.09f); //bottom left
	glVertex2f(x + 0.09f, y - 0.09f); //bottom right
	glVertex2f(x + 0.09f, y); //top right
	glEnd();
}


void			Glfw_Class::createWindow()
{
	if (!glfwInit())
	{
		std::cout << "GLFW failed to start" << std::endl;
		exit(1);
	}

	// glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	// glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	// glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	this->_window = glfwCreateWindow(this->_width, this->_height, "Nibbler_42", NULL, NULL);
	if (this->_window == NULL)
	{
		std::cout << "Error: Failed to create glfw window." << std::endl;
		glfwTerminate();
		exit(1);
	}
	glfwMakeContextCurrent(this->_window);
	glViewport(0, 0, this->_width, this->_height);
	// //Initializing glew
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Glew Error!" << std::endl;
		exit(1);
	}
}

void		Glfw_Class::destroyWindow() 
{
	glfwTerminate();
}

float		Glfw_Class::processCoord(int coord, std::string type)
{
	std::cout << std::endl;
	if (type == "x")
	{
		float ans = (float)2 / this->_width;
		float ans2 = (float)this->_width / 2;
		float ans3 = (float)coord - ans2;
		float ret = (float)ans3 * ans;
		return (ret);
	}
	else
	{
		float ans = (float)2 / this->_height;
		float ans2 = (float)this->_height / 2;
		float ans3 = (float)coord - ans2;
		float ret = (float)ans3 * ans;
		return (ret);
	}
}

int			Glfw_Class::updateWindow(std::vector<Part> &Snake)
{
	float x, y;
	int	ret = this->_ret;

	glfwShowWindow(this->_window);
	glfwFocusWindow(this->_window);

	while (true)
	{
		usleep(100000); //to slow down the snake
		glClear(GL_COLOR_BUFFER_BIT);
		processInput();

		for (size_t i = 0; i < Snake.size(); i++)
		{
			processInput();
			x = processCoord(Snake[i].x, "x");
			y = processCoord(Snake[i].y, "y");
			drawCell(x, y);
		}
		glfwSwapBuffers(this->_window);
		glfwPollEvents();
		return (this->_ret);
	}
	return (ret);
}

Glfw_Class      *createGLFWWindow(std::string name, int width, int height)
{
    return new Glfw_Class(name, width, height);
}

void            deleteWindow(Glfw_Class *glfw_class)
{
		delete	glfw_class;
}