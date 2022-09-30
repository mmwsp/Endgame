#include "../inc/game.h"

// removes projectiles that have already hit the target or whose target has disappeared

void mx_clear_enemies(enemy_t **enemies, int *money, int *score) {
    if (enemies == NULL) 
        return;

    for (int i = 0; enemies[i] != NULL; i++) {

        if (enemies[i]->health <= 0) {
            if (enemies[i]->health > -100000 && enemies[i]->health <= 0) {
                (*money)++;
                (*score)++;
            }
	        free(enemies[i]);
            for (int j = i; enemies[j] != NULL || i == j; j++) { // 

                if ( enemies[j + 1] != NULL) {
		    
                    enemies[j] = enemies[j + 1];
                }
                else {
                    enemies[j] = NULL;
                    break;
                }
            }
        }
    }
}

