#include "Balle.h"
Balle::Balle(float ray)
{
    pos.x=0;
    pos.y=0;
    velocity.y=10;
    velocity.x=0;
    rayon=ray;

}
void Balle:: update(float timeElapsed)
{
    position.x+= timeElapsed*speed.x;
    position.y+=timeElapsed*speed.y;
}


