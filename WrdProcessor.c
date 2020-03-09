/******************************************************************************
NAME        Bryan Michael Tice  
Course      CSCI-1153
Assignment  Project 
Instructor  Dr. Chu Jong
Date        12-12-19
Description 

            This program uses a linked list to read in, sort and count the words
            in a file. The user enters a file name and the list couns unique 
            words also, then asks user to enter a word to search in the text 
            it has just scanned. The program ends when the user inputs EINPUT
*******************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXCHARS 30
#define DEBUG 0
FILE* inFile;
/* Declcartion of linked list data structure*/
struct Word_Record_Type
{
  char A_Word[MAXCHARS]; 
  struct Word_Record_Type *Next_Storage_Vessle;
};

struct Word_Record_Type *sorted_wrod;//1st pntr struct of 
void insert(char *name);//functions needed beyond local scope
int Line_Search();
int main()
{

    int cntr,Word_Count=0;//main's var declaration
    
   sorted_wrod=NULL;//initialize fst ptr
    
    void getfile();//function declations that do not require global scope
    int Read_Word();
    void display_Words();
    void search_word();
   
    //function calls and main program logic
    getfile();
 
    cntr=Read_Word(&Word_Count);
    printf("The number of words is %d",Word_Count);
    printf("\nThe number of unique words is %d\n",cntr);
    display_Words();
    search_word(cntr);
    fclose(inFile);
    printf("\nBye!");
     return 0;
}
void getfile()  //opens the file a user inputs, returns null if file not found. 
{
    char file[MAXCHARS];
    int count=0;
     
    do{
	scanf("%s",file);
	inFile = fopen(file,"r");
	
	if(inFile==NULL)
	{
	    printf("\n File not found for reading!\n");
	}
    }while(inFile==NULL);    
   
}

int Read_Word(int *count)//function to read and clean the words into from the file
{ 
    
    int forskey,wordskey=0;
    char word[100],diffy_word[100][100];
    fseek(inFile, 0, SEEK_SET);
    while( fscanf(inFile,"%29s",word)==1 )
    {
        *count+=1;
        int MeasureWord=strlen(word);
       
      if(ispunct(word[0])>0)
      {
          *count-=1;
          continue;
      }
       if(ispunct(word[MeasureWord-1])>0)
      {
          word[MeasureWord-1]='\0';
         
      }
      if(ispunct(word[MeasureWord-2])>0)
      {
          word[MeasureWord-2]='\0';
         
      }
      
      
  int Repeat_NUM=0;
if(strlen(word)>0)
{
    for(int k=0; k<wordskey;k++)
    {
        if(strcmp(diffy_word[k],word)==0)
        {
            Repeat_NUM+=1;
        }
    }
}
if (Repeat_NUM==0)
{
    strcpy(diffy_word[wordskey++],word);

    insert(word); // inserts the word onto the list when it has been scrubbed and is not a duplicate
}

    
  }

     return wordskey; 
}
void insert(char *name)
{
  struct Word_Record_Type *linearLocate(char *);  /* function prototype */
  struct Word_Record_Type *newaddr, *here;  /* pointers to structure */
                                   /* of type NameRec */


  newaddr = (struct Word_Record_Type*) malloc(sizeof(struct Word_Record_Type));
  if (newaddr == (struct Word_Record_Type *) NULL)  /* check the address */
  {
    printf("\nCould not allocate the requested space\n");
    exit(1);
  }

  /* locate where the new structure should be placed and */
  /* update all pointer members */
  if (sorted_wrod == NULL)  /* no list currently exists */
  {
    newaddr->Next_Storage_Vessle = NULL;
    sorted_wrod = newaddr;
  }
  else if (strcmp(name, sorted_wrod->A_Word) < 0) /* a new first structure */
  {
    newaddr->Next_Storage_Vessle = sorted_wrod;
    sorted_wrod = newaddr;
  }
  else  /* structure is not the first structure of the list */
  {
    here = linearLocate(name);
    newaddr->Next_Storage_Vessle = here->Next_Storage_Vessle;
    here->Next_Storage_Vessle = newaddr;
  }

  strcpy(newaddr->A_Word,name);  /* store the name */
}
/* This function locates the address of where a new structure 
   should be inserted within an existing list. 
   It receives the address of a name and returns the address of a      
   structure of type NameRec 
*/
struct Word_Record_Type *linearLocate(char *name)
{
  struct Word_Record_Type *one, *two;
  one = sorted_wrod;
  two = one->Next_Storage_Vessle;

  if (two == NULL)
    return(one);  /* new structure goes after the existing single structure */
  while(1)
  {
    if(strcmp(name,two->A_Word) < 0) /* if it is located within the list */
      break;
    else if(two->Next_Storage_Vessle == NULL)  /* it goes after the last structure */
    {
      one = two;
      break;
    }
    else  /* more structures to search against */
    {
      one = two;
      two = one->Next_Storage_Vessle;
    }
  }   /* the break takes us here */

  return(one);
}

/* display names from the linked list */
void display_Words()
{
  struct Word_Record_Type *contents;

  contents = sorted_wrod;
  printf("\nThe names currently in the list, in alphabetical");
  printf("\norder, are:\n");
  while (contents != NULL)  /* display till end of list */
  {
    printf("%s,",contents->A_Word);
    contents = contents->Next_Storage_Vessle;
  }
}
void search_word(int wordnum)
{
    
    char line[80];
    int index = 0;
    int lines = 0;
    
    char find_word[MAXCHARS];
    
   do{
    
    fseek(inFile, 0, SEEK_SET);
        printf("\n Please enter a word to be searched:");
        scanf("%s",find_word);
        
        if(find_word=="EINPUT")
        exit(1);
        
         int result = Line_Search(sorted_wrod, 0, wordnum, find_word); 
         int width;
     if(result == -1)
     {
         //printf("PRINT THE LINE WITH THE WORD HERE%s\n",find_word);
         
         while ( fgets(line, 80, inFile) != NULL)
         {
             lines++;
             if (index = strstr(line, find_word) != NULL)
             {
                 printf("Line number %d\n", lines);
                 printf("%s", line);
                 width=(strlen(line))-((sizeof(find_word)));
                 printf("%*c\b^\n",width,' ');
                 
             }
             
         }
         
     }
    else
    printf("\nThe word is not found in the text file.");
  
}
         
while(strcmp(find_word,"EINPUT")!=0);
    

}

int Line_Search(struct Word_Record_Type *head, int l, int r, char word[]) 
{ 
    
   
    
 //   printf("\nthe word sent in is%s\n",word);
   // printf("\n the word in contents is %s:",head->A_Word);
    while(head!=NULL)
    {
        if(strcmp(head->A_Word,word)==0)
        {
        //printf("found word %s\n",head->A_Word);
        return -1;
        }
        else
        head=head->Next_Storage_Vessle;
    }
    
    
} 

