#include "header.h"

void PrintHeading() {
	const char PROGRAMMER[30] = "Natasha Lukmanto";
	const char CLASS[6] = "CS 1B";
	const char SECTION[25] = "M-Th: 5:00p - 7:20p";
	const int LAB_NUM = 0 - 7;
	const char LAB_NAME[100] = "Lab #7 - Testing";

	cout << left;
	cout << "**************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n**************************************************\n\n";
	cout << right;
}

void ChocolatesForSheeps(int total_sheeps, int total_chocolates, int *chocolate, int *remainder) {
    *chocolate = total_chocolates / total_sheeps;
    *remainder = total_chocolates % total_sheeps;

    if (*chocolate > 4) {
        *chocolate = 4;
        total_chocolates = total_chocolates - (total_sheeps * 4);
        *remainder = total_chocolates;
    }
}