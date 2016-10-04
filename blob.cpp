#pragma once
#include "blob.h"

blob::blob(int x, int y, float radius) : mPosition(x, y), mVelocity(vector::randomVec()) {
	mRadius = radius;
}

blob::blob() : mPosition(0, 0), mVelocity(vector::randomVec()) {
	mRadius = 40;
}

void blob::update(int screenWidth, int screenHeight) {
	mPosition.add(mVelocity);

	int x = mPosition.getX();
	int y = mPosition.getY();

	if (x >= screenWidth || x <= 0)
		mVelocity.setX(-1 * mVelocity.getX());

	else if (y >= screenHeight || y <= 0)
		mVelocity.setY(-1 * mVelocity.getY());
}