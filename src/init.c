#include "../header/main.h"

/**
 * create_window - creates sdl window instance
 * @name: string pointer to be used to window title
 * @sdl: data structure of SDL_Instance
 */
void create_window(char *name, SDL_Instance *sdl)
{
	sdl->window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (!sdl->window)
	{
		printf("SDL Error Occured:%s\n", SDL_GetError());
		safe_close_sdl(sdl);
		exit(EXIT_FAILURE);
	}
}

/**
 * create_renderer - creates sdl renderer instance
 * @sdl: data structure of SDL_Instance
 */
void create_renderer(SDL_Instance *sdl)
{
	sdl->renderer = SDL_CreateRenderer(sdl->window, -1,
	SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	if (!sdl->renderer)
	{
		printf("SDL Error Occured:%s\n", SDL_GetError());
		safe_close_sdl(sdl);
		exit(EXIT_FAILURE);
	}
}

/**
 * safe_close_sdl - frees and closes sdl
 * @sdl: data structure of SDL_Instance
 */
void safe_close_sdl(SDL_Instance *sdl)
{
	if (sdl->window)
		SDL_DestroyWindow(sdl->window);
	if (sdl->renderer)
		SDL_DestroyRenderer(sdl->renderer);
	if (sdl->skybox)
		SDL_DestroyTexture(sdl->skybox);
	if (sdl->wall_surface)
		SDL_FreeSurface(sdl->wall_surface);
	if (sdl->wall_texture)
		SDL_DestroyTexture(sdl->wall_texture);
	if (sdl->weapon)
		SDL_DestroyTexture(sdl->weapon);

	sdl->window = NULL;
	sdl->renderer = NULL;
	sdl->skybox = NULL;
	sdl->wall_surface = NULL;
	sdl->wall_texture = NULL;

	SDL_Quit();
}
