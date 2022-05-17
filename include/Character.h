#ifndef CHARACTER_H
#define CHARACTER_H

#include <CommonFunc.h>
#include <BaseObject.h>
#include <windows.h>

const int GRAVITY_FALL = 2;
class Character : public BaseObject
{
    public:
        Character();
        virtual ~Character();
        bool jump(SDL_Event e);
        void shown(SDL_Renderer *screen);
        void update();
        void moving();
        void setDead(const bool& isDead);
        void reset();
        bool getDead(){return dead;};
    private:
        int xpos;
        int ypos;
        int yval;
        int characterHeight;
        int characterWidht;
        bool dead;
};

#endif // CHARACTER_H
