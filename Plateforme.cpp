#include "Plateforme.h"
Plateforme::Plateforme() {
    sizeX = 0;
    sizeY = 0;
    tiltAngle = 0;
    maxSpeed = 10; // à déterminer
    speed.x = 0;
    speed.y = 0;
    pos.x = x;
    pos.y = y;
}
Plateforme:: Plateforme(int length, int height, int x, int y)
{
    sizeX= length;
    sizeY= height;
    tiltAngle=0;
    maxSpeed=30; // à déterminer
    speed.x=0;
    speed.y=0;
    pos.x=x;
    pos.y=y;  // je sais pas s'il y a moyen de forcer la valeur à être consante étant donné que la struct n'est pas const
}

void Plateforme:: move(int joystickvalueX)
{
    // calcul à verifier (512 est la valeur quand le joystick est au "repos")

    speed.x= (joystickvalueX*maxSpeed)/100;
}

void Plateforme::update(float timeElapsed)
{
    pos.x+= speed.x*timeElapsed;

}

void Plateforme::draw(std::ostream &s)
{
    if(sizeX = 1)
        s << "_";

    for(int i = 1; i <sizeX-1; i++)
    {
        s << "-";
    }


    s << "|";
}


}

bool Plateforme::checkCollision(Position posHit)
{
    //l'implémentation dépend de ou se situe notre point d'ancrage.
    //j'assumes qu'il est dans le coin gauche inférieur.
    if(posHit.y<=pos.y+sizeY)
    {
        if((posHit.x>=pos.x)&&(posHit.x<=pos.x+sizeX)) return true;
    }

    return false;
}