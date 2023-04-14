#include "Balle.h"
Balle::Balle(LevelInfos I, QGraphicsScene* scene) :_scene(scene)
{
    pos.x = I.pos_Ball_iniX;
    pos.y = I.pos_Ball_iniY;
    oldPosX = pos.x;
    oldPosY = pos.y;
    speed.y = I.speed_B_x;
    speed.x = I.speed_B_y;
    rayon = I.ball_radius;
    MaxSpeed = I.maxspeed_B;
    circle = new QGraphicsEllipseItem(0,0,rayon*2,rayon*2);
    circle->setPos(pos.x, pos.y);
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
    MaxSpeed = sqrt(pow(speed.x, 2) + pow(speed.y, 2));
    circle = new QGraphicsEllipseItem(0,0,rayon*2, rayon*2);
    circle->setPos(pos.x, pos.y);
    circle->setBrush(Qt::magenta);
    _scene->addItem(circle);
}
Balle::~Balle() {
    delete circle;
}

void Balle::update()
{
    checkCollision(pos);
    int speedX;
    int speedY;
    float current_speed = sqrt(pow(speed.x,2) + pow(speed.y,2));
    float speed_ratio = current_speed / MaxSpeed;
    speedX = round(speed_ratio * speed.x);
    speedY = round(speed_ratio * speed.y);
    oldPosX = pos.x;
    oldPosY = pos.y;

    pos.x += speedX;
    pos.y += speedY;
}

void Balle:: draw()
{
    circle->setPos(pos.x, pos.y);
    //qDebug() << pos.x << pos.y;
}


bool Balle::checkCollision(Position posHit)
{
    double distance = sqrt(pow(posHit.x - pos.x, 2) + pow(posHit.y - pos.y, 2));
    if (distance <= rayon) return true;
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
void Balle::platVelocity(float angle) {
    speed.x = round(MaxSpeed * cos(angle));
    speed.y = round(MaxSpeed * sin(angle));
    if (speed.y == 0)
        speed.y = -1;
}