#include "Plateforme.h"
Plateforme::Plateforme() {
}
Plateforme::Plateforme(LevelInfos I)
{
    sizeX = I.Plat_length;
    sizeY = I.Plat_heigth;
    rows = I.rows;
    columns = I.columns;
    speed.x = 0;
    speed.y = 0;
    pos.x = I.pos_Plat_iniX;
    pos.y = I.pos_Plat_iniY;  
}

void Plateforme::move(int joystickvalueX)
{
  

    speed.x = joystickvalueX;
}

void Plateforme::update()
{
    pos.x += speed.x;
    
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
        UI[rows - 1][i] = '#';
    }
}




void Plateforme::checkCollision(Balle *b)
{
    //l'implémentation dépend de ou se situe notre point d'ancrage.
    //j'assumes qu'il est dans le coin gauche inférieur.
    if (b->getPos().y + b->getrayon() == pos.y - 1)
    {
        if (b->getPos().x + b->getrayon() >= pos.x && b->getPos().x - b->getrayon() <= pos.x + sizeX) // on frappe la plateforme
        {
            if (b->getPos().x == pos.x + sizeX / 2 || b->getPos().x == pos.x + sizeX / 2 - 1)//milieu POSITION:(2 et 3)
                b->setVelocity(0, -1); //straight

            else if (pos.x == b->getPos().x) //coin gauche dans tt les cas on l'envoie a gauche POSITION:(0)
            {
                b->setVelocity(-1, -1);
            }
            else if (b->getPos().x == pos.x + sizeX - 1) // coin droit on l'envoie a droite POSITION:(5)
            {
                b->setVelocity(1, -1);
            }
            else if (b->getPos().x == pos.x + 1) //normal gauche (entre coin et milieu) POSITION:1
            {
                if (b->getSpeed().x > 0)
                    b->changeVelocity(1, 1);
                else
                    b->changeVelocity(0, 1);
            }
            else if (b->getPos().x == pos.x + sizeX - 2) //normal droit (entre coin et milieu) POSITION:4
            {
                if (b->getSpeed().x < 0)
                    b->changeVelocity(1, 1);
                else
                    b->changeVelocity(0, 1);
            }


            //if (pos.x + sizeX / 2 >= b->getPos().x) //on est a gauche
            //{
            //    if (b->getSpeed().x >= 0) b->changeVelocity(1, 1);//il allait vers la droite
            //    else b->changeVelocity(0, 1);
            //}
            //else //on est a droite
            //{
            //    if (b->getSpeed().x <= 0) b->changeVelocity(1, 1);//il allait vers la gauche
            //    else b->changeVelocity(0, 1);
            //}
        }
    }
}
