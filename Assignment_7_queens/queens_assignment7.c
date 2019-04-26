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
/*      Assignment: 7                                       */
/*                                                          */
/*                                                          */
/*      Topic:  Chapter 23                                  */
/*                                                          */
/*      File name: queens_assignment.c                      */
/*                                                          */
/*      Date: May 14, 2016                                  */
/*                                                          */
/*      Objective: Place 8 queens on an 8x8 chess board so  */
/*      that none of the queens attack each other           */
/*                                                          */
/*      Comments: None                                      */
/************************************************************/

#include <stdio.h>
#include <stdbool.h>
#define BOARDSIZE 8
#define DIAGONAL (2 * BOARDSIZE - 1)
#define DOWNOFFSET 7
#define FALSE 0
#define TRUE 1
#define OUTPUT_FILE_PATH "output.txt"


void writeBoard (FILE *pOutputFile);
void clearBoard (void);
void addQueen (FILE *pOutputFile);

int queencol [BOARDSIZE]; /* queen column */
bool colfree [BOARDSIZE]; // is column free
bool upfree [DIAGONAL]; //up diagonal is free
bool downfree [DIAGONAL ]; //down diagonal free
int queencount = -1; // row queen is placed
int numsol= 0; // number of solutions found


int main (void)
{
    int i, quit = 1, user_choice;
    char user_choice_char;
    FILE *pOutputFile;

    pOutputFile = fopen(OUTPUT_FILE_PATH, "w");


    printf("Hello, which column (0-7) of row 0 would you like to place the first queen? ");
    fprintf(pOutputFile, "Hello, which column (0-7) of row 0 would you like to place the first queen? ");
    scanf(" %c", &user_choice_char);
    fprintf(pOutputFile, "%c\n", user_choice_char);
    while(user_choice_char < '0' || user_choice_char >= '7'){

        printf("Invalid argument, please select a number between 0 - 7: ");
        fprintf(pOutputFile, "Invalid argument, please select a number between 0 - 7: ");
        scanf(" %c", &user_choice_char);
        fprintf(pOutputFile, "%c\n", user_choice_char);

    }

    user_choice = user_choice_char - '0'; //converts user char to int
//    printf("user choice: %d\n", user_choice);


    while(quit == 1){

        clearBoard ();
        queencol[++queencount] = user_choice;
        colfree[user_choice] = FALSE;
        upfree[queencount + user_choice] = FALSE;
        downfree [queencount - user_choice + DOWNOFFSET] = FALSE;
        addQueen (pOutputFile);

        printf("Next column? (press 'x' to quit) ");
        fprintf(pOutputFile, "Next column? (press 'x' to quit) ");
        scanf(" %c", &user_choice_char);
        fprintf(pOutputFile, "%c\n", user_choice_char);

        while(user_choice_char < '0' || user_choice_char > '7' && user_choice_char != 'x'){

            printf("Invalid argument, please select a number between 0 - 7: ");
            fprintf(pOutputFile, "%c is an invalid argument, please select a number between 0 - 7: ", user_choice_char);
            scanf(" %c", &user_choice_char);
            fprintf(pOutputFile, "%c\n", user_choice_char);

        }
        if(user_choice_char == 'x')
            quit = 0;
        else
            user_choice = user_choice_char - '0';

    }
    /* end of for loop */
    return 0;
    /* end of main function */
}




void addQueen (FILE *pOutputFile)
{
    int col; /* column being tried for the queen */
    queencount++;
    for (col = 0; col < BOARDSIZE; col++)
    {
        if (colfree [col] && upfree [queencount + col] && downfree [queencount - col + DOWNOFFSET ] )
        { // put the queen in position (queencount, col)
            queencol [queencount] = col;
            colfree [col] = FALSE;
            upfree [queencount + col] = FALSE;
            downfree [queencount - col + DOWNOFFSET] = FALSE;

            if (queencount == BOARDSIZE - 1)
            { /* terminal condition */
            //    printf ("\n %d Queen Solution: %d\n\n", 8, ++numsol);
                writeBoard (pOutputFile);
            }
            else
                addQueen (pOutputFile); /* recursive call */
            if (queencount - 1 < 0)
                continue;
            colfree [col] = TRUE; // backtrack queen
            upfree[queencount - 1 + col] = TRUE;
            downfree [queencount - 1 - col + DOWNOFFSET] = TRUE;
            queencount--;
        } /* end of if colfree
            */
    }
/* end of for loop
*/
}



void writeBoard (FILE *pOutputFile) /* prints the output of N
queens placement */
{
    int col;
    static int qcount = 0;
    for (col = 0; col < BOARDSIZE; col++)
    {
        if(qcount == 0 && queencol [qcount] == col){ //places a 'U' for user selection
            printf ("U ");
            fprintf(pOutputFile, "U ");
        }
        else if (queencol [qcount] == col){
            printf ("Q ");
            fprintf(pOutputFile, "Q ");
        }
        else{
            printf ("* ");
            fprintf(pOutputFile, "* ");
        }
    }
    /* end of for loop */
    printf ("\n\n");
    fprintf(pOutputFile, "\n\n");
    if (qcount++ < BOARDSIZE - 1)
        writeBoard (pOutputFile);
    qcount = 0;
}
/* end of writeBoard function */
/* clears the board for next placement */

void clearBoard (void)
{
    for (int i = 0; i < BOARDSIZE; i++)
    {
        colfree [i] = TRUE;
        queencol [i] = -1;
    }
    /* end of for loop */
    for (int j = 0; j < DIAGONAL; j++)
    {
        upfree [j] = TRUE;
        downfree [j] = TRUE;
    }
    /* end of for loop */
    queencount = -1;
}
/* end of clearBoard function */
