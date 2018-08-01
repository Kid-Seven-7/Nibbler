/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sfml.lib.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:30:14 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/25 07:58:36 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFML_LIB_HPP
#define SFML_LIB_HPP

#include "../include/IGraphicsMain.hpp"
#include "../include/Nibbler.hpp"

class Sfml_Class : public IGraphicsMain
{
    private:
        int         _width;
        int         _height;
        std::string _name;
        sf::RenderWindow  _window;
        Sfml_Class(void);

    public:
        Sfml_Class(std::string name, int width, int height);
        ~Sfml_Class(void);

        int             getWidth() const;
        int             getHeight() const;
        std::string     getName() const;
        void            createWindow();
        void            destroyWindow();
        int            updateWindow(std::vector<Part> &Snake);
};

extern "C"
{
    Sfml_Class  *createSFMLWindow(std::string name, int width, int height);
    void        deleteWindow(Sfml_Class *sfml_class);
}

#endif
