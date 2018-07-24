/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfw.lib.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:50:59 by jngoma            #+#    #+#             */
/*   Updated: 2018/07/23 09:51:01 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glfw.lib.hpp"

Glfw_Class::Glfw_Class(std::string name, int width, int height)
:_name(name), _width(width), _height(height)
{}

Glfw_Class::~Glfw_Class(){
	glfwTerminate();
}

int	Glfw_Class::getWidth() const{
	return this->_width;
}

int	Glfw_Class::getHeight() const{
	return this->_height;
}

std::string Glfw_Class::getName() const{
	return this->_name;
}

void Glfw_Class::createWindow(){
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
			return;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(this->getWidth(), this->getHeight(), this->getName().c_str(), NULL, NULL);
	if (!window){
			glfwTerminate();
			return;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window)){
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
	}
}

Glfw_Class      *createWindow(std::string name, int width, int height){
    return new Glfw_Class(name, width, height);
}

void            deleteWindow(Glfw_Class *Glfw_Class){
    // delete  Glfw_Class;
		(void)Glfw_Class;
		std::cout << "dest called" << '\n';
}
