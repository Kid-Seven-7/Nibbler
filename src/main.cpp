/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:47:02 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/24 16:45:28 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include <string>
#include <iostream>
#include "../include/IGraphicsMain.hpp"

void    dlerror_wrapper(void){
    std::cout << "Error: " << dlerror() << std::endl;
    exit(EXIT_FAILURE);
}

int main(int ac, char **av){
	if (ac != 5){
		std::cout << "Invalid input\nUSAGE: [Lib/so/path][height][width][Lib #no]" << '\n';
		return (1);
	}

  void    *dl_handler;
  int lib_choice = std::stoi(av[4]);

  if (lib_choice == 1){
		//SFML WINDOW CREATION
    dl_handler = dlopen(av[1], RTLD_LAZY | RTLD_LOCAL);
    if (!dl_handler)
      dlerror_wrapper();

<<<<<<< HEAD
        IGraphicsMain    *(*WindowCreator)(std::string, int width, int height);
        WindowCreator = (IGraphicsMain *(*)(std::string, int width, int height)) dlsym(dl_handler, "createSFMLWindow");
=======
    ISfml_Class    *(*WindowCreator)(std::string, int width, int height);
    WindowCreator = (ISfml_Class *(*)(std::string, int width, int height)) dlsym(dl_handler, "createSFMLWindow");
>>>>>>> origin

    if (!WindowCreator)
      dlerror_wrapper();

<<<<<<< HEAD
        IGraphicsMain *newWindow;
        newWindow = WindowCreator("Sfml Window", std::stoi(av[2]), std::stoi(av[3]));
        newWindow->createWindow();

        void    (*WindowDestructor)(IGraphicsMain *);
        WindowDestructor = (void(*)(IGraphicsMain *)) dlsym(dl_handler, "deleteWindow");
=======
    ISfml_Class *newWindow;
    newWindow = WindowCreator("Sfml Window", std::stoi(av[2]), std::stoi(av[3]));
    newWindow->createSfmlWindow();

    void    (*WindowDestructor)(ISfml_Class *);
    WindowDestructor = (void(*)(ISfml_Class *)) dlsym(dl_handler, "deleteWindow");
>>>>>>> origin

    if (!WindowDestructor)
      dlerror_wrapper();

    WindowDestructor(newWindow);
    dlclose(dl_handler);
  }	else if (lib_choice == 2){
    //SDL WINDOW CREATION
    dl_handler = dlopen(av[1], RTLD_LAZY | RTLD_LOCAL);
    if (!dl_handler)
      dlerror_wrapper();

<<<<<<< HEAD
        IGraphicsMain    *(*WindowCreator)(std::string, int width, int height);
        WindowCreator = (IGraphicsMain *(*)(std::string, int width, int height)) dlsym(dl_handler, "createSDLWindow");
=======
    ISdl_Class    *(*WindowCreator)(std::string, int width, int height);
    WindowCreator = (ISdl_Class *(*)(std::string, int width, int height)) dlsym(dl_handler, "createSDLWindow");
>>>>>>> origin

    if (!WindowCreator)
      dlerror_wrapper();

<<<<<<< HEAD
        IGraphicsMain *newWindow;
        newWindow = WindowCreator("Sdl Window", std::stoi(av[2]), std::stoi(av[3]));
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
        dl_handler = dlopen(av[1], RTLD_LAZY | RTLD_LOCAL);
        if (!dl_handler)
            dlerror_wrapper();

        IGraphicsMain    *(*WindowCreator)(std::string, int width, int height);
        WindowCreator = (IGraphicsMain *(*)(std::string, int width, int height)) dlsym(dl_handler, "createGLFWWindow");

        if (!WindowCreator)
            dlerror_wrapper();

        IGraphicsMain *newWindow;
        newWindow = WindowCreator("GLFW Window", std::stoi(av[2]), std::stoi(av[3]));
        newWindow->createWindow();

        void    (*WindowDestructor)(IGraphicsMain *);
        WindowDestructor = (void(*)(IGraphicsMain *)) dlsym(dl_handler, "deleteWindow");
=======
    ISdl_Class *newWindow;
    newWindow = WindowCreator("Sdl Window", std::stoi(av[2]), std::stoi(av[3]));
    newWindow->createSdlWindow();

    void    (*WindowDestructor)(ISdl_Class *);
    WindowDestructor = (void(*)(ISdl_Class *)) dlsym(dl_handler, "deleteWindow");
>>>>>>> origin

    if (!WindowDestructor)
      dlerror_wrapper();

    WindowDestructor(newWindow);
    dlclose(dl_handler);
  }
}
