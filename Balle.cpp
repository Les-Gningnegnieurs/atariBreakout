#include "Balle.h"
Balle::Balle(float ray, int x, int y)
{
    pos.x=3;
    pos.y=7;
    speed.y = -10;
    speed.x=-10;
    rayon=ray;
    maxSpeed=10; // à définir plus tard;

}
void Balle:: update(float timeElapsed)
{

    if(speed.x>maxSpeed) speed.x=maxSpeed;
    else if(speed.x<-maxSpeed) speed.x=-maxSpeed;
    if(speed.y>maxSpeed) speed.y=maxSpeed;
    else if(speed.y<-maxSpeed) speed.y=-maxSpeed;
   // if (timeElapsed >= 100)timeElapsed = 100;
    pos.x+= (timeElapsed*speed.x)/1000;
    pos.y+=(timeElapsed*speed.y)/1000;
}


void Balle:: draw(std::ostream &s)
{
    
  s<<"o";
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







