#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "struct.h"
#include "macros.h"
#include "parser.h"
#include "player.h"
#include "texture.h"
#include "raycast.h"

void create_window(char *name, SDL_Instance *sdl);
void safe_close_sdl(SDL_Instance *sdl);
void create_renderer(SDL_Instance *sdl);
void print_sdl_error(void);

void game_event_loop(SDL_Instance *sdl, map_t *map);
void poll_events(int *quit, SDL_Event *e, player *player, SDL_Point *mouse,
		SDL_bool *map_active);

void draw_2d_map(SDL_Instance *sdl, map_t *map);
void send_frame(SDL_Instance *sdl);


SDL_Point rotate_point(const SDL_Point *point, float cx, float cy, float deg,
		float ray_size);

#endif
