/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfw.lib.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:51:03 by jngoma            #+#    #+#             */
/*   Updated: 2018/07/23 09:51:12 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLFW_LIB_HPP
#define GLFW_LIB_HPP

#include "GLFWMain.hpp"

class Glfw_Class : public GraphicsMain {
    private:
			std::string _name;
      int _width;
      int _height;

      Glfw_Class(void);

    public:
      Glfw_Class(std::string name, int width, int height);
      ~Glfw_Class(void);

      int getWidth() const;
      int getHeight() const;
      std::string getName() const;
      void createWindow();
};

extern "C" {
    Glfw_Class *createWindow(std::string name, int width, int height);
    void deleteWindow(Glfw_Class *Glfw_Class);
}

#endif
