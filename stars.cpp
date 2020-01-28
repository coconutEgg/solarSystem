#include "stars.hpp"
#include <cmath>
/*@Implementation for class Star*/
void Star::drawStar()
{
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);

    int n = 1440;

    //save the current matrix state 
    glPushMatrix();

    //if it is a satellite
    if(parentStar != NULL && parentStar->distance > 0)
    {   
        //rotate around the axis Z
        glRotatef(parentStar->alpha, 0,0,1);
        //translate on the x axis
        glTranslatef(parentStar->distance,0.0, 0.0);
    }

    
    glBegin(GL_LINES);
    for(int i = 0 ; i < n ; i ++ )
    {
        glVertex2f(distance *cos(2*PI*i/n), distance*sin(2*PI*i/n) );
    }

    glEnd();
    
    //rotate alpha around the axis z
    glRotatef(alpha, 0, 0, 1);
    //translate along the x by the distance
    glTranslatef(distance, 0 ,0);
    //revolution
    glRotatef(alphaSelf, 0, 0, 1);

    //color the star
    glColor3f(rgbaColor[0], rgbaColor[1], rgbaColor[2]);
    glutSolidSphere(radius, 40, 32);

    glPopMatrix();
}

void Star::update(long timeSpan)
{
    alpha += timeSpan * speed;
    alphaSelf += selfSpeed;
}

/*Implementation for class Planet*/
void Planet::drawPlanet()
{
    GLfloat mat_ambient[] = {0.0f, 0.0f, 0.5f, 1.0f};
    GLfloat mat_diffuse[] = {0.0f, 0.0f, 0.5f, 1.0f};
    GLfloat mat_specular[] = {0.0f, 0.0f, 1.0f, 1.0f};
    GLfloat mat_emission[] = {rgbaColor[0], rgbaColor[1], rgbaColor[2], rgbaColor[3]};
    GLfloat mat_shininess = 90.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_EMISSION,  mat_emission);
    glMaterialf (GL_FRONT, GL_SHININESS, mat_shininess);
}

void LightPlanet::drawLight()
{
    GLfloat light_position[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat light_ambient[]  = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat light_diffuse[]  = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position); // 指定零号光源的位置
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);  // 表示各种光线照射到该材质上，经过很多次反射后追踪遗留在环境中的光线强度
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);  // 漫反射后的光照强度
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
}