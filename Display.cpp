#include "Display.h"

Display::~Display() {
	delete camera;
	SDL_FreeSurface(screen);
	SDL_DestroyTexture(scrtex);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	if (charset) {
		SDL_FreeSurface(charset);
	}
}

bool Display::displayInit() {
	if (SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer) != 0) {
		SDL_Quit();
		return false;
	};
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_SetWindowTitle(window, "The Cowboy Hell");

	screen = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
	scrtex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
	
	charset = loadImage("./cs8x8.bmp", 0x00000000);

	camera = new Camera();
	return true;
}

SDL_Surface* Display::loadImage(const char* path) {
	SDL_Surface* image = SDL_LoadBMP(path);
	return image;
}

SDL_Surface* Display::loadImage(const char* path, int color) {
	SDL_Surface* image = SDL_LoadBMP(path);
	SDL_SetColorKey(image, true, color);
	return image;
}

void Display::render() {
	SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, scrtex, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void Display::DrawString(int x, int y, const char* text, bool _static) {
	if (!_static) {
		x -= camera->getX();
		y -= camera->getY();
	}
	int px, py, c;
	SDL_Rect s, d;
	s.w = 8;
	s.h = 8;
	d.w = 8;
	d.h = 8;
	while (*text) {
		c = *text & 255;
		px = (c % 16) * 8;
		py = (c / 16) * 8;
		s.x = px;
		s.y = py;
		d.x = x;
		d.y = y;
		SDL_BlitSurface(charset, &s, screen, &d);
		x += 8;
		text++;
	};
};

void Display::DrawSurface(SDL_Surface* sprite, int x, int y, bool _static) {
	if (!_static) {
		x -= camera->getX();
		y -= camera->getY();
	}
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = sprite->w;
	dest.h = sprite->h;
	SDL_BlitSurface(sprite, NULL, screen, &dest);
};

void Display::DrawPixel(SDL_Surface* surface, int x, int y, Uint32 color, bool _static) {
	if (!_static) {
		x -= camera->getX();
		y -= camera->getY();
	}
	if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT) {
		return;
	}
	int bpp = surface->format->BytesPerPixel;
	Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;
	*(Uint32*)p = color;
};

void Display::DrawLine(int x, int y, int l, int dx, int dy, Uint32 color, bool _static) {
	for (int i = 0; i < l; i++) {
		DrawPixel(screen, x, y, color, _static);
		x += dx;
		y += dy;
	};
};

void Display::DrawRectangle(int x, int y, int l, int k, Uint32 outlineColor, Uint32 fillColor, bool _static) {
	int i;
	DrawLine(x, y, k, 0, 1, outlineColor, _static);
	DrawLine(x + l - 1, y, k, 0, 1, outlineColor, _static);
	DrawLine(x, y, l, 1, 0, outlineColor, _static);
	DrawLine(x, y + k - 1, l, 1, 0, outlineColor, _static);
	for (i = y + 1; i < y + k - 1; i++)
		DrawLine(x + 1, i, l - 2, 1, 0, fillColor, _static);
};

Camera* Display::getCamera() {
	return camera;
}