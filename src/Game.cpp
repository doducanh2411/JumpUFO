#include "Game.h"

BaseObject background;
Character character;
Map myMap;
Text point;
Text highestPoint;
ImpTimer fps_timer;

void Game::init(const char* title, int xpos, int ypos, int width, int height){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL could not initialize: " << SDL_GetError() ;
        running = false;
    }else{
        if(!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ){
			std::cout << "Linear texture filtering not enabled!";
		}
		gWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if(gWindow == NULL){
			std::cout <<  "Window could not be created!" << SDL_GetError() ;
			running = false;
		}else{
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if(gRenderer == NULL){
                std::cout << "Renderer could not be created!" << SDL_GetError();
                running = false;
            }else{
                int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) ){
					std::cout << "SDL_image could not initialize!" << IMG_GetError();
					running = false;
				}
				if( TTF_Init() == -1 )
                {
                    std::cout << "SDL_ttf could not initialize! SDL_ttf Error: %s\n" << TTF_GetError() ;
                    running = false;
                }else{
                      gFont = TTF_OpenFont("res//font//joystixmonospace.ttf",20);
                      if(gFont == NULL) running = false;
                }
                if ( SDL_Init(SDL_INIT_AUDIO) < 0 ) running = false;
                else if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) running = false;
            }
		}
    }
}
void Game::setUp(){
    gMusic = Mix_LoadWAV( "res//sound//theme1.wav" );
    gDie = Mix_LoadWAV( "res//sound//dead.wav" );
    gJump = Mix_LoadWAV("res//sound//jump.wav");

    background.loadFromFile("res//image//background.png", gRenderer);

    point.SetColor(255, 255, 255);
    highestPoint.SetColor(255, 255, 255);

    myMap.setAsteroidTex(gRenderer);
    myMap.setAsteroidPos();
    myMap.setAsteroidSpeed();
}
void Game::handleEvent(){
    SDL_Event e;
    SDL_PollEvent(&e);
    switch(e.type){
    case SDL_QUIT:
        running = false;
        break;
    }
    if(character.jump(e) == true) Mix_PlayChannel(-1, gJump, 0);
}
void Game::render(){
    background.render(gRenderer);

    point.RenderText(gRenderer, 0, 0);
    highestPoint.RenderText(gRenderer, 550, 0);

    character.moving();
    character.shown(gRenderer);

    myMap.renderMap(gRenderer);

    SDL_RenderPresent(gRenderer);
}
void Game::logic(){
    std::string myPoint = "Point: " + std::to_string(myMap.getPoint());
    point.SetText(myPoint);
    point.LoadFromRenderText(gFont, gRenderer);

    if(myMap.getPoint() > getBestPoint()) fixBestPoint(myMap.getPoint());

    std::string highPoint = "Best Point: " + std::to_string(getBestPoint());
    highestPoint.SetText(highPoint);
    highestPoint.LoadFromRenderText(gFont, gRenderer);

    std::string question = myPoint + ". Your best point is: " + std::to_string(getBestPoint()) + "\n" + "Do you want to restart ?";
    character.setDead(myMap.collision(character));
    if(character.getDead() == true){
        Mix_PlayChannel(-1, gDie , 0);
        int res = MessageBox(NULL, question.c_str(), "Game Over!", MB_YESNO);
        switch(res){
        case IDYES:
            myMap.reset();
            character.reset();
            break;
        case IDNO:
            running = false;
            break;
        }
    }
}
void Game::gameLoop(){
    fps_timer.start();
    handleEvent();
    logic();
    render();
    setFps(fps_timer);
}
void Game::clean(){
    Mix_FreeChunk( gJump ); gJump = NULL;
    Mix_FreeChunk( gDie ); gDie = NULL;
    Mix_FreeChunk( gMusic ); gMusic = NULL;
    background.free();
    character.free();
    myMap.free();
    point.free();
    highestPoint.free();
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}
void Game::setFps(ImpTimer fps_timer){
    int real_imp_time = fps_timer.get_ticks();
    int time_one_frame = 1000/FRAME_PER_SECOND;
    if (real_imp_time<time_one_frame)
    {
        int delay_time = time_one_frame - real_imp_time;
        if (delay_time >= 0) SDL_Delay(delay_time);
    }
}
void Game::showMenu(){
    Mix_PlayChannel( -1, gMusic, -1  );
    BaseObject menu;
    menu.loadFromFile("res//image//menu.png", gRenderer);
    menu.render(gRenderer);
    SDL_Event e;
    bool runMenu = true;
    while(runMenu){
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT) {runMenu = false; running = false;}
            if(e.type == SDL_KEYDOWN){
                if(e.key.keysym.sym == SDLK_SPACE){runMenu = false; running = true;};
            }
            SDL_RenderPresent(gRenderer);
        }
    }
}
