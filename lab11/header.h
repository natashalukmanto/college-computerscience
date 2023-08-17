#ifndef HEADER_H_
#define HEADER_H_

//Preprocessor Directives 
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

/*****************************************************************
 * FUNCTION PrintHeading 
 * _______________________________________________________________
 * This function receives an ofstream object (outFile)
 * prints heading to console (cout) and output file, 
 * returns nothing. 
 * _______________________________________________________________
 * PRE-CONDITIONS
 *  This function takes an ofstream object (outFile).
 * 
 * POST-CONDITIONS
 *  This function will output class heading.
******************************************************************/
void PrintHeading(
    ostream& outFile //IN – output file object
    );

/*****************************************************************
 * FUNCTION PrintHeading 
 * _______________________________________________________________
 * This function uses ostringstream
 * prints heading to console (cout) and output file, 
 * returns nothing. 
 * _______________________________________________________________
 * PRE-CONDITIONS
 *  This function takes no parameter.
 * 
 * POST-CONDITIONS
 *  This function will output class heading.
******************************************************************/
string PrintHeading();

/*****************************************************************
 * FUNCTION CalculateGCD & RecursiveGCD
 * _______________________________________________________________
 * This function finds the greatest common divisor
 * _______________________________________________________________
 * PRE-CONDITIONS
 *  num1: the first integer.
 *  num2: the second integer.
 *  ofstream object (outFile)
 * 
 * POST-CONDITIONS
 *  This function returns the answer.
******************************************************************/
int CalculateGCD(int num1, int num2, ofstream& outFile);
int RecursiveGCD(int num1, int num2, int originalNum1, int originalNum2, ofstream& outFile, bool outputFlag);

#endif /* HEADER_H_ */