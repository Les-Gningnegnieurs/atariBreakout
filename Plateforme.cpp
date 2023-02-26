#include "Plateforme.h"
Plateforme::Plateforme() {
    sizeX = 0;
    sizeY = 0;
    tiltAngle = 0;
    maxSpeed = 10; // à déterminer
    speed.x = 0;
    speed.y = 0;
    pos.x = 30;
    pos.y = 20;
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

    speed.x= joystickvalueX;
}

void Plateforme::update()
{   
    pos.x += speed.x;

    //revérifier ces limites (pas bon d'avoir des valeurs hardcodé
    if (pos.x >= 128)
        pos.x = 64;
    else if (pos.x <= 0)
        pos.x = 0;

}

void Plateforme::draw(std::ostream&s)
{
    std::stringstream ss;
    ss << s.rdbuf();
    std::string myString = ss.str();
    for (int i = pos.x; i < pos.x + sizeX; i++)
    {
        myString[i] = '_';
    }
    s.flush();
    s << myString;
}




bool Plateforme::checkCollision(Position posHit)
{
    //l'implémentation dépend de ou se situe notre point d'ancrage.
    //j'assumes qu'il est dans le coin gauche inférieur.
    if(posHit.y>=pos.y)
    {
        if((posHit.x>=pos.x)&&(posHit.x<=pos.x+sizeX)) return true;
    }

    return false;
}