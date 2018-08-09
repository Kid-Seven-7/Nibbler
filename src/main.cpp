/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:47:02 by amatshiy          #+#    #+#             */
/*   Updated: 2018/08/01 07:50:55 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include <string>
#include <iostream>
#include <fstream>
#include "../include/StartEngine.hpp"
#include "../include/IGraphicsMain.hpp"


void    dlerror_wrapper(void){
  std::cout << "Error: " << dlerror() << std::endl;
  exit(EXIT_FAILURE);
}

int main(int ac, char **av){
	std::string name;
  if (ac > 3){
		do{
			system("clear");
			std::cout << "Please type a 3 character player name" << '\n';
    	std::cout << "Enter your name : ";
			std::getline(std::cin, name);
		}while (name.size() != 3 );
    try{
      StartEngine s_engine(std::stoi(av[1]), std::stoi(av[2]), std::stoi(av[3]), name);
      s_engine.mainControl();
    }
    catch (std::exception & e){
      std::cout << "\033[0;31mError:\033[0m the arguments passed are invalid" << std::endl;
      std::cout << "\033[0;31mException details: \033[0m" << e.what() << std::endl;
    }
  }
  else
    std::cout << "Usage: ./42_Nibbler height width 1, 2, or 3" << std::endl;
  return (0);
}
