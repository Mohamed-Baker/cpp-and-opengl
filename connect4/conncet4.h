#include <glut.h>
#include <cmath>
#include "Check.h"


bool set = true ;

int connect4 [6][7] ;

int y [7] ;  //Array For The Value of y-axis

int index [7]; // index of the y-axis

int counter ;



void initVariables( )


 {
	 counter = 0;
	 for (int i = 0 ; i < 6 ; i ++)
		 for(int j = 0 ; j < 7 ; j ++)
			 connect4[i][j]=0;
	 for (int i = 0 ; i < 7 ; i++)
		 y[i] = 50;

	 for (int i = 0 ; i < 7 ; i++)
		 index[i] = 0;
 }


// Display the Game
 void display ()
{
   
	initVariables();
 
int x1=150,z=50,r1=30;

glClear(GL_COLOR_BUFFER_BIT );
glColor3ub(150, 150, 150); // set the drawing color
 
for (int l = 0; l < 6 ; l++)
{
  for (int k = 0 ;k < 7 ; k++)
  {
    
	 
		  glBegin(GL_POINTS);
		  for (double i = 0; i<360 ; i++)
		    glVertex2i(x1 + r1*cos(i), z + r1*sin(i));
		  glEnd();

		  glFlush();
	 
	x1+=70;
  }
  x1=150;
  z+=70;

}
x1=150;z=50;
glColor3ub(0, 0, 0);
 }
 
void restart()
{
	display();
}


 void Timer(int x)
 { restart();
 set = true;}


 int player ;

//Add Refrence to The Arrary

void addrefrence(int x , int position)
{
	if (index [position] < 6 )
	{  
		if (counter % 2 == 0)
	        { glColor3ub(255, 255, 0); player = 1;} 
    
       else
           {glColor3ub(150, 30, 30); player = 2;}

	
	switch (player)
	     {   case 1:
	          connect4 [index[position]][position] = 1 ; break;
	         case 2 :
	          connect4 [index[position]][position] = 2 ; break;	
		     default : break;
	     }
	  


	   drawCircle(x , y[position]);
	  bool winning =  check (index[position] ,  position ,  player , connect4 );
		y [position]  =  y [position] +  70 ;
	     index [position] = index [position] + 1;
		 counter++;
		if (winning)
		{	set = false ;
		glutTimerFunc(2500,Timer,1);
          
		}
	 

	}

}


