#ifndef TEXT_H
#define TEXT_H

#include <CommonFunc.h>
#include <BaseObject.h>
class Text : public BaseObject
{
    public:
        Text();
        virtual ~Text();
        void LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen);
        void Free();

        void SetColor(Uint8 red=0, Uint8 green=0, Uint8 blue=0);

        void RenderText(SDL_Renderer *screen, int xpos, int ypos);

        int getWidth() const { return width; }
        int getHeight() const { return height; }

        void SetText(const std::string& text) {textContent = text;}
        std::string GetText() const { return textContent; }
    private:
        std::string textContent;
        SDL_Color textColor;
        SDL_Texture* texture_;
        int width;
        int height;
};

#endif // TEXT_H
