#ifndef ADMTEXTURAS_H
#define ADMTEXTURAS_H

#include <string>
#include "SDL.h"
#include <map>

class AdmTexturas
{
    public:
        static AdmTexturas* getInstancia()
        {
            return s_Instancia = (s_Instancia != nullptr)? s_Instancia : new AdmTexturas();
        }

        bool cargar(std::string id, std::string filename);
        void drop(std::string id);
        void clean();

        void draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip=SDL_FLIP_NONE);
        void drawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip=SDL_FLIP_NONE);

    private:
        AdmTexturas(){}
        std::map<std::string, SDL_Texture*> m_textureMap;
        static AdmTexturas* s_Instancia;
};

#endif // ADMTEXTURAS_H
