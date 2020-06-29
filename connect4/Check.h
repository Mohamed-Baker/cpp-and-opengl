#include <glut.h>

void drawCircle(int, int);

int c;
int k ;
bool bo;
int flag = 0;


bool yplus = false , yminus = false , xplus = false, xminus = false;


void inti(int x ,int y )
{
	if (y + 3 < 7)
		yplus = true;
	if (y - 3 > -1)
		yminus = true;
	if (x + 3 < 6)
		xplus = true;
	else 
		xminus = true;

}

// chose the winning color

void choseColor(int player)
{
	if (player == 1)
		glColor3ub(180, 180, 0); //for yellow
	else
		 glColor3ub(255, 0, 0); //for red
}


bool check ( int indexofx , int indexofy , int player ,int connect4 [][7])
{
	inti(indexofx ,indexofy );

	if (yplus)
	{ 
      c = 0 ; k = 0;
	        while(k < 4)
		        { if (connect4 [indexofx][indexofy + k] == player)
		          	  c ++;   
	         	  else 
		        	  break;
	              if (c == 4)
			     { // in case of winning
					 choseColor(player);
					 for(int i = 0; i < 4 ; i++)
						
					 drawCircle(150 + ((indexofy + i) * 70),50 + (indexofx * 70));
					 
					return true;
				 }
				  k++;
	            }
	       if(yplus && xplus)
		  	  {
				   c = 0 ; k = 0;
	               while(k<4)
	          	 { if (connect4 [indexofx + k][indexofy + k] == player)
	             		  c ++;   
	              else 
			           break;
	               if (c == 4)
			         { // in case of winning
					  choseColor(player);

					 for(int i = 0; i < 4 ; i++)
					 drawCircle(150 + ((indexofy + i) * 70),50 + ((indexofx + i) * 70));
					 return true;
				     }
			           k++;
	              }
	           }
	      if(yplus && xminus)
		    	{    c = 0 ; k = 0;
	                  while(k<4)
		           { if (connect4 [indexofx - k][indexofy + k] == player)
		            	  c++;   
		             else 
		         	  break;
	                if (c == 4)
	    	    	 { // in case of winning
						choseColor(player);

					 for(int i = 0; i < 4 ; i++)
					 drawCircle(150 + ((indexofy + i) * 70),50 + ((indexofx - i) * 70));
					 
					 
					 return true;
				 }
		          	 k++;
	               }
	            }
	  }
	  if(yminus)
	{ 
		     c = 0 ; k = 0;
	           while(k<4)
		      {   if (connect4 [indexofx][indexofy - k] == player)
			           c++;   
		          else 
		         	  break;
	              if (c == 4)
	        		  { // in case of winning
					 choseColor(player);

					 for(int i = 0; i < 4 ; i++)
					 drawCircle(150 + ((indexofy - i) * 70),50 + (indexofx * 70));
					 
					 
					return true;
				 }
	         		 k++;
	           }

	  if(yminus && xplus)
		       { 
				 c = 0 ; k = 0;
	             while(k<4)
		            { if (connect4 [indexofx + k][indexofy - k] == player)
		            	  c++;   
	              	  else 
			               break;
	                  if (c == 4)
			            { 
							// in case of winning
							choseColor(player);

					      for(int i = 0; i < 4 ; i++)
					    drawCircle(150 + ((indexofy - i) * 70),50 + ((indexofx + i) * 70));
					 
					 
					return true;
				     }
			           k++;
	                 }
	           }
	  	  if(yminus && xminus)
		       {  c = 0;  k = 0;
	             while(k<4)
		            { if (connect4 [indexofx - k][indexofy - k] == player)
		            	  c++;   
	              	  else 
			               break;
	                  if (c == 4)
			            { 
						// in case of winning
					 choseColor(player);

					 for(int i = 0; i < 4 ; i++)
					 drawCircle(150 + ((indexofy - i) * 70),50 + ((indexofx - i) * 70));
					 
					 
					return true;
				     }
			           k++;
	                 }
	            }

	     }


	  if (xplus)

		  	  { 
				  c = 0 ; k = 0;
	               while(k<4)
		 { 
			 if (connect4 [indexofx + k][indexofy] == player)
			  c++;   
		        else 
			      break;
	         if (c == 4)
				 
			   {  //// in case of winning
				    choseColor(player);

					 for(int i = 0; i < 4 ; i++)
					 drawCircle(150 + (indexofy * 70),50 + ((indexofx + i) * 70));
					 
					 
					return true;
				 }
			 k++;
			  
	     }
	         }
	  if(yminus)

		  	  {c = 0 ; k = 0;
	  while(k<4)
		 { if (connect4 [indexofx - k][indexofy ] == player)
			  c ++;   
		  else 
			  break;
	      if (c == 4)
			  {     // in case of winning
				    choseColor(player);

					 for(int i = 0; i < 4 ; i++)
					 drawCircle(150 + (indexofy * 70),50 + ((indexofx - i) * 70));
					 
					 
					return true;
				 }
			 k++;
	      }
	      }

	  if(flag < 2 && indexofy > 0)
	  {
		  
		 bo = check ( indexofx ,indexofy-1 ,player ,connect4);
			  flag++;
			  if(bo)
			  { flag = 0;
			    return true;
			  }
	  }
	  flag = 0;
	   if(flag < 2 && indexofy > 0 && indexofx > 0)
	  {
		  
		 bo = check ( indexofx-1 ,indexofy-1 ,player ,connect4);
			  flag++;
			  if(bo)
			  { flag = 0;
			    return true;
			  }
	  }
	   flag = 0;

	    if(flag < 2 && indexofy < 7 && indexofx > 0)
	  {
		  
		 bo = check ( indexofx - 1 ,indexofy + 1 ,player ,connect4);
			  flag++;
			  if(bo)
			  { flag = 0;
			    return true;
			  }
	  }
	   flag = 0;
 return false;
}

void drawCircle(int x2 , int y2)
{


        int r2 = 20 ; 
  
		  glBegin(GL_POLYGON);
		   for (double i = 0; i<360 ; i++)
		    glVertex2i(x2 + r2*cos(i), y2+ r2*sin(i));
		  glEnd();

		 glFlush();
		 
     

}
