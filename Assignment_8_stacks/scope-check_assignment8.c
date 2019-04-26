/************************************************************/
/*****                      prologue                    *****/
/*                                                          */
/*      University of California Extension, Santa Cruz      */
/*                                                          */
/*          Advance C Programming                           */
/*                                                          */
/*      Instructor: Rajainder A. Yeldandi                   */
/*                                                          */
/*      Author: Vincent Jison                               */
/*                                                          */
/*      Assignment: 8                                       */
/*                                                          */
/*                                                          */
/*      Topic:  Chapter 20                                  */
/*                                                          */
/*      File name: scope-check_assignment8.c                */
/*                                                          */
/*      Date: May 15, 2016                                  */
/*                                                          */
/*      Objective: Evaluate the validity of the scopes      */
/*      within an expression                                */
/*                                                          */
/*      Comments: None                                      */
/************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 150
#define EMPTYSTACK -1
#define FILE_PATH "input.txt"
#define OUTPUT_FILE_PATH "output.txt"

typedef struct theStack{

    int top;
    char stackContents[MAXLEN];

} CHSTACK;


void push(char x, CHSTACK *sp, FILE *pOutFile);
char pop(CHSTACK *sp, FILE *pOutFile);
int empty(CHSTACK *sp);
int main(void){

    char stringFromFile[MAXLEN];
    int i;
    FILE *pFile;
    FILE *pOutputFile;
    CHSTACK stack, *sptr;
    sptr = &stack;


    stack.top = EMPTYSTACK;


//opens input file:
    pFile = fopen(FILE_PATH, "r");
    if(pFile == NULL)
        printf("Error opening file.");
    else{
        fgets(stringFromFile, MAXLEN, pFile) != NULL; //copies contents of file into string
//        puts(stringFromFile); //prints string contents to screen
        fclose(pFile);
    }


//opens output file to be written to:
    pOutputFile = fopen(OUTPUT_FILE_PATH, "w");

//prints file contents to screen
fprintf(pOutputFile, "\nContents read from file: \n%s\n", stringFromFile);


    for(i = 0; stringFromFile[i] != '\0'; i++){

        if(stringFromFile[i] == '(' || stringFromFile[i] == '[' || stringFromFile[i] == '{'){
            push(stringFromFile[i], sptr, pOutputFile);
        }


        else if(stringFromFile[i] == ')' || stringFromFile[i] == ']' || stringFromFile[i] == '}'){
            if((*sptr).stackContents[(*sptr).top] == '(' && stringFromFile[i] == ')'){
                fprintf(pOutputFile,"Closing scope %c found, ", stringFromFile[i]);
                pop(sptr, pOutputFile);
            }
            else if((*sptr).stackContents[(*sptr).top] == '[' && stringFromFile[i] == ']'){
                fprintf(pOutputFile,"Closing scope %c found, ", stringFromFile[i]);
                pop(sptr, pOutputFile);
            }
            else if((*sptr).stackContents[(*sptr).top] == '{' && stringFromFile[i] == '}'){
                fprintf(pOutputFile,"Closing scope %c found, ", stringFromFile[i]);
                pop(sptr, pOutputFile);
            }
            else{
                fprintf(pOutputFile,"Last opening scope %c not match closing scope %c. Expression is invalid.\n", sptr->stackContents[sptr->top], stringFromFile[i]);
                exit(1);

            }
        }
     //   else
     //       fprintf(pOutputFile, "character %c read from string, ignored.\n", stringFromFile[i]);


    }

    fprintf(pOutputFile, "All opening and closing scopes verified. The expression is valid.\n");

    fclose(pOutputFile);
return 0;
}


//pushes char to top of stack
void push(char x, CHSTACK *sp, FILE *pOutFile){

    if ((*sp).top == MAXLEN - 1){
        fprintf(pOutFile, "stack full\n");
        exit(1);
    }
    else{
        (*sp).stackContents[++((*sp).top)] = x;

        fprintf(pOutFile,"pushing %c onto stack\n", x);
    }

return;
}

//checks stack if empty
int empty(CHSTACK *sp){

    if((*sp).top == -1){
    //    printf("empty!\n");
        return 1;
    }
    else{
    //    printf("not empty!\n");
        return 0;
    }
}

//pops char from top of stack
char pop(CHSTACK *sp, FILE *pOutFile){

    char pop_temp;

    if(empty(sp)){
        fprintf(pOutFile, "Stack is empty, no contents to pop\n");
        exit(1);
    }
    else{

        pop_temp = (*sp).stackContents[(*sp).top--];
        fprintf(pOutFile, "popping %c from stack\n", pop_temp);
        return pop_temp;
    }
}
