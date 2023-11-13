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

// init.c
void create_window(char *name, SDL_Instance *);
void safe_close_sdl(SDL_Instance *);
void create_renderer(SDL_Instance *);

// events.c
void game_event_loop(SDL_Instance *, map_t *);
void poll_events(int *quit, SDL_Event *e, player *player, SDL_Point *mouse,
		SDL_bool *map_active);

// render.c
void draw_2d_map(SDL_Instance *, map_t *);
void send_frame(SDL_Instance *);

#endif
