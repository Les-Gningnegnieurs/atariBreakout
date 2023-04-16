#include "Balle.h"
Balle::Balle(LevelInfos I, QGraphicsScene* scene, int rand) :_scene(scene)
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
    circle->setBrush(getRandColor(rand));
    _scene->addItem(circle);
}
Balle::Balle(QGraphicsScene* scene, Position posB, int radius, int speedX, int speedY, int rand) :_scene(scene) {
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
    circle->setBrush(getRandColor(rand));
    _scene->addItem(circle);
}

QBrush Balle::getRandColor(int rand) {
    switch (rand % 16)
    {
    case 0:
        return QColor(64,224,208); //turquoise
        break;
    case 1: 
        return QColor(0, 168, 107); //jade
        break;
    case 2:
        return QColor(0, 15, 137); //phtalloblue
        break;
    case 3:
        return QColor(220, 20, 60); //cramoisi
        break;
    case 4:
        return QColor(36, 68, 92);
        break;
    case 5:
        return QColor(56, 148, 178); //bleu ceruleen
        break;
    case 6:
        return QColor(26, 140, 102); //vert viridien 26, 140, 102
        break;
    case 7:
        return QColor(92, 58, 147);    //violet dioxazine
        break;
    case 8:
        return QColor(34, 120, 15);    //vert de vessie
        break;
    case 9:
        return QColor(223, 175, 44);     //jaune ocre
        break;
    case 10:
        return QColor(248, 235, 0);    // jaune cadmium
        break;
    case 11:
        return QColor(88, 65, 15);    //jaune indien
        break;
    case 12:
        return QColor(218, 40, 41);     //rouge pyrol
        break;
    case 13:
        return QColor(103, 113, 121);      //gris de payne
        break;
    case 14:
        return QColor(69, 73, 78);     //GRIS DE GRAPHITE  
        break;
    case 15:
        return QColor(8, 24, 31);     //violet quiller
        break;
    }
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