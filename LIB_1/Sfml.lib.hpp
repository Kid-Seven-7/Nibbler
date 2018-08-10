/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sfml.lib.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:30:14 by amatshiy          #+#    #+#             */
/*   Updated: 2018/08/09 14:42:17 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFML_LIB_HPP
#define SFML_LIB_HPP

#include "../include/IGraphicsMain.hpp"
#include "../include/Nibbler.hpp"

class Sfml_Class : public IGraphicsMain{
private:
  int _width;
  int _height;
	int _loop;
  std::string _name;
  sf::RenderWindow _window;
	sf::SoundBuffer _sound;
	sf::SoundBuffer _sound1;
	sf::SoundBuffer _sound2;
	sf::Sound _music;
	sf::Sound _music1;
	sf::Sound _music2;
  Sfml_Class(void);

public:
  Sfml_Class(std::string name, int width, int height);
  ~Sfml_Class(void);

	//Ints
	int getLoop() const;
  int getWidth() const;
  int getHeight() const;
	int updateWindow(std::vector<Part> &Snake, int food_x, int food_y);

	//Voids
	void nextLoop();
  void createWindow();
  void destroyWindow();
	void setLoop(int loop);

	//std::strings
	std::string getName() const;
};

extern "C"{
  Sfml_Class *createSFMLWindow(std::string name, int width, int height);
  void deleteWindow(Sfml_Class *sfml_class);
}

#endif
