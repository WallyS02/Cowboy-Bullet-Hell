#pragma once

#include "Entity.h"

#define SPIRAL_LENGTH 5
#define FIXED_CIRCLE_SPEED 1
#define CIRCLE_CORRECTION 0.3

class Bullet :public Entity
{
	char bulletDirection;
	double speed, spiral;
	char gunman, level;
	bool changeDirection;
	int rotated, type;
	void addCoordinatesX(int sign);
	void addCoordinatesY(int sign);
	void levelPX(int sign);
	void levelPY(int sign);
	void levelPXRotated(int sign);
	void levelPYRotated(int sign);
	void levelRXSinusoid(int sign);
	void levelRYSinusoid(int sign);
	void levelRXSinusoidRotated(int sign);
	void levelRYSinusoidRotated(int sign);
	void PlevelPTimeStamps();
	void RLevelTimeStampsX(int sign);
	void RLevelTimeStampsY(int sign);
	void BLevelTimeStampsX(int sign);
	void BLevelTimeStampsY(int sign);
	void GlevelTimeStampsX(int sign);
	void GlevelTimeStampsY(int sign);
	void explodingCirclesShotRightUp(double part);
	void explodingCirclesShotRightDown(double part);
	void explodingCirclesShotLeftUp(double part);
	void explodingCirclesShotLeftDown(double part);
	void checkDirection();
public:
	Bullet(Game* game, double x, double y, char bulletDirection, double speed, char gunman, char level, int rotated, int type);
	~Bullet();
	void update();
	void render();
	int getType();
	int getGunman();
};