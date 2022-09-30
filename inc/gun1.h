#ifndef  GUN1
#define GUN1



#include "structures.h"
#include <math.h>



void mx_fire_towers(tower_t **towers, projectile_t **projectiles, enemy_t **enemies, float current_time);
// target search, target shooting, target switching
/// current_time can be a timer !!!!!!!!!!!!!!!!!!!!
void mx_move_projectile(projectile_t **projectiles);
// moves projectiles or deals damage if the projectile hits the target
void mx_clear_projectiles(projectile_t **projectiles);
// removes projectiles that have already hit the target or whose target has disappeared

#endif

