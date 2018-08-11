/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sfml.lib.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:36:57 by amatshiy          #+#    #+#             */
/*   Updated: 2018/08/11 16:39:17 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sfml.lib.hpp"
#include <iostream>

//Defines for directions
#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

Sfml_Class::Sfml_Class(std::string name, int width, int height)
	: _width(width), _height(height), _name(name)
{
}

Sfml_Class::~Sfml_Class() {}

void Sfml_Class::setLoop(int loop)
{
	this->_loop = loop;
}

int Sfml_Class::getLoop() const
{
	return this->_loop;
}

int Sfml_Class::getWidth() const
{
	return this->_width;
}

int Sfml_Class::getHeight() const
{
	return this->_height;
}

std::string Sfml_Class::getName() const
{
	return this->_name;
}

//draws iindividual sprites
void drawSprite(sf::Sprite &snakePart, sf::RenderWindow &win, Part &body)
{
	int x = body.x;
	int y = body.y;
	snakePart.setPosition(x, y);
	win.draw(snakePart);
	win.display();
}

void Sfml_Class::createWindow()
{
	this->_window.create(sf::VideoMode(this->getWidth(), this->getHeight()), this->getName(), sf::Style::Titlebar | sf::Style::Close);
	sf::SoundBuffer buffer1;
	if (!buffer1.loadFromFile("../Assets/sound/loop2.wav"))
		return;
	else
		this->_sound1 = buffer1;

	sf::Sound sound1;
	sound1.setBuffer(this->_sound1);
	this->_music1 = sound1;

	sf::SoundBuffer buffer2;
	if (!buffer2.loadFromFile("../Assets/sound/loop3.wav"))
		return;
	else
		this->_sound2 = buffer2;

	sf::Sound sound2;
	sound2.setBuffer(this->_sound2);
	this->_music2 = sound2;

	sf::SoundBuffer buffer3;
	if (!buffer3.loadFromFile("../Assets/sound/loop3.wav"))
		return;
	else
		this->_sound3 = buffer3;

	sf::Sound sound3;
	sound3.setBuffer(this->_sound3);
	this->_music3 = sound3;

	this->_music1.play();
	this->_music1.setLoop(true);
	this->_loop = 1;
	std::cout << "Running SFML now..." << '\n';
}

void Sfml_Class::destroyWindow(){
	this->_window.close();
}

bool isInRange(int x, int y, int foodX, int foodY)
{
	int isX = 0;
	int isY = 0;
	isX = ((x < foodX + 25) && (x > foodX - 25)) ? 1 : 0;
	isY = ((y < foodY + 25) && (y > foodY - 25)) ? 1 : 0;
	return (isX == 1 && isY == 1) ? true : false;
}

int Sfml_Class::updateWindow(std::vector<Part> &Snake, int food_x, int food_y)
{
	static int dir = UP;
	static bool foodOnScreen = false;
	sf::Vector2f pos;

	//creating background texture
	sf::Texture bg_texture;
	sf::Texture food;
	std::vector<sf::Sprite> snakeSprites;

	int x, y, foodX, foodY, food_choice;
	sf::Texture snakeHead;
	sf::Texture Body;

	if (Snake.size() > 30)
	{
		if (getLoop() != 2)
		{
			this->_music1.stop();
			this->_music2.play();
			this->_music2.setLoop(true);
			this->_loop = 2;
		}
	}

	if (!(foodOnScreen))
	{
		foodX = food_x;
		foodY = food_y;
		food_choice = rand() % 5 + 1;
	}

	if (!snakeHead.loadFromFile("assets/sprites/head.bmp"))
		return -1;
	if (!Body.loadFromFile("assets/sprites/body.bmp"))
		return -1;

	//loading bg_texture from file
	if (!bg_texture.loadFromFile("assets/background/grass.bmp"))
		return -1;
	sf::Sprite bg_sprite(bg_texture);

	if (food_choice == 1)
	{
		if (!food.loadFromFile("assets/sprites/chips.bmp"))
			return -1;
	}
	else if (food_choice == 2)
	{
		if (!food.loadFromFile("assets/sprites/pizza.bmp"))
			return -1;
	}
	else if (food_choice == 3)
	{
		if (!food.loadFromFile("assets/sprites/dorito.bmp"))
			return -1;
	}
	else if (food_choice == 4)
	{
		if (!food.loadFromFile("assets/sprites/icecream.bmp"))
			return -1;
	}
	else if (food_choice == 4)
	{
		if (!food.loadFromFile("assets/sprites/icecream.bmp"))
			return -1;
	}
	else if (food_choice == 5)
	{
		if (!food.loadFromFile("assets/sprites/chocchip.bmp"))
			return -1;
	}

	sf::Sprite food_sprite(food);

	food_sprite.setPosition(foodX, foodY);
	pos = food_sprite.getPosition();

	sf::Sprite SnakeSprite[250];
	snakeSprites.reserve(250);

	// Loop over each sprite, setting their textures
	for (int i = 0; i < 250; ++i)
	{
		SnakeSprite[i].setTexture(Body);
		snakeSprites.push_back(SnakeSprite[i]);
	}

	//Get base scale for all subsequent sprites
	sf::Vector2f scale1 = SnakeSprite[0].getScale();

	for (size_t i = 0; i < Snake.size(); ++i)
	{
		x = Snake[i].x;
		y = Snake[i].y;

		if (i == 0)
			snakeSprites.at(i).setTexture(snakeHead);

		snakeSprites.at(i).setScale(scale1.x / 2, scale1.y / 2);
		snakeSprites.at(i).setPosition(x, y);
	}

	food_sprite.setScale(scale1.x / 2, scale1.y / 2);

	//scaling the bg_sprite
	sf::Vector2f scale = bg_sprite.getScale();
	if (this->getWidth() > 1000)
		bg_sprite.setScale(scale.x * 2, scale.y * 1);

	// check all the window's events that were triggered since the last iteration of the loop
	sf::Event event;

	//drawing the background
	this->_window.clear();
	this->_window.draw(bg_sprite);
	this->_window.draw(food_sprite);

	foodOnScreen = true;
	if (isInRange(Snake.at(0).x, Snake.at(0).y, pos.x, pos.y))
	{
		foodOnScreen = false;
		return 200;
	}

	//Draw all spritesin vector
	for (size_t i = 0; i < Snake.size(); ++i)
		this->_window.draw(snakeSprites.at(i));
	this->_window.display();

	//Key inputs
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (dir != DOWN)
			dir = UP;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		if (dir != UP)
			dir = DOWN;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		if (dir != RIGHT)
			dir = LEFT;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		if (dir != LEFT)
			dir = RIGHT;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
		return (301);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
		return (302);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->_window.close();
		exit(0);
	}

	// event.type = sf::Event::Closed;
	while (this->_window.pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
			this->_window.close();
	}

	return dir;
}

Sfml_Class *createSFMLWindow(std::string name, int width, int height)
{
	return new Sfml_Class(name, width, height);
}

void deleteWindow(Sfml_Class *sfml_class)
{
	delete sfml_class;
}
