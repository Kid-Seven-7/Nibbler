/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:47:02 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/25 08:29:46 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include <string>
#include <iostream>
#include "../include/IGraphicsMain.hpp"


void    dlerror_wrapper(void)
{
    std::cout << "Error: " << dlerror() << std::endl;
    exit(EXIT_FAILURE);
}

int main(int ac, char **av)
{
    void    *dl_handler;
    int lib_choice = std::stoi(av[3]);
    std::string window[] = {"createSFMLWindow", "createSDLWindow", "createGLFWWindow"};
    std::string lib_path[] = {"bin/sfml.so", "bin/sdl.so", "bin/glfw.so"};

    if (lib_choice == 1)
    {
        //SFML WINDOW CREATION
        dl_handler = dlopen(lib_path[sfml_path].c_str(), RTLD_LAZY | RTLD_LOCAL);
        if (!dl_handler)
            dlerror_wrapper();

        IGraphicsMain    *(*WindowCreator)(std::string, int width, int height);
        WindowCreator = (IGraphicsMain *(*)(std::string, int width, int height)) dlsym(dl_handler, window[SfmlWin].c_str());

        if (!WindowCreator)
            dlerror_wrapper();

        IGraphicsMain *newWindow;
        newWindow = WindowCreator("Sfml Window", std::stoi(av[1]), std::stoi(av[2]));
        newWindow->createWindow();

        void    (*WindowDestructor)(IGraphicsMain *);
        WindowDestructor = (void(*)(IGraphicsMain *)) dlsym(dl_handler, "deleteWindow");

        if (!WindowDestructor)
            dlerror_wrapper();

        WindowDestructor(newWindow);
        dlclose(dl_handler);
    }
    else if (lib_choice == 2)
    {
        //SDL WINDOW CREATION
        dl_handler = dlopen(lib_path[sdl_path].c_str(), RTLD_LAZY | RTLD_LOCAL);
        if (!dl_handler)
            dlerror_wrapper();

        IGraphicsMain    *(*WindowCreator)(std::string, int width, int height);
        WindowCreator = (IGraphicsMain *(*)(std::string, int width, int height)) dlsym(dl_handler, window[SdlWin].c_str());

        if (!WindowCreator)
            dlerror_wrapper();

        IGraphicsMain *newWindow;
        newWindow = WindowCreator("Sdl Window", std::stoi(av[1]), std::stoi(av[2]));
        newWindow->createWindow();

        void    (*WindowDestructor)(IGraphicsMain *);
        WindowDestructor = (void(*)(IGraphicsMain *)) dlsym(dl_handler, "deleteWindow");

        if (!WindowDestructor)
            dlerror_wrapper();

        WindowDestructor(newWindow);
        dlclose(dl_handler);
    }
    else if (lib_choice == 3)
    {
        //SDL WINDOW CREATION
        dl_handler = dlopen(lib_path[glfw_path].c_str(), RTLD_LAZY | RTLD_LOCAL);
        if (!dl_handler)
            dlerror_wrapper();

        IGraphicsMain    *(*WindowCreator)(std::string, int width, int height);
        WindowCreator = (IGraphicsMain *(*)(std::string, int width, int height)) dlsym(dl_handler, window[GlfwWin].c_str());

        if (!WindowCreator)
            dlerror_wrapper();

        IGraphicsMain *newWindow;
        newWindow = WindowCreator("GLFW Window", std::stoi(av[1]), std::stoi(av[2]));
        newWindow->createWindow();

        void    (*WindowDestructor)(IGraphicsMain *);
        WindowDestructor = (void(*)(IGraphicsMain *)) dlsym(dl_handler, "deleteWindow");

        if (!WindowDestructor)
            dlerror_wrapper();

        WindowDestructor(newWindow);
        dlclose(dl_handler);
    }
}
