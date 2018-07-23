/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sdl.lib.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:11:28 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/23 08:25:31 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_LIB_HPP
#define SDL_LIB_HPP

#include "ISdl.lib.hpp"

class Sdl_Class : public ISdl_Class
{
    private:
        int         _width;
        int         _height;
        std::string _name;
        Sdl_Class(void);

    public:
        Sdl_Class(std::string name, int width, int height);
        ~Sdl_Class(void);

        int             getWidth() const;
        int             getHeight() const;
        std::string     getName() const;
        void            createSdlWindow();
};

extern "C"
{
    Sdl_Class  *createSDLWindow(std::string name, int width, int height);
    void        deleteWindow(Sdl_Class *sdl_class);
}

#endif