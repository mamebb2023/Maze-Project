#include "../header/main.h"

/**
 * main - Entry point
 * @argc: Number of arguments passed to the program
 * @argv: Pointer to string arguments passed to the program
 *
 * Return: (0) on success, exits with failure status on failure
 */
#ifdef _WIN32
int WinMain(int argc, char **argv)
#else
int main(int argc, char **argv)
#endif
{
	(void) argc;
	(void) argv;

	SDL_Instance sdl = {NULL, NULL, NULL, NULL, NULL, NULL};
	map_t map;
	char *map_path;

	map_path = concat("maps/", "default");
	map = handle_file(map_path);

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error:%s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	create_window(WINDOW_TITLE, &sdl);
	create_renderer(&sdl);

	game_event_loop(&sdl, &map);
	free_map(&map);
	safe_close_sdl(&sdl);

	return (0);
}
