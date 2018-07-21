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

class GraphicsMain
{
    public:
        virtual int         getWidth() const = 0;
        virtual int         getHeight() const = 0;
        virtual std::string getName() const = 0;
        virtual void        createSfmlWindow() = 0;
};
#endif