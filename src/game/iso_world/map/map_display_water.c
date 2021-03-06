/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_display_water
*/

#include "my_rpg.h"

extern const int TXTR_WATER;

void display_texture_water(sfRenderWindow *window, map_t *map, sfVector2i p)
{
    map->render_state.texture = map->textures[TXTR_WATER];
    sfRenderWindow_drawVertexArray(window, map->txtr_vrtx_a[p.y][p.x],
                                    &map->render_state);
    sfRenderWindow_drawVertexArray(window, map->txtr_vrtx_b[p.y][p.x],
                                        &map->render_state);
}
