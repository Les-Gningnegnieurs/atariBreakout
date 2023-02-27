#include "Balle.h"
Balle::Balle(float radius, int posX, int posY)
{
    pos.x = posX;
    pos.y = posY;
    oldPosX = pos.x;
    oldPosY = pos.y;
    speed.y =-1;
    speed.x = -1;
    rayon = radius;
    maxSpeed=12; // à définir plus tard;

}
void Balle::update()
{
    float speedX;
    float speedY;
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

void Balle::outOfBounds()
{
    //implémentation reste à définir;

}

void Balle::changeVelocity(bool x, bool y){
    if(x)
        speed.x *= -1;
    
    if(y)
        speed.y *= -1;
}







