#include "Entity.h"

Entity::Entity(Game *game, const char* imagePath, double x, double y) {
	this->x = x;
	this->y = y;
	this->game = game;
	image = game->getDisplay()->loadImage(imagePath);
	leftUpCornerX = x;
	leftUpCornerY = y;
	leftDownCornerX = x;
	leftDownCornerY = y + image->h;
	rightUpCornerX = x + image->w;
	rightUpCornerY = y;
	rightDownCornerX = x + image->w;
	rightDownCornerY = y + image->h;
}

Entity::~Entity() {
	
}

void Entity::update() {

}

void Entity::render() {

}

double Entity::getLeftUpCornerX() {
	return leftUpCornerX;
}

double Entity::getLeftUpCornerY() {
	return leftUpCornerY;
}

double Entity::getLeftDownCornerX() {
	return leftDownCornerX;
}

double Entity::getLeftDownCornerY() {
	return leftDownCornerY;
}

double Entity::getRightUpCornerX() {
	return rightUpCornerX;
}

double Entity::getRightUpCornerY() {
	return rightUpCornerY;
}

double Entity::getRightDownCornerX() {
	return rightDownCornerX;
}

double Entity::getRightDownCornerY() {
	return rightDownCornerY;
}

SDL_Surface* Entity::getImage() {
	return image;
}