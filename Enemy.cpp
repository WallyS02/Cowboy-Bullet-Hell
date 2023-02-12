#include "Enemy.h"

Enemy::Enemy(Game* game, double x, double y, char level) : Entity(game, "./robotRed.bmp", x, y) {
	timer = 0;
	this->level = level;
	moveDirection = false;
	if (level == 'B')
		image = game->getDisplay()->loadImage("./robotBlue.bmp");
	if (level == 'G')
		image = game->getDisplay()->loadImage("./robotGreen.bmp");
}

Enemy::~Enemy() {

}

void Enemy::shoot(char bulletDirection, double speed, int rotated, int type) {
	for (int i = 0; i < BULLET_NUMBER; i++) {
		if (!game->getBullet(i)) {
			game->setBullet(i, new Bullet(game, leftUpCornerX, leftUpCornerY + (image->h / 2), bulletDirection, speed, 'E', level, rotated, type));
			break;
		}
	}
}

void Enemy::explodingCirclesShot(double x, double y, char bulletDirection, double speed, int rotated, int type) {
	for (int i = 0; i < BULLET_NUMBER; i++) {
		if (!game->getBullet(i)) {
			game->setBullet(i, new Bullet(game, x, y, bulletDirection, speed, 'E', level, rotated, type));
			break;
		}
	}
}

void Enemy::PLevelProjectiles() {
	if (game->getWorldTime() <= 5) {
		shoot('W', FIXED_ENEMY_BULLET_SPEED, 0, 0);
	}
	if (game->getWorldTime() > 8 && game->getWorldTime() <= 8.8) {
		shoot('W', FIXED_ENEMY_BULLET_SPEED, 0, 1);
	}
	if (game->getWorldTime() > 12 && game->getWorldTime() <= 12.8) {
		shoot('W', FIXED_ENEMY_BULLET_SPEED, 0, 2);
	}
	if (game->getWorldTime() > 15) {
		shoot('W', FIXED_ENEMY_BULLET_SPEED, 0, 0);
	}
}

void Enemy::RLevelProjectiles() {
	shoot('W', FIXED_ENEMY_BULLET_SPEED, 0, 0);
	shoot('N', FIXED_ENEMY_BULLET_SPEED, 0, 0);
	shoot('S', FIXED_ENEMY_BULLET_SPEED, 0, 0);
	shoot('E', FIXED_ENEMY_BULLET_SPEED, 0, 0);
	shoot('N', FIXED_ENEMY_BULLET_SPEED, 0, 3);
	shoot('N', FIXED_ENEMY_BULLET_SPEED, 2, 3);
	shoot('S', FIXED_ENEMY_BULLET_SPEED, 0, 3);
	shoot('S', FIXED_ENEMY_BULLET_SPEED, 2, 3);
	shoot('W', FIXED_ENEMY_BULLET_SPEED, 0, 3);
	shoot('W', FIXED_ENEMY_BULLET_SPEED, 2, 3);
	shoot('E', FIXED_ENEMY_BULLET_SPEED, 0, 3);
	shoot('E', FIXED_ENEMY_BULLET_SPEED, 2, 3);
}

void Enemy::BLevelProjectiles() {
	if (game->getWorldTime() > 10 && game->getWorldTime() <= 30) {
		shoot('W', FIXED_ENEMY_BULLET_SPEED, 0, 0);
		shoot('N', FIXED_ENEMY_BULLET_SPEED, 1, 0);
		shoot('S', FIXED_ENEMY_BULLET_SPEED, 1, 0);
		shoot('E', FIXED_ENEMY_BULLET_SPEED, 0, 0);
	}
	else {
		shoot('N', FIXED_ENEMY_BULLET_SPEED, 0, 0);
		shoot('S', FIXED_ENEMY_BULLET_SPEED, 0, 0);
		shoot('W', FIXED_ENEMY_BULLET_SPEED, 1, 0);
		shoot('N', FIXED_ENEMY_BULLET_SPEED, 1, 0);
		shoot('S', 2*FIXED_ENEMY_BULLET_SPEED, 1, 0);
		shoot('E', 2*FIXED_ENEMY_BULLET_SPEED, 1, 0);
		shoot('N', FIXED_ENEMY_BULLET_SPEED, 2, 0);
		shoot('N', FIXED_ENEMY_BULLET_SPEED, 3, 0);
		shoot('S', FIXED_ENEMY_BULLET_SPEED, 3, 0);
		shoot('S', FIXED_ENEMY_BULLET_SPEED, 2, 0);
		shoot('E', FIXED_ENEMY_BULLET_SPEED, 4, 0);
		shoot('W', FIXED_ENEMY_BULLET_SPEED, 4, 0);
	}
}

void Enemy::GLevelProjectiles() {
	if (game->getWorldTime() >= 10 && game->getWorldTime() <= 20) {
		shoot('N', FIXED_ENEMY_BULLET_SPEED, 0, 0);
		shoot('S', FIXED_ENEMY_BULLET_SPEED, 0, 0);
		shoot('W', FIXED_ENEMY_BULLET_SPEED, 1, 0);
		shoot('N', FIXED_ENEMY_BULLET_SPEED, 1, 0);
		shoot('S', 2 * FIXED_ENEMY_BULLET_SPEED, 1, 0);
		shoot('E', 2 * FIXED_ENEMY_BULLET_SPEED, 1, 0);
	}
	if (game->getWorldTime() > 20 && game->getWorldTime() <= 30) {
		shoot('N', FIXED_ENEMY_BULLET_SPEED, 0, 0);
		shoot('S', FIXED_ENEMY_BULLET_SPEED, 0, 0);
	}
	else {
		shoot('W', FIXED_ENEMY_BULLET_SPEED, 0, 0);
		shoot('N', FIXED_ENEMY_BULLET_SPEED, 0, 0);
		shoot('S', FIXED_ENEMY_BULLET_SPEED, 0, 0);
		shoot('E', FIXED_ENEMY_BULLET_SPEED, 0, 0);
		shoot('W', FIXED_ENEMY_BULLET_SPEED, 1, 0);
		shoot('N', FIXED_ENEMY_BULLET_SPEED, 1, 0);
		shoot('S', FIXED_ENEMY_BULLET_SPEED, 1, 0);
		shoot('E', FIXED_ENEMY_BULLET_SPEED, 1, 0);
	}
}

void Enemy::move() {
	if (x <= -FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_WIDTH + CAMERA_SPEED)
		moveDirection = true;
	if (rightUpCornerX >= FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_WIDTH - CAMERA_SPEED)
		moveDirection = false;
	if (!moveDirection) {
		x = x - ENEMY_SPEED;
		leftUpCornerX = leftUpCornerX - ENEMY_SPEED;
		leftDownCornerX = leftDownCornerX - ENEMY_SPEED;
		rightUpCornerX = rightUpCornerX - ENEMY_SPEED;
		rightDownCornerX = rightDownCornerX - ENEMY_SPEED;
	}

	if (moveDirection) {
		x = x + ENEMY_SPEED;
		leftUpCornerX = leftUpCornerX + ENEMY_SPEED;
		leftDownCornerX = leftDownCornerX + ENEMY_SPEED;
		rightUpCornerX = rightUpCornerX + ENEMY_SPEED;
		rightDownCornerX = rightDownCornerX + ENEMY_SPEED;
	}
}

void Enemy::update() {
	if(level == 'G')
		move();
	timer += game->getDelta();
	if (timer >= PROJECTILES_TIME_BREAK) {
		timer -= PROJECTILES_TIME_BREAK;
		if (game->getWorldTime() >= SHOOTING_TIME_STARTER) {
			if (level == 'P') {
				PLevelProjectiles();
			}
			if (level == 'R') {
				RLevelProjectiles();
			}
			if (level == 'B') {
				BLevelProjectiles();
			}
			if (level == 'G') {
				GLevelProjectiles();
			}
		}
	}
}

void Enemy::render() {
	game->getDisplay()->DrawSurface(image, x, y, 0);
}