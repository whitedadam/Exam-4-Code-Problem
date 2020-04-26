/*
* Program Name: COP 2220 Exam 4 Coding Portion
*
* Description: This program is the coding portion of the 4th Exam. It is a 
* program that will read a paragraph from a file and report statics on the 
* various elements within the file.
*
* Author: John Adam Whited N1456488
*
* Date: 4/25/2020
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_CHARS 80
#define FLUSH while(getchar() != '\n')

void GetFileName(char*);
void ReadFileArray(char*, char[][MAX_CHARS], char* newArray);
void ResizeArray(char[][MAX_CHARS], char*);
void PrintArray(char[][MAX_CHARS]);
int CountAlph(int, char*);
int CountDigit(int, char[][MAX_CHARS]);
int CountPunc(int, char[][MAX_CHARS]);
void ReportTotals(int, int, int);

int main(void) {

  char *fileName; 
  char fileText[MAX_LINES][MAX_CHARS];
  char * newArray;
  int alpha, digit, punct;
  int i, j;

  GetFileName(fileName);
  ReadFileArray(fileName, fileText, newArray);
  ResizeArray(fileText, newArray);

  //PrintArray(fileText); //Test Function to measure dynamic array allocation

  alpha = CountAlph(alpha, newArray);
  digit = CountDigit(digit, fileText);
  punct = CountPunc(punct, fileText);

  ReportTotals(alpha, digit, punct);

  return 0;
}//End main

void GetFileName(char* fileName){

 /*
  * Function Name: GetFileName()
  *
  * Input Parameters: Takes a char pointer named fileName
  *
  * Description: This function prompts the user for a file name. It then
  * returns this variable to the main function for use in other parts of the 
  * application.
  *
  * Return Value: Return value is set to void, but it returns char pointer 
  * fileName.
  */

  printf("This application will scan your document and report character statistics.\n");
  printf("Please enter your file name ending with '.txt'.: \n");
  scanf("%s", fileName);

  return;
}//End Function

void ReadFileArray(char* fileName, char fileText[][MAX_CHARS], char* newArray){

  /*
  * Function Name: ReadFileArray()
  *
  * Input Parameters: char* fileName, char fileText[][MAX_CHARS]
  *
  * Description: This function takes the fileName given by user and opens the file. It then loads the array of fileText.
  *
  * Return Value: Return value is set to void, but it returns the fileText Array.
  */
  
  FILE *fp;
  int i, j;
  char* newLen = NULL;

  fp = fopen(fileName, "r");

  if (fileName == NULL){
    printf("The file could not be processed. Check the name and try again.\n");
  }
  else {
  printf("\nSuccess! Now analyzing your file.\n");  
  }

  for (i = 0; i < MAX_LINES; i++){
    for (j = 0; j < MAX_CHARS; j++){  
      
      if (EOF == 0){
        break;
      }
      else if (fscanf(fp, "%c", &fileText[i][j]) != '\0'){
        continue;
      }
      else{
        fscanf(fp, "%c", &fileText[i][j]);
      }
    }
  }//End For Loop

  fclose(fp);

  return;
}//End Function

void ResizeArray(char fileText[][MAX_CHARS], char* newArray){

  /*
  * Function Name: ResizeArray()
  *
  * Input Parameters: char fileText[][MAX_CHARS], char* newArray
  *
  * Description: This function takes the fileText array and loads the string into a new pointer array.
  *
  * Return Value: Return value is set to void, but it returns the newArray point array.
  */

  int n, i, j;
  int newLen = 0;
  
  printf("\n");
  
  for (i = 0; i < strlen(fileText[i]); i++){

      n = strlen(fileText[i]);      
      newArray = (char*)calloc(n, sizeof(char)); 
      strcpy(newArray, fileText[i]);
      printf("%s", &newArray[i]);
    
  }
  
  free(newArray);

  printf("\n");

  return;
}//End Function

void PrintArray(char fileText[][MAX_CHARS]){

  /*
  * Function Name: PrintArray()
  *
  * Input Parameters: fileText[][MAX_CHARS] array
  *
  * Description: This function prints the array for testing proper array scanning.
  *
  * Return Value: Returns void. This function is a test function.
  */

  int i, j;

  for (i = 0; i < MAX_LINES; i++){
    for (j = 0; j < MAX_CHARS; j++){

        if(fileText[i][j] != '\0'){
          printf("%c", fileText[i][j]);
        }
    }
  }
  
  printf("\n");

  return;
}//End Function

int CountAlph(int alpha, char* newArray){

  /*
  * Function Name: CountAlpha()
  *
  * Input Parameters: Takes a the alpha integer and the fileText array
  *
  * Description: This function counts the number of alphabetic characters in the array.
  *
  * Return Value: Returns value of alpha.
  */

  int i, j;

  for (i = 0; i < MAX_LINES; i++){
    for (j = 0; j < MAX_CHARS; j++){

        if (isalpha(newArray[i]) == 0){
          alpha++;
        }
    
    }
  }

  return alpha;
}//End Function

int CountDigit(int digit, char fileText[][MAX_CHARS]){

  /*
  * Function Name: CountDigit()
  *
  * Input Parameters: Takes the digit integer and the fileText array
  *
  * Description: This function counts the number of numeric characters in the array.
  *
  * Return Value: Returns value of digit.
  */
  
  int i, j;

  for (i = 0; i < MAX_LINES; i++){
    for (j = 0; j < MAX_CHARS; j++){

        if (isdigit(fileText[i][j]) == 0){
          digit++;
        }
    
    }
  }

  return digit;
}//End Function

int CountPunc(int punct, char fileText[][MAX_CHARS]){

  /*
  * Function Name: CountDigit()
  *
  * Input Parameters: Takes in the punct integer and the fileText array
  *
  * Description: This function counts the number of punctuation characters in the array.
  *
  * Return Value: Returns value of punct.
  */
  
  int i, j;

  for (i = 0; i < MAX_LINES; i++){
    for (j = 0; j < MAX_CHARS; j++){

        if (ispunct(fileText[i][j]) == 0){
          punct++;
        }
    
    }
  }
  
  return punct;
}//End Function

void ReportTotals(int alpha, int digit, int punct){

  /*
  * Function Name: ReportTotals()
  *
  * Input Parameters: Takes in the alpha, digit, and punct integers
  *
  * Description: This function prints the totals found for CountAlph, CountDigit and CountPunc
  *
  * Return Value: Returns void.
  */

  printf("\nAfter scanning your document, here are the totals on alphabetic, numeric, and puntuation characters.\n\n");
  printf("Alphabetic: %d\n", alpha);
  printf("Digits: %d\n", digit);
  printf("Punctuation: %d\n", punct);
  
  return;
}//End Function