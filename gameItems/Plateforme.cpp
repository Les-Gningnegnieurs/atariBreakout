#include "Plateforme.h"
Plateforme::Plateforme() {
}
Plateforme::Plateforme(LevelInfos I, QGraphicsScene* scene) : _scene(scene)
{
    Window_X = I._windowResolutionX;
    Window_Y = I._windowResolutionY;
    sizeX = I.Plat_length;
    sizeY = I.Plat_heigth;
    rows = I.rows;
    columns = I.columns;
    speed.x = 0;
    speed.y = 0;
    pos.x = I.pos_Plat_iniX;
    pos.y = I.pos_Plat_iniY;
    //pos.x = I.pos_Plat_iniX;  //si on marche en pixels
    //pos.y = I.pos_Plat_iniY;  //pixels
    rect = new QGraphicsRectItem(0,0, sizeX, sizeY);
    rect->setBrush(Qt::gray);
    rect->setPos(pos.x, pos.y);
    _scene->addItem(rect);
    /*rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();*/

}
void Plateforme::update2(){
}
void Plateforme::move2() {
}
void Plateforme::move(int joystickvalueX)
{
    speed.x = joystickvalueX*2;
}

void Plateforme::update()
{
    pos.x += speed.x;
    
    if (pos.x >= Window_X - sizeX)
        pos.x = Window_X - sizeX;
    else if (pos.x <= 0)
        pos.x = 0;
    draw();
}

void Plateforme::draw()
{

    rect->setPos(pos.x, pos.y);
}




void Plateforme::checkCollision(Balle *b)
{
    //l'implémentation dépend de ou se situe notre point d'ancrage.
    //j'assumes qu'il est dans le coin gauche inférieur.
    Position posBa = b->getPos();
    int rayon = b->getrayon();
    Velocity speed = b->getSpeed();
    int middle_R = pos.x + (sizeX) / 2;
    int middle_L = middle_R-1;
    //if (posBa.y == pos.y - rayon && speed.y > 0)  //- facile de hit la plateforme
    if (posBa.y >= pos.y - rayon && speed.y > 0) //+ facile de hit la plateforme(pogne le côté aussi)
    {
        if (posBa.x >= pos.x - rayon  && posBa.x < middle_L) //gauche
        {
            if (posBa.x == pos.x-rayon && speed.x > 0)    //coin gauche
                b->setVelocity(-1, -1);
            else if (posBa.x >= pos.x  && posBa.x < middle_L && speed.x >= 0)  //renvoie du meme bord si allait vers la droite (
                b->setVelocity(-1, -1); //&& posBa.x < middle_L est une condition inutile
            else if(posBa.x >= pos.x && posBa.x < middle_L && speed.x <= 0)
                b->changeVelocity(0, 1);    //sinon change juste le y
        }
        else if (posBa.x == middle_L || posBa.x == middle_R)   //si dans un des milieux
            b->setVelocity(0, -1); //renvoyer straigth
        else if(posBa.x > middle_R && posBa.x <= pos.x + sizeX) //droite
        {
            if (posBa.x == pos.x + sizeX && speed.x < 0)   //coin droit
                b->setVelocity(1, -1);
            else if (posBa.x > middle_R &&posBa.x <= pos.x + (sizeX-1) && speed.x <= 0) //renvoie du meme bord si allait vers la gauche
                b->setVelocity(1, -1);
            else if(posBa.x > middle_R && posBa.x <= pos.x + (sizeX - 1) && speed.x >= 0)
                b->changeVelocity(0, 1);    //sinon change juste le y
        }
    }
}
