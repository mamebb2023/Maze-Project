#ifndef RAYCAST_H
#define RAYCAST_H

// raycast.c
SDL_Point rotate_point(const SDL_Point *point, float cx, float cy, float deg,
		float ray_size);
void raycast(SDL_Instance *sdl, player *player,  map_t *map,
		SDL_bool *map_active);
SDL_Point check_ray_intersections(SDL_Point *center, double ray_rotation_angle,
		map_t map, double *ray_len, int *orientation);
double remove_fish_eye_effect(player *player, double ray_length,
		double ray_view_angle);
void draw_3D_walls(SDL_Instance *sdl, double ray_length, int index,
		SDL_Color wall_color);

// racast_2.c
void untextured_sky(SDL_Instance *sdl);
void untextured_floor(SDL_Instance *sdl);
void player_collision_detection(player *player, map_t *map);
int check_intersect_orientation(SDL_Rect wall, SDL_Point *pointA,
		SDL_Point *pointB);
int lines_intersect(line *line1, line *line2, SDL_Point *hitp);

#endif /* RAYCAST_H */

