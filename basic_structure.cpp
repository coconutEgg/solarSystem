/* g++ main.cpp -o main -lGL -lGLU -lglut */

/*------------Introduction-----------------------------*/
/*#(1) OpenGL: Open Graphic Library; It has many 
*render functions; It is independent of any window 
*systems or operating Systems; It does not have most 
*of interactive functionality*/

/*#(2) GLUT: OpenGL Utility Toolkit: tool processing*
*OpenGL prpgram; deal with system calls, I/O, cross-*
*-platformwindow program and mouse event and keyboard event*/


/*@include the basic header of the GLUT*/
#include <GL/glut.h>

/*@macro for GUI window*/
#define WINDOW_X_POS 50
#define WINDOW_Y_POS 50
#define WIDTH 700
#define HEIGHT 700

/*@register call-backs for GLUT*/
void onDisplay(void);
void onUpdate(void);
void onKeyBoard(unsigned char key, int x, int y);

int main(int argc, char *argv[])
{
    //@---init the GLUT object using argc and argv
    glutInit(&argc, argv);
    
    //@----set the display mode
    //GLUT_SINGLE VS GLUT_DOUBLE: https://stackoverflow.com/questions/28298540/difference\
    -between-single-bufferedglut-single-and-double-buffered-drawingglut
    //GLUT_SINGLE buffer : directly displayed on the screen, low efficiency
    //GLUT_DOUBLE buffer : swap between two buffers, hight efficiency
    //GLUT_DOUBLE buffer can be seperated into foreground buffer and background buffer;
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

    //@---init the initial position of the window
    glutInitWindowPosition(WINDOW_X_POS, WINDOW_Y_POS);

    //@--init the window size when created
    glutInitWindowPosition(WIDTH, HEIGHT);

    //@--create a window, the title shall be set
    glutCreateWindow("Solar System");


    /*bind three call-back functions for different events*/

    //@ glutDisplayFunc(void (*func)(void))
    //--invoked when a window should be displayed
    glutDisplayFunc(onDisplay);

    //@ glutIdleFunc(void (*func)(void))
    //--invoked during idle time
    glutIdleFunc(onUpdate);

    //@ glutKeyboardFunc(void (*func)(unsigned char key, int x, int y))
    //--invoked when an asscociated key is pressed or released
    glutKeyboardFunc(onKeyBoard);


    //@--main loop of the program
    glutMainLoop();
    return 0;
}