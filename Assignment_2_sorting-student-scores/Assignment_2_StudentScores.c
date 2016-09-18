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
/*      Assignment: 2                                       */
/*                                                          */
/*                                                          */
/*      Topic:  Chapter 2, 3, 4                             */
/*                                                          */
/*      File name: Assignment_1_Temperature.c               */
/*                                                          */
/*      Date: April 17, 2016                                */
/*                                                          */
/*      Objective: Print the average, max, min of all input */
/*      for student's exam scores.  Also print last score   */
/*      that was entered.                                   */
/*                                                          */
/*      Comments: None                                      */
/************************************************************/

#include <stdio.h>
#include <stdlib.h>


int main(void){

    int exams_total; //total scores to be entered
    int exam_score; //input from user

    float exams_average;
    float exams_sum = 0; //total sum of all scores entered so far
    int exams_max_score = -1;
    int exams_min_score = 101;

    int i = 1;  //keeps track of how many exams have been processed in loop

    printf("Hello, how many exam scores will you enter?\n");
    scanf("%d", &exams_total);
    if(exams_total == 0){

        printf("No scores entered.\n");
        return 0;

    }

    while(i <= exams_total){

        printf("\nEnter score: ");
        scanf("%d", &exam_score);

        if(exam_score > exams_max_score){
            exams_max_score = exam_score;
        }
        if(exam_score < exams_min_score){
            exams_min_score = exam_score;
        }


        exams_average = (exam_score + exams_sum) / i;

        exams_sum = exam_score + exams_sum; //total sum of scores entered so far; this is used in average calculation


        printf("Last score entered: %d\n", exam_score);
        printf("Average exam score: %.2f\n", exams_average);
        printf("Highest exam score: %d\n", exams_max_score);
        printf("Lowest exam score: %d\n", exams_min_score);


        i++;
    }

return 0;
}
