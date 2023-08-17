/***********************************************************
 * AUTHOR		: Natasha Lukmanto
 * STUDENT ID	: 1253798
 * LAB #     	: Assignment #2 – Multi-Dimensional Array - Tic Tac Toe
 * CLASS 		: CS 1B
 * SECTION 		: M-Th : 5p - 7:20p
 * DUE DATE 	: Fri Jun 16, 2023 11:59pm
 **********************************************************/

#include "header.h"
#include "functions.cpp"

/***********************************************************
 *
 * Assignment #2 – Multi-Dimensional Array - Tic Tac Toe
 *
 * _________________________________________________________
 * This program allow two users or one user & computer
 * to play the game Tic Tac Toe
 * _________________________________________________________
 *
 * INPUT:
 * 	row: an integer variable from the user to specify the row
 *  col: an integer variable from the user to specify the column
 *
 * OUTPUT:
 *  the Tic-Tac-Toe game!
 *
 ***********************************************************/

int main()
{
    // VARIABLES & CONSTANTS
    int menu_option; // IN – option inputted by the user, depending on what to do
    string playerX = "X", playerO = "O"; // IN – players' name
    char boardAr[ROW_SIZE][COLUMN_SIZE];
    char winner;

    int numOfMoves;

    srand(time(NULL));

    PrintHeading();
    OutputInstruct();

    do {
        numOfMoves = 0;
        cout << "MAIN MENU" << endl;
        cout << "=========" << endl;
        cout << "0 – to exit" << endl
             << "1 – to set player names" << endl
             << "2 – to play in TWO PLAYER mode" << endl
             << "3 – to play in ONE PLAYER mode" << endl;
        cout << "Enter your menu option: ";
        cin >> menu_option;

        switch (menu_option)
        {
        case 0:
            cout << "Thank you for using my program!" << endl << endl;
            break;
        case 1:
            cout << endl << "Input player's X name: ";
            cin >> playerX;
            cout << "Input player's O name: ";
            cin >> playerO;
            GetPlayers(playerX, playerO);
            cout << endl;
            break;
        case 2:
            winner = 'N';
            token = 'X';
            InitBoard(boardAr);
            do {
                cout << endl << "Take a look at the board & make your move!" << endl;
                DisplayBoard(boardAr);
                cout << endl;
                GetAndCheckInp(boardAr, token, playerX, playerO, numOfMoves);
                DisplayBoard(boardAr);
                token = SwitchToken(token);
                winner = CheckWin(boardAr, numOfMoves);
            if (winner == 'X' || winner == 'O' || winner == 'D') { OutputWinner(winner, playerX, playerO); }
            } while (winner == 'N');
            cout << endl;
            break;
        case 3:
            winner = 'N';
            token = 'X';
            InitBoard(boardAr);
            do {
                cout << endl << "Take a look at the board & make your move!" << endl;
                DisplayBoard(boardAr);
                cout << endl;
                GetAndCheckInp(boardAr, token, playerX, playerO, numOfMoves);
                DisplayBoard(boardAr);
                cout << "It's the computer's turn!" << endl;
                ComputerMove(boardAr);
                DisplayBoard(boardAr);
                winner = CheckWin(boardAr, numOfMoves);
            if (winner == 'X' || winner == 'O' || winner == 'D') { OutputWinner(winner, playerX, playerO); }
            } while (winner == 'N');
            cout << endl;
            break;
        default:
            cout << "Invalid menu option. Please try again!" << endl << endl;
        }
    } while (menu_option != 0);
}