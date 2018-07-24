/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sfml.lib.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:36:57 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/24 15:13:04 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sfml.lib.hpp"

Sfml_Class::Sfml_Class(std::string name, int width, int height)
{
    this->_name = name;
    this->_width = width;
    this->_height = height;
}

Sfml_Class::~Sfml_Class() {}

int         Sfml_Class::getWidth() const
{
    return this->_width;
}

int         Sfml_Class::getHeight() const
{
    return this->_height;
}

std::string Sfml_Class::getName() const
{
    return this->_name;
}

void        Sfml_Class::createWindow()
{
    sf::Window window(sf::VideoMode(this->getWidth(), this->getHeight()), this->getName());

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}

void        Sfml_Class::destroyWindow() {}

void        Sfml_Class::updateWindow() {}

Sfml_Class      *createSFMLWindow(std::string name, int width, int height)
{
    return new Sfml_Class(name, width, height);
}

void            deleteWindow(Sfml_Class *sfml_class)
{
    delete  sfml_class;
}