//
// Created by stao0901 on 2023-02-11.
//

#ifndef UNTITLED_PLATEFOME_H
#define UNTITLED_PLATEFOME_H
struct Position {
    int x;
    int y;
};
struct Velocity {
    int x;
    int y;
};

class Plateform {
private:
    Position pos;
    Velocity speed;
    int sizeX;
    int sizeY;
    int tiltAngle;
    int maxSpeed;
public:
    bool checkCollision();
    void update(float timeElapsed);
    void move(int joystickvalueX);
    void draw();



};

#endif //UNTITLED_PLATEFOME_H
