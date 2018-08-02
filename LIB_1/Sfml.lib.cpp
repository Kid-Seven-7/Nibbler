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

//Defines for directions
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

//draws iindividual sprites
void drawSprite(sf::Sprite &snakePart, sf::RenderWindow &win, Part &body){
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
	//Game over texture
	sf::Texture over;

	//Load texture from file
	if (!over.loadFromFile("assets/background/gameover.png"))
		return;

	//Create sprite with game over texture
	sf::Sprite gameOver(over);

	//Scale sprite size
	sf::Vector2f scale = gameOver.getScale();
	gameOver.setScale(scale.x * 2, scale.y * 2);

	this->_window.clear();
	this->_window.draw(gameOver);
	this->_window.display();

	//closes window when 'esc' is pressed
	while (true){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			std::cout << "Closing SFML window..." << '\n';
			this->_window.close();
			std::cout << "SFML window closed" << '\n';
			break;
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
			std::cout << "Restarting game" << '\n';
			createWindow();
			break;
		}
	}

}

bool isInRange(int x, int y, int foodX, int foodY){
	int isX = 0;
	int isY = 0;
	isX = ((x < foodX + 20) && (x > foodX - 20)) ? 1 : 0;
	isY = ((y < foodY + 20) && (y > foodY - 20)) ? 1 : 0;
	return (isX == 1 && isY == 1) ? true : false;
}

int Sfml_Class::updateWindow(std::vector<Part> &Snake){
	static int dir = UP;
	static bool foodOnScreen = false;
	sf::Vector2f pos;

	//creating background texture
	sf::Texture bg_texture;
	sf::Texture food;
	std::vector<sf::Sprite> snakeSprites;

	int x, y, foodX, foodY;
	sf::Texture snakeHead;
	sf::Texture Body;

	if (!(foodOnScreen)){
		foodX = rand() % (this->_width - 100) + 1;
		foodY = rand() % (this->_height - 100) + 1;
		std::cout << "foodX :" <<foodX<< '\n';
		std::cout << "foodY :" <<foodY<< '\n';
	}

	if (!snakeHead.loadFromFile("assets/sprites/head.png"))
		return -1;
	if (!Body.loadFromFile("assets/sprites/body.png"))
		return -1;

	//loading bg_texture from file
	if (!bg_texture.loadFromFile("assets/background/grass.jpg"))
    return -1;
	sf::Sprite bg_sprite(bg_texture);

	if (!food.loadFromFile("assets/sprites/mouse.png"))
    return -1;
	sf::Sprite food_sprite(food);

	food_sprite.setPosition(foodX, foodY);
	pos = food_sprite.getPosition();

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

	snakeSprites.reserve(30);
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

	//Get base scale for all subsequent sprites
	sf::Vector2f scale1 = SnakeSprite0.getScale();

	for (size_t i = 0; i < Snake.size(); ++i){
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
	if (isInRange(Snake.at(0).x, Snake.at(0).y, pos.x, pos.y)){
		foodOnScreen = false;
		return 200;
		// std::cout << "add part" << '\n';
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
		this->_window.close();
		return -1;
	}

	// event.type = sf::Event::Closed;
	while (this->_window.pollEvent(event)){
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
			this->_window.close();
	}

	return dir;
}

Sfml_Class *createSFMLWindow(std::string name, int width, int height){
  return new Sfml_Class(name, width, height);
}

void deleteWindow(Sfml_Class *sfml_class){
  delete  sfml_class;
}
