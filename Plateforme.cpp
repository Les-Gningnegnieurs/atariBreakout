#include "Plateforme.h"

Plateforme:: Plateforme(int length, int height)
{
    sizeX= length;
    sizeY= height;
    tiltAngle=0;
    maxSpeed=10; // à déterminer
    speed.x=0;
    speed.y=0;
    pos.x=0;
    pos.y=0;  // je sais pas s'il y a moyen de forcer la valeur à être consante étant donné que la struct n'est pas const
}

void Plateforme:: move(int joystickvalueX)
{
    // calcul à verifier (512 est la valeur quand le joystick est au "repos")

    speed.x= ((joystickvalueX-512)*maxSpeed)/512;
}

void Plateforme::update(float timeElapsed)
{
    pos.x+= speed.x*timeElapsed;

}

void Plateforme::draw()
{
    std::cout<<"Plateforme de"<< sizeX<< " de longeur et "<< sizeY<< "de hauteur"<<std::endl;
    std::cout<<"La position est:"<<pos.x<<" la vitesse est:"<<speed.x<<std::endl;

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