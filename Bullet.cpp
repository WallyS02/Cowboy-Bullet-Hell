#include "Bullet.h"

Bullet::Bullet(Game* game, double x, double y, char bulletDirection, double speed, char gunman, char level, int rotated, int type) : Entity(game, "./bulletLeft.bmp", x, y) {
	this->bulletDirection = bulletDirection;
	this->speed = speed;
	this->gunman = gunman;
	this->level = level;
	this->type = type;
	if (type == 1) {
		image = game->getDisplay()->loadImage("./bigBulletLeft.bmp");
		leftUpCornerX = x;
		leftUpCornerY = y;
		leftDownCornerX = x;
		leftDownCornerY = y + image->h;
		rightUpCornerX = x + image->w;
		rightUpCornerY = y;
		rightDownCornerX = x + image->w;
		rightDownCornerY = y + image->h;
	}
	if(gunman == 'P')
		image = game->getDisplay()->loadImage("./bulletRight.bmp");
	spiral = 2;
	changeDirection = false;
	this->rotated = rotated;
}

Bullet::~Bullet() {
	
}

void Bullet::explodingCirclesShotRightUp(double part) {
	double fixedCorrection = 0.0;
	if (rotated == 0) {
		fixedCorrection = CIRCLE_CORRECTION;
	}

	x = x + part * FIXED_CIRCLE_SPEED - fixedCorrection;
	leftUpCornerX = leftUpCornerX + part * FIXED_CIRCLE_SPEED - fixedCorrection;
	leftDownCornerX = leftDownCornerX + part * FIXED_CIRCLE_SPEED - fixedCorrection;
	rightUpCornerX = rightUpCornerX + part * FIXED_CIRCLE_SPEED - fixedCorrection;
	rightDownCornerX = rightDownCornerX + part * FIXED_CIRCLE_SPEED - fixedCorrection;

	y = y - FIXED_CIRCLE_SPEED + fixedCorrection;
	leftUpCornerY = leftUpCornerY - FIXED_CIRCLE_SPEED + fixedCorrection;
	leftDownCornerY = leftDownCornerY - FIXED_CIRCLE_SPEED + fixedCorrection;
	rightUpCornerY = rightUpCornerY - FIXED_CIRCLE_SPEED + fixedCorrection;
	rightDownCornerY = rightDownCornerY - FIXED_CIRCLE_SPEED + fixedCorrection;
}

void Bullet::explodingCirclesShotRightDown(double part) {
	double fixedCorrection = 0.0;
	if (rotated == 0)
		fixedCorrection = CIRCLE_CORRECTION;

	x = x + FIXED_CIRCLE_SPEED - fixedCorrection;
	leftUpCornerX = leftUpCornerX + FIXED_CIRCLE_SPEED - fixedCorrection;
	leftDownCornerX = leftDownCornerX + FIXED_CIRCLE_SPEED - fixedCorrection;
	rightUpCornerX = rightUpCornerX + FIXED_CIRCLE_SPEED - fixedCorrection;
	rightDownCornerX = rightDownCornerX + FIXED_CIRCLE_SPEED - fixedCorrection;

	y = y + part * FIXED_CIRCLE_SPEED - fixedCorrection;
	leftUpCornerY = leftUpCornerY + part * FIXED_CIRCLE_SPEED - fixedCorrection;
	leftDownCornerY = leftDownCornerY + part * FIXED_CIRCLE_SPEED - fixedCorrection;
	rightUpCornerY = rightUpCornerY + part * FIXED_CIRCLE_SPEED - fixedCorrection;
	rightDownCornerY = rightDownCornerY + part * FIXED_CIRCLE_SPEED - fixedCorrection;
}

void Bullet::explodingCirclesShotLeftUp(double part) {
	double fixedCorrection = 0.0;
	if (rotated == 0)
		fixedCorrection = CIRCLE_CORRECTION;

	x = x - FIXED_CIRCLE_SPEED + fixedCorrection;
	leftUpCornerX = leftUpCornerX - FIXED_CIRCLE_SPEED + fixedCorrection;
	leftDownCornerX = leftDownCornerX - FIXED_CIRCLE_SPEED + fixedCorrection;
	rightUpCornerX = rightUpCornerX - FIXED_CIRCLE_SPEED + fixedCorrection;
	rightDownCornerX = rightDownCornerX - FIXED_CIRCLE_SPEED + fixedCorrection;

	y = y - part * FIXED_CIRCLE_SPEED + fixedCorrection;
	leftUpCornerY = leftUpCornerY - part * FIXED_CIRCLE_SPEED + fixedCorrection;
	leftDownCornerY = leftDownCornerY - part * FIXED_CIRCLE_SPEED + fixedCorrection;
	rightUpCornerY = rightUpCornerY - part * FIXED_CIRCLE_SPEED + fixedCorrection;
	rightDownCornerY = rightDownCornerY - part * FIXED_CIRCLE_SPEED + fixedCorrection;
}

void Bullet::explodingCirclesShotLeftDown(double part) {
	double fixedCorrection = 0.0;
	if (rotated == 0)
		fixedCorrection = CIRCLE_CORRECTION;

	x = x - part * FIXED_CIRCLE_SPEED + fixedCorrection;
	leftUpCornerX = leftUpCornerX - part * FIXED_CIRCLE_SPEED + fixedCorrection;
	leftDownCornerX = leftDownCornerX - part * FIXED_CIRCLE_SPEED + fixedCorrection;
	rightUpCornerX = rightUpCornerX - part * FIXED_CIRCLE_SPEED + fixedCorrection;
	rightDownCornerX = rightDownCornerX - part * FIXED_CIRCLE_SPEED + fixedCorrection;

	y = y + FIXED_CIRCLE_SPEED - fixedCorrection;
	leftUpCornerY = leftUpCornerY + FIXED_CIRCLE_SPEED - fixedCorrection;
	leftDownCornerY = leftDownCornerY + FIXED_CIRCLE_SPEED - fixedCorrection;
	rightUpCornerY = rightUpCornerY + FIXED_CIRCLE_SPEED - fixedCorrection;
	rightDownCornerY = rightDownCornerY + FIXED_CIRCLE_SPEED - fixedCorrection;
}

/*
	level(levelSymbol)(Coordinates) means attack pattern of a given level and coordinate
*/

void Bullet::levelPX(int sign) {
	x = x + sign * game->getDelta() * speed;
	leftUpCornerX = leftUpCornerX + sign * game->getDelta() * speed;
	leftDownCornerX = leftDownCornerX + sign * game->getDelta() * speed;
	rightUpCornerX = rightUpCornerX + sign * game->getDelta() * speed;
	rightDownCornerX = rightDownCornerX + sign * game->getDelta() * speed;
}

void Bullet::levelPY(int sign) {
	y = y + sign * game->getDelta() * speed;
	leftUpCornerY = leftUpCornerY + sign * game->getDelta() * speed;
	leftDownCornerY = leftDownCornerY + sign * game->getDelta() * speed;
	rightUpCornerY = rightUpCornerY + sign * game->getDelta() * speed;
	rightDownCornerY = rightDownCornerY + sign * game->getDelta() * speed;
}

void Bullet::levelPXRotated(int sign) {
	x = x + sign * game->getDelta() * speed;
	leftUpCornerX = leftUpCornerX + sign * game->getDelta() * speed;
	leftDownCornerX = leftDownCornerX + sign * game->getDelta() * speed;
	rightUpCornerX = rightUpCornerX + sign * game->getDelta() * speed;
	rightDownCornerX = rightDownCornerX + sign * game->getDelta() * speed;

	y = y + sign * game->getDelta() * speed;
	leftUpCornerY = leftUpCornerY + sign * game->getDelta() * speed;
	leftDownCornerY = leftDownCornerY + sign * game->getDelta() * speed;
	rightUpCornerY = rightUpCornerY + sign * game->getDelta() * speed;
	rightDownCornerY = rightDownCornerY + sign * game->getDelta() * speed;
}

void Bullet::levelPYRotated(int sign) {
	y = y + sign * game->getDelta() * speed;
	leftUpCornerY = leftUpCornerY + sign * game->getDelta() * speed;
	leftDownCornerY = leftDownCornerY + sign * game->getDelta() * speed;
	rightUpCornerY = rightUpCornerY + sign * game->getDelta() * speed;
	rightDownCornerY = rightDownCornerY + sign * game->getDelta() * speed;

	x = x - sign * game->getDelta() * speed;
	leftUpCornerX = leftUpCornerX - sign * game->getDelta() * speed;
	leftDownCornerX = leftDownCornerX - sign * game->getDelta() * speed;
	rightUpCornerX = rightUpCornerX - sign * game->getDelta() * speed;
	rightDownCornerX = rightDownCornerX - sign * game->getDelta() * speed;
}

void Bullet::levelRXSinusoid(int sign) {
	if (rotated == 3) {
		sign *= -1;
	}

	x = x + sign * game->getDelta() * speed;
	leftUpCornerX = leftUpCornerX + sign * game->getDelta() * speed;
	leftDownCornerX = leftDownCornerX + sign * game->getDelta() * speed;
	rightUpCornerX = rightUpCornerX + sign * game->getDelta() * speed;
	rightDownCornerX = rightDownCornerX + sign * game->getDelta() * speed;

	if (rotated == 3) {
		sign *= -1;
	}

	y = y + sign * spiral;
	leftUpCornerY = leftUpCornerY + sign * spiral;
	leftDownCornerY = leftDownCornerY + sign * spiral;
	rightUpCornerY = rightUpCornerY + sign * spiral;
	rightDownCornerY = rightDownCornerY + sign * spiral;
}

void Bullet::levelRXSinusoidRotated(int sign) {

	x = x + sign * game->getDelta() * speed;
	leftUpCornerX = leftUpCornerX + sign * game->getDelta() * speed;
	leftDownCornerX = leftDownCornerX + sign * game->getDelta() * speed;
	rightUpCornerX = rightUpCornerX + sign * game->getDelta() * speed;
	rightDownCornerX = rightDownCornerX + sign * game->getDelta() * speed;

	y = y - sign * game->getDelta() * speed;
	leftUpCornerY = leftUpCornerY - sign * game->getDelta() * speed;
	leftDownCornerY = leftDownCornerY - sign * game->getDelta() * speed;
	rightUpCornerY = rightUpCornerY - sign * game->getDelta() * speed;
	rightDownCornerY = rightDownCornerY - sign * game->getDelta() * speed;

	y = y + sign * spiral;
	leftUpCornerY = leftUpCornerY + sign * spiral;
	leftDownCornerY = leftDownCornerY + sign * spiral;
	rightUpCornerY = rightUpCornerY + sign * spiral;
	rightDownCornerY = rightDownCornerY + sign * spiral;

	x = x + sign * spiral;
	leftUpCornerX = leftUpCornerX + sign * spiral;
	leftDownCornerX = leftDownCornerX + sign * spiral;
	rightUpCornerX = rightUpCornerX + sign * spiral;
	rightDownCornerX = rightDownCornerX + sign * spiral;
}

void Bullet::levelRYSinusoid(int sign) {
	if (rotated == 3) {
		sign *= -1;
	}

	y = y + sign * game->getDelta() * speed;
	leftUpCornerY = leftUpCornerY + sign * game->getDelta() * speed;
	leftDownCornerY = leftDownCornerY + sign * game->getDelta() * speed;
	rightUpCornerY = rightUpCornerY + sign * game->getDelta() * speed;
	rightDownCornerY = rightDownCornerY + sign * game->getDelta() * speed;

	if (rotated == 3) {
		sign *= -1;
	}

	x = x + sign * spiral;
	leftUpCornerX = leftUpCornerX + sign * spiral;
	leftDownCornerX = leftDownCornerX + sign * spiral;
	rightUpCornerX = rightUpCornerX + sign * spiral;
	rightDownCornerX = rightDownCornerX + sign * spiral;
}

void Bullet::levelRYSinusoidRotated(int sign) {
	y = y + sign * game->getDelta() * speed;
	leftUpCornerY = leftUpCornerY + sign * game->getDelta() * speed;
	leftDownCornerY = leftDownCornerY + sign * game->getDelta() * speed;
	rightUpCornerY = rightUpCornerY + sign * game->getDelta() * speed;
	rightDownCornerY = rightDownCornerY + sign * game->getDelta() * speed;

	x = x - sign * game->getDelta() * speed;
	leftUpCornerX = leftUpCornerX - sign * game->getDelta() * speed;
	leftDownCornerX = leftDownCornerX - sign * game->getDelta() * speed;
	rightUpCornerX = rightUpCornerX - sign * game->getDelta() * speed;
	rightDownCornerX = rightDownCornerX - sign * game->getDelta() * speed;

	x = x + sign * spiral;
	leftUpCornerX = leftUpCornerX + sign * spiral;
	leftDownCornerX = leftDownCornerX + sign * spiral;
	rightUpCornerX = rightUpCornerX + sign * spiral;
	rightDownCornerX = rightDownCornerX + sign * spiral;

	y = y + sign * spiral;
	leftUpCornerY = leftUpCornerY + sign * spiral;
	leftDownCornerY = leftDownCornerY + sign * spiral;
	rightUpCornerY = rightUpCornerY + sign * spiral;
	rightDownCornerY = rightDownCornerY + sign * spiral;
}

void Bullet::PlevelPTimeStamps() {
	levelPX(-1);
}

void Bullet::RLevelTimeStampsX(int sign) {
	if (game->getWorldTime() <= 10)
		levelRXSinusoid(sign);
	if (game->getWorldTime() > 10 && game->getWorldTime() <= 15)
		levelPXRotated(sign);
	if (game->getWorldTime() > 15 && game->getWorldTime() <= 15.8) {
		if(type == 1)
			levelPX(sign);
		else levelPXRotated(sign);
	}
	if (game->getWorldTime() > 15.8 && game->getWorldTime() <= 30)
		levelPX(sign);
	if (game->getWorldTime() > 30) {
		if (type == 1)
			levelPX(sign);
		else levelRXSinusoid(sign);
	}
}

void Bullet::RLevelTimeStampsY(int sign) {
	if (game->getWorldTime() <= 10)
		levelRYSinusoid(sign);
	if (game->getWorldTime() >= 10 && game->getWorldTime() <= 15)
		levelPYRotated(sign);
	if (game->getWorldTime() > 15 && game->getWorldTime() <= 15.8) {
		if (type == 1)
			levelPY(sign);
		else levelPYRotated(sign);
	}
	if (game->getWorldTime() > 15.8 && game->getWorldTime() <= 30)
		levelPY(sign);
	if (game->getWorldTime() > 30) {
		if (type == 1)
			levelPY(sign);
		else levelRYSinusoid(sign);
	}
}

void Bullet::BLevelTimeStampsX(int sign) {
	if (game->getWorldTime() <= 10) {
		if (rotated == 0)
			levelPX(sign);
		if (rotated == 1)
			levelPXRotated(sign);
		if (rotated == 2 || rotated == 3)
			levelRXSinusoid(sign);
		if (rotated == 4)
			levelRXSinusoid(sign);
	}
	if (game->getWorldTime() > 10 && game->getWorldTime() <= 20) {
		if (rotated == 0)
			levelPXRotated(sign);
		if (rotated == 1 || rotated == 2 || rotated == 3 || rotated == 4)
			levelRXSinusoidRotated(sign);
	}
	if (game->getWorldTime() > 20 && game->getWorldTime() <= 30) {
		if (rotated == 0 || rotated == 2 || rotated == 3 || rotated == 4)
			levelRXSinusoidRotated(sign);
		if (rotated == 1)
			levelPXRotated(sign);
	}
	if (game->getWorldTime() > 30) {
		if (rotated == 0)
			levelPX(sign);
		if (rotated == 1)
			levelPXRotated(sign);
		if (rotated == 2 || rotated == 3)
			levelRXSinusoid(sign);
		if (rotated == 4)
			levelRXSinusoid(sign);
	}
}

void Bullet::BLevelTimeStampsY(int sign) {
	if (game->getWorldTime() <= 10) {
		if (rotated == 0)
			levelPY(sign);
		if (rotated == 1)
			levelPYRotated(sign);
		if (rotated == 2 || rotated == 3)
			levelRYSinusoid(sign);
	}
	if (game->getWorldTime() >= 10 && game->getWorldTime() <= 20) {
		if (rotated == 0)
			levelPYRotated(sign);
		if (rotated == 1 || rotated == 2 || rotated == 3)
			levelRYSinusoidRotated(sign);
	}
	if (game->getWorldTime() > 20 && game->getWorldTime() <= 30) {
		if (rotated == 0 || rotated == 2 || rotated == 3)
			levelRYSinusoidRotated(sign);
		if (rotated == 1)
			levelPYRotated(sign);
	}
	if (game->getWorldTime() > 30) {
		if (rotated == 0)
			levelPY(sign);
		if (rotated == 1)
			levelPYRotated(sign);
		if (rotated == 2 || rotated == 3)
			levelRYSinusoid(sign);
	}
}

void Bullet::GlevelTimeStampsX(int sign) {
	if (game->getWorldTime() <= 10) {
		if (rotated == 1)
			levelPXRotated(sign);
		if (rotated == 0)
			levelPX(sign);
	}
	if (game->getWorldTime() >= 10 && game->getWorldTime() <= 20) {
		if (rotated == 0)
			levelPX(sign);
		if (rotated == 1)
			levelPXRotated(sign);
	}
	if (game->getWorldTime() > 20 && game->getWorldTime() <= 30) {
		levelRXSinusoid(sign);
	}
	if (game->getWorldTime() > 30) {
		if (rotated == 1)
			levelPXRotated(sign);
		if (rotated == 0)
			levelPX(sign);
	}
}

void Bullet::GlevelTimeStampsY(int sign) {
	if (game->getWorldTime() <= 10) {
		if (rotated == 1)
			levelPYRotated(sign);
		if (rotated == 0)
			levelPY(sign);
	}
	if (game->getWorldTime() >= 10 && game->getWorldTime() <= 20) {
		if (rotated == 0)
			levelPY(sign);
		if (rotated == 1)
			levelPYRotated(sign);
	}
	if (game->getWorldTime() > 20 && game->getWorldTime() <= 30) {
		levelRYSinusoid(sign);
	}
	if (game->getWorldTime() > 30) {
		if (rotated == 1)
			levelPYRotated(sign);
		if (rotated == 0)
			levelPY(sign);
	}
}

void Bullet::addCoordinatesX(int sign) {
	if (level == 'P') {
		if (gunman == 'P')
			levelPX(sign);
		else PlevelPTimeStamps();
	}

	if (level == 'R') {
		RLevelTimeStampsX(sign);
	}

	if (level == 'B') {
		BLevelTimeStampsX(sign);
	}

	if (level == 'G') {
		GlevelTimeStampsX(sign);
	}
}

void Bullet::addCoordinatesY(int sign) {
	if (level == 'P')
		levelPY(sign);

	if (level == 'R') {
		RLevelTimeStampsY(sign);
	}

	if (level == 'B') {
		BLevelTimeStampsY(sign);
	}

	if (level == 'G') {
		GlevelTimeStampsY(sign);
	}
}

void Bullet::checkDirection() {
	if (type == 3) {
		switch (bulletDirection)
		{
		case 'N':
			if (rotated == 0)
				explodingCirclesShotRightUp(1.0);
			else
				explodingCirclesShotRightUp(0.0);
			break;
		case 'S':
			if (rotated == 0)
				explodingCirclesShotLeftDown(1.0);
			else
				explodingCirclesShotLeftDown(0.0);
			break;
		case 'W':
			if (rotated == 0)
				explodingCirclesShotLeftUp(1.0);
			else
				explodingCirclesShotLeftUp(0.0);
			break;
		case 'E':
			if (rotated == 0)
				explodingCirclesShotRightDown(1.0);
			else
				explodingCirclesShotRightDown(0.0);
			break;
		}
	}
	else {
		switch (bulletDirection)
		{
		case 'N':
			addCoordinatesY(-1);
			break;
		case 'S':
			addCoordinatesY(1);
			break;
		case 'W':
			addCoordinatesX(-1);
			break;
		case 'E':
			addCoordinatesX(1);
			break;
		}
	}
}

void Bullet::update() {
	checkDirection();
	if (spiral <= -SPIRAL_LENGTH) {
		changeDirection = true;
	}
	if (spiral >= SPIRAL_LENGTH) {
		changeDirection = false;
	}
	if (changeDirection) {
		spiral += 0.1;
	}
	if (!changeDirection) {
		spiral -= 0.1;
	}
}

void Bullet::render() {
	game->getDisplay()->DrawSurface(image, x, y, 0);
}

int Bullet::getGunman() {
	return gunman;
}

int Bullet::getType() {
	return type;
}