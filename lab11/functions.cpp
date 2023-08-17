#include "header.h"

void PrintHeading(ostream& outFile) {
    const char PROGRAMMER[30] = "Natasha Lukmanto";
	const char CLASS[6] = "CS 1B";
	const char SECTION[25] = "M-Th: 5:00p - 7:20p";
	const int LAB_NUM = 0 - 7;
	const char LAB_NAME[50] = "Lab #11 - Introduction to Recursion";

	outFile << left;
	outFile << "**************************************************";
	outFile << "\n* PROGRAMMED BY : " << PROGRAMMER;
	outFile << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	outFile << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	outFile << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	outFile << "\n**************************************************\n\n";
	outFile << right;
}

string PrintHeading() {
    ostringstream oFile;
    const char PROGRAMMER[30] = "Natasha Lukmanto";
	const char CLASS[6] = "CS 1B";
	const char SECTION[25] = "M-Th: 5:00p - 7:20p";
	const int LAB_NUM = 0 - 7;
	const char LAB_NAME[50] = "Lab #11 - Introduction to Recursion";

	oFile << left;
	oFile << "**************************************************";
	oFile << "\n* PROGRAMMED BY : " << PROGRAMMER;
	oFile << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	oFile << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	oFile << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	oFile << "\n**************************************************\n\n";
	oFile << right;

    return oFile.str();
}

int RecursiveGCD(int num1, int num2, int originalNum1, int originalNum2, ofstream& outFile, bool outputFlag) {
    if (num2 == 0) {
        if (outputFlag) {
            outFile << "The GCD for " << originalNum1 << " & " << originalNum2 << " = " << num1 << endl;
        }
        return num1;
    }

    int gcd = RecursiveGCD(num2, num1 % num2, originalNum1, originalNum2, outFile, !outputFlag);

    if (num1 % num2 == 0 && outputFlag) {
        outFile << "The GCD for " << originalNum1 << " & " << originalNum2 << " = " << gcd << endl << endl;
    }

    return gcd;
}

int CalculateGCD(int num1, int num2, ofstream& outFile) {
    return RecursiveGCD(num1, num2, num1, num2, outFile, true);
}
