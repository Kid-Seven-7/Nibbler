/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:47:02 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/25 09:30:11 by amatshiy         ###   ########.fr       */
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
    StartEngine s_engine(std::stoi(av[1]));
    s_engine.mainControl();
    return (0);
}
