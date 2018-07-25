/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StartEngine.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 08:58:33 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/25 09:30:13 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/StartEngine.hpp"

StartEngine::StartEngine() {}

StartEngine::StartEngine(int libChoice) 
{
    this->_libChoice = libChoice;
}

StartEngine::StartEngine(StartEngine const & src) { *this = src; }

StartEngine::~StartEngine() {}

StartEngine const & StartEngine::operator=(StartEngine const & rhs)
{
    (void)rhs;
    return *this;
}

void * StartEngine::switchLib(int libChoice)
{
    std::string lib_path[] = {"../bin/sfml.so", "../bin/sdl.so", "../bin/glfw.so"};
    void    *dl_handler;

    if (libChoice == 2)
        return  dlopen(lib_path[sdl_path].c_str(), RTLD_LAZY | RTLD_LOCAL);
    else if (libChoice == 3)
        return  dlopen(lib_path[glfw_path].c_str(), RTLD_LAZY | RTLD_LOCAL);
    else
        return  dlopen(lib_path[sfml_path].c_str(), RTLD_LAZY | RTLD_LOCAL);
}

void    StartEngine::mainControl()
{
    void    *dl_handler;
    std::string window[] = {"createSFMLWindow", "createSDLWindow", "createGLFWWindow"};

    dl_handler = switchLib(this->_libChoice);

    IGraphicsMain    *(*WindowCreator)(std::string, int width, int height);
        WindowCreator = (IGraphicsMain *(*)(std::string, int width, int height)) dlsym(dl_handler, window[this->_libChoice - 1].c_str());

        if (!WindowCreator)
            dlerror_wrapper();

        IGraphicsMain *newWindow;
        newWindow = WindowCreator("Nibbler_42", 400, 400);
        newWindow->createWindow();

        void    (*WindowDestructor)(IGraphicsMain *);
        WindowDestructor = (void(*)(IGraphicsMain *)) dlsym(dl_handler, "deleteWindow");

        if (!WindowDestructor)
            dlerror_wrapper();

        WindowDestructor(newWindow);
        dlclose(dl_handler);
}

void    StartEngine::dlerror_wrapper(void)
{
    std::cout << "Error: " << dlerror() << std::endl;
    exit(EXIT_FAILURE);
}