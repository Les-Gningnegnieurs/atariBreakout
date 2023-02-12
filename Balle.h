//
// Created by stao0901 on 2023-02-11.
//
#define PI 3.14159
struct Position {
    int x;
    int y;
};
struct Velocity {
    int x;
    int y;
};

#ifndef UNTITLED_BALLE_H
#define UNTITLED_BALLE_H
class Balle{
private:
    Position pos;
    float rayon;
    Velocity speed;
public:
    Balle(float ray);
    float aire() {return rayon*rayon*PI;}
    void update(float timeElapsed);
    void draw();
    Position getPos() {return pos;}
    bool checkCollision();
    void outOfBounds();


};

#endif //UNTITLED_BALLE_H
