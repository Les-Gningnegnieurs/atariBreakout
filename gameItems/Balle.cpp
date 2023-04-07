#include "Balle.h"
Balle::Balle(LevelInfos I, QGraphicsScene* scene) :_scene(scene)
{
    pos.x = I.pos_Ball_iniX;
    pos.y = I.pos_Ball_iniY;
    oldPosX = pos.x;
    oldPosY = pos.y;
    speed.y = I.speed_B_y;
    speed.x = I.speed_B_x;
    rayon = I.ball_radius;
    circle = new QGraphicsEllipseItem(pos.x, pos.y,rayon*2,rayon*2);
    circle->setBrush(Qt::magenta);
    _scene->addItem(circle);
}
Balle::Balle(QGraphicsScene* scene, Position posB, int radius, int speedX, int speedY) :_scene(scene) {
    pos.x = posB.x;
    pos.y = posB.y;
    oldPosX = pos.x;
    oldPosY = pos.y;
    speed.y = speedY;
    speed.x = speedX;
    rayon = radius;
    circle = new QGraphicsEllipseItem(pos.x, pos.y, rayon * 2, rayon * 2);
    circle->setBrush(Qt::magenta);
    _scene->addItem(circle);
}
void Balle::update()
{
    int speedX;
    int speedY;
    speedX = 1 * speed.x;
    speedY = 1 * speed.y;
    oldPosX = pos.x;
    oldPosY = pos.y;

    pos.x += speedX;
    pos.y += speedY;
   
}

void Balle:: draw()
{
    circle->setPos(pos.x, pos.y);
}


bool Balle::checkCollision(Position posHit)
{
    double distance = sqrt(pow( posHit.x- pos.x, 2) + pow(posHit.y - pos.y, 2));
    if(distance<=rayon) return true;
    return false;


}

void Balle::changeVelocity(bool x, bool y){
    if(x)
        speed.x *= -1;
    
    if(y)
        speed.y *= -1;
}

void Balle::setVelocity(int x, int y) {
    speed.x = x;
    speed.y = y;
}