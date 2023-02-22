#include "Balle.h"
Balle::Balle(float ray, int x, int y)
{
    pos.x=x;
    pos.y=y;
    speed.y=5;
    speed.x=5;
    rayon=ray;
    maxSpeed=10; // à définir plus tard;

}
void Balle:: update(float timeElapsed)
{

    if(speed.x>maxSpeed) speed.x=maxSpeed;
    else if(speed.x<-maxSpeed) speed.x=-maxSpeed;
    if(speed.y>maxSpeed) speed.y=maxSpeed;
    else if(speed.y<-maxSpeed) speed.y=-maxSpeed;
    pos.x+= timeElapsed*speed.x;
    pos.y+=timeElapsed*speed.y;
}


void Balle:: draw()
{
    std::cout<< "la vitesse en x est de "<<speed.x<< " la vitesse en y est de "<< speed.y<<std::endl;
    std::cout<< "la position en x est "<<pos.x<<" la position en y est "<<pos.y<<std::endl;

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







