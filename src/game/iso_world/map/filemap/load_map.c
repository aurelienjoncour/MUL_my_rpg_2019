/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** load_map
*/

#include "my_rpg.h"

extern const char *MAP_EXTENSION;

bool allow_char(char *script, char *allow_char)
{
    int len_script = my_strlen(script);
    int len_allow = my_strlen(allow_char);
    int cnt = 0;

    for (int i = 0; i  < len_script; i++) {
        cnt = 0;
        for (int j = 0; j < len_allow; j++) {
            if (script[i] == allow_char[j])
                cnt++;
        }
        if (cnt != 1)
            return true;
    }
    return false;
}

static int error_handling(char **file)
{
    if (!file || word_array_len(file) < 1) {
        return EXIT_ERROR;
    }
    for (int i = 0; file[i] != NULL; i++)
        if (allow_char(file[i], " \t0123456789-"))
            return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static int get_size_map(sfVector2i *size_map, char **file)
{
    char **line = my_str_to_word_array(file[0], " ");

    if (!line)
        return EXIT_ERROR;
    if (word_array_len(line) != 2) {
        word_array_destroy(line);
        return EXIT_ERROR;
    }
    size_map->x = my_getnbr(line[0]);
    size_map->y = my_getnbr(line[1]);
    word_array_destroy(line);
    if (size_map->x < 2 || size_map->y < 2)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static int load_map_data(map_t *map_load, char **file)
{
    if (word_array_len(file) > 1)
        fill_map(map_load, file[1]);
    if (word_array_len(file) > 2)
        fill_map_texture(map_load, file[2]);
    return EXIT_SUCCESS;
}

int load_map(const char *filepath, map_t *map)
{
    map_t map_load;
    char **file = my_read_file(filepath);
    sfVector2i size_map = {0};

    if (my_file_ext_cmp(filepath, MAP_EXTENSION) == false)
        return puterr("Load ISO map : wrong file extension\n", EXIT_ERROR);
    if (error_handling(file))
        return puterr("Load ISO Map fail\n", EXIT_ERROR);
    if (get_size_map(&size_map, file))
        return puterr("Load ISO map : Invalid size map\n", EXIT_ERROR);
    if (map_create(&map_load, size_map.y, size_map.x))
        return puterr("Load ISO map : Fail to create map\n", EXIT_ERROR);
    load_map_data(&map_load, file);
    word_array_destroy(file);
    map_destroy(map);
    *map = map_load;
    map->modified = true;
    if (map_update(map) == EXIT_FAILURE)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
