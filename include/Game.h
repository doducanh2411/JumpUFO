#ifndef GAME_H
#define GAME_H

#include <CommonFunc.h>
#include <BaseObject.h>
#include <Character.h>
#include <Map.h>
#include <ImpTimer.h>
#include <Text.h>
class Game
{
    public:
        void init(const char* title, int xpos, int ypos, int width, int height);
        void showMenu();
        void setUp();
        void handleEvent();
        void logic();
        void render();
        void gameLoop();
        void setFps(ImpTimer fps_timer);
        void clean();
        bool isRunning(){
            return running;
        };
    private:
        bool running;
};

#endif // GAME_H
