/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicsMain.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:53:14 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/20 12:21:46 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_MAIN
#define GRAPHICS_MAIN

#include <SFML/Window.hpp>
#include <iostream>

template <typename T>
class GraphicsMain
{
    public:
        virtual int         getWidth() const = 0; //not needed
        virtual int         getHeight() const = 0; //not needed
        virtual std::string getName() const = 0; //not needed
        virtual void        createWindow() = 0;
        virtual void        destroyWindow(T window) = 0;
        virtual void        updateWindow(T window) = 0;
};
#endif
