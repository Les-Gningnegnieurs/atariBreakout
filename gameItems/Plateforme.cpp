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
    /*QPixmap pixmap("ressources/bar1.png");
    QPixmap scaledPixmap = pixmap.scaled(sizeX,sizeY,Qt::KeepAspectRatioByExpanding);
    rect = new QGraphicsPixmapItem(scaledPixmap);
    rect->setPos(0, 0);*/
    rect = new Plati(sizeX, sizeY);
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
    speed.x = joystickvalueX*12;
}

void Plateforme::update()
{
    pos.x += speed.x;
    
    if (pos.x >= Window_X - sizeX)
        pos.x = Window_X - sizeX;
    else if (pos.x <= 0)
        pos.x = 0;
}

void Plateforme::draw()
{

    rect->setPos(pos.x, pos.y);
}
void Plateforme::setLenght(int l)
{ 
    sizeX = l; 
    delete rect;
    rect = new Plati(sizeX, sizeY, "ressources/bar2.png");
    rect->setPos(pos.x, pos.y);
    _scene->addItem(rect);

}


void Plateforme::checkCollision(Balle *b)
{
    //l'implémentation dépend de ou se situe notre point d'ancrage.
    //j'assumes qu'il est dans le coin gauche inférieur.
    Position posBa = b->getPos();
    int rayon = b->getrayon();
    Velocity speed = b->getSpeed();
    int middleX = (pos.x + (sizeX-1) / 2);
    int middleY = (pos.y + (sizeY - 1) / 2);
    if (posBa.y + rayon * 2 >= pos.y && posBa.y + rayon * 2 < pos.y + sizeY && speed.y > 0) //+ facile de hit la plateforme(pogne le côté aussi)
    {
        if (posBa.x + 2 * rayon >= pos.x && posBa.x <= pos.x + sizeX - 1)
        {
            float angle = atan2(posBa.y + rayon - middleY,
                posBa.x + rayon - middleX);
            b->platVelocity(angle);
        }
    }

    
}
