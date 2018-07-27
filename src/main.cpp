/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:47:02 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/26 09:00:35 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include <string>
#include <iostream>
#include "../include/StartEngine.hpp"
#include "../include/IGraphicsMain.hpp"


void    dlerror_wrapper(void)
{
    std::cout << "Error: " << dlerror() << std::endl;
    exit(EXIT_FAILURE);
}

int main(int ac, char **av)
{
    if (ac > 3)
    {
        try
        {
            StartEngine s_engine(std::stoi(av[1]), std::stoi(av[2]), std::stoi(av[3]));
            s_engine.mainControl();
        }
        catch (std::exception & e)
        {
            std::cout << "Error: You fucking passed invalid arguments" << std::endl;
            std::cout << "Exception details: " << e.what() << std::endl;
        }
    }
    else
        std::cout << "Usage: ./42_Nibbler height width 1, 2, or 3" << std::endl;
    return (0);
}
