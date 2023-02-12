#pragma once

#define _USE_MATH_DEFINES
#include<math.h>
#include<stdio.h>
#include<string.h>

#include "Camera.h"

extern "C" {
#include"./SDL2-2.0.10/include/SDL.h"
#include"./SDL2-2.0.10/include/SDL_main.h"
}

#ifdef __cplusplus
extern "C"
#endif

#define SCREEN_WIDTH	640
#define SCREEN_HEIGHT	480

class Display
{
	SDL_Surface *screen, *charset;
	SDL_Texture* scrtex;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Camera* camera;
public:
	~Display();
	bool displayInit();
	SDL_Surface* loadImage(const char* path);
	SDL_Surface* loadImage(const char* path, int color);
	void render();
	void DrawString(int x, int y, const char* text, bool _static);
	void DrawSurface(SDL_Surface* sprite, int x, int y, bool _static);
	void DrawPixel(SDL_Surface* surface, int x, int y, Uint32 color, bool _static);
	void DrawLine(int x, int y, int l, int dx, int dy, Uint32 color, bool _static);
	void DrawRectangle(int x, int y, int l, int k, Uint32 outlineColor, Uint32 fillColor, bool _static);
	Camera* getCamera();
};

