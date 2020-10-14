#include "Warrior.h"
#include "AdmTexturas.h"
#include "SDL.h"

Warrior::Warrior(Properties* props): Personaje(props)
{
    m_Row = 1;
    m_FrameCount = 6;
    m_AnimSpeed = 80;
}

void Warrior::Draw()
{
    AdmTexturas::getInstancia()->drawFrame(m_TextureID, m_Transform->X, m_Transform->Y, m_Width, m_Height, m_Row, m_Frame);
}

void Warrior::Update(float dt)
{
    m_Frame = (SDL_GetTicks()/m_AnimSpeed)% m_FrameCount;
}

void Warrior::Clean()
{
    AdmTexturas::getInstancia()->clean();
}

