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
void Balle::update(float timeElapsed)
{
    float speedX;
    float speedY;
    speedX = ((timeElapsed * speed.x) / 100000);
    speedY = ((timeElapsed * speed.y) / 100000);

    if (speedX >= 1) speedX = 1;
    else if (speedX <= -1)speedX = -1;
    if (speedY >= 1)speedY = 1;
    else if (speedY <= -1)speedY = -1;

    pos.x += speedX;
    pos.y += speedY;
    if (pos.x >= 80)pos.x = 80;
    else if (pos.x <= 0)pos.x = 0;
    if (pos.y >= 25)pos.y = 25;
    else if (pos.y <= 0)pos.y;
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







