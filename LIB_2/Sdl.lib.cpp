/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sdl.lib.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:11:23 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/25 07:43:31 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sdl.lib.hpp"

Sdl_Class::Sdl_Class(std::string name, int width, int height)
{
    this->_name = name;
    this->_width = width;
    this->_height = height;
    this->_window = NULL;
}

Sdl_Class::~Sdl_Class() {}

int         Sdl_Class::getWidth() const{
    return this->_width;
}

int         Sdl_Class::getHeight() const{
    return this->_height;
}

std::string Sdl_Class::getName() const{
    return this->_name;
}

void        Sdl_Class::createWindow(){
    SDL_Surface * screenSurface = NULL;

    //creating window
    if ( SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cout << "Error: " << SDL_GetError() << std::endl;
    else    {
        this->_window = SDL_CreateWindow(this->_name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->_width, this->_height, SDL_WINDOW_SHOWN);
        if (this->_window == NULL)
            std::cout << "Error: Failed to create window" << std::endl;
        else        {
            screenSurface = SDL_GetWindowSurface( this->_window );

            SDL_FillRect ( screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface( this->_window );
            SDL_Delay( 5000 );
        }
    }
}

void        Sdl_Class::destroyWindow(){
    SDL_DestroyWindow( this->_window );
    SDL_Quit();
}

int        Sdl_Class::updateWindow(std::vector<Part> &Snake){
	(void)Snake;
  SDL_UpdateWindowSurface( this->_window );
	return 0;
}

Sdl_Class      *createSDLWindow(std::string name, int width, int height){
    return new Sdl_Class(name, width, height);
}

void            deleteWindow(Sdl_Class *sdl_class){
    delete  sdl_class;
}
