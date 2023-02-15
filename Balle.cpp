#include "Balle.h"
Balle::Balle(float ray)
{
    pos.x=0;
    pos.y=0;
    speed.y=0;
    speed.x=0;
    rayon=ray;
    maxSpeed=10; // à définir plus tard;

}
void Balle:: update(float timeElapsed)
{

    if(speed.x>maxSpeed) speed.x=maxSpeed;
    else if(speed.x<-maxSpeed) speed.x=-maxSpeed;
    if(speed.y>maxSpeed) speed.y=maxSpeed;
    else if(speed.y<-maxSpeed) speed.y=-maxSpeed;
    position.x+= timeElapsed*speed.x;
    position.y+=timeElapsed*speed.y;
}


void Balle:: draw()
{
    cout<< "la vitesse en x est de "<<speed.x<< " la vitesse en y est de "<< speed.y<<endl;
    cout<< "la position en x est "<<pos.x<<" la position en y est "<<pos.y<<endl;

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






