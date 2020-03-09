/******************************************************************************
Name: 			Bryan Michael Tice

Course: 		CSCI-1153

Instructor:		Dr. Chu Jong

Assignment:		Lab 03

Program Description:    This program performs a calculation of how far the 
			horizon is, based off height above the earth's surface.
			the program opens and closes a file containing the 
			radius's of the Earth and Moon and performs a loop from 
			a height of 0 to 8000 ft to show change in horizon gets
			larger when you're higher off the surface of earth.  


*******************************************************************************/

#include <stdio.h>    /*needed for standard output*/
#include <math.h>    /*needed for math functions*/
#include <stdlib.h> /*needed for exit testing*/

int main ()
{
	FILE *inFile; /*creates a file address called inFile*/
	float HorzDis(float,float);/*creates our function fot Distance*/
	float RadEarth,RadMoon;
	inFile = fopen("Radius.txt","r");/*opens the file in read mode and assigns it to inFile*/
    while (fscanf(inFile, "%f %f",&RadEarth,&RadMoon) != EOF)/*reads the radius of earth and moon*/
    fclose(inFile);  /*closes the file we opened*/
	HorzDis(RadEarth,RadMoon);/*our only function call*/
  return 0;
}   
float HorzDis(float x,float y)/* x,y are radius passed along*/
{
    printf("  Height         Distance(Moon)        Distance (Earth)\n");/*top of table*/
    printf("===========    ==================     ==================\n");/*printout*/
	int height=0;
	do/*prints distances from 0-8000*/
	{
	    float d_earth,d_moon;
	    d_earth=sqrt((2*x*1000*height)+(height*height));
	    d_moon=sqrt((2*y*1000*height)+(height*height));
		d_earth*=.001;
		d_moon*=.001;
		printf("%5d Meter      %6.2f Kilometer       %6.2f Kilometer\n",height,d_earth,d_moon);
	    height+=500;
	}while(height<=8000);
}/* Have a great weekend Dr. Jong!! Don't play too much golf :) */