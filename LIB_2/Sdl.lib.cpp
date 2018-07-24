/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sdl.lib.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:11:23 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/24 15:23:01 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sdl.lib.hpp"

Sdl_Class::Sdl_Class(std::string name, int width, int height)
{
    this->_name = name;
    this->_width = width;
    this->_height = height;
}

Sdl_Class::~Sdl_Class() {}

int         Sdl_Class::getWidth() const
{
    return this->_width;
}

int         Sdl_Class::getHeight() const
{
    return this->_height;
}

std::string Sdl_Class::getName() const
{
    return this->_name;
}

void        Sdl_Class::createWindow()
{
    SDL_Window * window = NULL;
    SDL_Surface * screenSurface = NULL;

    //creating window
    if ( SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cout << "Error: " << SDL_GetError() << std::endl;
    else
    {
        window = SDL_CreateWindow(this->_name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->_width, this->_height, SDL_WINDOW_SHOWN);
        if (window == NULL)
            std::cout << "Error: Failed to create window" << std::endl;
        else
        {
            screenSurface = SDL_GetWindowSurface( window );

            SDL_FillRect ( screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface( window );
            SDL_Delay( 5000 );
            SDL_DestroyWindow( window );
            SDL_Quit();
        }
    }
}

void        Sdl_Class::destroyWindow() {}

void        Sdl_Class::updateWindow() {}

Sdl_Class      *createSDLWindow(std::string name, int width, int height)
{
    return new Sdl_Class(name, width, height);
}

void            deleteWindow(Sdl_Class *sdl_Class)
{
    delete  sdl_Class;
}