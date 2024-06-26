#define FRAMERATE 1000/60
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define CENTER_X (SCREEN_WIDTH / 2)
#define CENTER_Y (SCREEN_HEIGHT / 2)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>
#include <SDL_TTF.h>
#include <SDL_IMAGE.h>
#include "controller.h"



SDL_Texture* load_BMP_image(SDL_Window* win, SDL_Renderer* rend) {
    SDL_Surface* image = SDL_LoadBMP("image.bmp");
    SDL_Renderer* render = SDL_CreateRenderer(win, -1, 0);
    SDL_Texture* BACKGROUND_TEXTURE = SDL_CreateTextureFromSurface(rend, image);
}

void init_SDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
        printf("error initializing SDL: %s\n", SDL_GetError());
}


int main(int argc, char* argv[]) {
    init_SDL();
    SDL_Window* win = SDL_CreateWindow("GAME", 
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture* BACKGROUND_TEXTURE = load_BMP_image(win, rend);
    SDL_Rect BACKRenderer = {CENTER_X-(SCREEN_WIDTH/4), CENTER_Y-(SCREEN_HEIGHT/4), 
    (SCREEN_WIDTH/2), (SCREEN_HEIGHT/2)};

    CONTROLER CONTROLER = initController();
    Player PLAYER = initPlayer(CENTER_X, CENTER_Y);
    while (1) {
        int events_info = handle_events(win, rend, &CONTROLER);
        update_player(&CONTROLER, &PLAYER);

        if (events_info != 0)return events_info;
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, BACKGROUND_TEXTURE, NULL, &BACKRenderer);

        SDL_Rect rect = {PLAYER.x, PLAYER.y, 10, 10};
        SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
        SDL_RenderDrawRect(rend, &rect);
        SDL_RenderFillRect(rend, &rect);
        SDL_RenderPresent(rend); 
        SDL_Delay(FRAMERATE);
    }
    return 0;
}
