/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StartEngine.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 08:44:28 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/25 08:50:44 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef START_ENGINE_HPP
#define START_ENGINE_HPP

#include "IGraphicsMain.hpp"

class StartEngine
{
    public:
        StartEngine(void);
        StartEngine(StartEngine const & src);
        ~StartEngine(void);

        StartEngine const & operator=(StartEngine const & rhs);
        void    *   switchLib();
};
#endif