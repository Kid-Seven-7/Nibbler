/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGraphicsMain.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:53:14 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/26 08:03:58 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef IGRAPHICS_MAIN
# define IGRAPHICS_MAIN

# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>
# include <SFML/OpenGL.hpp>
# include <SFML/System.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Config.hpp>
# include <SFML/Main.hpp>
# include <SFML/Network.hpp>
# include <SDL.h>
# include <GLFW/glfw3.h>
# include <iostream>
// # include "Nibbler.hpp"

struct Part;

enum eLibPath {sfml_path, sdl_path, glfw_path};

class IGraphicsMain
{
    public:
        virtual int         getWidth() const = 0; //not needed
        virtual int         getHeight() const = 0; //not needed
        virtual std::string getName() const = 0; //not needed
        virtual void        createWindow() = 0;
        virtual void        destroyWindow() = 0;
        virtual int        updateWindow(std::vector<Part> &Snake) = 0;
        virtual 						~IGraphicsMain(){}
};
#endif
