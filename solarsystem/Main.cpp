
#include <glut.h>
#include <cstdio>



float angle = 0.0f;
GLuint textureID;
char *images [] = { "images/sun.bmp" , "images/mercury.bmp" , "images/venus.bmp" ,
	                "images/earth.bmp" , "images/mars.bmp" , "images/jupiter.bmp" ,
					"images/saturn.bmp" , "images/uranus.bmp" , "images/neptune.bmp" , 
                   } ;
float speed [] = { 8 , 6 , 4 , 3 , 2 , 1 , 0.5 , 0.1 };
int distance [] = { 110 , 130 , 150 , 190 , 260 , 340 , 400 , 580 };
int radius [] = { 4 , 7 , 40 , 5 , 35 , 25 , 15 , 13 };
float rotaion [] = { 50 , 200 , 30 , 40 , 14 , 12 , 14 , 13 };


int size = 3 * 128 * 128;
unsigned char *info = new unsigned char[54];
unsigned char *data = new unsigned char [size];
int width = 128;
int height = 128;



void readBMP(char *s)
{
    int i;
    FILE* f = fopen(s, "rb");
    
     fread(info, sizeof(unsigned char), 54, f); 
     fread(data, sizeof(unsigned char), size, f); 

    fclose(f);



    for(i = 0; i < size; i += 3)
    {
            unsigned char tmp = data[i];
            data[i] = data[i+2];
            data[i+2] = tmp;
    }


    
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
	gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);



}



void init()
{
	
   glClearColor( 0.0, 0.0, 0.0, 1.0 );
   glEnable(GL_DEPTH_TEST);
       glMatrixMode(GL_PROJECTION);
    
 	glLoadIdentity();
	glOrtho(-600,600,-340,340,600,-600);

	glFrustum(-600,600,-340,340,600,-600);
	// glViewport (-600,-600,600,600);
    // glLoadIdentity(); 
    // gluLookAt(0,0,0,0,0,100,0,1,0);
 
  
}

void  display()

{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3ub(255, 255, 255);
	
	
		 //glLoadIdentity();
	
	
	
	




	glEnable(GL_TEXTURE_2D);

	glPushMatrix();
	readBMP(images[0]);
	GLUquadricObj* sun = gluNewQuadric();
	gluQuadricTexture(sun,1
		);
	glRotatef(-90,1.0f, 0.0f, 0.0f);
	gluSphere(sun, 100, 60, 60);
	glPopMatrix();

	for ( int i = 1 ; i < 9 ; i++)
	{
		
	glPushMatrix();	
	readBMP(images[i]);
	GLUquadricObj* Quadric = gluNewQuadric();
	gluQuadricTexture(Quadric, true);
	glRotatef((GLfloat) angle*speed[i-1] ,0.0f, 1.0f, 0.0f);
	glTranslatef(distance[i-1],0,0);
	glRotatef(-90,1.0f, 0.0f, 0.0f);
	glRotatef((GLfloat) angle*rotaion[i-1],0.0f, 0.0f, 1.0f);
	gluSphere(Quadric,radius[i-1] , 40, 40);
	glPopMatrix();
	};
	
	glDisable ( GL_TEXTURE_2D );
	
	glFlush();
	glutSwapBuffers();


}
void update(int value) 
{

	angle++;
	if(angle > 600) angle=0;
	glutPostRedisplay();
	glutTimerFunc(10, update, 0);
}
void reshape (int w, int h)
{
	
 glViewport (0, 0, (GLsizei) w, (GLsizei) h);

		
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	


	

 
}
void main()
{
  int mode = GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH; 
  glutInitDisplayMode( mode );

  glutInitWindowSize(1200,680);
  glutInitWindowPosition(0,0);

  glutCreateWindow("SolarSystem");
  init();
  glutDisplayFunc( display );
 
  glutTimerFunc(25, update, 0);
 //glutReshapeFunc(reshape);
  glutMainLoop();
    delete data;
	delete info;
}
