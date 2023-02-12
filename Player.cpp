#include "Player.h"

Player::Player(Game *game, double x, double y) : Entity(game, "./cowboy.bmp", x, y) {
	lastKey = 'E';
}

Player::~Player() {

}

void Player::shoot(char bulletDirection, double speed) {
	for (int i = 0; i < BULLET_NUMBER; i++) {
		if (!game->getBullet(i)) {
			game->setBullet(i, new Bullet(game, leftUpCornerX + image->w, leftUpCornerY + (image->h / 2), bulletDirection, speed, 'P', 'P', 0, 0));
			break;
		}
	}
}

void Player::arenaY(int sign) { // moving Y coordinates
	game->getDisplay()->getCamera()->addY(-1 * sign * CAMERA_SPEED);
	leftUpCornerY -= sign * CAMERA_SPEED;
	rightUpCornerY -= sign * CAMERA_SPEED;
	rightDownCornerY -= sign * CAMERA_SPEED;
	leftDownCornerY -= sign * CAMERA_SPEED;
}

void Player::arenaX(int sign) { // moving X coordinates
	game->getDisplay()->getCamera()->addX(-1 * sign * CAMERA_SPEED);
	leftUpCornerX -= sign * CAMERA_SPEED;
	rightUpCornerX -= sign * CAMERA_SPEED;
	rightDownCornerX -= sign * CAMERA_SPEED;
	leftDownCornerX -= sign * CAMERA_SPEED;
}

void Player::update() {
	if (leftUpCornerY > -FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_HEIGHT && rightUpCornerY > -FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_HEIGHT
		&& leftDownCornerY < FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_HEIGHT && rightDownCornerY < FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_HEIGHT
		&& leftUpCornerX > -FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_WIDTH && leftDownCornerX > -FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_WIDTH
		&& rightUpCornerX < FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_WIDTH && rightDownCornerX < FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_WIDTH) {
		if (game->getInput()->getKey(SDLK_UP)) {
			arenaY(1);
			lastKey = 'N';
		}
		if (game->getInput()->getKey(SDLK_DOWN)) {
			arenaY(-1);
			lastKey = 'S';
		}
		if (game->getInput()->getKey(SDLK_LEFT)) {
			arenaX(1);
			lastKey = 'W';
		}
		if (game->getInput()->getKey(SDLK_RIGHT)) {
			arenaX(-1);
			lastKey = 'E';
		}
	}
	else {
		if (leftUpCornerY <= -FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_HEIGHT && rightUpCornerY <= -FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_HEIGHT) {
			arenaY(-1);
		}
		if (leftDownCornerY >= FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_HEIGHT && leftDownCornerY >= FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_HEIGHT) {
			arenaY(1);
		}
		if (leftUpCornerX <= -FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_WIDTH && leftDownCornerX <= -FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_WIDTH) {
			arenaX(-1);
		}
		if (rightUpCornerX >= FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_WIDTH && rightDownCornerX >= FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_WIDTH) {
			arenaX(1);
		}
	}

	if (game->getInput()->isJustPressed(SDLK_SPACE)) {
		shoot(lastKey, FIXED_PLAYER_BULLET_SPEED);
	}
}

void Player::render() {
	game->getDisplay()->DrawSurface(image, x, y, 1);
}