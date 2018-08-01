/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfw.lib.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:51:03 by jngoma            #+#    #+#             */
/*   Updated: 2018/07/30 09:51:43 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLFW_LIB_HPP
#define GLFW_LIB_HPP

#include <GL/glew.h>
#include "../include/IGraphicsMain.hpp"

class Glfw_Class : public IGraphicsMain {
    private:
      int           _width;
      int           _height;
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
      int          updateWindow(std::vector<Part> &Snake);
};

extern "C"
{
    Glfw_Class  *createGLFWWindow(std::string name, int width, int height);
    void        deleteWindow(Glfw_Class *glfw_class);
}

#endif
