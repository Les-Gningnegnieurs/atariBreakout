#include "Plateforme.h"
Plateforme::Plateforme() {
}
Plateforme::Plateforme(LevelInfos I)
{
    sizeX = I.Plat_length;
    sizeY = I.Plat_heigth;
    rows = I.rows;
    columns = I.columns;
    tiltAngle = 0;
    maxSpeed = 1; // à déterminer
    speed.x = 0;
    speed.y = 0;
    pos.x = I.pos_Plat_iniX;
    pos.y = I.pos_Plat_iniY;  // je sais pas s'il y a moyen de forcer la valeur à être consante étant donné que la struct n'est pas const
}

void Plateforme::move(int joystickvalueX)
{
    // calcul à verifier (512 est la valeur quand le joystick est au "repos")

    speed.x = joystickvalueX;
}

void Plateforme::update()
{
    pos.x += speed.x;
    //revérifier ces limites (pas bon d'avoir des valeurs hardcodé
    if (pos.x >= columns - 1 - sizeX)
        pos.x = columns - sizeX - 1;
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
        UI[rows - 1][i] = '_';
    }
}




void Plateforme::checkCollision(Balle *b)
{
    //l'implémentation dépend de ou se situe notre point d'ancrage.
    //j'assumes qu'il est dans le coin gauche inférieur.
    if (b->getPos().y + b->getrayon() >= pos.y)
    {
        if (pos.x <= b->getPos().x && pos.x + sizeX / 2 >= b->getPos().x) //on est a gauche
        {
            if (b->getSpeed().x >= 0) b->changeVelocity(1, 1);//il allait vers la droite
            else b->changeVelocity(0, 1);
        }
        else if (pos.x + sizeX / 2 <= b->getPos().x && pos.x + sizeX >= b->getPos().x) {
            if (b->getSpeed().x <= 0) b->changeVelocity(1, 1);//il allait vers la gauche
            else b->changeVelocity(0, 1);
        }
            
    }
}