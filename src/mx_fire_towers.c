#include "../inc/game.h"

// target search, target shooting, target switching

void mx_fire_towers(tower_t **towers, projectile_t **projectiles, enemy_t **enemies, float current_time) {
    if (projectiles == NULL || towers == NULL || enemies == NULL) 
        return;

    for (int i = 0; towers[i] != NULL; i++) {
    
        if (towers[i]->target == NULL) { // if no target 
        
            for (int j = 0; enemies[j] != NULL; j++) { // find enemy

                if (enemies[j]->health > 0 && towers[i]->range >= sqrt( pow( (enemies[j]->x - towers[i]->x), 2) + pow( (enemies[j]->y - towers[i]->y), 2) )) {         

                    towers[i]->target = enemies[j];
                }
            }
        }
        else if (towers[i]->target->health <= 0 || towers[i]->range <= sqrt( pow( (towers[i]->target->x - towers[i]->x), 2) + pow( (towers[i]->target->y - towers[i]->y), 2) )) {

            towers[i]->target = NULL;
            for (int j = 0; enemies[j] != NULL; j++) { // find enemy

                if ( enemies[j]->health > 0 && towers[i]->range >= sqrt( pow( (enemies[j]->x - towers[i]->x), 2) + pow( (enemies[j]->y - towers[i]->y), 2) )) {

                    towers[i]->target = enemies[j];
                }
            }
        }
        if (towers[i]->target != NULL) {

            if (towers[i]->last_fire_time + towers[i]->cooldown <= current_time) {

                int j = 0;
                for ( ; projectiles[j] != NULL; j++) {}

                projectiles[j] = (projectile_t *)malloc( sizeof(projectile_t) );
                projectiles[j]->aim = towers[i]->target;
                projectiles[j]->x = towers[i]->x;
                projectiles[j]->y = towers[i]->y;
                projectiles[j]->speed = towers[i]->prjctl->speed;
                projectiles[j]->damage = towers[i]->prjctl->damage;
                projectiles[j]->tex_main_path = towers[i]->prjctl->tex_main_path;

                towers[i]->last_fire_time = current_time;
            }
        }
    }
    
    
}

