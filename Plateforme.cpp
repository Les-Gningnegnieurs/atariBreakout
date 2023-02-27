#include "Plateforme.h"
Plateforme::Plateforme() {
}
Plateforme:: Plateforme(LevelInfos I)
{
    sizeX= I.Plat_length;
    sizeY= I.Plat_heigth;
    rows = I.rows;
    columns = I.columns;
    tiltAngle=0;
    maxSpeed=1; // à déterminer
    speed.x=0;
    speed.y=0;
    pos.x=I.pos_Plat_iniX;
    pos.y=I.pos_Ball_iniY;  // je sais pas s'il y a moyen de forcer la valeur à être consante étant donné que la struct n'est pas const
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

void Plateforme::draw(char UI[RESMAX_Y][RESMAX_X])
{
    //clear la ligne de la plateforme (plus simple que clear tout le UI
    for (int i = 0; i < columns; i++)
    {
        UI[rows - 1][i] = ' ';
    }
    for (int i = pos.x; i < pos.x + sizeX; i++)
    {
        UI[rows-1][i] = '_';
    }
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