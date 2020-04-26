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

void GetFileName(char*);
void ReadFileArray(char*, char[][MAX_CHARS]);
void ResizeArray(char[][MAX_CHARS]);
void PrintArray(char[][MAX_CHARS]);
int CountAlph(int, char[][MAX_CHARS]);
int CountDigit(int, char[][MAX_CHARS]);
int CountPunc(int, char[][MAX_CHARS]);
void ReportTotals(int, int, int);

int main(void) {

  char *fileName; 
  char fileText[MAX_LINES][MAX_CHARS];
  int alpha, digit, punct;
  int i, j;

  GetFileName(fileName);
  ReadFileArray(fileName, fileText);
  ResizeArray(fileText);

  PrintArray(fileText); //Test Function to measure dynamic array allocation

  alpha = CountAlph(alpha, fileText);
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

void ReadFileArray(char* fileName, char fileText[][MAX_CHARS]){

  FILE *fp;
  int i, j;
  char* newLen = NULL;
  char* newArray[10][10];

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
      /*else if (scanf("%c", &fileText[i][j]) != EOF){
        newLen = (char*)calloc(strlen(newArray), sizeof(char));
        newArray[i][j] = newLen;
      }*/
      else {
        fscanf(fp, "%c", &fileText[i][j]);
      }
    
    }
  }//End For Loop

  fclose(fp);

  return;
}//End Function

void ResizeArray(char fileText[][MAX_CHARS]){

  int i, j;
  int newLen = 0;

  

  for (i = 0; i < MAX_LINES; i++){
    for (j = 0; j < MAX_CHARS; j++){

      
    }
  }
  
  /*for (i = 0; i < MAX_LINES; i++){

    if ((isalpha(fileText[i][0]) == 0) || (isdigit(fileText[i][0]) == 0) || (ispunct(fileText[i][0]) == 0)) {
      newLen++;
    }
  }

  printf("\n%d\n", newLen);*/

  return;
}//End Function

void PrintArray(char fileText[][MAX_CHARS]){

  int i, j;

  for (i = 0; i < MAX_LINES; i++){
    for (j = 0; j < MAX_CHARS; j++){

        printf("%c", fileText[i][j]);
    
    }
  }
  
  printf("\n");

  return;
}//End Function

int CountAlph(int alpha, char fileText[][MAX_CHARS]){

  int i, j;

  for (i = 0; i < MAX_LINES; i++){
    for (j = 0; j < MAX_CHARS; j++){

        if (isalpha(fileText[i][j])){
          alpha++;
        }
    
    }
  }

  return alpha;
}//End Function

int CountDigit(int digit, char fileText[][MAX_CHARS]){

  int i, j;

  for (i = 0; i < MAX_LINES; i++){
    for (j = 0; j < MAX_CHARS; j++){

        if (isdigit(fileText[i][j])){
          digit++;
        }
    
    }
  }

  return digit;
}//End Function

int CountPunc(int punct, char fileText[][MAX_CHARS]){

  int i, j;

  for (i = 0; i < MAX_LINES; i++){
    for (j = 0; j < MAX_CHARS; j++){

        if (ispunct(fileText[i][j])){
          punct++;
        }
    
    }
  }
  
  return punct;
}//End Function

void ReportTotals(int alpha, int digit, int punct){

  printf("\nAfter scanning your document, here are the totals on alphabetic, numeric, and puntuation characters.\n\n");
  printf("Alphabetic: %d\n", alpha);
  printf("Digits: %d\n", digit);
  printf("Punctuation: %d\n", punct);
  
  return;
}//End Function