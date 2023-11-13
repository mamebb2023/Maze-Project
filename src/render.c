#include "../header/main.h"

/**
 * draw_2d_map - creates 2d points to the screen
 * @sdl: data structure of SDL_Instance
 * @map: map_t data structure representing 2D map
 */
void draw_2d_map(SDL_Instance *sdl, map_t *map)
{
	int i, j;
	SDL_Rect block = {0, 0, GRID_SIZE, GRID_SIZE};

	for (i = 0; i < map->rows; i++)
	{
		for (j = 0; j < map->columns; j++)
		{
			block.x = (j << 4) + MAP_MARGIN;
			block.y = (i << 4) + MAP_MARGIN;
			if (map->arr[i][j] == '0')
			{
				REND_COLOR(sdl->renderer, 255, 255, 255, 100);
				SDL_RenderFillRect(sdl->renderer, &block);
			}
			else
			{
				REND_COLOR(sdl->renderer, 0, 0, 0, 150);
				SDL_RenderFillRect(sdl->renderer, &block);
			}
		}
	}
}

/**
 * send_frame - draws the results in renderer to the screen
 * @sdl: data structure of SDL_Instance
 */
void send_frame(SDL_Instance *sdl)
{
	REND_COLOR_BLACK(sdl->renderer);
	SDL_SetRenderDrawBlendMode(sdl->renderer, SDL_BLENDMODE_BLEND);
	SDL_RenderPresent(sdl->renderer);
	SDL_RenderClear(sdl->renderer);
}
