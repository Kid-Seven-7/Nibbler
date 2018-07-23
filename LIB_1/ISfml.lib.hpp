/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISfml.lib.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:53:14 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/23 08:25:28 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISFML_LIB_HPP
#define ISFML_LIB_HPP

#include <SFML/Window.hpp>
#include <iostream>

class ISfml_Class
{
    public:
        virtual int         getWidth() const = 0;
        virtual int         getHeight() const = 0;
        virtual std::string getName() const = 0;
        virtual void        createSfmlWindow() = 0;
};
#endif