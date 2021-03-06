/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-28T08:36:54+01:00 | Author: simon
*/

#ifndef H_GAME
#define H_GAME

#include "game_t.h"

void game_destroy(game_t *game);
int game_create(game_t *game);

int game_loop(game_t *game);

void call_event_manager(game_t *game, sfEvent *event);

float as_seconds(sfClock *clock);
void event_window_close(game_t *game);
bool is_key_released(sfEvent *event, sfKeyCode key);
bool is_key_pressed(sfEvent *event, sfKeyCode key);

// SUB MENU EVENT
void submenu_event_manager(game_t *game, sfEvent *event);

#endif
