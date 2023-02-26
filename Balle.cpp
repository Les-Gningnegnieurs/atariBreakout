#include "Balle.h"
Balle::Balle(float ray, int x, int y)
{
    pos.x = 40;
    pos.y = 12;
    speed.y =-1;
    speed.x= -1;
    rayon=ray;
    maxSpeed=12; // à définir plus tard;

}
void Balle::update()
{
    float speedX;
    float speedY;
    speedX = 1 * speed.x;
    speedY = 1 * speed.y;

    pos.x += speedX;
    pos.y += speedY;
}

void Balle:: draw(std::ostream &s)
{
    
        std::stringstream ss;
        ss << s.rdbuf();
        std::string myString = ss.str();
        myString[(pos.x * pos.y) + pos.y] = 'O';
        s.flush();
        s << myString;
    
    
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







