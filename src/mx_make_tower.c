#include "../inc/game.h"

tower_t *mx_make_tower(int type, int x, int y) {
   if(type == 1) {
        projectile_t *projectile = (projectile_t *)malloc(sizeof(projectile_t));
        projectile -> speed = 10;
        projectile -> damage = 200;
        projectile -> tex_main_path = "resources/prj1.png";
        
        tower_t *tower = (tower_t *)malloc(sizeof(tower_t));
        
        tower->x = x;
        tower->y = y;
        tower->prjctl = projectile;
        tower->target = NULL;
        tower->range = 150;
        tower->cooldown = 1000;
        tower->last_fire_time = SDL_GetTicks();
        tower->tex_frame_path = "resources/tower1.png";
        return tower;
   }
   if(type == 2) {
        projectile_t *projectile = (projectile_t *)malloc(sizeof(projectile_t));
        projectile -> speed = 20;
        projectile -> damage = 120;
        projectile -> tex_main_path = "resources/prj3.png";
        
        tower_t *tower = (tower_t *)malloc(sizeof(tower_t));
        
        tower->x = x;
        tower->y = y;
        tower->prjctl = projectile;
        tower->target = NULL;
        tower->range = 180;
        tower->cooldown = 400;
        tower->last_fire_time = SDL_GetTicks();
        tower->tex_frame_path = "resources/tower3.png";
        return tower;
   }  
   if(type == 3) {
        projectile_t *projectile = (projectile_t *)malloc(sizeof(projectile_t));
        projectile -> speed = 30;
        projectile -> damage = 2000;
        projectile -> tex_main_path = "resources/prj2.png";
        
        tower_t *tower = (tower_t *)malloc(sizeof(tower_t));
        
        tower->x = x;
        tower->y = y;
        tower->prjctl = projectile;
        tower->target = NULL;
        tower->range = 270;
        tower->cooldown = 2000;
        tower->last_fire_time = SDL_GetTicks();
        tower->tex_frame_path = "resources/tower2.png";
        return tower;
   }
   return NULL;
}


