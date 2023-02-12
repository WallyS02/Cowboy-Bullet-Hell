#include"Game.h"

int main(int argc, char **argv) {
	char level;
	scanf("%c", &level);
	if (level != 'P' && level != 'R' && level != 'B' && level != 'G') {
		return 0;
	}
	Game* game = nullptr;
	do {
		if (game) {
			delete game;
		}
		game = new Game();
		game->gameInit(level);
		game->run();
	} while (game->getInput()->getKey(SDLK_n));
	return 0;
};
