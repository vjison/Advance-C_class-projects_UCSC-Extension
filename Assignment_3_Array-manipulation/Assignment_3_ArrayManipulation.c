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
/*      Assignment: 3                                       */
/*                                                          */
/*                                                          */
/*      Topic:  Chapter 6                                   */
/*                                                          */
/*      File name: Assignment_3_ArrayManipulation.c         */
/*                                                          */
/*      Date: April 23, 2016                                */
/*                                                          */
/*      Objective: Read the input into an array from        */
/*      standard input as integer. Print array in original  */
/*      form, reverse order, and ascending order.           */
/*      Prompt user for number and return index location    */
/*                                                          */
/*      Comments: None                                      */
/************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 40

int main(void){

    int numArray[MAXLEN];
//    int numArrayDummy[] = {14, 17, 56, 85, 22, 97, 33, 71, 19, 62, 38, 44,
//                            51, 29, 77, 65, 40, 99, 4, 47, 67, 41, 23, 81,
//                            73, 8, 100, 35, 91, 58, 59, 25, 15, 38, 95, 60,
//                            20, 7, 60, 10};
    int i = 0, tempVar, ascend_pass;
    int userNumber, numberFound;


    printf("Enter %d digits:\n", MAXLEN);
    while(i<MAXLEN){

        scanf("%d", &numArray[i]);
        //printf("numArray[%d] = %d\n", i, numArray[i]);
        i++;

    }

//prints original array contents
    printf("Original array form: ");
    i = 0;
    while(i <= MAXLEN-1){
        printf(" %d", numArray[i]);
        i++;

    }

//prints reverse order of original array
    printf("\n\nReverse order of array: ");
    while(i > 0){
        i--;
        printf(" %d", numArray[i]);

    }

//rearranges the array in ascending order using bubble sort
    printf("\n\nAscending order: ");
    for(ascend_pass = 1; ascend_pass <= MAXLEN -1; ascend_pass++)
        for(i = 0; i <= MAXLEN -2; i++)
            if(numArray[i] > numArray[i +1]){
                tempVar = numArray[i];
                numArray[i] = numArray[i+1];
                numArray[i+1] = tempVar;
                }

    for(i = 0, numberFound = 0; i <= MAXLEN - 1; i++)
        printf(" %d", numArray[i]);


//requests input from user and returns index location of number
    printf("\n");
    while(1){
    printf("Select a number from the array; its index will be returned: ");
    scanf("%d", &userNumber);

    for(i = 0, numberFound = 0; i <= MAXLEN -1; i++){
        if(numArray[i] == userNumber){
            printf("%d found at index %d\n", userNumber, i);
            numberFound = 1;
            break;
        }
        }

        if(numberFound == 0){
            printf("%d does not exist in the array\n", userNumber);
        }
    }






return 0;
}
