/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StartEngine.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 08:44:28 by amatshiy          #+#    #+#             */
/*   Updated: 2018/08/12 08:33:07 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef START_ENGINE_HPP
#define START_ENGINE_HPP

#include "IGraphicsMain.hpp"
#include <dlfcn.h>
#include <time.h>
#include <thread>

class StartEngine
{
  private:
    int           _libChoice;
    int           _height;
    int           _width;
    std::string   _name;
    void          *_dl_handler;
    std::thread   _sound;

  public:
    StartEngine(void);
    StartEngine(StartEngine const &src);
    StartEngine(int height, int width, int libChoice, std::string name);
    ~StartEngine(void);

    StartEngine const &operator=(StartEngine const &rhs);
    void *switchLib(int libChoice = 1);
    void mainControl();
    void dlerror_wrapper(void);
    static void	gonBeThread();
    void setScore(std::string name, int score);
};
#endif
