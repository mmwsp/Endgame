#include "../inc/game.h"

enemy_t *mx_make_en(int type, float x) {
    if(type == 1) {
       enemy_t *enemy = (enemy_t *)malloc(sizeof(enemy_t));
       enemy->x = 10;
       enemy->y = 225;
       enemy->health = 1000 * x;
       enemy->speed = 1;
       enemy->tex_main_path = "resources/enemy.png";
       return enemy;
   }
   if(type == 2) {
       enemy_t *enemy = (enemy_t *)malloc(sizeof(enemy_t));
       enemy->x = 10;
       enemy->y = 225;
       enemy->health = 700 * x;
       enemy->speed = 1;
       enemy->tex_main_path = "resources/enemy1.png";
       return enemy;
   }  
   if(type == 3) {
       enemy_t *enemy = (enemy_t *)malloc(sizeof(enemy_t));
       enemy->x = 10;
       enemy->y = 225;
       enemy->health = 3000 * x;
       enemy->speed = 1;
       enemy->tex_main_path = "resources/enemy2.png";
       return enemy;
   }
   return NULL;
}

