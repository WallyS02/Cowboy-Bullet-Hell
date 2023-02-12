#include "Game.h"

Game::~Game() {
	for (int i = 0; i < BULLET_NUMBER; i++) {
		if(bullet[i])
			delete bullet[i];
	}
	delete[] bullet;
	delete enemy;
	delete player;
	SDL_Quit();
}

bool Game::gameInit(char level) {
	display = new Display();
	input = new Input();
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		return false;
	}
	t1 = SDL_GetTicks();

	this->level = level;
	frames = 0;
	fpsTimer = 0;
	fps = 0;
	quit = 0;
	worldTime = 0;
	unprocessed = 0;
	playerCount = 0;
	enemyCount = 0;
	timeMeter = 0;
	invincibilityFrames = false;

	display->displayInit();

	player = new Player(this, SCREEN_WIDTH / 2 - 60, SCREEN_HEIGHT / 2 - 75);
	enemy = new Enemy(this, SCREEN_WIDTH / 5 * 4, SCREEN_HEIGHT / 2 - 75, level);
	bullet = new Bullet*[BULLET_NUMBER];
	for (int i = 0; i < BULLET_NUMBER; i++) {
		bullet[i] = nullptr;
	}
	return true;
}

Input* Game::getInput() {
	return input;
}

Bullet* Game::getBullet(int i) {
	return bullet[i];
}

void Game::setBullet(int i, Bullet* b) {
	bullet[i] = b;
}

Display* Game::getDisplay() {
	return display;
}

double Game::getDelta() {
	return delta;
}

bool Game::playerHitboxCheck(int i) {
	if ((bullet[i]->getLeftDownCornerY() <= player->getRightDownCornerY() && bullet[i]->getLeftDownCornerY() >= player->getRightUpCornerY())
		&& (bullet[i]->getLeftDownCornerX() >= player->getLeftDownCornerX() && bullet[i]->getLeftDownCornerX() <= player->getRightDownCornerX())) {
		return false;
	}
	if ((bullet[i]->getLeftUpCornerY() <= player->getRightDownCornerY() && bullet[i]->getLeftUpCornerY() >= player->getRightUpCornerY())
		&& (bullet[i]->getLeftUpCornerX() >= player->getLeftDownCornerX() && bullet[i]->getLeftUpCornerX() <= player->getRightDownCornerX())) {
		return false;
	}
	if ((bullet[i]->getRightUpCornerY() <= player->getRightDownCornerY() && bullet[i]->getRightUpCornerY() >= player->getRightUpCornerY())
		&& (bullet[i]->getRightUpCornerX() >= player->getLeftDownCornerX() && bullet[i]->getRightUpCornerX() <= player->getRightDownCornerX())) {
		return false;
	}
	if ((bullet[i]->getRightDownCornerY() <= player->getRightDownCornerY() && bullet[i]->getRightDownCornerY() >= player->getRightUpCornerY())
		&& (bullet[i]->getRightDownCornerX() >= player->getLeftDownCornerX() && bullet[i]->getRightDownCornerX() <= player->getRightDownCornerX())) {
		return false;
	}
	return true;
}

bool Game::enemyHitboxCheck(int i) {
	if ((bullet[i]->getLeftDownCornerY() <= enemy->getRightDownCornerY() && bullet[i]->getLeftDownCornerY() >= enemy->getRightUpCornerY())
		&& (bullet[i]->getLeftDownCornerX() >= enemy->getLeftDownCornerX() && bullet[i]->getLeftDownCornerX() <= enemy->getRightDownCornerX())) {
		return false;
	}
	if ((bullet[i]->getLeftUpCornerY() <= enemy->getRightDownCornerY() && bullet[i]->getLeftUpCornerY() >= enemy->getRightUpCornerY())
		&& (bullet[i]->getLeftUpCornerX() >= enemy->getLeftDownCornerX() && bullet[i]->getLeftUpCornerX() <= enemy->getRightDownCornerX())) {
		return false;
	}
	if ((bullet[i]->getRightUpCornerY() <= enemy->getRightDownCornerY() && bullet[i]->getRightUpCornerY() >= enemy->getRightUpCornerY())
		&& (bullet[i]->getRightUpCornerX() >= enemy->getLeftDownCornerX() && bullet[i]->getRightUpCornerX() <= enemy->getRightDownCornerX())) {
		return false;
	}
	if ((bullet[i]->getRightDownCornerY() <= enemy->getRightDownCornerY() && bullet[i]->getRightDownCornerY() >= enemy->getRightUpCornerY())
		&& (bullet[i]->getRightDownCornerX() >= enemy->getLeftDownCornerX() && bullet[i]->getRightDownCornerX() <= enemy->getRightDownCornerX())) {
		return false;
	}
	return true;
}

bool Game::bulletHitboxCheck(int i) {
	if (bullet[i]->getType() == 2) {
		if (bullet[i]->getLeftUpCornerX() <= enemy->getLeftUpCornerX() - FIXED_SPECIAL_PROJECTILE_DISTANCE) {
			enemy->explodingCirclesShot(enemy->getLeftUpCornerX() - FIXED_SPECIAL_PROJECTILE_DISTANCE, enemy->getLeftUpCornerY() + (enemy->getImage()->h / 2), 'N', FIXED_ENEMY_BULLET_SPEED, 0, 3);
			enemy->explodingCirclesShot(enemy->getLeftUpCornerX() - FIXED_SPECIAL_PROJECTILE_DISTANCE, enemy->getLeftUpCornerY() + (enemy->getImage()->h / 2), 'N', FIXED_ENEMY_BULLET_SPEED, 2, 3);
			enemy->explodingCirclesShot(enemy->getLeftUpCornerX() - FIXED_SPECIAL_PROJECTILE_DISTANCE, enemy->getLeftUpCornerY() + (enemy->getImage()->h / 2), 'S', FIXED_ENEMY_BULLET_SPEED, 0, 3);
			enemy->explodingCirclesShot(enemy->getLeftUpCornerX() - FIXED_SPECIAL_PROJECTILE_DISTANCE, enemy->getLeftUpCornerY() + (enemy->getImage()->h / 2), 'S', FIXED_ENEMY_BULLET_SPEED, 2, 3);
			enemy->explodingCirclesShot(enemy->getLeftUpCornerX() - FIXED_SPECIAL_PROJECTILE_DISTANCE, enemy->getLeftUpCornerY() + (enemy->getImage()->h / 2), 'W', FIXED_ENEMY_BULLET_SPEED, 0, 3);
			enemy->explodingCirclesShot(enemy->getLeftUpCornerX() - FIXED_SPECIAL_PROJECTILE_DISTANCE, enemy->getLeftUpCornerY() + (enemy->getImage()->h / 2), 'W', FIXED_ENEMY_BULLET_SPEED, 2, 3);
			enemy->explodingCirclesShot(enemy->getLeftUpCornerX() - FIXED_SPECIAL_PROJECTILE_DISTANCE, enemy->getLeftUpCornerY() + (enemy->getImage()->h / 2), 'E', FIXED_ENEMY_BULLET_SPEED, 0, 3);
			enemy->explodingCirclesShot(enemy->getLeftUpCornerX() - FIXED_SPECIAL_PROJECTILE_DISTANCE, enemy->getLeftUpCornerY() + (enemy->getImage()->h / 2), 'E', FIXED_ENEMY_BULLET_SPEED, 2, 3);
			return false;
		}
	}
	if (bullet[i]->getLeftDownCornerX() <= -FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_WIDTH && bullet[i]->getLeftUpCornerX() <= -FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_WIDTH) {
		return false;
	}
	if (bullet[i]->getRightUpCornerX() >= FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_WIDTH && bullet[i]->getRightDownCornerX() >= FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_WIDTH) {
		return false;
	}
	if (bullet[i]->getLeftUpCornerY() <= -FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_HEIGHT && bullet[i]->getRightUpCornerY() <= -FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_HEIGHT) {
		return false;
	}
	if (bullet[i]->getRightDownCornerY() >= FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_HEIGHT && bullet[i]->getLeftDownCornerY() >= FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_HEIGHT) {
		return false;
	}
	return true;
}

void Game::bulletUpdating(int i) {
	bool bulletOk = true;
	if (bullet[i]) {
		bulletOk = bulletHitboxCheck(i);
		if (!bulletOk) {
			delete bullet[i];
			bullet[i] = nullptr;
		}
	}
	if (bullet[i]) {
		if (bullet[i]->getGunman() == 'E') {
			if (worldTime - timeMeter >= FIXED_INVINCIBILITY_FRAMES_TIME) {
				invincibilityFrames = false;
			}
			if (!invincibilityFrames) {
				bulletOk = playerHitboxCheck(i);
				if (!bulletOk) {
					playerCount++;
					delete bullet[i];
					bullet[i] = nullptr;
					if (timeMeter >= FIXED_INVINCIBILITY_FRAMES_TIME)
						invincibilityFrames = true;
					timeMeter = worldTime;
				}
			}
		}
		else {
			bulletOk = enemyHitboxCheck(i);
			if (!bulletOk) {
				enemyCount++;
				delete bullet[i];
				bullet[i] = nullptr;
			}
		}
	}
	if (bullet[i]) {
		bullet[i]->update();
	}
}

double Game::getWorldTime() {
	return worldTime;
}

void Game::run() {
	while (!quit) {
		toRender = false;

		t2 = SDL_GetTicks();

		delta = (t2 - t1) * 0.001;
		t1 = t2;

		worldTime += delta;

		fpsTimer += delta;

		unprocessed += delta;

		while (unprocessed >= UPDATE_CAP) {
			unprocessed -= UPDATE_CAP;
			toRender = true;
			update();
			if (fpsTimer > 1.0) {
				fps = frames;
				frames = 0;
				fpsTimer -= 1.0;
			};
		}

		if (toRender) {
			render();
			display->render();
			frames++;
		}
	};
}

void Game::update() {
	input->update();
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			input->setKey(event.key.keysym.sym, true);
			break;
		case SDL_KEYUP:
			input->setKey(event.key.keysym.sym, false);
			break;
		case SDL_QUIT:
			quit = 1;
			break;
		};
	};
	if (input->isJustPressed(SDLK_ESCAPE)) {
		quit = true;
	}
	if (input->isJustPressed(SDLK_n)) {
		quit = true;
		return;
	}
	player->update();
	enemy->update();
	for (int i = 0; i < BULLET_NUMBER; i++) {
		bulletUpdating(i);
	}
}

void Game::render() {
	display->DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0xF2D16B, 0xF2D16B, 1);
	display->DrawRectangle(0, 9, 100 + worldTime*50, 50, 0x6198D3, 0x6198D3, 1);
	display->DrawRectangle((SCREEN_WIDTH - 100) - 50 * worldTime, 9, SCREEN_WIDTH, 50, 0x6198D3, 0x6198D3, 1);

	display->DrawString(SCREEN_WIDTH / 3 + 10, 10, "Welcome to the Cowboy Hell!", 1);
	display->DrawString(SCREEN_WIDTH / 3 - 150, 20, "Time elapsed from the start of the level: ", 1);
	char text[128], text1[128], text2[128];
	sprintf(text, "%.1lf s %.0lf frames / s", worldTime, fps);
	display->DrawString(SCREEN_WIDTH / 2 + 160 - strlen(text) * 8 / 2, 20, text, 1);
	display->DrawString(SCREEN_WIDTH / 2 - 120, 30, "Player hits: ", 1);
	sprintf(text1, "%u", enemyCount);
	display->DrawString(SCREEN_WIDTH / 2 - 20, 30, text1, 1);
	display->DrawString(SCREEN_WIDTH / 2 + 30, 30, "Enemy hits: ", 1);
	sprintf(text2, "%u", playerCount);
	display->DrawString(SCREEN_WIDTH / 2 + 120, 30, text2, 1);

	display->DrawLine(-FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_WIDTH, -FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_HEIGHT, (2 * FIXED_ARENA_SIZE_MULTIPLIER) * SCREEN_WIDTH, 1, 0, 0x800000, 0);
	display->DrawLine(-FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_WIDTH, FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_HEIGHT, (2 * FIXED_ARENA_SIZE_MULTIPLIER) * SCREEN_WIDTH, 1, 0, 0x800000, 0);
	display->DrawLine(-FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_WIDTH, -FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_HEIGHT, (2 * FIXED_ARENA_SIZE_MULTIPLIER) * SCREEN_HEIGHT, 0, 1, 0x800000, 0);
	display->DrawLine(FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_WIDTH, -FIXED_ARENA_SIZE_MULTIPLIER * SCREEN_HEIGHT, (2 * FIXED_ARENA_SIZE_MULTIPLIER) * SCREEN_HEIGHT, 0, 1, 0x800000, 0);

	player->render();
	enemy->render();
	for (int i = 0; i < BULLET_NUMBER; i++) {
		if (bullet[i])
			bullet[i]->render();
	}
}