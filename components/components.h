/// Fichier qui contient les structs des différents composants de la manette
struct Joystick {
    int x;
    int y;
};

struct Bargraph{
    bool status[10];
};

struct LedRGB{
    int status;
    int R;
    int G;
    int B;
};

struct Accelerometre{
    int x;
    int y;
    int z;
};

struct OuputChanged{
    bool leds;
    bool bargraph;
};