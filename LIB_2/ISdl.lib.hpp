/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISdl.lib.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:11:32 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/23 08:25:30 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISDL_LIB_HPP
#define ISDL_LIB_HPP

#include <SDL.h>
#include <iostream>

class ISdl_Class
{
    public:
        virtual int         getWidth() const = 0;
        virtual int         getHeight() const = 0;
        virtual std::string getName() const = 0;
        virtual void        createSdlWindow() = 0;
};
#endif