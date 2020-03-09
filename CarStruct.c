/******************************************************************************
Name: 			Bryan Michael Tice

Course: 		CSCI-1153

Instructor:		Dr. Chu Jong

Assignment:		Lab 05

Program Description:    This program opens a file cardb.txt and inputs the data
                    into a structure. It sorts the data to complete a binary 
                    search at the users request. The program terminates when The
                    user inputs a negative number. 

*******************************************************************************/
#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  /*needed for dynamic memory allocation functions*/
FILE *inFile;
struct CarInfo
  {
        int VIN;
        int miles;
        int gal_used;
        char Manufacturer[15];
 };
int main()
{
    //declare needed vars
    int cntr,mvz,x;
    struct CarInfo *MyCarArray;
    //declare needed functions
    int sort();
    int getfile();
    void readfile();
    int binarySearch();
    // calls a function to open the file and count the number of lines in the file.
    cntr=getfile(inFile);
    //creates space in memory for the data to go into
    MyCarArray = malloc(cntr*sizeof(struct CarInfo));
    //calls a function to read the data from the file into the data structure
    readfile(inFile,cntr,MyCarArray);
    //closes the file when done reading informaton
    fclose(inFile);
    //calls a function to sort the data so a binary search can be performed. 
    sort(MyCarArray,cntr);
    //prints out the top of the requested output data
    printf("Following are the information of all vehicles:\n");
    printf("Vehicle ID #  Miles Driven  Gallons Used  Manufacture\n");
    printf("============  ============  ============  ===========\n");
    //uses a loop function to output remainder of data from structure
    // after it has been sorted
      for(int i = 0; i<cntr;i++)
    { 
        printf("%9d%14d%14d%14s \n",MyCarArray[i].VIN,
                                MyCarArray[i].miles,
                                MyCarArray[i].gal_used,
                                MyCarArray[i].Manufacturer);
                                
    }
  // requests user input and calls a binary search function if 
  // the user inputs a number greater than or equal to 0
  //outputs user requested data
    do{  
    printf("Please enter a Vehicle ID Number:");
    scanf("%d",&x);
    if (x<0)
       break;
     int result = binarySearch(MyCarArray, 0, cntr-1, x); 
     (result == -1)? printf("Vehicle Not Found\n") 
                 : printf("%d Miles Driven     %d Gallons Used    Manufactured by %s \n"
                 ,MyCarArray[result].miles 
                 ,MyCarArray[result].gal_used
                 ,MyCarArray[result].Manufacturer); 
    }while(x>=0);
                 
                 printf("Good bye!\n");
	free(MyCarArray);
  
  return 0;
}
int getfile(char name[])
{
    
    char file[12]="cardb.txt";
    int count=0;
    //opens file for command line output
	inFile = fopen(file,"r");
	//creates a character index variable for traversal
    char CharIndex;
    // goes through the file, counts new lines. 
    for (CharIndex = getc(inFile); CharIndex != EOF; CharIndex = getc(inFile)) 
        {
            if (CharIndex == '\n') 
            count = count + 1;
        }
    return count+1;//returns the number of new lines plus 1 to determin amount of
                    // memory needed.
    
}
void readfile(FILE *inFile,int count,struct CarInfo *MyCustomInfo)
{
    //jumps back to the top of the file so we don't have to reopen again.
    fseek(inFile, 0, SEEK_SET);
    //inputs all the data into the structure
    for(int i =0; i<count;i++)
    {
        fscanf(inFile,"%d %d %d %s",&MyCustomInfo[i].VIN,
                                    &MyCustomInfo[i].miles,
                                    &MyCustomInfo[i].gal_used,
                                    MyCustomInfo[i].Manufacturer);
    }
   
}
int sort(struct CarInfo *list,int s)
{
    int i,j;
    struct CarInfo temp;
    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (list[j].VIN > list[j + 1].VIN)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            } 
        }
    }
}
int binarySearch(struct CarInfo *arr, int l, int r, int x) 
{ 
  while (l <= r) 
  { 
    int m = l + (r-l)/2; 
    // Check if VIN is located at mid 
    if (arr[m].VIN == x)  
        return m;   
    // If x greater, ignore left half   
    if (arr[m].VIN < x)  
        l = m + 1;  
    // If x is smaller, ignore right half  
    else 
         r = m - 1;  
  } 
  
  // if we reach here, then element was not present 
  return -1;  
} 
