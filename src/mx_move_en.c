#include "../inc/game.h"

void mx_move_en(enemy_t **enemy) {
    for(int i = 0; enemy[i] != NULL; i++) {
        if(enemy[i]->x <= 135 && enemy[i]->y == 225) {
            enemy[i]->x += enemy[i]->speed;
        }
        else if(enemy[i]->x >= 135 && enemy[i]->y <= 450 && enemy[i]->x <= 200) {
            enemy[i]->y += enemy[i]->speed;
        }
        else if(enemy[i]->x <= 435  && enemy[i]->y >= 450) {
            enemy[i]->x += enemy[i]->speed;
        }
        else if(enemy[i]->x >= 435  && enemy[i]->y >= 75 && enemy[i]->x <= 500) {
            enemy[i]->y -= enemy[i]->speed;
        }    
        else if(enemy[i]->x <= 585  && enemy[i]->y <= 75) {
            enemy[i]->x += enemy[i]->speed;
        }
        else if(enemy[i]->x >= 585  && enemy[i]->y <= 525) {
            enemy[i]->y += enemy[i]->speed;
        }      
        else if(enemy[i]->x <= 790  && enemy[i]->y >= 525) {
            enemy[i]->x += enemy[i]->speed;
        }  
    }
    
}

