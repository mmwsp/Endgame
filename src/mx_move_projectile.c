#include "../inc/game.h"
// moves projectiles or deals damage if the projectile hits the target

void mx_move_projectile(projectile_t **projectiles) {
    if (projectiles == NULL) 
        return;
        
    for (int i = 0; projectiles[i] != NULL; i++) {

        if (projectiles[i]->aim != NULL) {
            if (projectiles[i]->aim->health <= 0) {
                projectiles[i]->aim = NULL;
                continue;
            }
            float enemy_hitbox_range = 0;
            // do not change
            float range = (float)sqrt( pow( (projectiles[i]->aim->x - projectiles[i]->x), 2) + pow( (projectiles[i]->aim->y  - projectiles[i]->y), 2) );
            // if range prj - aim <= speed -> hit enemy
            if (projectiles[i]->speed + enemy_hitbox_range >= range) {
                
                projectiles[i]->aim->health -= projectiles[i]->damage;
                projectiles[i]->aim = NULL;
            }
            else { // else move prj to aim
                float lambda = projectiles[i]->speed / ( range - projectiles[i]->speed );
                projectiles[i]->x = ( (projectiles[i]->x + (lambda * projectiles[i]->aim->x) ) / (1 + lambda) );
                projectiles[i]->y = ( (projectiles[i]->y + (lambda * projectiles[i]->aim->y) ) / (1 + lambda) );
            }
        }
    }
}

