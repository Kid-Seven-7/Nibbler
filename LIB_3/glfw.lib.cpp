/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfw.lib.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:50:59 by jngoma            #+#    #+#             */
/*   Updated: 2018/07/25 08:13:55 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glfw.lib.hpp"

Glfw_Class::Glfw_Class(std::string name, int width, int height)
{
	this->_name = name;
	this->_height = height;
	this->_width = width;
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

void			Glfw_Class::createWindow()
{
	if (!glfwInit())
		return;

	this->_window = glfwCreateWindow(this->getWidth(), this->getHeight(), this->getName().c_str(), NULL, NULL);
	if (!this->_window)
	{
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(this->_window);

	while (!glfwWindowShouldClose(this->_window))
	{
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(this->_window);
			glfwPollEvents();
	}
	destroyWindow();
}

void		Glfw_Class::destroyWindow() 
{
	glfwTerminate();
}

void		Glfw_Class::updateWindow() {}

Glfw_Class      *createGLFWWindow(std::string name, int width, int height)
{
    return new Glfw_Class(name, width, height);
}

void            deleteWindow(Glfw_Class *glfw_class)
{
		delete	glfw_class;
}
