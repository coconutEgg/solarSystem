#ifndef _SOLARSYSTEM_H_
#define _SOLARSYSTEM_H_
#include <GL/glut.h>
#include <cstring>
/*---Linear Algebra---*/
/*(1) The essence of the matrix is describing the 
motivation of an item */

#define PI 3.1415926

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
    GLfloat rgbaColor[4];

    //parent star
    Star *parentStar;

    Star(GLfloat radius, GLfloat distance, 
        GLfloat speed, GLfloat selfSpeed,
        Star *parentStar):parentStar(parentStar),
        radius(radius), speed(speed), selfSpeed(selfSpeed),
        distance(distance)
        {
            for(int i = 0 ; i < 4; i ++ )
            {
                this->rgbaColor[i] = 1.0f;
            }

            if(speed > 0)
            {
                this->speed = 360.0f /speed;
            }
            else
            {
                this->speed = 0;
            }
        };

    //the function to draw for general stars
    void drawStar();
    //set drawStar() as the default function
    virtual void draw() { drawStar(); };

    virtual void update( long timeSpan);
protected:
    GLfloat alphaSelf, alpha;
};

class Planet : public Star
{
public:
    Planet(GLfloat radius, GLfloat distance, 
        GLfloat speed, GLfloat selfSpeed,
        Star *parentStar, GLfloat rgbColor[3]):
        Star(radius, distance, speed, selfSpeed, parentStar)
        {
            for(int i = 0; i < 3 ; i ++ )
            {
                this->rgbaColor[i] = rgbaColor[i];
            }
            rgbaColor[3] = 1.0f;
        };


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
    LightPlanet(GLfloat radius, GLfloat distance, 
        GLfloat speed, GLfloat selfSpeed,
        Star *parentStar, GLfloat rgbColor[3]):
        Planet(radius, distance, speed, selfSpeed, parentStar, rgbColor)
        {};

    void drawLight();
    virtual void draw()
    {
        drawLight();
        drawPlanet();
        drawStar();
    };
};

#endif