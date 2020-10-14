#ifndef WARRIOR_H
#define WARRIOR_H

#include "Personaje.h"

class Warrior: public Personaje
{
    public:
        Warrior(Properties* props);

        virtual void Draw();
        virtual void Clean();
        virtual void Update(float dt);

    private:
        int m_Row, m_Frame, m_FrameCount;
        int m_AnimSpeed;
};

#endif // WARRIOR_H
