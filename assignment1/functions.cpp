#include "header.h"

void PrintHeading(ostream& outFile) {
    const char PROGRAMMER[30] = "Natasha Lukmanto";
	const char CLASS[6] = "CS 1B";
	const char SECTION[25] = "M-Th: 5:00p - 7:20p";
	const int LAB_NUM = 0 - 7;
	const char LAB_NAME[50] = "Assignment #1 – Functions and Arrays";

	outFile << left;
	outFile << "**************************************************";
	outFile << "\n* PROGRAMMED BY : " << PROGRAMMER;
	outFile << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	outFile << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	outFile << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	outFile << "\n**************************************************\n\n";
	outFile << right;
}

void GetInput(ifstream& inFile, string names[], int ids[], double balances[]) {
	int i = 0; string name;

	while (!inFile.eof() && i < 10) {
		getline(inFile, name);
		names[i] = name;
		inFile >> ids[i] >> balances[i];
		inFile.ignore(1000, '\n');
		i += 1;
	}
}

int SearchBalance(char L_or_S, string names[], int ids[], double balances[], ostream& outFile) {
	int index_answer; int temp;
	if (L_or_S == 'L') {
		temp = balances[0];
		for (int i = 0; i < 10; i++) {
			if (balances[i] > temp) { 
				temp = balances[i];
				index_answer = i;
				}
		}
		outFile << left;
		outFile << "Larger Balance:" << endl;
		outFile << setw(9) << "ID #" << setw(25) << "NAME" << setw(11) << "BALANCE DUE" << endl;
		outFile << setw(9) << "----" << setw(25) << "--------------------" << setw(11) << "-----------" << endl;
		outFile << setw(9) << ids[index_answer] << setw(25) << names[index_answer];
		outFile << setw(5) << "$" << right << balances[index_answer] << endl << endl;
		//!! How did you set up the $ and the balances correctly?
	} else {
		temp = balances[0];
		for (int i = 0; i < 10; i++) {
			if (balances[i] < temp) { 
				temp = balances[i];
				index_answer = i;
				}
		}
		outFile << left;
		outFile << "Smaller Balance:" << endl;
		outFile << setw(9) << "ID #" << setw(25) << "NAME" << setw(11) << "BALANCE DUE" << endl;
		outFile << setw(9) << "----" << setw(25) << "--------------------" << setw(11) << "-----------" << endl;
		outFile << setw(9) << ids[index_answer] << setw(25) << names[index_answer];
		outFile << setw(6) << "$" << right << balances[index_answer] << endl << endl;
	}
	return index_answer;
}

float SumOrAvg(char S_or_A, double balances[], ostream& outFile) {
	float answer = 0;
	if (S_or_A == 'S') {
		for (int i = 0; i < 10; i++) {
			answer += balances[i];
		}
		outFile << "Sum of Balance for all persons:" << endl;
		outFile << "$         " << left << answer << endl << endl;
	} else {
		for (int i = 0; i < 10; i++) { answer += balances[i]; }
		answer = answer / 10.0;
		outFile << "Average Balance for all persons:" << endl;
		outFile << "$         " << left << answer << endl << endl;
	}
	return answer;
}

int SearchName(string name, string names[], int ids[], double balances[], ostream& outFile) {
	int index_answer;
	for (int i = 0; i < 10; i++) {
		if (name == names[i]) {
			index_answer = i;
			outFile << left;
			outFile << "Search Name:" << endl;
			outFile << setw(9) << "ID #" << setw(25) << "NAME" << setw(11) << "BALANCE DUE" << endl;
			outFile << setw(9) << "----" << setw(25) << "--------------------" << setw(11) << "-----------" << endl;
			outFile << setw(9) << ids[index_answer] << setw(25) << names[index_answer];
			outFile << setw(6) << "$" << right << balances[index_answer] << endl << endl;
		}
	}
	return index_answer;
}