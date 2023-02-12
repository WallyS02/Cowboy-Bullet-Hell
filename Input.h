#pragma once

#define NUM_KEYS 256
#define ASCII_SHIFT 1073741753

class Input
{
	bool* keys;
	bool* keysLast;
public:
	Input();
	~Input();
	void update();
	bool isJustPressed(int i);
	bool isJustReleased(int i);
	bool getKey(int i);
	bool getKeyLast(int i);
	void setKey(int i, bool x);
	void setKeyLast(int i, bool x);
};

