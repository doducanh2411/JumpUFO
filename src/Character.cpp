#include "Character.h"

Character::Character()
{
    xpos = 90;
    ypos = 1;
    yval = 0;
    characterHeight = 64;
    characterWidht = 64;
    dead = false;
}

Character::~Character()
{
    BaseObject::free();
}
void Character::shown(SDL_Renderer *screen){
    loadFromFile("res//image//UFO.png", screen);
    xpos = 90;
    rect.x = xpos;
    rect.y = ypos;
    rect.w = characterWidht;
    rect.h = characterHeight;
    render(screen);
}

bool Character::jump(SDL_Event e){
    if(e.type == SDL_KEYDOWN){
        if (e.key.keysym.sym == SDLK_SPACE){
            yval = -20;
            return true;
        }
    }else{
        return false;
    }
}
void Character::moving(){
    yval += GRAVITY_FALL;
    ypos += yval;
}
void Character::setDead(const bool& isDead){
    dead = isDead;
    if(ypos <= 0 || ypos >= SCREEN_HEIGHT - 64) dead = true;
}
void Character::reset(){
    xpos = 90;
    ypos = 1;
    yval = 0;
    dead = false;
}


