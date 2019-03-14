// https://github.com/Costava/sdl2-draw-demo

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <SDL.h>

// Initial size
int screen_width = 512;
int screen_height = 512;

int clamp(int val, int min, int max) {
	if (val < min) return min;
	if (val > max) return max;

	return val;
}

void set_pixel(SDL_Surface *surface, int x, int y, Uint8 r, Uint8 g, Uint8 b) {
	Uint32 *pixels = (Uint32 *) surface->pixels;

	Uint32 color = SDL_MapRGB(surface->format, r, g, b);

	pixels[x + (y * surface->w)] = color;
}

int main(int argc, char *argv[]) {
	SDL_Window *window = NULL;
	SDL_Surface *surface = NULL;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL_Init failed: %s\n", SDL_GetError());

		exit(1);
	}

	window = SDL_CreateWindow("Draw", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	if (window == NULL) {
		printf("SDL_CreateWindow failed: %s\n", SDL_GetError());

		exit(1);
	}

	surface = SDL_GetWindowSurface(window);

	// Initialize window to all black
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 0));
	SDL_UpdateWindowSurface(window);

	srand(time(NULL));

	int mouse_x = 0;
	int mouse_y = 0;

	int x = 0;
	int y = 0;

	Uint8 r = 128;
	Uint8 g = 128;
	Uint8 b = 128;

	SDL_Event event;
	int quit = 0;
	int drawing = 0;

	while (!quit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = 1;
			}
			else if (event.type == SDL_WINDOWEVENT) {
				if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
					surface = SDL_GetWindowSurface(window);

					SDL_GetWindowSize(window, &screen_width, &screen_height);

					SDL_UpdateWindowSurface(window);
				}
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN) {
				drawing = 1;
			}
			else if (event.type == SDL_MOUSEBUTTONUP) {
				drawing = 0;
			}
			else if (event.type == SDL_MOUSEMOTION) {
				mouse_x = event.motion.x;
				mouse_y = event.motion.y;

				x = mouse_x;
				y = mouse_y;
			}
		}

		if (drawing) {
			if (rand() > RAND_MAX / 2) x += 1;
			else x -= 1;

			if (rand() > RAND_MAX / 2) y += 1;
			else y -= 1;

			if (rand() > RAND_MAX / 2) r += 1;
			else r -= 1;

			if (rand() > RAND_MAX / 2) g += 1;
			else g -= 1;

			if (rand() > RAND_MAX / 2) b += 1;
			else b -= 1;

			x = clamp(x, 0, screen_width - 1);
			y = clamp(y, 0, screen_height - 1);

			set_pixel(surface, x, y, r, g, b);
			SDL_UpdateWindowSurface(window);
		}
	}

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
