#pragma once

#include "Entity.h"

#define FIXED_ENEMY_BULLET_SPEED 1000.0
#define ENEMY_SPEED 2
#define SHOOTING_TIME_STARTER 1.5
#define PROJECTILES_TIME_BREAK 0.05

class Enemy :public Entity
{
	double timer;
	char level;
	bool moveDirection;
	void PLevelProjectiles();
	void RLevelProjectiles();
	void BLevelProjectiles();
	void GLevelProjectiles();
	void move();
public:
	Enemy(Game* game, double x, double y, char level);
	~Enemy();
	void shoot(char bulletDirection, double speed, int rotated, int type);
	void explodingCirclesShot(double x, double y, char bulletDirection, double speed, int rotated, int type);
	void update();
	void render();
};