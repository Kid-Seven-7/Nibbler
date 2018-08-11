/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sdl.lib.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:11:23 by amatshiy          #+#    #+#             */
/*   Updated: 2018/08/09 14:41:50 by amatshiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sdl.lib.hpp"
#include <iostream>
#include <SDL.h>

//Defines for directions
# define UP 0
# define DOWN 1
# define RIGHT 2
# define LEFT 3

Sdl_Class::Sdl_Class(std::string name, int width, int height)
:_width(width), _height(height), _name(name), _window(NULL)
{}

Sdl_Class::~Sdl_Class() {}

int Sdl_Class::getWidth() const{
  return this->_width;
}

int Sdl_Class::getHeight() const{
  return this->_height;
}

std::string Sdl_Class::getName() const{
  return this->_name;
}

void Sdl_Class::createWindow(){
	SDL_Renderer *renderer = NULL;

	//copy renderer to class member
	this->_renderer = renderer;

	std::cout << "SDL running..." << '\n';

	//initializes SDL Lib
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return;

	// Creates and renders a window
  if (SDL_CreateWindowAndRenderer(this->_width,
																	this->_height,
																	SDL_WINDOW_RESIZABLE,
																	&this->_window,
																	&this->_renderer))
    return;

	//Sets title
	SDL_SetWindowTitle(this->_window, "Nibbler_42");
	SDL_SetWindowResizable(this->_window, SDL_FALSE);
}

void Sdl_Class::destroyWindow(){
	SDL_Surface *gameOverSurface;
	SDL_Texture *gameOverTexture;

	SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 255);
	SDL_RenderClear(this->_renderer);

	//Game over loop
	for (int i = 0; i < 5000; ++i){
		gameOverSurface = SDL_LoadBMP("assets/background/gameover.bmp");
		if (!gameOverSurface)
			return;
		gameOverTexture = SDL_CreateTextureFromSurface(this->_renderer, gameOverSurface);
		if (!gameOverTexture)
			return;

		SDL_RenderCopy(this->_renderer, gameOverTexture, NULL, NULL);
		SDL_RenderPresent(this->_renderer);

		SDL_FreeSurface(gameOverSurface);
		SDL_DestroyTexture(gameOverTexture);
	}
}

bool isInRange(int x, int y, int foodX, int foodY){
	int isX = 0;
	int isY = 0;

	isX = ((x < foodX + 15) && (x > foodX - 15)) ? 1 : 0;
	isY = ((y < foodY + 15) && (y > foodY - 15)) ? 1 : 0;

	return (isX == 1 && isY == 1) ? true : false;
}

int Sdl_Class::updateWindow(std::vector<Part> &Snake, int food_x, int food_y){
	SDL_AudioSpec wav_spec;
Uint32 wav_length;
Uint8 *wav_buffer;

/* Load the WAV */
if (SDL_LoadWAV("../Assets/sound/loop2.wav", &wav_spec, &wav_buffer, &wav_length) == NULL) {
    fprintf(stderr, "Could not open test.wav: %s\n", SDL_GetError());
} else {
    /* Do stuff with the WAV data, and then... */
    SDL_FreeWAV(wav_buffer);
}
SDL_PauseAudio(0);
	//general variables
	int x ,y;
	static int foodX, foodY;
	static int direction = UP;
	static bool foodOnScreen = false;
	std::vector<SDL_Rect> snakeSprites;
	//SDL variables
	SDL_Event event;
	SDL_Rect dstrect, dstrectF;
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	SDL_Surface *surfaceBG, *spriteHead, *spriteBody, *spriteFood;
	SDL_Texture *textureBG, *spriteHeadTexture, *spriteBodyTexture, *foodTexture;

	snakeSprites.reserve(250);

	//Sets title
	SDL_SetWindowTitle(this->_window, "Nibbler_42");

	//Loading surface images
	surfaceBG = SDL_LoadBMP("assets/background/grass.bmp");
	if (!surfaceBG)
		return -1;
	spriteBody = SDL_LoadBMP("assets/sprites/body.bmp");
	if (!spriteBody)
		return -1;
	spriteHead = SDL_LoadBMP("assets/sprites/head.bmp");
	if (!spriteHead)
		return -1;
	spriteFood = SDL_LoadBMP("assets/sprites/chocchip.bmp");
	if (!spriteFood)
		return -1;

	if (!(foodOnScreen)){
		foodX = food_x;
		foodY = food_y;
	}

	dstrectF.x = foodX;
	dstrectF.y = foodY;
	dstrectF.w = 32;
	dstrectF.h = 32;

	//init vector
	for (int i = 0; i < 250; ++i) {
		snakeSprites.push_back(dstrect);
		snakeSprites.at(i).w = 32;
		snakeSprites.at(i).h = 32;
	}

	//Assign snake variables to the corresponding vector node
	for (size_t i = 0; i < Snake.size(); ++i){
		x = Snake[i].x;
		y = Snake[i].y;

		snakeSprites.at(i).x = x;
		snakeSprites.at(i).y = y;
	}

	//Setting textures from sufaces
	textureBG = SDL_CreateTextureFromSurface(this->_renderer, surfaceBG);
	if (!textureBG)
		return -1;
	spriteBodyTexture = SDL_CreateTextureFromSurface(this->_renderer, spriteBody);
	if (!spriteBodyTexture)
		return -1;
	spriteHeadTexture = SDL_CreateTextureFromSurface(this->_renderer, spriteHead);
	if (!spriteHeadTexture)
		return -1;
	foodTexture = SDL_CreateTextureFromSurface(this->_renderer, spriteFood);
	if (!foodTexture)
		return -1;

	// main loop
	while (1) {
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
			break;

		//Drawing BG
		SDL_RenderCopy(this->_renderer, textureBG, NULL, NULL);
		SDL_RenderCopy(this->_renderer, foodTexture, NULL, &dstrectF);
		foodOnScreen = true;
		if (isInRange(Snake.at(0).x, Snake.at(0).y, dstrectF.x, dstrectF.y)){
			foodOnScreen = false;
			return 200;
		}
		for (size_t i = 0; i < Snake.size(); ++i){
			//Drawing Snake
			dstrect = snakeSprites.at(i);
			if (i == 0)
				SDL_RenderCopy(this->_renderer, spriteHeadTexture, NULL, &dstrect);
			else
				SDL_RenderCopy(this->_renderer, spriteBodyTexture, NULL, &dstrect);
		}

		//Render current items in memory
		SDL_RenderPresent(this->_renderer);

		//Freeing RAM
		SDL_FreeSurface(surfaceBG);
		SDL_FreeSurface(spriteHead);
		SDL_FreeSurface(spriteBody);
		SDL_FreeSurface(spriteFood);
		SDL_DestroyTexture(textureBG);
		SDL_DestroyTexture(foodTexture);
		SDL_DestroyTexture(spriteHeadTexture);
		SDL_DestroyTexture(spriteBodyTexture);

		//Keyboard input
		if (state[SDL_SCANCODE_F1])
			return (300);
		else if (state[SDL_SCANCODE_F3])
			return (302);
		else if (state[SDL_SCANCODE_UP] && direction != DOWN)
			direction = UP;
		else if (state[SDL_SCANCODE_LEFT] && direction != RIGHT)
			direction = LEFT;
		else if (state[SDL_SCANCODE_DOWN] && direction != UP)
			direction = DOWN;
		else if (state[SDL_SCANCODE_RIGHT] && direction != LEFT)
			direction = RIGHT;
		else if (state[SDL_SCANCODE_ESCAPE]){
			//destroys window && renderer once done
			SDL_DestroyRenderer(this->_renderer);
			SDL_DestroyWindow(this->_window);

			//Quits SDL
			SDL_Quit();
			return -1;
		}
		return direction;
	}
	return (0);
}

Sdl_Class *createSDLWindow(std::string name, int width, int height){
  return new Sdl_Class(name, width, height);
}

void deleteWindow(Sdl_Class *sdl_class){
  delete  sdl_class;
}
