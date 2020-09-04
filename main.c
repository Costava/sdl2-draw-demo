#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
	#include <SDL.h>
#elif defined(__linux)
	#include <SDL2/SDL.h>
#else
	#error Failed to include SDL2
#endif

// Initial size
int screen_width = 512;
int screen_height = 512;

int clamp(const int val, const int min, const int max) {
	if (val < min) return min;
	if (val > max) return max;

	return val;
}

// Return true or false with ~equal probability
bool rand_bool(void) {
	if (rand() > RAND_MAX / 2) return true;

	return false;
}

void set_pixel(
	SDL_Surface *const surface,
	const int x,
	const int y,
	const Uint8 r,
	const Uint8 g,
	const Uint8 b)
{
	Uint32 *const pixels = (Uint32 *) surface->pixels;

	const Uint32 color = SDL_MapRGB(surface->format, r, g, b);

	pixels[x + (y * surface->w)] = color;
}

int main(void) {
	// Initialize SDL2
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("SDL_Init failed: %s\n", SDL_GetError());
		exit(1);
	}

	SDL_Window *const window = SDL_CreateWindow(
		"Draw",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		screen_width, screen_height,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	if (window == NULL) {
		printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
		exit(1);
	}

	SDL_Surface *surface = SDL_GetWindowSurface(window);

	if (surface == NULL) {
		printf("SDL_GetWindowSurface failed: %s\n", SDL_GetError());
		exit(1);
	}

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

	bool quit = false;
	bool drawing = false;

	while (!quit) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			else if (event.type == SDL_WINDOWEVENT) {
				if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
					surface = SDL_GetWindowSurface(window);

					if (surface == NULL) {
						printf("SDL_GetWindowSurface failed: %s\n",
							SDL_GetError());
						exit(1);
					}

					SDL_GetWindowSize(window, &screen_width, &screen_height);
					SDL_UpdateWindowSurface(window);
				}
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN) {
				drawing = true;
			}
			else if (event.type == SDL_MOUSEBUTTONUP) {
				drawing = false;
			}
			else if (event.type == SDL_MOUSEMOTION) {
				mouse_x = event.motion.x;
				mouse_y = event.motion.y;

				x = mouse_x;
				y = mouse_y;
			}
		}

		if (drawing) {
			if (rand_bool()) x += 1;
			else x -= 1;

			if (rand_bool()) y += 1;
			else y -= 1;

			if (rand_bool()) r += 1;
			else r -= 1;

			if (rand_bool()) g += 1;
			else g -= 1;

			if (rand_bool()) b += 1;
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
