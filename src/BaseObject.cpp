#include "BaseObject.h"

BaseObject::BaseObject()
{
    rect.x = 0;
    rect.y = 0;
    rect.h = 0;
    rect.w = 0;
    mTexture = NULL;
}

BaseObject::~BaseObject()
{
    free();
}
void BaseObject::loadFromFile(std::string path, SDL_Renderer *screen){
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    SDL_Texture *resTexture;
    resTexture = SDL_CreateTextureFromSurface(screen, loadedSurface);
    rect.w = loadedSurface->w;
    rect.h = loadedSurface->h;
    mTexture = resTexture;
    SDL_FreeSurface(loadedSurface);
}
void BaseObject::render(SDL_Renderer *ren, int degrees){

    SDL_Rect renderQuad = {rect.x, rect.y, rect.w, rect.h};
    SDL_RenderCopyEx( ren, mTexture, NULL, &renderQuad, degrees, 0, SDL_FLIP_NONE );
}
bool BaseObject::checkCollision(BaseObject a, BaseObject b){
    bool frag = true;

    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = a.getX();
    rightA = a.getX() + a.getW();
    topA = a.getY();
    bottomA = a.getY() + a.getH();

    leftB = b.getX();
    rightB = b.getX() + b.getW();
    topB = b.getY();
    bottomB = b.getY() + b.getH();

    if( bottomA <= topB ){
        frag = false;
    }

    if( topA >= bottomB ){
        frag = false;
    }

    if( rightA <= leftB ){
        frag = false;
    }

    if( leftA >= rightB ){
        frag = false;
    }
    return frag;
}

void BaseObject::free(){
    if(mTexture != NULL){
        rect.x = 0;
        rect.y = 0;
        rect.h = 0;
        rect.w = 0;
        mTexture = NULL;
    }
}
