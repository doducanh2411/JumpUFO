#include "Text.h"

Text::Text()
{
    textColor.r = 255;
    textColor.g = 255;
    textColor.b = 255;
    texture_ = NULL;
}

Text::~Text()
{
    BaseObject::free();
}

void Text::LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen)
{
    SDL_Surface* textSurface = TTF_RenderText_Solid( font, textContent.c_str(), textColor );
    SDL_Texture* resTexture;
    resTexture = SDL_CreateTextureFromSurface(screen, textSurface);
    width = textSurface->w;
    height = textSurface->h;
    texture_ = resTexture;
    SDL_FreeSurface(textSurface);
}

void Text::Free()
{
    if (texture_ != NULL)
    {
        SDL_DestroyTexture(texture_);
        texture_ = NULL;
    }
}

void Text::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
    textColor.r = red;
    textColor.g = green;
    textColor.b = blue;
}

void Text::RenderText(SDL_Renderer *screen, int xpos, int ypos)
{
    SDL_Rect renderQuad = { xpos, ypos, width, height };
    SDL_RenderCopy(screen, texture_, NULL, &renderQuad);
}
