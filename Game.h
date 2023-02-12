#pragma once

#include "Display.h"
#include "Input.h"
class Player;
class Enemy;
class Bullet;

#define UPDATE_CAP 1.0/60.0
#define CAMERA_SPEED 10
#define BULLET_NUMBER 1000
#define FIXED_INVINCIBILITY_FRAMES_TIME 2.0
#define FIXED_ARENA_SIZE_MULTIPLIER 3
#define FIXED_SPECIAL_PROJECTILE_DISTANCE 150

class Game
{
	char level;
	int t1, t2, quit, frames, playerCount, enemyCount;
	double delta, fpsTimer, fps, unprocessed, worldTime, timeMeter;
	SDL_Event event;
	bool toRender, invincibilityFrames;
	Display* display;
	Input* input;
	Player* player;
	Enemy* enemy;
	Bullet **bullet;
	bool playerHitboxCheck(int i);
	bool enemyHitboxCheck(int i);
	bool bulletHitboxCheck(int i);
	void bulletUpdating(int i);
public:
	~Game();
	bool gameInit(char level);
	void run();
	void update();
	void render();
	Input* getInput();
	Bullet* getBullet(int i);
	void setBullet(int i, Bullet* b);
	Display* getDisplay();
	double getDelta();
	double getWorldTime();
};
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"