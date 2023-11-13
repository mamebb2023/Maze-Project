#ifndef TEXTURE_H
#define TEXTURE_H

// texture.c
void shade_walls(SDL_Color *color_ref, int orientation);
void texture_sky(SDL_Instance *sdl, map_t *map);
void texture_walls(SDL_Instance *sdl, double line_height,
		int column, int y_pos, uint8_t alpha);
int render_thread(void *td);
void weapon_gun(SDL_Instance *sdl, map_t *map);

#endif /* TEXTURE_H */

