#include <iostream>
#include "Motor.h"
#include "AdmTexturas.h"
#include "Warrior.h"

using namespace std;

Motor* Motor::s_Instancia = nullptr;
Warrior* player = nullptr;

bool Motor::init()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
    {
        SDL_Log("Falla en inicializar SDL: %s", SDL_GetError());
        return false;
    }

    m_window = SDL_CreateWindow("JUEGO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WiDTH, SCREEN_HEIGHT, 0);
    if(m_window == nullptr)
    {
        SDL_Log("Falla en crear Window: %s", SDL_GetError());
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(m_renderer == nullptr)
    {
        SDL_Log("Falla en crear renderer: %s", SDL_GetError());
        return false;
    }

    AdmTexturas::getInstancia()->cargar("player", "propiedades/guerrero2.png");
    //jugador = new Guerrero(new Propiedades("player", 100, 200, 136, 96));
    player = new Warrior(new Properties("player", 100, 200, 136, 96));

    Transform tf;
    tf.Log();
    return m_estaFuncionando = true;
}

void Motor::update()
{
    player->Update(0);
}

void Motor::render()
{
    SDL_SetRenderDrawColor(m_renderer, 124, 218, 254, 255);
    SDL_RenderClear(m_renderer);

    //AdmTexturas::getInstancia()->draw("tree", 100, 100, 347, 465);
    player->Draw();
    SDL_RenderPresent(m_renderer);
}

void Motor::eventos()
{
    SDL_Event evento;
    SDL_PollEvent(&evento);
    switch(evento.type)
    {
    case SDL_QUIT:
        salir();
        break;
    }
}

bool Motor::clean()
{
    AdmTexturas::getInstancia()->clean();
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    IMG_Quit();
    SDL_Quit();
}

void Motor::salir()
{
    m_estaFuncionando = false;
}


