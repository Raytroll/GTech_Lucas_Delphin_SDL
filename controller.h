#ifndef CONTROLLER_H
#define CONTROLLER_H
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define FALSE 0
#define TRUE 1
#define max(a,b) (((a) > (b)) ? (a) : (b))
typedef struct {int x; int y;} Vec2;

typedef struct{
    Vec2 DIR;
} CONTROLER;



CONTROLER initController();


typedef struct {int x; int y;} Player;


Player initPlayer(int x, int y);

int handle_events(SDL_Window* win, SDL_Renderer* rend, CONTROLER* CONTROLER);

int update_player(CONTROLER* CONTROLER, Player* PLAYER);

#endif
