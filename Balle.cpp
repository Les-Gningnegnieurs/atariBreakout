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
    //
    if(speed.x>maxSpeed) speed.x=maxSpeed;
    else if(speed.x<-maxSpeed) speed.x=-maxSpeed;
    if(speed.y>maxSpeed) speed.y=maxSpeed;
    else if(speed.y<-maxSpeed) speed.y=-maxSpeed;
    position.x+= timeElapsed*speed.x;
    position.y+=timeElapsed*speed.y;
}





