#include "../include/Nibbler.hpp"
#include <iostream>

//Main constructor
Snake_class::Snake_class(int width, int height)
:direction(UP)
{
	//Creates a snake with 4 nodes
	for (int i = 0; i < 4; ++i){
		addPart();
		//places each subsequent node one row back
		this->Snake.at(i).x = (width/2) - (i * 20);
		this->Snake.at(i).y = (height/2);
		this->Snake.at(i).prevY = this->Snake.at(i).y;
		this->Snake.at(i).prevX = this->Snake.at(i).x - 1;

		if (i > 0){
			//Sets the next values for all non head parts
			this->Snake.at(i).nextX = this->Snake.at(i-1).x;
			this->Snake.at(i).nextY = this->Snake.at(i-1).y;
		}
		else{
			//head node has 'no' next values
			this->Snake.at(i).nextX = 0;
			this->Snake.at(i).nextY = 0;
		}
	}
}

Snake_class::~Snake_class(){
	this->Snake.clear();
}

int Snake_class::getX(int index){
	//returns the X of the node at index - DUH
	return (this->Snake.at(index).x);
}

int Snake_class::getY(int index){
	//returns the Y of the node at index - DUH
	return (this->Snake.at(index).y);
}

int Snake_class::getNextX(int index){
	//returns the nextX of the node at index - DUH
	return (this->Snake.at(index).nextX);
}

int Snake_class::getNextY(int index){
	//returns the nextY of the node at index - DUH
	return (this->Snake.at(index).nextY);
}

void Snake_class::addPart(){
	//Adds a node to the snake
	Part p;
	this->Snake.push_back(p);
	//initializing last node to remove garbage values
	this->Snake.at(this->Snake.size()-1).x = this->Snake.at(this->Snake.size()-1).y;
}

void Snake_class::setDirection(int dirValue){
	//Sets the direction - DUH
	if (dirValue == UP)
		this->direction = UP;
	if (dirValue == DOWN)
		this->direction = DOWN;
	if (dirValue == LEFT)
		this->direction = LEFT;
	if (dirValue == RIGHT)
		this->direction = RIGHT;
}

int Snake_class::getDirection(){
	//gets the direction - DUH
	return (this->direction);
}

bool Snake_class::collision(){
	//checks for collisions
	int x = this->Snake.at(0).x;
	int y = this->Snake.at(0).y;

	//If head pos equals any body pos returns false; No collision
	for (size_t i = 1; i < Snake.size(); ++i){
		if (Snake.at(i).x == x && Snake.at(i).y == y)
			return (false);
	}
	return (true);
}

std::vector<Part> Snake_class::getVector(){
	//gets the vector - DUH
	return (this->Snake);
}

void Snake_class::setVector(std::vector<Part> &Snake){
	//sets the vector - DUH
	for (size_t i = 0; i < this->Snake.size(); ++i){
		this->Snake.at(i).x = Snake.at(i).x;
		this->Snake.at(i).y = Snake.at(i).y;
		this->Snake.at(i).prevX = Snake.at(i).prevX;
		this->Snake.at(i).prevY = Snake.at(i).prevY;
		this->Snake.at(i).nextX = Snake.at(i).nextX;
		this->Snake.at(i).nextY = Snake.at(i).nextY;
	}
}

bool isInRange(int x, int y, int foodX, int foodY){
	int isX = 0;
	int isY = 0;
	isX = ((x < foodX + 40) && (x > foodX - 40)) ? 1 : 0;
	isY = ((y < foodY + 40) && (y > foodY - 40)) ? 1 : 0;
	return (isX == 1 && isY == 1) ? true : false;
}

void	Snake_class::generateFood(int &width, int &height, int &food_x, int &food_y, std::vector<Part> &Snake)
{
	//generate normal food
	srand(time(NULL));
	int rand_food_x = rand() % (width - 100) + 1;
	int rand_food_y = rand() % (height - 100) + 1;

	for (size_t i = 0; i < Snake.size(); i++)
		if (isInRange(Snake[i].x, Snake[i].y, rand_food_x, rand_food_y)){
			rand_food_x = rand() % (width - 100) + 1;
			rand_food_y = rand() % (height - 100) + 1;
		}

	food_x = rand_food_x;
	food_y = rand_food_y;
}

Snake_class *snakeClass(int width, int height)
{
	return new Snake_class(width, height);
}
