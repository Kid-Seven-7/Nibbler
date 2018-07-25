/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StartEngine.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 08:44:28 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/25 09:30:35 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef START_ENGINE_HPP
#define START_ENGINE_HPP

#include "IGraphicsMain.hpp"
#include <dlfcn.h>

class StartEngine
{
    private:
        int     _libChoice;
        
    public:
        StartEngine(void);
        StartEngine(StartEngine const & src);
        StartEngine(int libChoice);
        ~StartEngine(void);

        StartEngine const & operator=(StartEngine const & rhs);
        void    *   switchLib(int libChoice = 1);
        void        mainControl();
        void        dlerror_wrapper(void);
};
#endif