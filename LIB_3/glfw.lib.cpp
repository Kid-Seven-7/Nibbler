/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfw.lib.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:50:59 by jngoma            #+#    #+#             */
/*   Updated: 2018/07/31 14:03:02 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glfw.lib.hpp"

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

	//Initializing glew
	if (glewInit() != GLEW_OK)
		std::cout << "Glew Error!" << std::endl;

	unsigned int	buffer;
	float	positions[6] = {
		-0.5f, -0.5f,
		0.0f, 0.5f,
		0.5f, -0.5f
	};

	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
	// glBindBuffer(GL_ARRAY_BUFFER, 0);
	while (!glfwWindowShouldClose(this->_window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawArrays(GL_TRIANGLES, 0, 3);
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