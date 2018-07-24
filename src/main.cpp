/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:47:02 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/23 10:06:33 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include <string>
#include <iostream>
#include "../LIB_1/ISfml.lib.hpp"
#include "../LIB_2/ISdl.lib.hpp"

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

    ISfml_Class    *(*WindowCreator)(std::string, int width, int height);
    WindowCreator = (ISfml_Class *(*)(std::string, int width, int height)) dlsym(dl_handler, "createSFMLWindow");

    if (!WindowCreator)
      dlerror_wrapper();

    ISfml_Class *newWindow;
    newWindow = WindowCreator("Sfml Window", std::stoi(av[2]), std::stoi(av[3]));
    newWindow->createSfmlWindow();

    void    (*WindowDestructor)(ISfml_Class *);
    WindowDestructor = (void(*)(ISfml_Class *)) dlsym(dl_handler, "deleteWindow");

    if (!WindowDestructor)
      dlerror_wrapper();

    WindowDestructor(newWindow);
    dlclose(dl_handler);
  }	else if (lib_choice == 2){
    //SDL WINDOW CREATION
    dl_handler = dlopen(av[1], RTLD_LAZY | RTLD_LOCAL);
    if (!dl_handler)
      dlerror_wrapper();

    ISdl_Class    *(*WindowCreator)(std::string, int width, int height);
    WindowCreator = (ISdl_Class *(*)(std::string, int width, int height)) dlsym(dl_handler, "createSDLWindow");

    if (!WindowCreator)
      dlerror_wrapper();

    ISdl_Class *newWindow;
    newWindow = WindowCreator("Sdl Window", std::stoi(av[2]), std::stoi(av[3]));
    newWindow->createSdlWindow();

    void    (*WindowDestructor)(ISdl_Class *);
    WindowDestructor = (void(*)(ISdl_Class *)) dlsym(dl_handler, "deleteWindow");

    if (!WindowDestructor)
      dlerror_wrapper();

    WindowDestructor(newWindow);
    dlclose(dl_handler);
  }
}
