#ifndef  STRUCTURES
#define STRUCTURES

#include <stdbool.h>

typedef struct enemy_s {
    float health;
    int y;
    int x;
    float speed;
    char *tex_main_path;
    
}               enemy_t;

typedef struct projectile_s {
        int x;
        int y;
    float speed;
    float damage;
    
    enemy_t *aim;

    char *tex_main_path;
    //char *tex_effect_path;
}               projectile_t;

typedef struct tower_s {
        int x;
        int y;
    projectile_t *prjctl;
    enemy_t *target;
    
    float range;
    float cooldown;
    float last_fire_time;

    char *tex_frame_path;
    //char *tex_tower_path;
}               tower_t;

#endif

