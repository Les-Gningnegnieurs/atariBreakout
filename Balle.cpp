#include "Balle.h"
Balle::Balle(LevelInfos I)
{
    pos.x = I.pos_Ball_iniX;
    pos.y = I.pos_Ball_iniY;
    oldPosX = pos.x;
    oldPosY = pos.y;
    speed.y =-1;
    speed.x = -1;
    rayon = I.ball_radius;
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

void Balle:: draw(char UI[RESMAX_Y][RESMAX_X])
{
    UI[getoldPosY()][getoldPosX()] = ' '; //espace a l'ancienne pos de la balle
    UI[getPos().y][getPos().x] = 'O'; //update la nouvelle pos de la balle dans l'array 
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

