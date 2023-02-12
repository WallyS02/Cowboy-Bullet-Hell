#pragma once

#include "Entity.h"

#define FIXED_PLAYER_BULLET_SPEED 5000.0

class Player :public Entity
{
	void arenaY(int sign);
	void arenaX(int sign);
	char lastKey;
public:
	Player(Game* game, double x, double y);
	~Player();
	void shoot(char bulletDirection, double speed);
	void update();
	void render();
};