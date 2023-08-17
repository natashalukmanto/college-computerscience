#include "header.h"
#include "functions.cpp"

int main() {
    int num1, num2;
    ofstream outFile;
    string outFileName = "OFile.txt";
    outFile.open(outFileName.c_str());

    //Using ostream
    PrintHeading(cout);
    PrintHeading(outFile);

    //Using ostringstream
    cout << PrintHeading();
    outFile << PrintHeading();

    for (int i = 0; i < 4; i++) {
        cout << left;
        cout << setw(26) << "Enter the first integer:";
        cin >> num1;
        cin.ignore(1000, '\n');
        cout << setw(26) << "Enter the second integer:";
        cin >> num2;
        cin.ignore(1000, '\n');
        cout << endl << right;
        if (num2 == 0) {
        outFile << "The GCD for " << num1 << " & 0 = " << num1 << endl;
        return 0;
        }
        CalculateGCD(num1, num2, outFile);
    }

    cout << "Thank you for using my GCD calculator!" << endl;
    cout << "---------------------------------------------------------------------------------------";

    outFile.close();

    return 0;
}