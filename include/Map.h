#ifndef MAP_H
#define MAP_H

#include <CommonFunc.h>
#include <BaseObject.h>

const int DISTANCE = 190;
const int TYPES = 3;
const int QUANTITY = 8;
class Asteroid : public BaseObject
{
    public:
        Asteroid();
        ~Asteroid();
        void set_x_pos(const int& x_pos){xpos = x_pos;};
        void set_y_pos(const int& y_pos){ypos = y_pos;};
        int get_x_pos(){return xpos;};
        int get_y_pos(){return ypos;};
    private:
        int ypos;
        int xpos;
};

class Map : public BaseObject
{
    public:
        void setAsteroidTex(SDL_Renderer *screen);
        void renderMap(SDL_Renderer *screen);
        void setAsteroidPos();
        void reset();
        bool collision(BaseObject a);
        int getPoint(){return point;}
    private:
        Asteroid asteroid[10];
        int speed = 5;
        int point = 0;
        int degrees = 0;
};
#endif // MAP_H
