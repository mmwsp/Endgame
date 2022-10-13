#include "../inc/game.h"

int mx_game(SDL_Window *window, SDL_Renderer *renderer) {

    tower_t **towers = (tower_t **)malloc( sizeof(tower_t *) * 50 );
    for(int i = 0; i < 50; i++) {
        towers[i] = NULL;
    }
    projectile_t **projectiles = (projectile_t **)malloc( sizeof(projectile_t *) * 500 );
    for(int i = 0; i < 500; i++) {
        projectiles[i] = NULL;
    }
    enemy_t **enemies = (enemy_t **)malloc( sizeof(enemy_t *) * 100 );
    for(int i = 0; i < 100; i++) {
        enemies[i] = NULL;
    }

    int base_health = 10;
    int money = 10;
    int score = 0;

    int arr[7][10] = { { 1, 1, 1, 1, 1, 9, 9, 9, 1, 1},
                       { 1, 1, 1, 1, 1, 9, 1, 9, 1, 1},
                       { 9, 9, 1, 1, 1, 9, 1, 9, 1, 1},
                       { 1, 9, 1, 1, 1, 9, 1, 9, 1, 1},
                       { 1, 9, 1, 1, 1, 9, 1, 9, 1, 1},
                       { 1, 9, 9, 9, 9, 9, 1, 9, 1, 1},
                       { 1, 1, 1, 1, 1, 1, 1, 9, 9, 9} };
    int price_arr[3] = { 5, 10, 20};

    int current_ui_x = 0;
    int current_ui_y = 0;
    int current_ts_x = 1;
    float last_spawn_time = SDL_GetTicks() + 6000;
    int finish = 0;
    
    

    SDL_Surface *map = IMG_Load("resources/map1.png");
    SDL_Texture *map_txtr = SDL_CreateTextureFromSurface(renderer, map); //create and make texture of map
    SDL_FreeSurface(map);
    
    int wave = 0;
    float mod = 1;

    int inner_menu = 0;
    SDL_Event windowEvent;
    while (SDL_QUIT != windowEvent.type) {

        if ( SDL_PollEvent(&windowEvent) ) {
            if (SDL_QUIT == windowEvent.type) {
                break;
            }
            else if (SDL_KEYDOWN == windowEvent.type) { 
                if (SDL_SCANCODE_LEFT == windowEvent.key.keysym.scancode && inner_menu == 0) { // <- 
                    if (current_ui_x != 0) 
                        current_ui_x--;
                }
                else if (SDL_SCANCODE_LEFT == windowEvent.key.keysym.scancode && inner_menu == 1) {
                    if (current_ts_x != 0) 
                        current_ts_x--;
                }
                if (SDL_SCANCODE_RIGHT == windowEvent.key.keysym.scancode && inner_menu == 0) { // -> 
                    if (current_ui_x != 9) 
                        current_ui_x++;
                }
                else if (SDL_SCANCODE_RIGHT == windowEvent.key.keysym.scancode && inner_menu == 1) {
                    if (current_ts_x != 2) 
                        current_ts_x++;
                }
                if (SDL_SCANCODE_UP== windowEvent.key.keysym.scancode && inner_menu == 0) {
                    if (current_ui_y != 0) 
                        current_ui_y--;
                }
                if (SDL_SCANCODE_DOWN == windowEvent.key.keysym.scancode && inner_menu == 0) {
                    if (current_ui_y != 6) 
                        current_ui_y++;
                }
                if (SDL_SCANCODE_SPACE == windowEvent.key.keysym.scancode && inner_menu == 0) {
                    if (arr[current_ui_y][current_ui_x] == 1) {
                        inner_menu = 1;
                        current_ts_x = 1;
                    }
                }
                else if (SDL_SCANCODE_SPACE == windowEvent.key.keysym.scancode && inner_menu == 1) {
                    if ( price_arr[current_ts_x] <= money ) { // check money -> if enough adt etc  place tower 
                        int i = 0;
         	            for ( ; towers[i] != NULL; i++) {}
                        towers[i] = mx_make_tower(current_ts_x + 1, 50/2 + 75*current_ui_x + 75/2, 75/2 + 75*current_ui_y + 75/2);
                        inner_menu = 0;
                        arr[current_ui_y][current_ui_x] = 2;
                        money -= price_arr[current_ts_x];
                    }
                }
                if (SDL_SCANCODE_ESCAPE == windowEvent.key.keysym.scancode && inner_menu == 0) {
                    if ( 0 ) { // menu
                        
                    }
                }
                else if (SDL_SCANCODE_ESCAPE == windowEvent.key.keysym.scancode && inner_menu == 1) {
                    inner_menu = 0;
                }
            }
        }
        else {
            SDL_RenderClear(renderer);

            SDL_RenderCopy(renderer, map_txtr, NULL, NULL);
            
            mx_render_ui(renderer, current_ui_x, current_ui_y);
            finish = mx_game_over(enemies, finish);
            
            if (wave / 25 == 1) {
                mod += mod / 3;
                wave = 0;
            }
            wave += mx_spawn_wave(enemies, &last_spawn_time, mod + (wave / 30) );

            mx_move_en(enemies);
            mx_clear_projectiles(projectiles);
            mx_clear_enemies(enemies, &money, &score);

 
            mx_fire_towers(towers, projectiles, enemies, SDL_GetTicks());
            mx_move_projectile(projectiles);
            mx_render_ttfs(renderer, money, (base_health - finish), score);

            
            mx_tower_render(renderer, towers);
            mx_projectile_render(renderer, projectiles);
            mx_enemy_render(renderer, enemies); //render of the test unit
            if (inner_menu == 1) {
                mx_render_tower_selection(renderer, current_ui_x, current_ui_y, current_ts_x); 
            }
            if(finish == base_health) {
                SDL_DestroyTexture(map_txtr);
                SDL_Surface *finish = IMG_Load("resources/finish.png");
                SDL_Texture *finish_txtr = SDL_CreateTextureFromSurface(renderer, finish); //create and make texture of map
                SDL_FreeSurface(finish);
                SDL_RenderCopy(renderer, finish_txtr, NULL, NULL);
                SDL_RenderPresent(renderer); 
                SDL_Delay(3000);
                return 1;
            }
            SDL_RenderPresent(renderer); 
         // SDL_Delay(5);

        }
    }
    //free malloc mem

    for(int i = 0; i < 50; i++) {
        free(towers[i]);
    }
    for(int i = 0; i < 500; i++) {
        free(projectiles[i]);
    }
    for(int i = 0; i < 100; i++) {
        free(enemies[i]);
    }
    free(towers);
    free(projectiles);
    free(enemies);
    
    
    SDL_DestroyTexture(map_txtr);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow( window );
    SDL_Quit();
    return 0;

}

