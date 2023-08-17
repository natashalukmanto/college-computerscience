#include "header.h"
#include "functions.cpp"

int main() {
    PrintHeading();

    int total_sheeps, total_chocolates, chocolate, remainder;
    cout << "Hello Farmer Pete!" << endl;
    cout << "How many sheeps do you have? ";
    cin >> total_sheeps;
    cout << "How many bars of chocolate do you have? ";
    cin >> total_chocolates;
    if (total_sheeps < 0 || total_chocolates < 0) { cout << "Invalid input! Your numbers can't be negative!"; }
    else if (total_sheeps > total_chocolates) { cout << "You don't have enough bars of chocolate. Sorry!"; }
    else { 
        ChocolatesForSheeps(total_sheeps, total_chocolates, &chocolate, &remainder);
        cout << endl;
        cout << "Each sheep will receive " << chocolate << " bars of chocolates." << endl;
        cout << "You have " << remainder << " bars of chocolate left!";
    }
}