#include "../include/Nibbler.hpp"
#include <iostream>

//Kinda useless
Snake_class::Snake_class()
:isAlive(true), direction(UP)
{}

//Main constructor
Snake_class::Snake_class(int width, int height)
:isAlive(true), direction(UP)
{
	//Creates a snake with 4 nodes
	for (int i = 0; i < 4; ++i){
		addPart();

		//init nodes
		this->Snake.at(i).isHead = false;
		this->Snake.at(i).isTail = false;
		this->Snake.at(i).canMove = false;
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

		//Head node is head
		if (i == 0)
			this->Snake.at(i).isHead = true;
		//Tail node is tail
		if ( i == 3)
			this->Snake.at(i).isTail = true;
	}
}

Snake_class::~Snake_class(){
	//TODO
}

int Snake_class::getLength(){
	//returns the length of the snake
	return ((this->Snake.size()) - 1);
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

bool Snake_class::getType(int index){
	// Checks if this node is the tail
	return (this->Snake.at(index).isTail);
}

void Snake_class::moveSnake(){
	//Moves the head based on the direction of travel
	//y/row up down
	//x/col left right
	if (direction == UP){
		this->Snake.at(0).x = this->Snake.at(0).x;
		this->Snake.at(0).y = this->Snake.at(0).y - 1;
	}
	if (direction == DOWN){
		this->Snake.at(0).x = this->Snake.at(0).x;
		this->Snake.at(0).y = this->Snake.at(0).y + 1;
	}
	if (direction == RIGHT){
		this->Snake.at(0).x = this->Snake.at(0).x + 1;
		this->Snake.at(0).y = this->Snake.at(0).y;
	}
	if (direction == LEFT){
		this->Snake.at(0).x = this->Snake.at(0).x - 1;
		this->Snake.at(0).y = this->Snake.at(0).y;
	}

	//Update all other nodes to make the current x & y equal to the nextX & nextY
	// and sets the nextX & nextY to the current x & y of the node in front
	for (size_t i = 1; i < this->Snake.size(); ++i){
		this->Snake.at(i).y = this->Snake.at(i).nextY;
		this->Snake.at(i).x = this->Snake.at(i).nextX;
		this->Snake.at(i).nextX = this->Snake.at(i-1).x;
		this->Snake.at(i).nextY = this->Snake.at(i-1).y;
	}
	this->Snake.at(Snake.size() - 1).isTail = true;
}

void Snake_class::addPart(){
	//Adds a node to the snake
	Part p;
	this->Snake.push_back(p);
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
	//gets the vector - DUH
	size_t num = 0;
	size_t diff = Snake.size() - this->Snake.size();
	for (size_t i = 0; i < this->Snake.size(); ++i){
		this->Snake.at(i).x = Snake.at(i).x;
		this->Snake.at(i).y = Snake.at(i).y;
		this->Snake.at(i).prevX = Snake.at(i).prevX;
		this->Snake.at(i).prevY = Snake.at(i).prevY;
		this->Snake.at(i).nextX = Snake.at(i).nextX;
		this->Snake.at(i).nextY = Snake.at(i).nextY;
		this->Snake.at(i).isHead = Snake.at(i).isHead;
		this->Snake.at(i).isTail = Snake.at(i).isTail;
		this->Snake.at(i).canMove = Snake.at(i).canMove;
		num = i;
	}

	for (size_t i = num; i < diff; ++i)
		this->Snake.push_back(Snake.at(i));
}

void Snake_class::reset(){
	while (this->Snake.size() > 4)
		this->Snake.pop_back();
}

void	Snake_class::generateFood(int width, int height, int & food_x, int & food_y, std::vector<Part> &Snake)
{
	(void)Snake;

	srand(time(NULL));
	int rand_food_x = rand() % width;
	int rand_food_y = rand() % height;

	for (size_t i = 0; i < Snake.size(); i++)
	{
		if (Snake[i].x == rand_food_x)
		{
			rand_food_x = rand() % width;
			i = 0;
		}
		if (Snake[i].y == rand_food_y)
		{
			rand_food_y = rand() % height;
			i = 0;
		}
	}
	food_x = rand_food_x;
	food_y = rand_food_y;
}

// void	Snake_class::generateObj(int width, int height, int & obj_x, int & obj_y, std::vector<Part> &Snake)
// {

// }

Snake_class *snakeClass(int width, int height)
{
	return new Snake_class(width, height);
}
