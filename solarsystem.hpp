#ifndef _SOLARSYSTEM_
#define _SOLARSYSTEM_

#include "stars.hpp"

#define STARS_NUM 10
#define TIMEPAST 1
#define SELFROTATE 3

enum STARS
{
    Sun,
    Mercury,
    Venuth,
    Earth,
    Moon,
    Mars,
    Jupiter,
    Saturn,
    Uranus,
    Neptune
};

class SolarSystem
{
    public:
    SolarSystem();
    ~SolarSystem();

    void onDisplay();
    void onUpdate();
    void onKeyboard(unsigned char key, int x, int y);

    private:
    Star *stars[STARS_NUM];

    //views: we need at least 9 parameters
    GLdouble viewx, viewY, viewZ;
    GLdouble centerX, centerY, centerZ;
    GLdouble upX, upY, upZ;

};


#endif