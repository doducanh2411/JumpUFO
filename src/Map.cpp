#include "Map.h"

Asteroid::Asteroid(){
    xpos = 0;
    ypos = 0;
}
Asteroid::~Asteroid(){
    BaseObject::free();
}

void Map::setAsteroidTex(SDL_Renderer *screen){
    srand(time(0));
    for(int i = 0; i < QUANTITY; i++){
        int random = get_random(TYPES, 1);
        std::string path = "res//image//asteroid" + std::to_string(random) + ".png";
        asteroid[i].loadFromFile(path, screen);
        asteroid[i].set_id(random);
    }
}
void Map::setAsteroidPos(){
    srand(time(0));
    for(int i = 0; i < QUANTITY; i++){
        asteroid[i].set_x_pos(DISTANCE * i + SCREEN_WIDTH);
    }
    for(int i = 0; i < QUANTITY; i++){
        int random = get_random(SCREEN_HEIGHT, 0);
        asteroid[i].set_y_pos(random);
    }
}
void Map::setAsteroidSpeed(){
    for(int i = 0; i < QUANTITY; i++){
        switch (asteroid[i].get_id()){
        case 1: asteroid[i].set_speed(6); break;
        case 2: asteroid[i].set_speed(7); break;
        case 3: asteroid[i].set_speed(5); break;
        }
    }
}
void Map::renderMap(SDL_Renderer *screen){
    int random = get_random(SCREEN_HEIGHT, 0);
    for(int i = 0; i < QUANTITY; i++){
        asteroid[i].SetRect(asteroid[i].get_x_pos(), asteroid[i].get_y_pos());
        asteroid[i].render(screen, degrees);
        if(asteroid[i].get_x_pos() + asteroid[i].getW() < 0){
            asteroid[i].set_x_pos(SCREEN_WIDTH);
            asteroid[i].set_y_pos(random);
        }
    }
    for(int i = 0; i < QUANTITY; i++){
        if(asteroid[i].get_x_pos() == 90) point++;
        asteroid[i].set_x_pos(asteroid[i].get_x_pos() - asteroid[i].get_speed());
    }
    degrees++;
}
bool Map::collision(BaseObject a){
    bool frag[QUANTITY];
    bool fragg = false;
    for(int i = 0; i < QUANTITY; i++){
        frag[i] = checkCollision(a, asteroid[i]);
        if(frag[i] == true) fragg = true;
    }
    return fragg;
}
void Map::reset(){
    srand(time(0));
    for(int i = 0; i < QUANTITY; i++){
        asteroid[i].set_x_pos(DISTANCE * i + SCREEN_WIDTH);
    }
    for(int i = 0; i < QUANTITY; i++){
        int random = get_random(SCREEN_HEIGHT, 0);
        asteroid[i].set_y_pos(random);
    }
    point = 0;
}


