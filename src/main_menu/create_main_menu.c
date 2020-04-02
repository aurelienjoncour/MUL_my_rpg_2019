/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_main_menu
*/

#include "my_rpg.h"

static const char *play_path[] = {
    "asset/sprite/buttons/play.png",
    "asset/sprite/buttons/play_h.png",
    "asset/sprite/buttons/play_c.png",
    NULL,
};

static const char *quit_path[] = {
    "asset/sprite/buttons/quit.png",
    "asset/sprite/buttons/quit_h.png",
    "asset/sprite/buttons/quit_c.png",
    NULL,
};

static const char *option_path[] = {
    "asset/sprite/buttons/option.png",
    "asset/sprite/buttons/option_h.png",
    "asset/sprite/buttons/option_c.png",
    NULL,
};

static const sfVector2f button_s = {300, 75};

static const sfVector2f button_p[3] = {
    {500, 400},
    {500, 500},
    {500, 600}
};

const char *font = "asset/font/MADETOMMY.ttf";

static int set_main_menu_button(game_t *game)
{
    int ret = 0;

    ret += set_texture_button(game->ui.main_menu->play, play_path);
    ret += set_texture_button(game->ui.main_menu->quit, quit_path);
    ret += set_texture_button(game->ui.main_menu->option, option_path);
    ret += set_button_label(game->ui.main_menu->play, "play", font, 50);
    ret += set_button_label(game->ui.main_menu->quit, "quit", font, 50);
    ret += set_button_label(game->ui.main_menu->option, "option", font, 50);
    return ret;
}

int create_main_menu(game_t *game)
{
    game->ui.main_menu = malloc(sizeof(main_menu_t));
    if (game->ui.main_menu == NULL)
        return EXIT_ERROR;
    game->ui.main_menu->play = create_button(button_p[0], button_s);
    game->ui.main_menu->quit = create_button(button_p[1], button_s);
    game->ui.main_menu->option = create_button(button_p[2], button_s);
    if (game->ui.main_menu->play == NULL || !game->ui.main_menu->quit
        || !game->ui.main_menu->option)
        return EXIT_ERROR;
    if (set_main_menu_button(game) != EXIT_SUCCESS)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
