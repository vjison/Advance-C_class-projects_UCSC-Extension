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
/*      Assignment: 5                                       */
/*                                                          */
/*                                                          */
/*      Topic:  Chapter 10                                  */
/*                                                          */
/*      File name: PointerPractice.c                        */
/*                                                          */
/*      Date: May 8, 2016                                   */
/*                                                          */
/*      Objective: There is an integer 25, a float 3.142, a */
/*      double 1.73217, a string “Hello, C                  */
/*      Programmer”, and a char ‘x’.                        */
/*      All the above have their pointers and               */
/*      pointers are assigned the addresses of              */
/*      respective variables.                               */
/*      There is a special pointer which is a               */
/*      pointer to the integer pointer.                     */
/*      You can initialize all the variables and            */
/*      pointers at compile time. Print the                 */
/*      value of the variables, their addresses             */
/*      and the address of the pointers.                    */
/*      Dereference the pointers and print                  */
/*      the values at respective pointers.                  */
/*      Dereference the pointer to integer                  */
/*      pointer and print the value.                        */
/*                                                          */
/*      Comments: None                                      */
/************************************************************/

#include <stdio.h>
#include <stdlib.h>


int main(void){

    int int_var = 25, *intptr;
    float float_var = 3.142, *floatptr;
    double double_var = 1.73217, *doubleptr;
    char string_var[] = "Hello, C Programmer", *stringptr;
    char char_var = 'x', *charptr;

    intptr = &int_var;
    floatptr = &float_var;
    doubleptr = &double_var;
    stringptr = &string_var[0]; //pointer stringptr points to first index of character array string_var[]
    charptr = &char_var;


    printf("The variable int_var contains %d and is located at address %u.\nThe address of pointer intptr is %u\n\n", *intptr, intptr, &intptr);
    printf("The variable float_var contains %f and is located at address %u.\nThe address of pointer floatptr is %u\n\n", *floatptr, floatptr, &floatptr);
    printf("The variable double_var contains %f and is located at address %u.\nThe address of pointer doubleptr is %u\n\n", *doubleptr, doubleptr, &doubleptr);
    printf("The variable char_var contains %c and is located at address %u.\nThe address of pointer charptr is %u\n\n", *charptr, charptr, &charptr);
    printf("The string array string_car[] contains %s.  The address of string_car[0] is %u.\nThe address of pointer stringptr is %u\n\n", string_var, stringptr, &stringptr);




return 0;
}

















