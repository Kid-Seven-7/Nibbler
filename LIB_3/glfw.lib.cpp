/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfw.lib.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:50:59 by jngoma            #+#    #+#             */
/*   Updated: 2018/08/12 10:54:12 by amatshiy         ###   ########.fr       */
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
	this->_food_x = -2.0f;
	this->_food_y = -2.0f;
	this->_eaten = false;
	this->_ret = DOWN;
	this->_direction = DOWN;
	this->_libChange = 0;
	this->_polyGonMode = false;
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
	if ((glfwGetKey(this->_window, GLFW_KEY_RIGHT) == GLFW_PRESS) && (this->_direction != LEFT))
	{
		this->_direction = RIGHT;
		this->_ret = RIGHT;
	}
	if ((glfwGetKey(this->_window, GLFW_KEY_LEFT) == GLFW_PRESS) && (this->_direction != RIGHT))
	{
		this->_direction = LEFT;
		this->_ret = LEFT;
	}
	else if ((glfwGetKey(this->_window, GLFW_KEY_UP) == GLFW_PRESS) && (this->_direction != UP))
	{
		this->_direction = DOWN;
		this->_ret = DOWN;
	}
	else if ((glfwGetKey(this->_window, GLFW_KEY_DOWN) == GLFW_PRESS) && (this->_direction != DOWN))
	{
		this->_direction = UP;
		this->_ret = UP;
	}
	else if (glfwGetKey(this->_window, GLFW_KEY_F1) == GLFW_PRESS)
	{
		//load sfml
		this->_libChange = 300;
	}
	else if (glfwGetKey(this->_window, GLFW_KEY_F2) == GLFW_PRESS)
	{
		//load sdl
		this->_libChange = 301;
	}
}

void			Glfw_Class::drawCell(float x, float y, int head)
{
	int	triangleAmount = 20;
	GLfloat	radius = 0.08f;
	GLfloat twicePie = 2.0f * M_PI;
	srand(time(NULL));
				// x // y
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //0.0 to 1.0 :)
	float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //0.0 to 1.0 :)
	float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //0.0 to 1.0 :)

	if (head == 1)
	{
		glBegin(GL_TRIANGLE_FAN);

		glColor3f  (r, g, b);
		glVertex2f(x, y);
		for (int i = 0; i <= triangleAmount; i++)
		{
			
			glVertex2f(
				x + (radius * cos(i * twicePie / triangleAmount)),
				y + (radius * sin(i * twicePie / triangleAmount))
			);
		}
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
		glEnd();
	}
	else if (head == 0)
	{
		r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //0.0 to 1.0 :)
		g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //0.0 to 1.0 :)
		b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //0.0 to 1.0 :)

		glBegin(GL_TRIANGLE_FAN);
		glColor3f  (r, g, b);
		glVertex2f(x, y);
		for (int i = 0; i <= triangleAmount; i++)
		{
			r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //0.0 to 1.0 :)
			g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //0.0 to 1.0 :)
			b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //0.0 to 1.0 :)
			glColor3f  (r, g, b);
			glVertex2f(
				x + (radius * cos(i * twicePie / triangleAmount)),
				y + (radius * sin(i * twicePie / triangleAmount))
			);
		}
		glEnd();
	}
	else
	{
		r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //0.0 to 1.0 :)
		g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //0.0 to 1.0 :)
		b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //0.0 to 1.0 :)

		glBegin(GL_TRIANGLE_FAN);
		if (head == 5)
		{
			radius = 0.2f;
			glColor3f  (r, r, r);
		}
		else
			glColor3f  (r, r, r);
		glVertex2f(x, y);
		for (int i = 0; i <= triangleAmount; i++)
		{
			r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //0.0 to 1.0 :)
			g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //0.0 to 1.0 :)
			b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //0.0 to 1.0 :)

			if (head == 5)
				glColor3f  (b, b, b);
			else
				glColor3f  (g, g, r);
			glVertex2f(
				x + (radius * cos(i * twicePie / triangleAmount)),
				y + (radius * sin(i * twicePie / triangleAmount))
			);
		}
		glEnd();
	}
}


void			Glfw_Class::createWindow()
{
	if (!glfwInit())
	{
		std::cout << "GLFW failed to start" << std::endl;
		exit(1);
	}

	// glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
	// glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR , 0);
	// glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	this->_window = glfwCreateWindow(this->_width, this->_height, "Nibbler_42", NULL, NULL);
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

void		Glfw_Class::drawFood(int food_x, int food_y, bool isBonus)
{

	if (this->_eaten == false)
	{
		if (this->_food_x < -1.0f )
		{
			this->_raw_food_x = food_x;
			this->_raw_food_y = food_y;
			this->_food_x = processCoord(food_x, "x");
			this->_food_y = processCoord(food_y, "y");
		}
		if (!isBonus)
			drawCell(this->_food_x, this->_food_y, 2);
		else
			drawCell(this->_food_x, this->_food_y, 5);
	}
	else
	{
		this->_raw_food_x = food_x;
		this->_raw_food_y = food_y;
		this->_food_x = processCoord(food_x, "x");
		this->_food_y = processCoord(food_y, "y");
		this->_eaten = false;
		drawCell(this->_food_x, this->_food_y, 2);
	}
}

bool	Glfw_Class::isInRange(int x, int y, int foodX, int foodY)
{
	int isX = 0;
	int isY = 0;
	isX = ((x < foodX + 45) && (x > foodX - 45)) ? 1 : 0;
	isY = ((y < foodY + 45) && (y > foodY - 45)) ? 1 : 0;
	return (isX == 1 && isY == 1) ? true : false;
}

bool	Glfw_Class::isOffScreen(int c_width, int c_height)
{
	if (c_width > this->_width || c_width < 0)
		return (true);
	if (c_height > this->_height || c_height < 0)
		return (true);
	return (false);
}

int			Glfw_Class::updateWindow(std::vector<Part> &Snake, int food_x, int food_y, bool bonus)
{
	int		ret = this->_ret;
	float	head_x, head_y, x, y;

	// glViewport(0, 0, this->_width + 80, this->_height);
	while (true)
	{
		// usleep(10000); //to slow down the snake
		glClearColor(0.12f, 0.12f, 0.12, 1.0f); // dark gray??
		// processInput();
		if (this->_libChange > 200)
		{
			std::cout << "Switching library..." << std::endl;
			return (this->_libChange);
		}
		glClear(GL_COLOR_BUFFER_BIT);
		for (size_t i = 0; i < Snake.size(); i++)
		{
			processInput();
			if (i == 0)
			{
				//head coords :)
				head_x = processCoord(Snake[0].x, "x");
				head_y = processCoord(Snake[0].y, "y");
				drawCell(head_x, head_y, 1);
				i++;
			}
			// if (this->isOffScreen(Snake[0].x, Snake[0].y))
			// 	return (404);
			x = processCoord(Snake[i].x, "x");
			y = processCoord(Snake[i].y, "y");
			 if (bonus)
				drawFood(food_x, food_y, true);
			else
				drawFood(food_x, food_y, false);
			drawCell(x, y, 0);
		}
		if (this->isOffScreen(Snake[0].x, Snake[0].y))
				return (404);
		if (this->isInRange(Snake[0].x, Snake[0].y, this->_raw_food_x, this->_raw_food_y))
		{
			this->_eaten = true;
			if (!this->_polyGonMode)
				this->_polyGonMode = true;
			else
				this->_polyGonMode = false;
			return (200);
		}
		if (this->_polyGonMode)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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