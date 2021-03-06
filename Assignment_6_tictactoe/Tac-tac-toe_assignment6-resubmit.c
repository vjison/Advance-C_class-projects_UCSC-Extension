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
/*      Assignment: 6                                       */
/*                                                          */
/*                                                          */
/*      Topic:  Chapter 10                                  */
/*                                                          */
/*      File name: Tic-tac-toe.c                            */
/*                                                          */
/*      Date: May 9, 2016                                   */
/*                                                          */
/*      Objective: Create a tic-tac-toe game and print      */
/*      results to a file.                                  */
/*                                                          */
/*      Comments: None                                      */
/************************************************************/



#include <stdio.h>
#include <stdlib.h>

#define BOARD_DIM 4 //minimum is 2

#define OUTPUT_FILE_PATH "tic-tac-toe-output.txt"
#define MAX_LEN 1000

void emptyBoard(char board[BOARD_DIM][BOARD_DIM]);
void printBoard(char board[BOARD_DIM][BOARD_DIM], FILE *pFile);
int main(void){

    char board_game[BOARD_DIM][BOARD_DIM];
    char win_check[BOARD_DIM];
    char recent_player, choice;
    int x, y; //x is row and y is column of board game
    int status = 1, drawcheck = 0;
    int player1_x, player1_y, player2_x, player2_y;
    int turn = 1; //1 = player 1, 2 = player 2
    int turnsTaken = 0; //keeps track of total moves made

    FILE *pOutputFile;

    //opens output text file
    pOutputFile = fopen(OUTPUT_FILE_PATH, "w");

    //initialize empty board game
    emptyBoard(board_game);

    //prints current board
        fprintf(pOutputFile, "Starting board:\n");
        printf("Starting board:\n");
    printBoard(board_game, pOutputFile);

    while(status >= 1){  // 0 for winner found, -1 for draw

        if(turn == 1){
            printf("\nPlayer 1 (X), choose row coordinate: ");
            scanf("%d", &player1_x);
            printf("Player 1 (X), choose column coordinate: ");
            scanf("%d", &player1_y);

            board_game[player1_x][player1_y] = recent_player = 'X';
        }

        if(turn == 2){
            printf("\nPlayer 2 (O), choose row coordinate: ");
            scanf("%d", &player2_x);
            printf("Player 2 (O), choose column coordinate: ");
            scanf("%d", &player2_y);

            board_game[player2_x][player2_y] = recent_player = 'O';
        }

    //check for win in rows:
        for(x = 0; x < BOARD_DIM; x++){
            for(y = 0 ;(board_game[x][0] == board_game[x][y]) && (board_game[x][y] != '_')&& y < BOARD_DIM ; y++)
                ;
            if(y == BOARD_DIM){

                status = 0; //winner found
                printf("\nwinner found in row!\n");
            }
        }


    //check for win in columns:
        for(y = 0; y < BOARD_DIM; y++){
            for(x = 0 ;(board_game[0][y] == board_game[x][y]) && (board_game[x][y] != '_') && x < BOARD_DIM ; x++){
                if(x == BOARD_DIM - 1){

                    status = 0; //winner found
                    printf("\nwinner found in column!\n");
                }
            }
        }

    //check for win in diagonal R to L:
        for(x = 1, y = BOARD_DIM-1; x < BOARD_DIM && y >= 0 && (board_game[0][BOARD_DIM-1] == board_game[x][y-1]) && board_game[0][BOARD_DIM-1] != '_'; x++, y--){

            if(y == 1){

                status = 0; //winner found

                printf("\nwinner found in diagonal R to L!\n");
            }
        }

    //check for win in diagonal L to R:
        for(x = 0, y = 0; x < BOARD_DIM && y < BOARD_DIM && (board_game[0][0] == board_game[x][y]) && board_game[0][0] != '_'; x++, y++){
            if(y == BOARD_DIM - 1){

                status = 0; //winner found
                printf("\nwinner found in diagonal L to R!\n");
            }
        }

    //check for DRAW (full board)
/*
        for(x = 0; x < BOARD_DIM && status != 0; x++){
            for(y = 0 ;(board_game[x][y] != '_') && y < BOARD_DIM ; y++){
                if(y == BOARD_DIM - 1){
                    drawcheck++; //increases by one each time a full row is found
                    printf("drawcheck = %d!!!!!\n", drawcheck);
                    if(drawcheck == 3){
                        printf("\nBoard full, this game is a draw!\n");
                        fprintf(pOutputFile, "\nBoard full, this game is a draw!\n"); //print to file
                        status = -1;
                    }
                }
            }
        }
*/

    //print board

      printBoard(board_game, pOutputFile);

        if(status == 1 && turn == 1){
            turn = 2;
            ++turnsTaken;
            }
        else if(status == 1 && turn == 2){
            turn = 1;
            ++turnsTaken;
            }


        if((turnsTaken == BOARD_DIM * BOARD_DIM) && status != 0){
            printf("\nBoard full, this game is a draw!\n");
            fprintf(pOutputFile, "\nBoard full, this game is a draw!\n"); //print to file
            status = -1;
        }

    printf("turns Taken = %d\n", turnsTaken);

////

        if(status == 0){ //winner found

            if(turn == 1){
                printf("Winner is player 1 (X)!\n");
                fprintf(pOutputFile, "Winner is player 1 (X)!\n");
            }
            else if(turn == 2){
                printf("Winner is player2 (O)!\n");
                fprintf(pOutputFile, "Winner is player 2 (O)!\n");
            }
        }

        if(status == 0 || status == -1){
            printf("Play again? (Y/N) ");
            fprintf(pOutputFile, "Play again? (Y/N) ");

            scanf(" %c", &choice);
            fprintf(pOutputFile, "%c \n", choice);

            if(choice == 'Y' || choice == 'y'){
                status = 1;
                emptyBoard(board_game);
                printBoard(board_game, pOutputFile);
                turnsTaken = 0;
                turn = 1;
            }
            else{
                status = 0;
                printf("end game.\n");
                fprintf(pOutputFile, "end game\n");
            }
        }

////



    }




    fclose(pOutputFile);
/*
while (neither PLAYER1 nor PLAYER2 has won, and the board is not full){

    get player PLAYER1 to make a move
    if (PLAYER1 has not won and the board is not full)
        get player PLAYER2 to make a move
}

if (the loop is over, either a player has won or the board is full)
if (player PLAYER1 has won), write PLAYER1 message
else if (player PLAYER2 has won),
write PLAYER2 message
else the board must be full and the game tied.
write the draw message

*/

return 0;
}



void emptyBoard(char board[BOARD_DIM][BOARD_DIM]){
    int x, y;
    //initialize empty board game
    for(x = 0; x < BOARD_DIM; x++){
        for(y = 0; y < BOARD_DIM; y++){
            board[x][y] = '_';
        }
    }

}

void printBoard(char board[BOARD_DIM][BOARD_DIM], FILE *pFile){

    int x, y;
    //print starting board to file

    fprintf(pFile, "\nR\\C 0,1,2,3\n");
    for(x = 0; x < BOARD_DIM; x++){
            fprintf(pFile, "%d   ", x);
        for(y = 0; y < BOARD_DIM; y++){
            fprintf(pFile, "%c",board[x][y]);
            fprintf(pFile, " ");
        }
        fprintf(pFile, "\n");
    }

    //print starting board to screen

    printf("\nR\\C 0,1,2,3\n");
    for(x = 0; x < BOARD_DIM; x++){
        printf("%d   ", x);
        for(y = 0; y < BOARD_DIM; y++){
            printf("%c",board[x][y]);
            printf(" ");
        }
        printf("\n");
    }


}
