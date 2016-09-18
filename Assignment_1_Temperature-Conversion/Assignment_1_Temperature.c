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
/*      Assignment: 1                                       */
/*                                                          */
/*                                                          */
/*      Topic:  Chapter 1 and 2                             */
/*                                                          */
/*      File name: Assignment_1_Temperature.c               */
/*                                                          */
/*      Date: April 17, 2016                                */
/*                                                          */
/*      Objective: Converts the temperature from Celsius to */
/*      Fahrenheit degree, or vice-versa                    */
/*                                                          */
/*      Comments: None                                      */
/************************************************************/

#include <stdio.h>
#include <stdlib.h>


int main(void){

    float userTemperature;
    int userConversionSelection;


    printf("Hello! What temperature (in degrees) would you like to convert?\n");
    scanf("%f", &userTemperature);

    printf("Press 1 to convert %.2f to Celsius, or 0 to convert %.2f to Farhenheit\n", userTemperature, userTemperature);
    scanf("%d", &userConversionSelection);

    /*Error checks user input*/
    while(userConversionSelection != 0 && userConversionSelection != 1){

        printf("Invalid selection, please press 1 to convert %0.2f to Celsius, or 0 to convert %0.2f to Farhenheit\n", userTemperature, userTemperature);
        scanf("%d", &userConversionSelection);

    }


    /*Farhenheit to Celsius calculation*/
    if(userConversionSelection ==  1){

        printf("Farhenheit scale is %.2f, equivalent Celsius is %.2f\n", userTemperature, ((userTemperature -32)*5/9));

    }

    /*Celsius to Farhenheit calculation*/
    if(userConversionSelection ==  0){

        printf("Celsius scale is %.2f, equivalent Farhenheit is %.2f\n", userTemperature, ((userTemperature * 9 /5)+32));

    }


return 0;
}
