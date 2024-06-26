#include <SDL.h>
#include <SDL_TTF.h>
#include <SDL_IMAGE.h>
#define PLAYER_SPEED 5
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


typedef struct {int x; int y;} Vec2;

typedef struct CONTROLER {
    Vec2 DIR;

} CONTROLER;


CONTROLER initController() {
    CONTROLER controller;
    controller.DIR = (Vec2) { 0.0, 0.0 };
    return controller;
}


typedef struct {
    int x;
    int y;
} Player;

Player initPlayer(int x, int y) {
    Player player;
    player.x = x;
    player.y = y;
    return player;
}




int handle_events(SDL_Window* win, SDL_Renderer* rend, CONTROLER* CONTROLER) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            SDL_DestroyRenderer(rend);
            SDL_DestroyWindow(win);
            SDL_Quit();
            return 1;}
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_UP)
            CONTROLER->DIR.y = -1 * PLAYER_SPEED;
            if (event.key.keysym.sym == SDLK_DOWN)
            CONTROLER->DIR.y = 1 * PLAYER_SPEED;
            if (event.key.keysym.sym == SDLK_LEFT)
            CONTROLER->DIR.x = -1 * PLAYER_SPEED;
            if (event.key.keysym.sym == SDLK_RIGHT)
            CONTROLER->DIR.x = 1 * PLAYER_SPEED;}
        if (event.type == SDL_KEYUP) {
            if (event.key.keysym.sym == SDLK_UP)
            CONTROLER->DIR.y = 0 * PLAYER_SPEED;
            if (event.key.keysym.sym == SDLK_DOWN)
            CONTROLER->DIR.y = 0 * PLAYER_SPEED;
            if (event.key.keysym.sym == SDLK_LEFT)
            CONTROLER->DIR.x = 0 * PLAYER_SPEED;
            if (event.key.keysym.sym == SDLK_RIGHT)
            CONTROLER->DIR.x = 0 * PLAYER_SPEED;}
    }
    return 0;
}

int update_player(CONTROLER* CONTROLER, Player* PLAYER) {
    if (PLAYER->x + 10 + CONTROLER->DIR.x < SCREEN_WIDTH && 
    PLAYER->x + CONTROLER->DIR.x > 0)
    PLAYER->x += CONTROLER->DIR.x;
    if (PLAYER->y+10+CONTROLER->DIR.y < SCREEN_HEIGHT && 
    PLAYER->y+CONTROLER->DIR.y > 0)
    PLAYER->y += CONTROLER->DIR.y;
}
