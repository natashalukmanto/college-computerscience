#include "header.h"

// PrintHeading() prints the heading in console output
void PrintHeading()
{
	const char PROGRAMMER[30] = "Natasha Lukmanto";
	const char CLASS[6] = "CS 1B";
	const char SECTION[25] = "M-Th: 5:00p - 7:20p";
	const int LAB_NUM = 0 - 7;
	const char LAB_NAME[100] = "Assignment #2 – Multi-Dimensional Array - Tic Tac Toe";

	cout << left;
	cout << "**************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS"
		 << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION"
		 << ": " << SECTION;
	cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n**************************************************\n\n";
	cout << right;
}

void OutputInstruct()
{
	cout << "Hello! Welcome to Tic Tac Toe by Natasha Lukmanto." << endl
		 << endl;
	cout << "**************************************************\n\n";
	cout << "Instructions:" << endl;
	cout << "To play Tic Tac Toe, take turns placing your X or O marker on a 3x3 grid " << endl;
	cout << "with the objective of getting three of your markers in a row horizontally, vertically, or diagonally " << endl;
	cout << "while blocking your opponent from doing the same." << endl
		 << endl;
	cout << "**************************************************\n\n";
}

void InitBoard(char boardAr[][COLUMN_SIZE])
{
	for (int i = 0; i < ROW_SIZE; i++)
	{
		for (int j = 0; j < COLUMN_SIZE; j++)
		{
			boardAr[i][j] = ' ';
		}
	}
}

void DisplayBoard(const char boardAr[][COLUMN_SIZE])
{
	int i;
	int j;
	cout << endl;
	cout << setw(10) << "1" << setw(8) << "2" << setw(9) << "3\n";
	for (i = 0; i < 3; i++)
	{
		cout << setw(7) << "[" << i + 1 << "][1] | "
			 << "[" << i + 1;
		cout << "][2] | "
			 << "[" << i + 1 << "][3]" << endl;
		cout << setw(14) << "|" << setw(9) << "|" << endl;
		for (j = 0; j < 3; j++)
		{
			switch (j)
			{
			case 0:
				cout << i + 1 << setw(9) << boardAr[i][j];
				cout << setw(4) << "|";
				break;
			case 1:
				cout << setw(4) << boardAr[i][j];
				cout << setw(5) << "|";
				break;
			case 2:
				cout << setw(4) << boardAr[i][j] << endl;
				break;
			default:
				cout << "ERROR!\n\n";
			}
		}
		cout << setw(14) << "|" << setw(10) << "|\n";
		if (i != 2)
		{
			cout << setw(32) << "--------------------------\n";
		}
	}
	cout << endl
		 << endl;
}

void GetPlayers(string &playerX, string &playerO)
{
	cout << endl
		 << playerX << " will be playing X!" << endl;
	cout << playerO << " will be playing O!" << endl;
}

void GetAndCheckInp(char boardAr[][COLUMN_SIZE], char token, string playerX, string playerO, int &numOfMoves)
{
	bool valid = false;
	do
	{
		if (token == 'X')
		{
			cout << playerX;
		}
		else
		{
			cout << playerO;
		}

		cout << "\'s turn! What is your play?: ";
		cin >> row >> col;
		row--;
		col--;

		if (row > ROW_SIZE - 1 || row < 0)
		{
			cout << "Invalid row - Please try again!\n";
		}
		else if (col > COLUMN_SIZE || col < 0)
		{
			cout << "Invalid column - Please try again!\n";
		}
		else if (boardAr[row][col] != ' ')
		{
			cout << "That spot is already taken – try again!\n";
		}
		else
		{
			valid = true;
			numOfMoves++;
			cout << numOfMoves;
		}
	} while (!valid);
	boardAr[row][col] = token;
	cin.ignore(1000, '\n');
}

char SwitchToken(char token)
{
	if (token == 'X')
	{
		return 'O';
	}
	else
	{
		return 'X';
	}
}

char CheckWin(const char boardAr[][COLUMN_SIZE], int &numOfMoves)
{
	// Check for X's WINS
	for (int i = 0; i < 3; ++i)
	{
		if (boardAr[i][0] == 'X' && boardAr[i][1] == 'X' && boardAr[i][2] == 'X')
		{
			return 'X';
		}
		if (boardAr[0][i] == 'X' && boardAr[1][i] == 'X' && boardAr[2][i] == 'X')
		{
			return 'X';
		}
	}

	if (boardAr[0][0] == 'X' && boardAr[1][1] == 'X' && boardAr[2][2] == 'X')
	{
		return 'X';
	}
	if (boardAr[0][2] == 'X' && boardAr[1][1] == 'X' && boardAr[2][0] == 'X')
	{
		return 'X';
	}

	// Check for O's WINS
	for (int i = 0; i < 3; ++i)
	{
		if (boardAr[i][0] == 'O' && boardAr[i][1] == 'O' && boardAr[i][2] == 'O')
		{
			return 'O';
		}
		if (boardAr[0][i] == 'O' && boardAr[1][i] == 'O' && boardAr[2][i] == 'O')
		{
			return 'O';
		}
	}

	if (boardAr[0][0] == 'O' && boardAr[1][1] == 'O' && boardAr[2][2] == 'O')
	{
		return 'O';
	}
	if (boardAr[0][2] == 'O' && boardAr[1][1] == 'O' && boardAr[2][0] == 'O')
	{
		return 'O';
	}


	// Check for DRAW
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (numOfMoves >= 9) {
				// D for DRAW
				return 'D';
			} 
			else {
				return 'N';
			}
		}
	}
	// for game NOT finished.
	return 'N';
}

void OutputWinner(char whoWon, string playerX, string playerO)
{
	if (whoWon == 'X')
	{
		cout << playerX << " won this round of Tic Tac Toe!" << endl
			 << endl;
	}
	else if (whoWon == 'O')
	{
		cout << playerO << " won this round of Tic Tac Toe!" << endl
			 << endl;
	}
	else
	{
		cout << "This round is a draw!" << endl
			 << endl;
	}
}

void ComputerMove(char boardAr[][COLUMN_SIZE])
{
	bool blockMove = false;

	for (int i = 0; i < 3; i++)
	{
		int xCount = 0;
		int emptyCount = 0;
		for (int j = 0; j < 3; j++)
		{
			if (boardAr[i][j] == 'X')
			{
				xCount++;
			}
			else if (boardAr[i][j] == ' ')
			{
				emptyCount++;
				row = i;
				col = j;
			}
		}
		if (xCount == 2 && emptyCount == 1)
		{
			blockMove = true;
			break;
		}
	}

	// Check columns for potential winning move by the player
	if (!blockMove)
	{
		for (int j = 0; j < 3; j++)
		{
			int xCount = 0;
			int emptyCount = 0;
			for (int i = 0; i < 3; i++)
			{
				if (boardAr[i][j] == 'X')
				{
					xCount++;
				}
				else if (boardAr[i][j] == ' ')
				{
					emptyCount++;
					row = i;
					col = j;
				}
			}
			if (xCount == 2 && emptyCount == 1)
			{
				blockMove = true;
				break;
			}
		}
	}

	// Check diagonals for potential winning move by the player
	if (!blockMove)
	{
		int xCount = 0;
		int emptyCount = 0;
		// Main diagonal
		for (int i = 0; i < 3; i++)
		{
			if (boardAr[i][i] == 'X')
			{
				xCount++;
			}
			else if (boardAr[i][i] == ' ')
			{
				emptyCount++;
				row = i;
				col = i;
			}
		}
		if (xCount == 2 && emptyCount == 1)
		{
			blockMove = true;
		}
		// Counter diagonal
		if (!blockMove)
		{
			xCount = 0;
			emptyCount = 0;
			for (int i = 0; i < 3; i++)
			{
				if (boardAr[i][3 - 1 - i] == 'X')
				{
					xCount++;
				}
				else if (boardAr[i][3 - 1 - i] == ' ')
				{
					emptyCount++;
					row = i;
					col = 3 - 1 - i;
				}
			}
			if (xCount == 2 && emptyCount == 1)
			{
				blockMove = true;
			}
		}
	}

	// If there is a potential winning move by the player, block it
	if (blockMove)
	{
		boardAr[row][col] = 'O';
	}
	else
	{
		// If there is no potential winning move, make a random move
		while (true)
		{
			row = std::rand() % 3;
			col = std::rand() % 3;
			if (boardAr[row][col] == ' ')
			{
				boardAr[row][col] = 'O';
				break;
			}
		}
	}
}