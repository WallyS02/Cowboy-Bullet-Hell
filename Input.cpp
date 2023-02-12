#include "Input.h"

Input::Input() {
	keys = new bool[NUM_KEYS];
	keysLast = new bool[NUM_KEYS];
	for (int i = 0; i < NUM_KEYS; i++) {
		keys[i] = false;
		keysLast[i] = false;
	}
}

Input::~Input() {
	delete[] keys;
	delete[] keysLast;
}

void Input::update() {
	for (int i = 0; i < NUM_KEYS; i++) {
		keysLast[i] = keys[i];
	}
}

bool Input::isJustPressed(int i) {
	if (i > 128) {
		return !keysLast[i - ASCII_SHIFT] && keys[i - ASCII_SHIFT];
	}
	return !keysLast[i] && keys[i];
}

bool Input::isJustReleased(int i) {
	if (i > 128) {
		return keysLast[i - ASCII_SHIFT] && !keys[i - ASCII_SHIFT];
	}
	return keysLast[i] && !keys[i];
}

bool Input::getKey(int i) {
	if (i > 128) {
		return keys[i - ASCII_SHIFT];
	}
	return keys[i];
}

bool Input::getKeyLast(int i) {
	if (i > 128) {
		return keysLast[i - ASCII_SHIFT];
	}
	return keysLast[i];
}

void Input::setKey(int i, bool x) {
	if (i > 128) {
		keys[i - ASCII_SHIFT] = x;
	}
	else keys[i] = x;
}

void Input::setKeyLast(int i, bool x) {
	if (i > 128) {
		keysLast[i - ASCII_SHIFT] = x;
	}
	else keysLast[i] = x;
}