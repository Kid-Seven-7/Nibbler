/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:47:02 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/20 15:41:24 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include "GraphicsMain.hpp"
#include <string>

void    dlerror_wrapper(void)
{
    std::cout << "Error: " << dlerror() << std::endl;
    exit(EXIT_FAILURE);
}

int main(int ac, char **av)
{
    void    *dl_handler;

    dl_handler = dlopen(av[1], RTLD_LAZY | RTLD_LOCAL);
    if (!dl_handler)
        dlerror_wrapper();
    
    GraphicsMain    *(*WindowCreator)(std::string, int width, int height);
    WindowCreator = (GraphicsMain *(*)(std::string, int width, int height)) dlsym(dl_handler, "createWindow");

    if (!WindowCreator)
        dlerror_wrapper();
    
    GraphicsMain *newWindow;
    newWindow = WindowCreator("Sfml Window", std::stoi(av[2]), std::stoi(av[3]));
    newWindow->createSfmlWindow();

    void    (*WindowDestructor)(GraphicsMain *);
    WindowDestructor = (void(*)(GraphicsMain *)) dlsym(dl_handler, "deleteWindow");

    if (!WindowDestructor)
        dlerror_wrapper();

    WindowDestructor(newWindow);
    dlclose(dl_handler);
}