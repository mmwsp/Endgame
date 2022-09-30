#pragma once

#include "../inc/sdl/SDL.h"
#include "../inc/sdl/SDL_image.h"
#include "../inc/sdl/SDL_timer.h"
#include "../inc/sdl/SDL_ttf.h"
#include "../inc/structures.h"
#include "../inc/gun1.h"

#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include <fcntl.h>

int mx_game(SDL_Window *window, SDL_Renderer *renderer);
void mx_menu(SDL_Window *window, SDL_Renderer *renderer);
void mx_enemy_render(SDL_Renderer *renderer, enemy_t **enemy);
void mx_move_en(enemy_t **enemy);
enemy_t *mx_make_en(int type, float x);
tower_t *mx_make_tower(int type, int x, int y);
void mx_tower_render(SDL_Renderer *renderer, tower_t **tower );
void mx_projectile_render(SDL_Renderer *renderer, projectile_t **projectile );
void mx_clear_enemies(enemy_t **enemies, int *money, int *score);

int mx_spawn_wave(enemy_t **enemies, float *last_spawn_time, float x);
void mx_render_ui(SDL_Renderer *renderer, int m_x, int m_y);
void mx_render_tower_selection(SDL_Renderer *renderer, int m_x, int m_y, int s_x);
int  mx_game_over(enemy_t **enemy,int finish);
void mx_render_ttfs(SDL_Renderer *renderer, int money, int health, int score);

