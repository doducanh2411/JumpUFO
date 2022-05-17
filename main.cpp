#include <iostream>
#include <CommonFunc.h>
#include <Game.h>

Game game;

int main(int argc, char *argv[]){
    game.init("Jump UFO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED ,SCREEN_WIDTH, SCREEN_HEIGHT);
    game.setUp();
    game.showMenu();
    while(game.isRunning()){
        game.gameLoop();
    }
    game.clean();
    return 0;
}
