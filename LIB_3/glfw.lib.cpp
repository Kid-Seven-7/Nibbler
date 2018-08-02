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

void			Glfw_Class::processInput()
{
	if (glfwGetKey(this->_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(this->_window, true);
}

void			Glfw_Class::createWindow()
{
	if (!glfwInit())
	{
		std::cout << "GLFW failed to start" << std::endl;
		exit(1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	this->_window = glfwCreateWindow(this->_width, this->_height, "Nibbler_42", NULL, NULL);
	if (this->_window == NULL)
	{
		std::cout << "Error: Failed to create glfw window." << std::endl;
		glfwTerminate();
		exit(1);
	}
	glfwMakeContextCurrent(this->_window);
	//Initializing glew
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Glew Error!" << std::endl;
		exit(1);
	}

	//setting dimensions
	glViewport(0, 0, this->_width, this->_height);
	while (!glfwWindowShouldClose(this->_window))
	{
		processInput();

		//rendering here
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(this->_window);
		glfwPollEvents();
	}
	glfwTerminate();
	// if (!glfwInit())
	// 	return;

	// this->_window = glfwCreateWindow(this->getWidth(), this->getHeight(), this->getName().c_str(), NULL, NULL);
	// if (!this->_window)
	// {
	// 	glfwTerminate();
	// 	return;
	// }

	// glfwMakeContextCurrent(this->_window);


	// unsigned int	buffer;
	// float	positions[6] = {
	// 	-0.5f, -0.5f,
	// 	0.0f, 0.5f,
	// 	0.5f, -0.5f
	// };

	// glGenBuffers(1, &buffer);
	// glBindBuffer(GL_ARRAY_BUFFER, buffer);
	// glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

	// glEnableVertexAttribArray(0);
	// glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
	// // glBindBuffer(GL_ARRAY_BUFFER, 0);
	// while (!glfwWindowShouldClose(this->_window))
	// {
	// 	glClear(GL_COLOR_BUFFER_BIT);
	// 	glDrawArrays(GL_TRIANGLES, 0, 3);
	// 	glfwSwapBuffers(this->_window);
	// 	glfwPollEvents();
	// }
	// destroyWindow();
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