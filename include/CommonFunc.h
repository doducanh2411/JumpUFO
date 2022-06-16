#ifndef COMMONFUNC_H
#define COMMONFUNC_H


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_rect.h>

#define SCREEN_HEIGHT 640
#define SCREEN_WIDTH 800

const int FRAME_PER_SECOND = 50 ;

static SDL_Window *gWindow = NULL;
static SDL_Renderer *gRenderer = NULL;
static TTF_Font *gFont = NULL;

static Mix_Chunk* gMusic = NULL;
static Mix_Chunk* gDie = NULL;
static Mix_Chunk* gJump = NULL;

int getBestPoint();
void fixBestPoint(int newPoint);
int get_random(int a, int b);
#endif // COMMONFUNC_H
