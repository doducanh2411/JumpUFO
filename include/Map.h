#ifndef MAP_H
#define MAP_H

#include <CommonFunc.h>
#include <BaseObject.h>

const int DISTANCE = 190;
const int TYPES = 3;
class Asteroid : public BaseObject
{
    public:
        Asteroid();
        ~Asteroid();
        void set_x_pos(const int x_pos){xpos = x_pos;};
        void set_y_pos(const int y_pos){ypos = y_pos;};
        int get_x_pos(){return xpos;};
        int get_y_pos(){return ypos;};
    private:
        int ypos ;
        int xpos ;
};

class Map : public BaseObject
{
    public:
        void setAsteroidTex(SDL_Renderer *screen);
        void Render(SDL_Renderer *screen);
        void setAsteroidPos();
        void reset();
        bool collision(BaseObject a);
        int getPoint(){return point;}
    private:
        Asteroid asteroidTex[10];
        int point = 0;
        int speed = 5;
        int degrees = 0;
};
#endif // MAP_H
