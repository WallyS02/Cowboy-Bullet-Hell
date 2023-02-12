#pragma once

#include "Display.h"
#include "Input.h"

class Game;

class Entity
{
protected:
	SDL_Surface* image;
	double x, y, leftUpCornerX, leftUpCornerY, leftDownCornerX, leftDownCornerY, rightUpCornerX, rightUpCornerY, rightDownCornerX, rightDownCornerY;
	Game *game;
public:
	Entity(Game *game, const char* imagePath, double x, double y);
	~Entity();
	void update();
	void render();
	double getLeftUpCornerX();
	double getLeftUpCornerY();
	double getLeftDownCornerX();
	double getLeftDownCornerY();
	double getRightUpCornerX();
	double getRightUpCornerY();
	double getRightDownCornerX();
	double getRightDownCornerY();
	SDL_Surface* getImage();
};
#include "Game.h"