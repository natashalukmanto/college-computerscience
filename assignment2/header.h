#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//CONSTANTS
const int ROW_SIZE = 3;
const int COLUMN_SIZE = 3;

//VARIABLE
int row, col;
char token;

/******************************************************************************
 * OutputInstruct
 * This function outputs instructions to the users. There are no input
 * or output parameters for this function as it only displays text to
 * the screen.
 *
 * RETURNS: nothing
 * à Displays the instructions to the user
 *****************************************************************************/
void OutputInstruct();

/******************************************************************************
 * InitBoard
 * This function initializes each spot in the board to a space ' '.
 *
 * RETURNS: Board initialized with all spaces
 *****************************************************************************/
void InitBoard(char boardAr[][COLUMN_SIZE]); // OUT - tic tac toe board

/******************************************************************************
* DisplayBoard
* This function outputs the tic tac toe board including the tokens
* played in the proper format (as described below).
*
* 1 2 3
* [1][1] | [1][2] | [1][3]
* | |
* 1 | |
* | |
* --------------------------
* [2][1] | [2][2] | [2][3]
* | |
* 2 | |
* | |
* --------------------------
* [3][1] | [3][2] | [3][3]
* | |
* 3 | |
* | |
*
* RETURNS: nothing
* à outputs the current state of the board
ASSIGNMENT #2 Multi-Dimensional Arrays – TIC TAC TOE CS1B
4 of 5
*****************************************************************************/
void DisplayBoard(const char boardAr[][COLUMN_SIZE]); // IN - tic tac toe board

/******************************************************************************
 * GetPlayers
 * This function prompts the user and gets the input for the players’ names.
 * playerX will always contain the name of the player that is using the X token.
 * playerO will always contain the name of the player that is using the O token.
 *
 * RETURNS: the players names through the variables playerX and playerO.
 *****************************************************************************/
void GetPlayers(string &playerX,  // OUT - player X’s name
                string &playerO); // OUT - player O’x name

/******************************************************************************
 * GetAndCheckInp
 * This function switches the active player.
 * It takes in a parameter representing the current player's token
 * as a character value (either an X or an O) and returns the opposite.
 * For example, if this function receives an X it returns an 0. If it
 * receives and O it returns and X.
 *
 * RETURNS: the token opposite of the one in which it receives.
 *****************************************************************************/
void GetAndCheckInp(char boardAr[][COLUMN_SIZE], char token, string playerX, string playerO, int &numOfMoves);

/******************************************************************************
 * SwitchToken
 * This function switches the active player.
 * It takes in a parameter representing the current player's token
 * as a character value (either an X or an O) and returns the opposite.
 * For example, if this function receives an X it returns an 0. If it
 * receives and O it returns and X.
 *
 * RETURNS: the token opposite of the one in which it receives.
 *****************************************************************************/
char SwitchToken(char token); // IN - current player’s token ('X' or 'O')

/******************************************************************************
 * CheckWin
 * This function checks to see if either player has run. Once it is
 * possible for a win condition to exist, this should run after each a
 * player makes a play.
 *
 * RETURNS the character value of the player that won or a value that
 * indicates a tie.
 *****************************************************************************/
char CheckWin(const char boardAr[][COLUMN_SIZE], int &numOfMoves); // IN - tic tac toe board

/******************************************************************************
 * OutputWinner
 * This function receives as input a character indicating which player won
 * or if the game was a tie and outputs an appropriate message. This function
 * does not return anything as it simply outputs the appropriate message to
 * the screen.
 *
 * RETURNS: nothing
 * à Displays the winner’s name
 *****************************************************************************/
void OutputWinner(char whoWon, // IN - represents the winner or a value
                  // indicating a tied game.
                  string playerX,  // OUT - player X’s name
                  string playerO); // OUT - player O’x name

#endif /* HEADER_H_ */