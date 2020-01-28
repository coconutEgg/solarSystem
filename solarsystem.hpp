#ifndef _SOLARSYSTEM_
#define _SOLARSYSTEM_

#include "stars.hpp"

#define STARS_NUM 10
#define TIMEPAST 1
#define SELFROTATE 3

#define REST 700
#define REST_Y (-REST)
#define REST_Z (REST)

enum STARS
{
    Sun,
    Mercury,
    Venus,
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

    GLdouble viewX, viewY, viewZ;       //相当于头的坐标位置;
    GLdouble centerX, centerY, centerZ; //相当于物体的坐标位置;
    GLdouble upX, upY, upZ;             //相当于头顶朝上的方向向量
};


#endif