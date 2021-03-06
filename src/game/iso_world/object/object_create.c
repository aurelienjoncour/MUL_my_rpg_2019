/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** 2020-03-05T14:33:04+01:00 : simon
*/

#include "my_rpg.h"

static void object_init(object_t *obj, const sfVector3f txr_size,
sfVector3f *sampling, const char **img_path)
{
    obj->width = 2;
    obj->size_txr = txr_size;
    if (!sampling)
        obj->size = (sfVector3f){100, 100, 100};
    else
        obj->size = *sampling;
    obj->angle = (sfVector2f){0, 45};
    obj->origin = (sfVector2f){400, 400};
    obj->line_color = (sfColor){200, 200, 200, 150};
    obj->path_img = img_path;
    obj->modified = sfFalse;
    obj->coord_map = (sfVector2i){1, 1};
    obj->linked_map = NULL;
}

int object_create(object_t *obj, const sfVector3f txr_size,
sfVector3f *sampling, const char **img_path)
{
    if (!obj)
        return EXIT_FAILURE;
    object_init(obj, txr_size, sampling, img_path);
    object_2d_matrix_create(obj);
    object_lines_create(obj);
    if (object_texture_create(obj, img_path) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
