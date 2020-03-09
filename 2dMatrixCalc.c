/******************************************************************************
Name: 			Bryan Michael Tice

Course: 		CSCI-1153

Instructor:		Dr. Chu Jong

Assignment:		Lab 04

Program Description:  this program opens a file containing the information of two 
                    2D matricies, reads that data into two matricies, then adds
                    them into another matrix.

*******************************************************************************/

#include <stdio.h>    /*needed for standard output*/
#include <math.h>    /*needed for math functions*/
 
FILE *inFile;
int main ()
{
	
	char getfile();
	char MatrixAddition();
	
	 /*creates a file address called inFile*/
       
      getfile(inFile);
      MatrixAddition(inFile);
    fclose(inFile);
	
  return 0;
}   
char getfile(char name[])
{
    
  
    char file[12];
    do{
    printf("please enter a file name you wish to open--->");
	scanf("%s",file);
	inFile = fopen(file,"r");
	
	if(inFile==NULL)
	{
	    printf("\n File not found for reading!\n");
	}
    }while(inFile==NULL);    
  
    
    
}
char  MatrixAddition(FILE *inFile)
{
    
    int m,n;
    fscanf(inFile,"%d %d",&n,&m);
    printf("%d %d\n",n,m);
    int matrix1[n][m],matrix2[n][m],sum[n][m];
    
    for(int i=0;i<=n-1;i++)
        {
            
            for(int j=0;j<=m-1;j++)
            {
                    
                    fscanf(inFile,"%d",&matrix1[i][j]);
                    printf("%u",matrix1[i][j]);
                    
                  
            }
        
            printf("\n");
        }
        printf("Matrix 2\n");
   for(int p=0;p<=n-1;p++)
        {
            
            for(int q=0;q<=m-1;q++)
            {
                    
                    fscanf(inFile,"%d",&matrix2[p][q]);
                    printf("%u",matrix2[p][q]);
                    
                  
            }
        
            printf("\n");
        }
 
   printf("The result of addition :\n");
    for(int y=0;y<=n-1;y++)
        {
            
            for(int z=0;z<=m-1;z++)
            {
                 
                   sum[y][z]=matrix1[y][z]+matrix2[y][z];
                   printf("   %2d",sum[y][z]);
                   
                  
                  
            }
         printf("\n");
            
        }
   }      