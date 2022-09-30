#include "../inc/game.h"

// 

int mx_spawn_wave(enemy_t **enemies, float *last_spawn_time, float x) {
	int cd = 4000;
	if (x >= 5)
		cd = 3000;
	if (x >= 10)
		cd = 2000;
	if (x >= 15)
		cd = 1000;
	if ( cd + *last_spawn_time <= SDL_GetTicks() ) {
		*last_spawn_time = SDL_GetTicks();
		int ran = rand() % 10;
		int i = 0;
		for ( ; enemies[i] != NULL; i++) {}
		
		if (ran >=0 && ran <=4 && i != 100) {
			enemies[i] = mx_make_en(1, x);
			return 1;
		}
		if (ran >=5 && ran <=7 && i != 100) {
			enemies[i] = mx_make_en(2, x);
			return 1;
		}
		if (ran >=7 && ran <=10 && i != 100) {
			enemies[i] = mx_make_en(3, x);
			return 1;
		}
	}
	return 0;
}

