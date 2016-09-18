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
/*      Assignment: 4                                       */
/*                                                          */
/*                                                          */
/*      Topic:  Chapter 10                                  */
/*                                                          */
/*      File name: StudentScores.c                          */
/*                                                          */
/*      Date: May 8, 2016                                   */
/*                                                          */
/*      Objective: Read 4 or 6 students scores from a file  */
/*      and find the average, min, max score for each       */
/*      student.                                            */
/*                                                          */
/*      Comments: None                                      */
/************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //needed for isdigit() and isspace() functions

#define FILE_PATH "input.txt"
#define OUTPUT_FILE_PATH "output.txt"
#define MAX_LEN 300

int convertCharToIntArray(char fromFile[], int intArray[]);
int find_Max(int integerArray[]);
int find_Min(int integerArray[]);
float find_Average(int integerArray[], int totalExams);
int student_ID_increment(void);
void return_grade(float score, FILE *fpout);


int main(void){

    char stringFromFile[MAX_LEN];
    int integerArray[MAX_LEN];
    int student_data_processed[MAX_LEN];
    FILE *pFile;
    FILE *pOutputFile;
    int exams_total; //total exam scores
    int exam_score; //input from user
    int total_students;
    int exams_per_student;
    int ID;

    float exams_average;
    float exams_sum = 0; //total sum of all scores entered so far


    int i = 0;  //keeps track of how many exams have been processed in loop

//opens file:
    pFile = fopen(FILE_PATH, "r");
    if(pFile == NULL)
        printf("Error opening file.");
    else{
        if(fgets(stringFromFile, MAX_LEN, pFile) != NULL) //copies contents of file into string
        //    puts(stringFromFile); //prints string contents to screen
        fclose(pFile);
    }

//prints file contents to screen
printf("\nExam scores read from file: %s\n", stringFromFile);

    exams_total = convertCharToIntArray(stringFromFile, integerArray); //converts string array into integer array for ease of use. returns total exams read



//requests input from user
    pOutputFile = fopen(OUTPUT_FILE_PATH, "w");

    printf("Hello. Are there 4 or 6 students?\n");
    scanf("%d", &total_students);
    while(total_students != 4 && total_students != 6){

        printf("Incorrect, please choose 4 or 6\n");
        scanf("%d", &total_students);

    }

//prints results to file:
    while((ID = student_ID_increment()) != total_students){
        fprintf(pOutputFile, "Student %d exam statistics: \n", ID + 1);
        i = 0;
        exams_per_student = exams_total / total_students;
        fprintf(pOutputFile, "Exam scores: ");
        while(i != exams_per_student){
            student_data_processed[i] = integerArray[(ID * exams_per_student)+i];
            fprintf(pOutputFile, "%d ", student_data_processed[i]);
            i++;
        }
        student_data_processed[i] = '\0';
        fprintf(pOutputFile, "\n"); //formatting


        fprintf(pOutputFile, "Maximum score: %d, Grade: ", find_Max(student_data_processed));
        return_grade(find_Max(student_data_processed), pOutputFile);
        fprintf(pOutputFile, "\nMinimum score: %d, Grade: ", find_Min(student_data_processed));
        return_grade(find_Min(student_data_processed), pOutputFile);
        fprintf(pOutputFile, "\nAverage score: %.2f, Grade: ",find_Average(student_data_processed, exams_per_student));
        return_grade(find_Average(student_data_processed, exams_per_student), pOutputFile);
        fprintf(pOutputFile, "\n\n"); //formatting
    }

    fclose(pOutputFile);


return 0;
}


//function that converts the string array into an interger array
int convertCharToIntArray(char fromFile[], int intArray[]){

    int i, j = 0;
    int exam_score;

        for(exam_score = 0, i = 0 ; fromFile[i] != '\0' ; i++){
            while(isdigit(fromFile[i])){
                exam_score = (exam_score * 10) + (fromFile[i] - 48); //fromFile[i] returns the decimal value of ASCII value of the number, and subtracts 48 to return actual number.
                i++;                          //Ex: char 2 is 50 decimal value. subtract 48 to give you 2 decimal value, which can be used in calculations
            }

            intArray[j] = exam_score; //pass newly converted integer into integer array

            if(isspace(fromFile[i]) && isdigit(fromFile[i+1])){ //checks for new upcoming integer, then increments index of integer array
                exam_score = 0;
                j++;
            }
        }

//printf("intArray[] = %d\n", intArray[9]); //for debug
return j + 1; //total number of scores

}

//function that assigns the student number using a static variable which will automatically
//increment each time the function is called
int student_ID_increment(void){

    static int studentID = -1;

    studentID++;

    return studentID;

}



int find_Max(int integerArray[]){



    int i = 0;
    int exams_max_score = -1;

    while(integerArray[i] != '\0'){

        if(integerArray[i] > exams_max_score){

                    exams_max_score = integerArray[i];
                }
    i++;
    }

//printf("Highest exam score: %d\n", exams_max_score);

return exams_max_score;


}

int find_Min(int integerArray[]){


    int i = 0;
    int exams_min_score = 101;

    while(integerArray[i] != '\0'){

        if(integerArray[i] < exams_min_score){
                    exams_min_score = integerArray[i];
            }
    i++;
    }

//printf("Lowest exam score: %d\n", exams_min_score);
return exams_min_score;
}

float find_Average(int integerArray[], int totalExams){

    int i = 0;
    float exams_average, exams_sum = 0;

    while(i <= totalExams){

        exams_sum = exams_sum + integerArray[i]; //total sum of scores entered so far; this is used in average calculation
        i++;

    }

//        printf("Average exam score: %.2f\n", exams_average);

return exams_average = exams_sum / totalExams;


}


void return_grade(float score, FILE *fpout){

    if(score > 95)
        fprintf(fpout, "A+");
    else if(score == 95)
        fprintf(fpout, "A");
    else if(score >= 90)
        fprintf(fpout, "A-");
    else if(score > 85)
        fprintf(fpout, "B+");
    else if(score == 85)
        fprintf(fpout, "B");
    else if(score >= 80)
        fprintf(fpout, "B-");
    else if(score > 75)
        fprintf(fpout, "C+");
    else if(score ==  75)
        fprintf(fpout, "C");
    else if(score > 70)
        fprintf(fpout, "C-");
    else if(score >=60)
        fprintf(fpout, "D");
    else if(score < 60)
        fprintf(fpout, "F");

}
