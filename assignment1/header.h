#ifndef HEADER_H_
#define HEADER_H_

//Preprocessor Directives 
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//Prototypes

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
 * FUNCTION GetInput 
 * _______________________________________________________________
 * This function will propagate the arrays or
 * reads in all the data from InFile.txt
 * _______________________________________________________________
 * PRE-CONDITIONS
 *  This function takes an ifstream object (InFile.txt).
 *  names[] : names of all the account holder in InFile.txt
 *  ids[] : ids of all the account holder in InFile.txt
 *  balances[]: balances of all the account holder in InFile.txt
 *  
 * POST-CONDITIONS
 *  This functions populated three arrays: names, ids, balances.
******************************************************************/
void GetInput(
    ifstream& inFile, //IN – input file object
    string names[],   //IN – arrays declared in main(); to be populated
    int ids[],        //IN – arrays declared in main(); to be populated
    double balances[] //IN – arrays declared in main(); to be populated
    );

/*****************************************************************
 * FUNCTION SearchBalance 
 * _______________________________________________________________
 * This function will find the larger balance 
 * and the smallest balance 
 * out of all the accounts in InFile.txt.
 * _______________________________________________________________
 * PRE-CONDITIONS
 *  This function takes an ifstream object (InFile.txt).
 *  L_or_S: either 'L' for larger balance or 'S' for smaller balance.
 *  names[] : names of all the account holder in InFile.txt
 *  ids[] : ids of all the account holder in InFile.txt
 *  balances[]: balances of all the account holder in InFile.txt
 *  
 * POST-CONDITIONS
 *  This functions return the larger balance or smaller balance.
******************************************************************/
int SearchBalance(
    char L_or_S, //IN – either 'L' for larger balance or 'S' for smaller balance.
    string names[], int ids[], double balances[], ostream& outFile);

/*****************************************************************
 * FUNCTION SumOrAvg 
 * _______________________________________________________________
 * This function find either the Sum of all the balances 
 * or the average of all the balances.
 * _______________________________________________________________
 * PRE-CONDITIONS
 *  This function takes an ofstream object (OFile.txt).
 *  L_or_S: either 'S' for the sum or 'A' for the average.
 *  balances[]: balances of all the account holder in InFile.txt
 *  
 * POST-CONDITIONS
 *  This functions return the sum  or the average.
******************************************************************/
float SumOrAvg(
    char S_or_A, //IN – either 'S' for the sum or 'A' for the average.
    double balances[], ostream& outFile);

/*****************************************************************
 * FUNCTION SearchName 
 * _______________________________________________________________
 * This function takes a name as an input 
 * and report if it finds the name in InFile.txt.
 * _______________________________________________________________
 * PRE-CONDITIONS
 *  This function takes an ifstream object (InFile.txt).
 *  name: the name the want to search for.
 *  names[] : names of all the account holder in InFile.txt
 *  ids[] : ids of all the account holder in InFile.txt
 *  balances[]: balances of all the account holder in InFile.txt
 *  
 * POST-CONDITIONS
 *  This functions return the index of the name searched.
******************************************************************/
int SearchName(
    string name, //IN – the name the want to search for.
    string names[], int ids[], double balances[], ostream& outFile);

#endif /* HEADER_H_ */