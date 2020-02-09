

#ifndef BSLAYER_CPP_
#define BSLAYER_CPP_
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <fcntl.h>
#include <linux/kd.h>
#include <sys/ioctl.h>
//#include <ncurses.h>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
bool instructionsmenu=false;
bool endgame=false;
int score=0;
int k=500;
int j=400;
bool chooselevel1=false;
bool chooselevel2=false;
bool shootcheck=false;
int shootx[10000];
int shooty[10000];
int counterforshoot=0;
int timerforshooting=0;
bool c=true;
bool level1=false;
bool level2=false;
bool moveincircle=false;
int timerforbar=0;
int freq = 2000; // freq in hz
  int len = 1000; // len in ms
int fd = open("/dev/console ", O_WRONLY);
bool falsemenucheck=false;
int pausegamesend=35;
int falsemenucolor=0;
int timerwithinfalsemenu=0;
int shootcount=0;
int recx1=100, recy1=0 , recx2=230, recy2=0, recx3=230, recy3=10, recx4=100, recy4=10;
//1
int ycordinates1=490;
int ycordinates2=450;
//2
int ycordinates3=440;
int ycordinates4=400;
//3
int ycordinates5=390;
int ycordinates6=350;
//4
int ycordinates7=340;
int ycordinates8=300;
//5
int ycordinates9=290;
int ycordinates10=250;
//6
int ycordinates11=240;
int ycordinates12=200;
//7
int ycordinates13=190;
int ycordinates14=150;
//8
int ycordinates15=140;
int ycordinates16=100;
//9

int sendcolors=1;
bool leftmovenment=false;
int circlexcordinate=150;
int circleycordinate=30;
int storecirclex;
int storecircley;
int sendvaluemoveup;
int sendvaluemoveleft;
int sendvaluecheck=1;
int timer=0;
//defining some MACROS

#define MAX(A,B) ((A) > (B) ? (A):(B)) // finds max of two numbers
#define MIN(A,B) ((A) < (B) ? (A):(B)) // find min of two numbers
#define ABS(A) ((A) < (0) ? -(A):(A))  // find ABS of a given number

// define some constants
// constant FPS (Frame per second) is  used to specify
// number of frames per second in your game.. if FPS is small
// your objects will move slowly and if large your objects
// will move faster, see the Timer function below for further help

#define FPS 1 // frame per seconds

// define another constant to hold ASCII for Escape key.
#define KEY_ESC 27 // A
int xcordinates1[500];
int xcordinates2[500];
int xcordinates3[500];
int xcordinates4[500];
int xcordinates5[500];
int xcordinates6[500];
int xcordinates7[500];
int xcordinates8[500];
int score_string=10;
//take an array for y coordinates
//0 define some colors as 2D arrays, we have five pre-defined colors here..
// you can add many more if you wish..

float colors[5][3] = { { 1 / 255.0, 164 / 255.0, 164 / 255.0 }, { 215 / 255.0, 0
		/ 255.0, 96 / 255.0 }, { 208 / 255.0, 209 / 255.0, 2 / 255.0 }, { 0
		/ 255.0, 161 / 255.0, 203 / 255.0 }, { 50 / 255.0, 116 / 255.0, 44
		/ 255.0 } };

bool rightmovenment=false;
int awab=0;
bool moveup=false;
bool movefromright=false;
bool movedown=false;
bool movefromleft=false;
bool gamestart=false;
int sendcolor=3;
bool gamepause=true;
const int nvertices = 722;
GLfloat vertices[nvertices][2];

// defining some utility functions...
/*
 * This function converts an input angle from degree to radians */
/* void DrawString(int x, int y, const string& score, float * color) {
 	//  A pointer to a font style..
 	//  Fonts supported by GLUT are: GLUT_BITMAP_8_BY_13,
 	//  GLUT_BITMAP_9_BY_15, GLUT_BITMAP_TIMES_ROMAN_10,
 	//  GLUT_BITMAP_TIMES_ROMAN_24, GLUT_BITMAP_HELVETICA_10,
 	//  GLUT_BITMAP_HELVETICA_12, and GLUT_BITMAP_HELVETICA_18.
 	GLvoid *font_style = GLUT_BITMAP_TIMES_ROMAN_24;
 	if (color)
 		glColor3fv(color);
 	glRasterPos3f(x, y, 1);
 	//  Draw the characters one by one
 	for (int i = 0; i < score.size(); i++)
 		glutBitmapCharacter(font_style, score[i]);
 } */

 void DrawString(int x, int y, const string& score, float * color,int send=40) {
 	//  A pointer to a font style..
 	//  Fonts supported by GLUT are: GLUT_BITMAP_8_BY_13,
 	//  GLUT_BITMAP_9_BY_15, GLUT_BITMAP_TIMES_ROMAN_10,
 	//  GLUT_BITMAP_TIMES_ROMAN_24, GLUT_BITMAP_HELVETICA_10,
 	//  GLUT_BITMAP_HELVETICA_12, and GLUT_BITMAP_HELVETICA_18.
 	GLvoid *font_style = GLUT_BITMAP_TIMES_ROMAN_24;
 	if (color)
 		glColor3fv(color);
 	glRasterPos3f(x, y, 1);
 	//  Draw the characters one by one
 	for (int i = 0; i < send/*score.size()*/; i++)
 		glutBitmapCharacter(font_style, score[i]);
 }
void moveupfunc()
   {
		 moveup=true;
		 movedown=false;
		 movefromright=false;
		 movefromleft=false;
		 if(storecirclex>circlexcordinate)
			sendvaluemoveup=1; //-
		 if(storecirclex<circlexcordinate)
		 sendvaluemoveup=0;
		 if(storecirclex==circlexcordinate)
			 sendvaluecheck=0;
		 else
				sendvaluecheck=1;
	 }
void movedownfunc()
{
	movedown=true;
	moveup=false;
	movefromleft=false;
	movefromright=false;
	if(storecirclex>circlexcordinate)
	sendvaluemoveup=1; //-
 if(storecirclex<circlexcordinate)
 sendvaluemoveup=0;
 if(storecirclex==circlexcordinate)
	 sendvaluecheck=0;
 else
		sendvaluecheck=1;
}
void movefromrightfunc()
{  //cout<<"hello";
	moveup=false;
	movefromright=true;
	movefromleft=false;
	movedown=false;
	if(storecircley>circleycordinate)
	 sendvaluemoveup=1; //-
	if(storecircley<circleycordinate)
	sendvaluemoveup=0;
	if(storecircley==circleycordinate)
		sendvaluecheck=0;
	else
		 sendvaluecheck=1;
}
void movefromleftfunc()
{
	movefromleft=true;
	moveup=false;
	movedown=false;
	movefromright=false;
	if(storecircley>circleycordinate)
	 sendvaluemoveup=1;
	if(storecircley<circleycordinate)
	sendvaluemoveup=0;
	if(storecircley==circleycordinate)
		sendvaluecheck=0;
	else
		 sendvaluecheck=1;
}
 void InitCircleVertices(float radius) {

	float hdegree = M_PI / 360.0;
	float angle = 0;
	for (int i = 0; i < 722; ++i) {
		vertices[i][0] = radius * cos(angle);
		vertices[i][1] = radius * sin(angle);
		angle += hdegree;
	}
}
void DrawCircle(float sx, float sy, float radius, float*color) {

	glColor3fv(color); // set the circle color
	InitCircleVertices(radius);
	glBegin(GL_TRIANGLE_FAN);
	glVertex4f(sx, sy, 0, 1);
	for (int i = 0; i < 722; ++i)
		glVertex4f(sx + vertices[i][0], sy + vertices[i][1], 0, 1);
	//			glVertex4f(sx + mx - 1, sy + my - 1, 0, 1);
	glEnd();
}
void shoottheballcheck()
{
	for(int i=0; i<26; i+=2)
		  { 
				for(int x=0; x<shootcount; x++)
				{
				
				if((shootx[x]+7>=xcordinates1[i] && shootx[x]-7<=xcordinates1[i+1]) && ( shooty[x]+7==ycordinates2))
				   {
						 xcordinates1[i]=1000;
						 xcordinates1[i+1]=1000;
						 score++;
						 shootx[x]=10000;
						 shooty[x]=100000;
             
					 }
			
 	if((shootx[x]+7>=xcordinates2[i] && shootx[x]-7<=xcordinates2[i+1]) && ( shooty[x]+7==ycordinates4))
	  				   { score++;
							   shootx[x]=10000;
						 shooty[x]=100000;
	  						 xcordinates2[i]=1000;
	  						 xcordinates2[i+1]=1000;
	              
	  					 }
	  			
 	if((shootx[x]+7>=xcordinates3[i] && shootx[x]-7<=xcordinates3[i+1]) && ( shooty[x]+7==ycordinates6))
			 	  		{  score++;
			 	  			 xcordinates3[i]=1000;
			 	  			 xcordinates3[i+1]=1000;
			 	         shootx[x]=10000;
						 shooty[x]=100000;
			 	 			 }
				
   if((shootx[x]+7>=xcordinates4[i] &&  shootx[x]-7<=xcordinates4[i+1]) && ( shooty[x]+7==ycordinates8))
			  	  		{    
			  			 	  	 xcordinates4[i]=1000;
			  			 	  	 xcordinates4[i+1]=1000;
			  			 	     shootx[x]=10000;
						 shooty[x]=100000;
			  			 	 }
			  	
	 if((shootx[x]+7>=xcordinates5[i] && shootx[x]-7<=xcordinates5[i+1]) && ( shooty[x]+7==ycordinates10))
							{  score++;
 	  						 xcordinates5[i]=1000;
								 xcordinates5[i+1]=1000;
								 shootx[x]=10000;
						 shooty[x]=100000;
		  				 }
				
 	
				 if((shootx[x]+7>=xcordinates6[i] && shootx[x]-7<=xcordinates6[i+1]) && ( shooty[x]+7==ycordinates12))
							{    score++;
							      
			 	  		  	 xcordinates6[i]=1000;
									 xcordinates6[i+1]=1000;
									 shootx[x]=10000;
						 shooty[x]=100000;
									
					 		 }
				
if((shootx[x]+7>=xcordinates7[i] && shootx[x]-7<=xcordinates7[i+1]) && ( shooty[x]+7==ycordinates14))
							{    score++;
							       
						 	  	 xcordinates7[i]=1000;
					   			 xcordinates7[i+1]=1000;
										shootx[x]=10000;
						 shooty[x]=100000;
									 
					 		 }
				}
			}
}
float Deg2rad(float degree) {
	return (degree / 180.0) * M_PI;
}
// seed the random numbers generator by current time (see the documentation of srand for further help)...
void InitRandomizer() {
	srand((unsigned int) time(0)); // time(0) returns number of seconds elapsed since January 1, 1970.
}
//This function returns a random value within the specified range of [rmin, rmax] ...
long GetRandInRange(const long &rmin, const long &rmax) {
	long range = rmax - rmin; // find the range
	long value = (rand() % (long) range) + rmin; // translate the generated number ...
//	cout << value << endl << flush;
	return value;
}

/*To draw a triangle we need three vertices with each vertex having 2-coordinates [x, y] and a color for the triangle.
 * This function takes 4 arguments first three arguments (3 vertices + 1 color) to
 * draw the triangle with the given color.
 * */
void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3,
		float color[]) {
	glColor3fv(color); // Set the triangle colour
	// ask library to draw triangle at given position...

	glBegin(GL_TRIANGLES);
	/*Draw triangle using given three vertices...*/
	glVertex4i(x1, y1, 0, 1);
	glVertex4i(x2, y2, 0, 1);
	glVertex4i(x3, y3, 0, 1);
	glEnd();
}
void movetheballdown()
{
   
	for(int i=0; i<26; i+=2)
		  { if((circlexcordinate+7>=xcordinates1[i] && circlexcordinate-7<=xcordinates1[i+1]) && ( circleycordinate+7==ycordinates2))
				   {
						 xcordinates1[i]=1000;
						 xcordinates1[i+1]=1000;
						 score++;
						 cout<<"\a";
             movedownfunc();
					 }
			}
 	for(int i=0; i<26; i+=2)
	   { if((circlexcordinate+7>=xcordinates2[i] && circlexcordinate-7<=xcordinates2[i+1]) && ( circleycordinate+7==ycordinates4))
	  				   { score++;
							   cout<<"\a";
	  						 xcordinates2[i]=1000;
	  						 xcordinates2[i+1]=1000;
	               movedownfunc();
	  					 }
	  			}
 	for(int i=0; i<26; i+=2)
			 { if((circlexcordinate+7>=xcordinates3[i] && circlexcordinate-7<=xcordinates3[i+1]) && ( circleycordinate+7==ycordinates6))
			 	  		{  score++;
							    cout<<"\a";
			 	  			 xcordinates3[i]=1000;
			 	  			 xcordinates3[i+1]=1000;
			 	         movedownfunc();
			 	 			 }
			 		}
	for(int i=0; i<26; i+=2)
			    { if((circlexcordinate+7>=xcordinates4[i] && circlexcordinate-7<=xcordinates4[i+1]) && ( circleycordinate+7==ycordinates8))
			  	  		{    score++;
								      cout<<"\a";
			  			 	  	 xcordinates4[i]=1000;
			  			 	  	 xcordinates4[i+1]=1000;
			  			 	     movedownfunc();
			  			 	 }
			  	}
	for(int i=0; i<26; i+=2)
				{ if((circlexcordinate+7>=xcordinates5[i] && circlexcordinate-7<=xcordinates5[i+1]) && ( circleycordinate+7==ycordinates10))
							{  score++;
 	  						 xcordinates5[i]=1000;
								 xcordinates5[i+1]=1000;
								 movedownfunc();
		  				 }
				}
 	for(int i=0; i<26; i+=2)
				{ if((circlexcordinate+7>=xcordinates6[i] && circlexcordinate-7<=xcordinates6[i+1]) && ( circleycordinate+7==ycordinates12))
							{    score++;
							      cout<<"\a";
			 	  		  	 xcordinates6[i]=1000;
									 xcordinates6[i+1]=1000;
									 movedownfunc();
					 		 }
				}
	for(int i=0; i<26; i+=2)
				{ if((circlexcordinate+7>=xcordinates7[i] && circlexcordinate-7<=xcordinates7[i+1]) && ( circleycordinate+7==ycordinates14))
							{    score++;
							       cout<<"\a";
						 	  	 xcordinates7[i]=1000;
					   			 xcordinates7[i+1]=1000;
									 movedownfunc();
					 		 }
				}
}
void movetheballup()
{
	for(int i=0; i<26; i+=2)
		{ if((circlexcordinate+7>=xcordinates1[i] && circlexcordinate-7<=xcordinates1[i+1]) && ( circleycordinate-7==ycordinates1))
				 { score++;  
             
					 xcordinates1[i]=1000;
					 xcordinates1[i+1]=1000;
					 moveupfunc();
				 }
				 if((circlexcordinate+7>=xcordinates2[i] && circlexcordinate-7<=xcordinates2[i+1]) && ( circleycordinate-7==ycordinates3))
	 	 						 { score++;    
                   

	 	 							 xcordinates2[i]=1000;
	 	 							 xcordinates2[i+1]=1000;
	 	 							 moveupfunc();
	 	 						 }
				 if((circlexcordinate+7>=xcordinates3[i] && circlexcordinate-7<=xcordinates3[i+1]) && ( circleycordinate-7==ycordinates5))
			 		 		  	{      score++;  


			 		 							 xcordinates3[i]=1000;
			 		 							 xcordinates3[i+1]=1000;
			 		 							 moveupfunc();
			 		 				 }
				 if((circlexcordinate+7>=xcordinates4[i] && circlexcordinate-7<=xcordinates4[i+1]) && ( circleycordinate-7==ycordinates7))
				 					{          score++;  

				 										 xcordinates4[i]=1000;
				 										 xcordinates4[i+1]=1000;
				 										 moveupfunc();
				 				  }
					if((circlexcordinate+7>=xcordinates5[i] && circlexcordinate-7<=xcordinates5[i+1]) && ( circleycordinate-7==ycordinates9))
									{        score++;  
													 xcordinates5[i]=1000;
													 xcordinates5[i+1]=1000;
													 moveupfunc();
									 }
				 if((circlexcordinate+7>=xcordinates6[i] && circlexcordinate-7<=xcordinates6[i+1]) && ( circleycordinate-7==ycordinates11))
				 								{    score++;  


				 										 xcordinates6[i]=1000;
				 										 xcordinates6[i+1]=1000;
				 										 moveupfunc();
				 								 }
					if((circlexcordinate+7>=xcordinates7[i] && circlexcordinate-7<=xcordinates7[i+1]) && ( circleycordinate-7==ycordinates13))
							 				 	{          score++;  
                                  
							 										 xcordinates7[i]=1000;
							 										 xcordinates7[i+1]=1000;
							 										 moveupfunc();
							 					 }
		}
}
void movetheballleft()
{
	for(int i=0; i<25; i+=2)
			{
			   if((circleycordinate-7<=ycordinates1 && circleycordinate+7>=ycordinates2 && xcordinates1[i]!=1000) && (circlexcordinate+7==xcordinates1[i])  )
				    { score++;  cout<<"\a";
							xcordinates1[i]=1000;
							movefromrightfunc();
						}
					if(circleycordinate-7<=ycordinates3 && circleycordinate+7>=ycordinates4 && xcordinates2[i]!=1000 && (circlexcordinate+7==xcordinates2[i]))
	 				  {     score++;  
	 								xcordinates2[i]=1000;
	 					   		movefromrightfunc();
	 		 			}
						if(circleycordinate-7<=ycordinates5 && circleycordinate+7>=ycordinates6 && xcordinates3[i]!=1000&& (circlexcordinate+7==xcordinates3[i]))
						{   score++;  
							  xcordinates3[i]=1000;
								movefromrightfunc();
					 	}
						if(circleycordinate-7<=ycordinates7 && circleycordinate+7>=ycordinates8 && xcordinates4[i]!=1000 && (circlexcordinate+7==xcordinates4[i]))
					 	{   score++;  
					 		  xcordinates4[i]=1000;
					 			movefromrightfunc();
					 	}
						if(circleycordinate-7<=ycordinates9 && circleycordinate+7>=ycordinates10 && xcordinates5[i]!=1000 && (circlexcordinate+7==xcordinates2[i]))
						{     score++;  
									xcordinates5[i]=1000;
                  movefromrightfunc();
						}
            if(circleycordinate-7<=ycordinates11 && circleycordinate+7>=ycordinates12 && xcordinates6[i]!=1000 && (circlexcordinate+7==xcordinates6[i]))
							 {      score++;
											xcordinates6[i]=1000;
											movefromrightfunc();
							 }
						if(circleycordinate-7<=ycordinates13 && circleycordinate+7>=ycordinates14 && xcordinates7[i+1]!=1000 && (circlexcordinate+7==xcordinates7[i]))
								{   score++; 
		                xcordinates7[i]=1000;
                  	movefromrightfunc();
								}

			}
}
void movetheballright()
{
	for(int i=0; i<26; i+=2)
			{
			   if((circleycordinate-7<=ycordinates1 && circleycordinate+7>=ycordinates2 && xcordinates1[i+1]!=1000 && xcordinates1[i]!=1000) && (circlexcordinate-7==xcordinates1[i+1])  )
				    { score++;  
							xcordinates1[i+1]=1000;
							movefromleftfunc();
						}
			}
			for(int i=0; i<26; i+=2)
					{
					   if(circleycordinate-7<=ycordinates3 && circleycordinate+7>=ycordinates4 && xcordinates2[i+1]!=1000 && xcordinates2[i]!=1000 && (circlexcordinate-7==xcordinates2[i+1]))
						    {   score++;  
										xcordinates2[i+1]=1000;
							   		movefromleftfunc();
				 				}

			  	}
for(int i=0; i<26; i+=2)
		{
			if(circleycordinate-7<=ycordinates5 && circleycordinate+7>=ycordinates6 && xcordinates3[i+1]!=1000 &&  xcordinates3[i]!=1000 && (circlexcordinate-7==xcordinates3[i+1]))
							   {      score++; 
												xcordinates3[i+1]=1000;
									   		movefromleftfunc();
						 			}

			}
for(int i=0; i<26; i+=2)
		{
			 if(circleycordinate-7<=ycordinates7 && circleycordinate+7>=ycordinates8 && xcordinates4[i+1]!=1000 && xcordinates4[i]!=1000 && (circlexcordinate-7==xcordinates4[i+1]))
										    {   score++;  
														xcordinates4[i+1]=1000;
											   		movefromleftfunc();
								 				}

		 }
for(int i=0; i<26; i+=2)
	 {
			 if(circleycordinate-7<=ycordinates9 && circleycordinate+7>=ycordinates10 && xcordinates5[i+1]!=1000 &&  xcordinates5[i]!=1000 && (circlexcordinate-7==xcordinates5[i+1]))
												    {   score++;  
																xcordinates5[i+1]=1000;
													   		movefromleftfunc();
										 				}

		}
for(int i=0; i<26; i+=2)
		{
	   if(circleycordinate-7<=ycordinates11 && circleycordinate+7>=ycordinates12 && xcordinates6[i+1]!=1000 && xcordinates6[i]!=1000 && (circlexcordinate-7==xcordinates6[i+1]))
       {                            score++;  
																		xcordinates6[i+1]=1000;
															   		movefromleftfunc();
				}

	 	}
for(int i=0; i<26; i+=2)
	{
			 if(circleycordinate-7<=ycordinates13 && circleycordinate+7>=ycordinates14 && xcordinates7[i+1]!=1000 && xcordinates7[i]!=1000 && (circlexcordinate-7==xcordinates7[i+1]))
								    {   score++; 
												xcordinates7[i+1]=1000;
											  movefromleftfunc();
						 				}

	} 
}
void DrawRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,int choosecolor=3 )
{
	 DrawTriangle(x1, y1, x2 , y2 , x3, y3 , colors[choosecolor]);
	 DrawTriangle(x1, y1, x4 , y4 , x3, y3 , colors[choosecolor]);
	// check++;

}
/*void moveupward()
{
	  circleycordinate-=2;
} */
/*
 * Write two functions DrawRectangle and DrawSphere
 * */

/*
 * Main Canvas drawing function.
 * */
void Display()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(7/*Red Component*/, 7.0/*Green Component*/,
			0.0/*Blue Component*/, 7/*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	//for(int x=10; ;)
//DrawString( 0, 300, "Game Paused press a to continue ", colors[5]);
//sendcolors+=2;
if(endgame==true)
{  /* for(int i=100 ; i<=k && c==true; i++)
	 { DrawString( 400, i, "Game over ", colors[5], score_string); 
	     int timer=0;
			 while(timer<100000)
			 timer++; } */
		DrawString( j,k, "Game over ", colors[5], score_string);
		DrawString( 10, 770, "Score="+to_string( score), colors[5], score_string);
		k++;
	//	j++;
		if(j>800)
		   j=100;
		if(k>700)
		  k=100;
		else if(j<10)
		j++;
		else 
		  {  
			//	k++;
	    	j++;
			}
		c=false;

}
if(gamestart==false && falsemenucheck==false)
   {  
	    timerwithinfalsemenu++;
			if(timerwithinfalsemenu==100)
			   {
					 falsemenucolor++;
					 timerwithinfalsemenu=0;
				 }
	    int k;
			if(falsemenucolor%2==0)
			   k=3;
			else 
			   k=1;
			if(instructionsmenu==false)
		  DrawRectangle(150, 250, 700,250,700,600, 150, 600,k);
				if(instructionsmenu==false){
			if(level1==true || level2==true)
		 { DrawString( 200, 500, "To start the game press upper arrowkey ", colors[5]); }
	    DrawString( 200, 450, "To Pause game at anytime press upkey ", colors[5]);
			DrawString( 200, 400, "To resume game at anytime press R key", colors[5]);
			DrawString( 200, 350, "For instructions regarding level press I", colors[5]);
			if(level1==true)
			DrawString( 200, 300, "To shoot the triangles press S button  ", colors[5]);
      if(level1==false && level2==false)
			{ DrawString( 200, 500, "For level one press E and for level 2 press D ", colors[5],50); }
			DrawString( 400,100, "GOOD LUCK ", colors[5], score_string); }
			if(instructionsmenu)
			{
			   DrawString( 200, 500, "In level 1 you can shoot rectangles  ", colors[5]);
				 DrawString( 200, 450, "In level 1 bar size remains constant  ", colors[5]);	
				 DrawString( 200, 400, "In level 2 you cannot shoot rectangles  ", colors[5]);
				 DrawString( 200, 350, "In level 2 bar size decreases with time  ", colors[5]);
				 DrawString( 200, 300, "To return to the main menu press M  ", colors[5]);
			}
			
    }
if(gamestart)
{ falsemenucheck=true;
	timer++;
	if(timer==200)
	{
		sendcolor++;
		timer=0;
	//	cout<<"hello";
	}
 if(sendcolor==6)
     { sendcolor=3; }
	DrawString( 10, 770, "Score="+to_string( score), colors[5], score_string);
	if(gamepause==true)
	DrawString( 10, 740, "To pause game at anytime press downkey ", colors[5]);
	if(gamepause==false)
	DrawString( 10, 740, "GAME PAUSED PRESS KEY R TO RESUME   ", colors[5],pausegamesend);
  timerforbar++;
	timerforshooting++;
 //sendcolor++;
  for(int i=shootcount; i<10000; i++)
	    {
				shootx[i]=(recx1+recx2)/2;
			}
	if(timerforshooting>1000 && timerforshooting<2000 )
	   {
        shootcheck=true;

		 }
	for(int i=0; i<shootcount; i++)
	    {
			   DrawCircle(shootx[i],shooty[i],5,colors[4]);	
			}
	for(int i=0; i<shootcount; i++)
	    {
			   shooty[i]++;
			}
    movetheballdown();

    shoottheballcheck();

	if(timerforbar==300 && recx2-recx1>=20 && level1==false)
	   {
			 recx1+=3;
			 recx2-=3;
			 recx3-=3;
			 recx4+=3;
			 timerforbar=0;
		 }

//move up /....../

movetheballup();

//move left/-----/
   movetheballleft();

//move right/...../
  movetheballright();
	//sendcolors=1;
	for(int i=0; i<26;i+=2)
	    {
        
				if(xcordinates1[i]!=1000 && xcordinates1[i+1]!=1000 )
				DrawRectangle(xcordinates1[i],ycordinates1,xcordinates1[i+1],ycordinates1,xcordinates1[i+1],ycordinates2,xcordinates1[i],ycordinates2,sendcolor);
        if(xcordinates2[i]!=1000 && xcordinates2[i+1]!=1000 )
				DrawRectangle(xcordinates2[i],ycordinates3,xcordinates2[i+1],ycordinates3,xcordinates2[i+1],ycordinates4,xcordinates2[i],ycordinates4,sendcolor);
        if(xcordinates3[i]!=1000 && xcordinates3[i+1]!=1000 )
        DrawRectangle(xcordinates3[i],ycordinates5,xcordinates3[i+1],ycordinates5,xcordinates3[i+1],ycordinates6,xcordinates3[i],ycordinates6,sendcolor);
        if(xcordinates4[i]!=1000 && xcordinates4[i+1]!=1000 )
				DrawRectangle(xcordinates4[i],ycordinates7,xcordinates4[i+1],ycordinates7,xcordinates4[i+1],ycordinates8,xcordinates4[i],ycordinates8,sendcolor);
        if(xcordinates5[i]!=1000 && xcordinates5[i+1]!=1000 )
				DrawRectangle(xcordinates5[i],ycordinates9,xcordinates5[i+1],ycordinates9,xcordinates5[i+1],ycordinates10,xcordinates5[i],ycordinates10,sendcolor);
        if(xcordinates6[i]!=1000 && xcordinates6[i+1]!=1000 )
        DrawRectangle(xcordinates6[i],ycordinates11,xcordinates6[i+1],ycordinates11,xcordinates6[i+1],ycordinates12,xcordinates6[i],ycordinates12,sendcolor);
        if(xcordinates7[i]!=1000 && xcordinates7[i+1]!=1000 )
				DrawRectangle(xcordinates7[i],ycordinates13,xcordinates7[i+1],ycordinates13,xcordinates7[i+1],ycordinates14,xcordinates7[i],ycordinates14,sendcolor);
			}


  DrawRectangle(recx1,recy1,recx2,recy2,recx3,recy3,recx4,recy4);
	DrawRectangle(recx1,recy1,recx2,recy2,recx3,recy3,recx4,recy4);
	DrawCircle(circlexcordinate,circleycordinate,7,colors[4]);
	//DrawCircle(storecirclex,storecircley,7,colors[1]);
	if(circleycordinate-7==10 && (circlexcordinate>=recx1 && circlexcordinate<=recx2))
	   {
			 moveupfunc();
		 }
	if(circlexcordinate==0)
	   {
			 endgame=true;
		 }

	if(circlexcordinate+7==910 )
	 	   {
	 			 //moveupward();
	 			 moveup=false;
				 movefromright=true;
				 movefromleft=false;
				 movedown=false;
				 if(storecircley>circleycordinate)
				  sendvaluemoveup=1; //-
				 if(storecircley<circleycordinate)
				 sendvaluemoveup=0;
				 if(storecircley==circleycordinate)
				   sendvaluecheck=0;
				 else
				    sendvaluecheck=1;
	 		 }
	if(circleycordinate+7==570)
		 {
		 			 movedown=true;
					 moveup=false;
					 movefromright=false;
					 movefromleft=false;
					 if(storecirclex>circlexcordinate)
					  sendvaluemoveup=1; //-
					 if(storecirclex<circlexcordinate)
					 sendvaluemoveup=0;
					 if(storecirclex==circlexcordinate)
					   sendvaluecheck=0;
					 else
					    sendvaluecheck=1;
 		 }


	if(circleycordinate-7<=0)
	   {
			 gamestart=false;
			 endgame=true;

		 }
	if(score>=91)
	   {
			 gamestart=false;
			 endgame=true; 
		 }
	if(circlexcordinate-7==40)
	   {
			 movefromleft=true;
			 moveup=false;
			 movedown=false;
			 movefromright=false;
			 if(storecircley>circleycordinate)
			  sendvaluemoveup=1;
			 if(storecircley<circleycordinate)
			 sendvaluemoveup=0;
			 if(storecircley==circleycordinate)
				 sendvaluecheck=0;
			 else
					sendvaluecheck=1;

		 }
  if(gamepause==true)
{
	if(moveup)
	{   storecirclex=circlexcordinate;
      storecircley=circleycordinate;

			circleycordinate+=1;
	  	if(sendvaluemoveup==1 && sendvaluecheck!=0)
     circlexcordinate-=1;
		 if(sendvaluemoveup==0 && sendvaluecheck!=0)
      circlexcordinate+=1;


	}
	else if(movefromright)
	        { storecirclex=circlexcordinate;
					storecircley=circleycordinate;

					circlexcordinate-=1;
						if(sendvaluemoveup==1 && sendvaluecheck!=0)
					 {circleycordinate-=1; }
					 if(sendvaluemoveup==0 && sendvaluecheck!=0)
						circleycordinate+=1;

					}
	 else if(movedown)
	     { storecirclex=circlexcordinate;
		 	storecircley=circleycordinate;
				  circleycordinate-=1;
				 if(sendvaluemoveup==1 && sendvaluecheck!=0)
			 {	circlexcordinate-=1; }
				if(sendvaluemoveup==0 && sendvaluecheck!=0)
				{ circlexcordinate+=1; }


			 }
	else if(movefromleft)
	    {  storecirclex=circlexcordinate;
			storecircley=circleycordinate;
				 circlexcordinate+=1;
				if(sendvaluemoveup==1 && sendvaluecheck!=0)
	     circleycordinate-=1;
			 if(sendvaluemoveup==0 && sendvaluecheck!=0)
	      circleycordinate+=1;
			}
	else{
		storecirclex=circlexcordinate;
 	storecircley=circleycordinate;
	 circlexcordinate+=1;
 	 circleycordinate+=1;

	}
	//1000*700
  DrawRectangle(0,600,1000,600,1000,630,0,630); //line drawn below score
	DrawRectangle(950,circleycordinate-5,950,circleycordinate+5,910,circleycordinate+5,910,circleycordinate-5);
	DrawRectangle(circlexcordinate-5,600,circlexcordinate+5,600,circlexcordinate+5,570,circlexcordinate-5,570);
  DrawRectangle(0,circleycordinate-5,0,circleycordinate+5,40,circleycordinate+5,40,circleycordinate-5);
}
}
//	DrawRectangle(50,500,100,500,100,520,50,520);
	glutPostRedisplay();

	glutSwapBuffers(); // do not modify this line..
}
/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		if(recx1!=0)
		  { recx1-=10; recx2-=10; recx3-=10;  recx4-=10; }


		// what to do when left key is pressed...

	} else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		if(recx2!=1000)
		{recx1+=10; recx2+=10; recx3+=10; recx4+=10; }



	} else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
   gamestart=true;


	}

	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
    gamepause=false;

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	/*
	 glutPostRedisplay();
	 */
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == KEY_ESC/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
		if (key == 114/* Escape key ASCII*/) {
			   gamepause=true; }
				if (key == 115/* Escape key ASCII*/) {
			   if(level1==true && gamepause==true)
				{ shootcount++; } }
				if (key == 101/* Escape key ASCII*/) { //easy
			   level1=true; }
				if (key == 100/* Escape key ASCII*/) { //easy
			   level2=true; }
				if (key == 105/* Escape key ASCII*/) { 
			     instructionsmenu=true; }
				if (key == 109/* Escape key ASCII*/) { 
			     instructionsmenu=false; }

}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1.0 / FPS, Timer, 0);
}

/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
	int width = 950, height = 800; // i have set my window size to be 800 x 600
	int even=1;
	int add=100;
	for(int i=0; i<26; i++)
		    { if(even%2!=0 && even>2)
					   {
							 xcordinates1[i]=add-50;
							 xcordinates2[i]=add-50;
							 xcordinates3[i]=add-50;
							 xcordinates4[i]=add-50;
							 xcordinates5[i]=add-50;
							 xcordinates6[i]=add-50;
							 xcordinates7[i]=add-50;
							 even++;
							 continue;
						 }
						 even++;
					xcordinates1[i]=add;
					xcordinates2[i]=add;
					xcordinates3[i]=add;
					xcordinates4[i]=add;
					xcordinates5[i]=add;
					xcordinates6[i]=add;
					xcordinates7[i]=add;
					add+=60;
			  }
	for(int i=0; i<10000; i++)
	    {
				shooty[i]=10;
			}
  // PlaySound("starwars.wav", NULL, Apna Maqam Paida Kar  Rahat Fateh Ali Khan  Ghazal  Allama Iqbal|SND_LOOP);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("ITCs Brick Slayer"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	glutDisplayFunc(Display); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); 
	// tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0 / FPS, Timer, 0);

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* BSLAYER_CPP_ */
