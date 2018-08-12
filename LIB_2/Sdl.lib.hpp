/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sdl.lib.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:11:28 by amatshiy          #+#    #+#             */
/*   Updated: 2018/08/12 10:09:08 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_LIB_HPP
#define SDL_LIB_HPP

#include "../include/IGraphicsMain.hpp"
#include "../include/Nibbler.hpp"

class Sdl_Class : public IGraphicsMain
{
private:
  int             _width;
  int             _height;
  std::string     _name;
  SDL_Window *    _window;
	SDL_Renderer * _renderer;
  Sdl_Class(void);

public:
  Sdl_Class(std::string name, int width, int height);
  ~Sdl_Class(void);

  int             getWidth() const;
  int             getHeight() const;
  std::string     getName() const;
  void            createWindow();
  void            destroyWindow();
  int            	updateWindow(std::vector<Part> &Snake, int food_x, int food_y, bool bonus);
};

extern "C"
{
  Sdl_Class  *createSDLWindow(std::string name, int width, int height);
  void        deleteWindow(Sdl_Class *sdl_class);
}

#endif
