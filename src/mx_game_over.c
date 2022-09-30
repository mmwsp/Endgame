#include "../inc/game.h"


int  mx_game_over(enemy_t **enemy, int finish) {
    int count = finish;
    for(int i = 0; enemy[i] != NULL; i++) {
   	 if (enemy[i]->x >= 765  && enemy[i]->y >= 525) {
    		count++;
            enemy[i]->health = -111222;
    	}
    }
      
    return count;
}

