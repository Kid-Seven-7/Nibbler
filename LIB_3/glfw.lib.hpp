/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfw.lib.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:51:03 by jngoma            #+#    #+#             */
/*   Updated: 2018/08/12 10:14:04 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLFW_LIB_HPP
#define GLFW_LIB_HPP

#include <GL/glew.h>
#include "../include/IGraphicsMain.hpp"
#include "../include/Nibbler.hpp"
#include <math.h>

//Defines for directions
# define UP 0
# define DOWN 1
# define RIGHT 2
# define LEFT 3

class Glfw_Class : public IGraphicsMain {
    private:
      int           _width;
      int           _height;
      int           _ret;
      float         _food_x;
      float         _food_y;
      int           _raw_food_x;
      int           _raw_food_y;
      bool          _eaten;
      int           _direction;
      int           _libChange;
      bool          _polyGonMode;
			std::string   _name;
      GLFWwindow *  _window;
      Glfw_Class(void);

    public:
      Glfw_Class(std::string name, int width, int height);
      ~Glfw_Class(void);

      int           getWidth() const;
      int           getHeight() const;
      std::string   getName() const;
      void          createWindow();
      void          destroyWindow();
      void          processInput();
      void          drawCell(float x, float y, int head);
      void          drawFood(int food_x, int food_y, bool bonus);
      float         processCoord(int coord, std::string type);
      bool          isInRange(int head_x, int head_y, int food_x, int food_y);
      bool          isOffScreen(int c_width, int c_height);
      int          	updateWindow(std::vector<Part> &Snake, int food_x, int food_y, bool bonus);
};

extern "C"
{
    Glfw_Class  *createGLFWWindow(std::string name, int width, int height);
    void        deleteWindow(Glfw_Class *glfw_class);
}

#endif
