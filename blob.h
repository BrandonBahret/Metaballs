#pragma once
#include "vector.h"

class blob {
private:
	vector mPosition, mVelocity;
	float mRadius;

public:

	blob(int x, int y, float radius = 40);

	blob();

	float getRadius() { return mRadius; }
	vector getPosition() { return mPosition; }

	void update(int width, int height);
};