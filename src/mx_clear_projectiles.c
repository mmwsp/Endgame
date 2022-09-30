#include "../inc/game.h"

// removes projectiles that have already hit the target or whose target has disappeared

void mx_clear_projectiles(projectile_t **projectiles) {
    if (projectiles == NULL) 
        return;

    for (int i = 0; projectiles[i] != NULL; i++) {

        if (projectiles[i]->aim == NULL) {

           // projectile_t *del = projectiles[i];
	    free(projectiles[i]);
            for (int j = i; projectiles[j] != NULL || i == j; j++) { // 

                if ( projectiles[j + 1] != NULL) {
		    
                    projectiles[j] = projectiles[j + 1];
                }
                else {
                    projectiles[j] = NULL;
                    break;
                }
            }

          //  free(del);

        }
    }
}

