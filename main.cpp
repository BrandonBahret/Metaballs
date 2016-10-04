#include <SDL.h>
#include <iostream>
#include "blob.h"
#include "LTimer.h"

#define DISTANCE(X1, Y1, X2, Y2) sqrt(((X2 - X1) * (X2 - X1)) + ((Y2 - Y1) * (Y2 - Y1)))

int main(int argv, char **args) {

	const int SCREEN_WIDTH  = 160;
	const int SCREEN_HEIGHT = 160;
	const int SCREEN_FPS = 60;
	const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* frame = SDL_CreateWindow("Metaballs",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	SDL_Renderer* painter = SDL_CreateRenderer(frame, -1, SDL_RENDERER_ACCELERATED );

	//The frames per second cap timer
	LTimer capTimer;

	const int numberOfBlobs = 7;

	blob blobs[numberOfBlobs];
	for (int i = 0; i < numberOfBlobs; i++) {
		blobs[i] = blob(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, rand() % 1000 + 1);
	}

	while (true) {
		capTimer.start();

		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				SDL_Quit();
				exit(0);
			}
		}

		for (blob &eachBlob : blobs) {
			eachBlob.update(SCREEN_WIDTH, SCREEN_HEIGHT);
		}

		for (int y = 0; y < SCREEN_HEIGHT; y++) {
			for (int x = 0; x < SCREEN_WIDTH; x++) {
				float sum = 0;
				for (blob eachBlob : blobs) {
					sum += eachBlob.getRadius() / DISTANCE(x, y, eachBlob.getPosition().getX(), eachBlob.getPosition().getY());
					if (sum > 255){
						sum = 255;
						break;
					}
				}

				SDL_SetRenderDrawColor(painter, sum, 120, 100, 255);
				SDL_RenderDrawPoint(painter, x, y);
			}
		}
		
		SDL_RenderPresent(painter);

		//If frame finished early
		int frameTicks = capTimer.getTicks();
		if (frameTicks < SCREEN_TICKS_PER_FRAME) {
			//Wait remaining time
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}
	}

	return EXIT_SUCCESS;
}