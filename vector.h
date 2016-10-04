#pragma once
#include <iostream>

class vector {

public:
	int mX, mY;

	vector(int x, int y) {
		mX = x;
		mY = y;
	}

	int getX() { return mX; }
	int getY() { return mY; }

	void setX(int x) { mX = x; }
	void setY(int y) { mY = y; }

	void add(vector vec) {
		mX += vec.getX();
		mY += vec.getY();
	}

	void negate() {
		mX *= -1;
		mY *= -1;
	}

	static vector randomVec(int upper = 5) {
		vector vec(rand() % upper + 1, rand() % upper + 1);
		return vec;
	}
};