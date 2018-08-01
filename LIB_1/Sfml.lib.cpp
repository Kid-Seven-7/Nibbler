/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sfml.lib.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:36:57 by amatshiy          #+#    #+#             */
/*   Updated: 2018/07/25 08:08:28 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sfml.lib.hpp"
#include <iostream>
// #include "../include/Nibbler.hpp"

# define UP 0
# define DOWN 1
# define RIGHT 2
# define LEFT 3

Sfml_Class::Sfml_Class(std::string name, int width, int height)
:_name(name), _width(width), _height(height)
{}

Sfml_Class::~Sfml_Class() {}

int Sfml_Class::getWidth() const{
  return this->_width;
}

int Sfml_Class::getHeight() const{
  return this->_height;
}

std::string Sfml_Class::getName() const{
  return this->_name;
}

void drawSprite(sf::Sprite &snakePart, sf::RenderWindow &win, Part &body){
	// (void)body;
	int x = body.x;
	int y = body.y;
	snakePart.setPosition(x,y);
	win.draw(snakePart);
	win.display();
}

void Sfml_Class::createWindow(){
  this->_window.create(sf::VideoMode(this->getWidth(), this->getHeight()), this->getName());
	std::cout << "Running SFML now..." << '\n';
}

void Sfml_Class::destroyWindow(){
	sf::Texture over;

	if (!over.loadFromFile("assets/background/gameover.png"))
		return;

	sf::Sprite gameOver(over);



  // this->_window.close();
	this->_window.clear();
	this->_window.draw(gameOver);
	this->_window.display();

}

int Sfml_Class::updateWindow(std::vector<Part> &Snake){
		static int dir = UP;
	  // run the program as long as the window is open
			//creating background texture
			sf::Texture bg_texture;
			std::vector<sf::Sprite> snakeSprites;

			int x, y;
			sf::Texture snakeHead;
			sf::Texture Body;
			// std::vector<sf::Sprite> snakeSprites;

			if (!snakeHead.loadFromFile("assets/sprites/head.png"))
				return -1;
			if (!Body.loadFromFile("assets/sprites/body.png"))
				return -1;

			//loading bg_texture from file
			if (!bg_texture.loadFromFile("assets/background/grass.jpg"))
	      return -1;
			sf::Sprite bg_sprite(bg_texture);

			//Adding texture to a sprite
			sf::Sprite SnakeSprite0(Body);
			sf::Sprite SnakeSprite1(Body);
			sf::Sprite SnakeSprite2(Body);
			sf::Sprite SnakeSprite3(Body);
			sf::Sprite SnakeSprite4(Body);
			sf::Sprite SnakeSprite5(Body);
			sf::Sprite SnakeSprite6(Body);
			sf::Sprite SnakeSprite7(Body);
			sf::Sprite SnakeSprite8(Body);
			sf::Sprite SnakeSprite9(Body);
			sf::Sprite SnakeSprite10(Body);
			sf::Sprite SnakeSprite11(Body);
			sf::Sprite SnakeSprite12(Body);
			sf::Sprite SnakeSprite13(Body);
			sf::Sprite SnakeSprite14(Body);
			sf::Sprite SnakeSprite15(Body);
			sf::Sprite SnakeSprite16(Body);
			sf::Sprite SnakeSprite17(Body);
			sf::Sprite SnakeSprite18(Body);
			sf::Sprite SnakeSprite19(Body);
			sf::Sprite SnakeSprite20(Body);
			sf::Sprite SnakeSprite21(Body);
			sf::Sprite SnakeSprite22(Body);
			sf::Sprite SnakeSprite23(Body);
			sf::Sprite SnakeSprite24(Body);
			sf::Sprite SnakeSprite25(Body);
			sf::Sprite SnakeSprite26(Body);
			sf::Sprite SnakeSprite27(Body);
			sf::Sprite SnakeSprite28(Body);
			sf::Sprite SnakeSprite29(Body);

			snakeSprites.reserve(100);
			snakeSprites.push_back(SnakeSprite0);
			snakeSprites.push_back(SnakeSprite1);
			snakeSprites.push_back(SnakeSprite2);
			snakeSprites.push_back(SnakeSprite3);
			snakeSprites.push_back(SnakeSprite4);
			snakeSprites.push_back(SnakeSprite5);
			snakeSprites.push_back(SnakeSprite6);
			snakeSprites.push_back(SnakeSprite7);
			snakeSprites.push_back(SnakeSprite8);
			snakeSprites.push_back(SnakeSprite9);
			snakeSprites.push_back(SnakeSprite10);
			snakeSprites.push_back(SnakeSprite11);
			snakeSprites.push_back(SnakeSprite12);
			snakeSprites.push_back(SnakeSprite13);
			snakeSprites.push_back(SnakeSprite14);
			snakeSprites.push_back(SnakeSprite15);
			snakeSprites.push_back(SnakeSprite16);
			snakeSprites.push_back(SnakeSprite17);
			snakeSprites.push_back(SnakeSprite18);
			snakeSprites.push_back(SnakeSprite19);
			snakeSprites.push_back(SnakeSprite20);
			snakeSprites.push_back(SnakeSprite21);
			snakeSprites.push_back(SnakeSprite22);
			snakeSprites.push_back(SnakeSprite23);
			snakeSprites.push_back(SnakeSprite24);
			snakeSprites.push_back(SnakeSprite25);
			snakeSprites.push_back(SnakeSprite26);
			snakeSprites.push_back(SnakeSprite27);
			snakeSprites.push_back(SnakeSprite28);
			snakeSprites.push_back(SnakeSprite29);

			sf::Vector2f scale1 = SnakeSprite0.getScale();
			for (size_t i = 0; i < Snake.size(); ++i){
				x = Snake[i].x;
				y = Snake[i].y;
				if (i == 0){
					snakeSprites.at(i).setTexture(snakeHead);
				}
				snakeSprites.at(i).setScale(scale1.x / 2, scale1.y / 2);
				snakeSprites.at(i).setPosition(x, y);
			}

			//scaling the bg_sprite
			sf::Vector2f scale = bg_sprite.getScale();
			if (this->getWidth() > 1000)
				bg_sprite.setScale(scale.x * 2, scale.y * 1);
	    // check all the window's events that were triggered since the last iteration of the loop
	    sf::Event event;
	    while (this->_window.pollEvent(event)){
	      // "close requested" event: we close the window
	      if (event.type == sf::Event::Closed)
	        this->_window.close();
	    }

			//drawing the background
			this->_window.clear();
			this->_window.draw(bg_sprite);
			sf::Vector2f pos;
			for (size_t i = 0; i < Snake.size(); ++i)
				this->_window.draw(snakeSprites.at(i));
			this->_window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			if (dir != DOWN)
				dir = UP;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			if (dir != UP)
				dir = DOWN;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
			if (dir != RIGHT)
				dir = LEFT;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
			if (dir != LEFT)
				dir = RIGHT;
		}
		return dir;
}

Sfml_Class *createSFMLWindow(std::string name, int width, int height){
  return new Sfml_Class(name, width, height);
}

void deleteWindow(Sfml_Class *sfml_class){
  delete  sfml_class;
}
