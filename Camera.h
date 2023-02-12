#pragma once

class Camera
{
	int x, y;
public:
	Camera();
	int getX();
	int getY();
	void addX(int x);
	void addY(int y);
};

