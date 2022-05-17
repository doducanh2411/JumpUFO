#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <CommonFunc.h>

class BaseObject
{
    public:
        BaseObject();
        virtual ~BaseObject();
        void loadFromFile(std::string path, SDL_Renderer *screen);
        void render(SDL_Renderer *ren = NULL, int degrees = 0);
        void SetRect(const int& x, const int& y) {rect.x=x, rect.y=y;}
        int getX(){return rect.x;};
        int getY(){return rect.y;};
        int getW(){return rect.w;};
        int getH(){return rect.h;};
        bool checkCollision(BaseObject a, BaseObject b);
        void free();
    protected:
        SDL_Texture *mTexture;
        SDL_Rect rect;
};

#endif // BASEOBJECT_H
