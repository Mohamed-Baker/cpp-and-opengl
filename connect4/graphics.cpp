 #include <stdafx.h>
#include <glut.h>
#include <cmath>
#include "conncet4.h"

void init()
{


glClearColor(1,1,1,1); // set the background color

glPointSize(4.0); // a ‘dot’ is 4 by 4 pixels 
gluOrtho2D(0, 800, 0, 600);


}


void keyboard(unsigned char key, int x, int y)
{
	if (set){
	switch(key)
	{
	case '1':
	  addrefrence(150 , 0);
	    break;
	case '2':
		addrefrence(220 , 1);
		break;
    case '3':
	    addrefrence(290 , 2);
		break;
	case '4':
		addrefrence(360 , 3);
		break;
	case '5':
		addrefrence(430 , 4);
		break;
	case '6':
		addrefrence(500 , 5);
		break;
	case '7':
		addrefrence(570 , 6);
		break;
	case '0':
		restart();
		break;
	default: break;
	}
}
}
void click (int button ,int state , int x, int y)

{ if (set)
{if (button == GLUT_RIGHT_BUTTON )
        restart();
	if ((button == GLUT_LEFT_BUTTON ) && (state == GLUT_UP)) 
	{if ( x > 115 && x <185)
	  addrefrence(150 , 0);
	else if ( x > 185 && x <255)
		addrefrence(220 , 1);
   else if ( x > 255 && x <325)
	    addrefrence(290 , 2);
	else if ( x > 325 && x <395)
		addrefrence(360 , 3);
	else if ( x > 395 && x <465)
		addrefrence(430 , 4);
	else if ( x > 465 && x <535)
		addrefrence(500 , 5);
	else if ( x > 535 && x <605)
		addrefrence(570 , 6);}
}
}



void main()
{
 
  glutInitDisplayMode( GLUT_RGBA|GLUT_SINGLE );
   
  glutInitWindowSize(800,600);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Connect 4");
  init();
  glutDisplayFunc(display);
  glutMouseFunc(click);
  glutKeyboardUpFunc(keyboard);

 glutMainLoop();

  
}
