/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Created: 2020-03-05T18:25:16+01:00 | Author: simon
*/

#include "my_rpg.h"

int object_reload(object_t *obj)
{
    if (!obj)
        return EXIT_FAILURE;
    object_destroy(obj);
    object_2d_matrix_create(obj);
    object_lines_create(obj);
    if (object_texture_create(obj, obj->path_img) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (obj->linked_map != NULL) {
        object_on_map_refresh(obj, obj->linked_map);
    }
    return EXIT_SUCCESS;
}
