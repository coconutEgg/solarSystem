#ifndef _SOLARSYSTEM_H_
#define _SOLARSYSTEM_H_
#include <GL/glut.h>
#include <cstring>

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

    Star(GLfloat radius, GLfloat distance, 
        GLfloat speed, GLfloat selfSpeed,
        Star *parentStar);

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
        Star *parentStar, GLfloat rgbColor[3]);

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
        Star *parentStar, GLfloat rgbColor[]);

    void drawLight();
    virtual void draw()
    {
        drawLight();
        drawPlanet();
        drawStar();
    };
};

#endif