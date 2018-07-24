/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sfml.lib.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:30:14 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/24 15:18:39 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFML_LIB_HPP
#define SFML_LIB_HPP

#include "../include/IGraphicsMain.hpp"

<<<<<<< HEAD
class Sfml_Class : public IGraphicsMain
{
=======
class Sfml_Class : public ISfml_Class{
>>>>>>> origin
    private:
        int         _width;
        int         _height;
        std::string _name;
        Sfml_Class(void);

    public:
        Sfml_Class(std::string name, int width, int height);
        ~Sfml_Class(void);

        int             getWidth() const;
        int             getHeight() const;
        std::string     getName() const;
        void            createWindow();
        void            destroyWindow();
        void            updateWindow();
};

extern "C"{
    Sfml_Class  *createSFMLWindow(std::string name, int width, int height);
    void        deleteWindow(Sfml_Class *sfml_class);
}

#endif
