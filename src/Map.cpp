#include "Map.h"

Asteroid::Asteroid(){
    xpos = 0;
    ypos = 0;
}
Asteroid::~Asteroid(){
    BaseObject::free();
}

void Map::setAsteroidTex(SDL_Renderer *screen){
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        int random = rand() % (TYPES - 1 + 1) + 1;
        std::string path = "res//image//asteroid" + std::to_string(random) + ".png";
        asteroidTex[i].loadFromFile(path, screen);
    }
}
void Map::setAsteroidPos(){
    for(int i = 0; i < 10; i++){
        asteroidTex[i].set_x_pos(DISTANCE * i + SCREEN_WIDTH);
    }
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        int random = rand() % (SCREEN_HEIGHT - 0 + 1) + 0;
        asteroidTex[i].set_y_pos(random);
    }
}

void Map::Render(SDL_Renderer *screen){
    int random = rand() % (SCREEN_HEIGHT - 0 + 1) + 0;
    for(int i = 0; i < 10; i++){
        asteroidTex[i].SetRect(asteroidTex[i].get_x_pos(), asteroidTex[i].get_y_pos());
        asteroidTex[i].render(screen, degrees);
        if(asteroidTex[i].get_x_pos() + asteroidTex[i].getW() < 0){
            asteroidTex[i].set_x_pos(SCREEN_WIDTH);
            asteroidTex[i].set_y_pos(random);
        }
    }
    for(int i = 0; i < 10; i++){
        if(asteroidTex[i].get_x_pos() == 90 ) point++;
        asteroidTex[i].set_x_pos(asteroidTex[i].get_x_pos() - speed);
    }
    degrees++;
}
bool Map::collision(BaseObject a){
    bool frag[10];
    bool fragg = false;
    for(int i = 0; i < 10; i++){
        frag[i] = checkCollision(a, asteroidTex[i]);
        if(frag[i] == true) fragg = true;
    }
    return fragg;
}
void Map::reset(){
    for(int i = 0; i < 10; i++){
        asteroidTex[i].set_x_pos(DISTANCE * i + SCREEN_WIDTH);
    }
    point = 0;
    speed = 5;
}


