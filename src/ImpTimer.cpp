#include "ImpTimer.h"

ImpTimer::ImpTimer()
{
    start_tick = 0;
}


void ImpTimer::start(){
    start_tick = SDL_GetTicks();
}
int ImpTimer::get_ticks(){
    return SDL_GetTicks() - start_tick;
}
