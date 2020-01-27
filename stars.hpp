#ifndef _SOLARSYSTEM_H_
#define _SOLARSYSTEM_H_
#include <GL/glut.h>

class Star
{
public:
    //revolution radius
    GLfloat radius;

    //revolution speed and rotation speed
    GLfloat speed, selfSpeed;

    //distance betweem the parent star
    GLfloat distance;

    //color of the planet
    GLfloat rgbColor[4];

    //parent star
    Star *parentStar;

    //general constructor
    Star(const GLfloat radius = 10, const GLfloat distance = 10,
         const GLfloat speed = 10, const GLfloat selfSpeed = 10,
         Star *parentStar = NULL) : radius(radius), distance(distance),
                                    speed(speed), selfSpeed(selfSpeed),
                                    parentStar(parentStar){};

    //--copy construct

    //--copy assignment

    //the function to draw for general stars
    void drawStar();
    //set drawStar() as the default function
    virtual void draw() { drawStar(); };

protected:
    GLfloat alphaSelf, alpha;
};

class Planet : public Star
{
public:
    //general constructor
    Planet(const GLfloat radius = 10, const GLfloat distance = 10,
           const GLfloat speed = 10, const GLfloat selfSpeed = 10,
           Star *parentStar = NULL, const GLfloat rgbColor[3] = {0})
        : Star(radius, distance, speed, selfSpeed, parentStar)
    {
        //deal with rgbColor
    }
    //--copy constructor

    //--copy assignment

    //define the function to draw a planet
    void drawPlanet();

    //its child can still overwrite the draw()
    virtual void draw()
    {
        drawPlanet();
        drawStar();
    };
};

class LightPlanet : public Planet
{
public:
    LightPlanet(const GLfloat radius = 10, const GLfloat distance = 10,
                const GLfloat speed = 10, const GLfloat selfSpeed = 10,
                Star *parentStar = NULL, const GLfloat rgbColor[] = {0})
                {
                    this->radius = radius;
                    this->distance = distance;
                    this->speed = speed;
                    this->selfSpeed = selfSpeed;
                    this->parentStar = parentStar;
                    //deal with the rgbColor
                }
    void drawLight();
    virtual void draw(){drawLight(); drawPlanet(); drawStar();};
};

#endif