#include "Camera.h"

Camera::Camera() {
	x = 0;
	y = 0;
}

int Camera::getX() {
	return x;
}

int Camera::getY() {
	return y;
}

void Camera::addX(int x) {
	this->x += x;
}

void Camera::addY(int y) {
	this->y += y;
}
