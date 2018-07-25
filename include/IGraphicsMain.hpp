/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGraphicsMain.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:53:14 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/25 08:19:04 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGRAPHICS_MAIN
#define IGRAPHICS_MAIN

#include <SFML/Window.hpp>
#include <SDL.h>
#include <GLFW/glfw3.h>
#include <iostream>

enum    eWindowType {SfmlWin, SdlWin, GlfwWin};

class IGraphicsMain
{
    public:
        virtual int         getWidth() const = 0; //not needed
        virtual int         getHeight() const = 0; //not needed
        virtual std::string getName() const = 0; //not needed
        virtual void        createWindow() = 0;
        virtual void        destroyWindow() = 0;
        virtual void        updateWindow() = 0;
        virtual ~IGraphicsMain(){}
};
#endif
