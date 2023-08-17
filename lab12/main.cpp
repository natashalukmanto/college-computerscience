/**********************************************************************
 * AUTHOR		: Natasha Lukmanto
 * STUDENT ID	: 1253798
 * LAB #     	: Lab #12 - Introduction to Object Oriented Programming
 * CLASS 		: CS 1B
 * SECTION 		: M-Th : 5p - 7:20p
 * DUE DATE 	: Fri Jun 16, 2023 11:59pm
**********************************************************************/

#include "animal.h"

int main()
{
    const char PROGRAMMER[30] = "Natasha Lukmanto";
    const char CLASS[5] = "CS1B";
    const char SECTION[25] = "M-Th: 5:00p - 7:20p";
    const int LAB_NUM = 0 - 7;
    const char LAB_NAME[55] = "Lab #12 - Introduction to Object Oriented Programming";

    int option1;
    bool invalid1 = true; // INPUT – temp variables for user's input choices & loop control variable
    string name;          // INPUT – temp variable for input animal's name
    string type;          // INPUT – temp variable for input type of animal
    int age;              // INPUT – temp variable for input animal's age
    double Ivalue;        // INPUT – temp variable for input animal's value/price
    Animal fluffy;        // PROC – create fluffy the class object
    Animal maa;           // PROC – create maa the class object
    Animal babe;          // PROC – create babe the class object

    // OUTPUT – Class Heading
    cout << left;
    cout << "**********************************************************************";
    cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
    cout << "\n* " << setw(14) << "CLASS"
         << ": " << CLASS;
    cout << "\n* " << setw(14) << "SECTION"
         << ": " << SECTION;
    cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
    cout << "\n**********************************************************************\n\n";
    cout << right;

    // PROCESSING: Asking user for input option.
    while (invalid1)
    {
        cout << "1 - Initialize Animals" << endl;
        cout << "0 - Exit" << endl;
        cout << "Enter selection: ";

        if (!(cin >> option1))
        {
            cout << endl
                 << "**** Please input a number between 0 and 1 ****" << endl
                 << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (option1 < 0 || option1 > 1)
        {
            cout << endl;
            cout << "**** The number " << option1 << " is an invalid entry     ****" << endl;
            cout << "**** Please input a number between 0 and 1 ****" << endl
                 << endl;
        }
        else if (option1 == 1)
        {
            fluffy.SetInitialValues("Fluffy", "Sheep", 1, 15000.00);
            maa.SetInitialValues("Maa", "Sheep", 3, 16520.35);
            babe.SetInitialValues("Babe", "Pig", 2, 10240.67);
            cout << "\nInitializing Fluffy, Maa, & Babe...\n\n";
            int option2;
            bool invalid2 = true; // INPUT – temp variables for user's input choices & loop control variable
            while (invalid2)
            {
                cout << "1 - Initialize Animals" << endl;
                cout << "2 - Change Age" << endl;
                cout << "3 - Change Value" << endl;
                cout << "4 - Display" << endl;
                cout << "0 - Exit" << endl;
                cout << "Enter selection: ";

                if (!(cin >> option2))
                {
                    cout << endl
                         << "**** Please input a number between 0 and 4 ****" << endl
                         << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else if (option2 < 0 || option2 > 4)
                {
                    cout << endl;
                    cout << "**** The number " << option2 << " is an invalid entry     ****" << endl;
                    cout << "**** Please input a number between 0 and 4 ****" << endl
                         << endl;
                }
                else
                {
                    // INPUT – temp variables for user's input choices & loop control variable
                    int option_initialize, option_age1, option_age2, option_value1, option_animals; double option_value2;
                    bool invalid3 = true, invalid4 = true, invalid5 = true, invalid_age = true, invalid_value = true;

                    char yes_or_no;
                    switch (option2)
                    {
                    case 0:
                        cout << endl;
                        invalid1 = false;
                        option1 = 0;
                        invalid2 = false;
                        return 0;
                    case 1:
                        while (invalid3)
                        {
                            cout << "\nAre you sure you want to reinitialize (Y/N)? ";
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cin.get(yes_or_no);
                            if (yes_or_no == 'N' || yes_or_no == 'n')
                            {
                                cout << "Animals have not been re-initialized!\n";
                                invalid3 = false;
                            }
                            else if (yes_or_no == 'Y' || yes_or_no == 'y')
                            {
                                fluffy.SetInitialValues("Fluffy", "Sheep", 1, 15000.00);
                                maa.SetInitialValues("Maa", "Sheep", 3, 16520.35);
                                babe.SetInitialValues("Babe", "Pig", 2, 10240.67);
                                cout << "Initializing Fluffy, Maa, & Babe...\n";
                                invalid3 = false;
                            }
                            else
                            {
                                cout << "**** " << yes_or_no << " is an invalid entry ****\n";
                                cout << "**** Please input Y or N ****\n";
                                cin.clear();
                            }
                        }
                        cout << endl;
                        break;
                    case 2:
                        while (invalid4)
                        {
                            cout << "\nCHANGE AGE: \n";
                            cout << "1 - Fluffy\n";
                            cout << "2 - Maa\n";
                            cout << "3 - Babe\n";
                            cout << "Select the animal you'd like to change: ";
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            if (!(cin >> option_age1))
                            {
                                invalid4 = true;
                                cout << endl
                                     << "**** Please input a number between 1 and 3 ****" << endl
                                     << endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            else if (option_age1 < 1 || option_age1 > 3)
                            {
                                cout << endl;
                                cout << "**** The number " << option_age1 << " is an invalid entry     ****" << endl;
                                cout << "**** Please input a number between 1 and 3 ****" << endl;
                            }
                            else
                            {   
                                cout << endl;
                                invalid4 = false;
                                while (invalid_age)
                                {
                                    cout << "NEW AGE: ";
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    if (!(cin >> option_age2))
                                    {
                                        cout << endl
                                             << "**** Please input a number between o and 11 ****" << endl
                                             << endl;
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    }
                                    else if (option_age2 < 0 || option_age2 > 10)
                                    {
                                        cout << endl;
                                        cout << "**** The number " << option_age2 << " is an invalid entry     ****" << endl;
                                        cout << "**** Please input a number between 0 and 11 ****" << endl
                                             << endl;
                                    }
                                    else
                                    {
                                        invalid_age = false;
                                        cout << endl;
                                        if (option_age1 == 1)
                                        {
                                            fluffy.ChangeAge(option_age2);
                                            cout << "Changing Fluffy's age to " << option_age2 << "..." << endl;
                                        } else if (option_age1 == 2)
                                        {
                                            maa.ChangeAge(option_age2);
                                            cout << "Changing Maa's age to " << option_age2 << "..." << endl;
                                        } else if (option_age1 == 3)
                                        {
                                            babe.ChangeAge(option_age2);
                                            cout << "Changing Babe's age to " << option_age2 << "..." << endl;
                                        }
                                    }
                                }
                            }
                        }
                            cout << endl;
                            break;
                    case 3:
                        while (invalid5)
                        {
                            cout << "\nCHANGE VALUE: \n";
                            cout << "1 - Fluffy\n";
                            cout << "2 - Maa\n";
                            cout << "3 - Babe\n";
                            cout << "Select the animal you'd like to change: ";
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            if (!(cin >> option_value1))
                            {
                                invalid5 = true;
                                cout << endl
                                     << "**** Please input a number between 1 and 3 ****" << endl
                                     << endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            else if (option_value1 < 1 || option_value1 > 3)
                            {
                                cout << endl;
                                cout << "**** The number " << option_value1 << " is an invalid entry     ****" << endl;
                                cout << "**** Please input a number between 1 and 3 ****" << endl;
                            }
                            else
                            {   
                                cout << endl;
                                invalid5 = false;
                                while (invalid_value)
                                {
                                    cout << "NEW VALUE: ";
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    if (!(cin >> option_value2))
                                    {
                                        cout << endl
                                             << "**** Please input a number between 0 and 400000****" << endl
                                             << endl;
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    }
                                    else if (option_value2 < 0 || option_value2 > 400000)
                                    {
                                        cout << endl;
                                        cout << "**** The number " << option_value2 << " is an invalid entry     ****" << endl;
                                        cout << "**** Please input a number between 0 and 400000****" << endl
                                             << endl;
                                    }
                                    else
                                    {
                                        invalid_value = false;
                                        cout << endl;
                                        if (option_value1 == 1)
                                        {
                                            fluffy.ChangeValue(option_value2);
                                            cout << "Changing Fluffy's value to " << option_value2 << "..." << endl;
                                        } else if (option_value1 == 2)
                                        {
                                            maa.ChangeValue(option_value2);
                                            cout << "Changing Maa's value to " << option_value2 << "..." << endl;
                                        } else if (option_value1 == 3)
                                        {
                                            babe.ChangeValue(option_value2);
                                            cout << "Changing Babe's value to " << option_value2 << "..." << endl;
                                        }
                                    }
                                }
                            }
                        }
                        cout << endl;
                        break;
                    case 4:
                        cout << left;
                        cout << "\nANIMAL     NAME           AGE VALUE      \n";
                        cout << "---------- -------------- --- -----------";
                        fluffy.Display();
                        maa.Display();
                        babe.Display();
                        cout << right;
                        cout << endl << endl;
                        break;
                        }
                    }
                }
            }
            else
            {
                invalid1 = false;
            }
        } 
    return 0;
}

// Animal Methods

// Set the initial values of the animal (name, type, age, and value/price)
void Animal::SetInitialValues(string aName, string aType, int aAge, float aValue)
{
    name = aName;
    type = aType;
    age = aAge;
    value = aValue;
}

// Change the animal's age
void Animal::ChangeAge(int aAge) { age = aAge; }

// Change the value/price of the animal
void Animal::ChangeValue(float aValue) { value = aValue; }

// Display the animal's information in a formatted table-like structure
void Animal::Display() const
{
    cout << endl;
    cout << setw(11) << type << setw(15) << name << setw(4) << age << right << setw(11) << value << left;
}

// Return animal's name
string Animal::GetName() const { return name; }

// Return animal's type
string Animal::GetType() const { return type; }

// Return animal's age
int Animal::GetAge() const { return age; }

// Return animal's value/price
float Animal::GetValue() const { return value; }

// Constructor: Initializes an Animal object with default values
Animal::Animal()
{
    name.clear();
    type.clear();
    age = 0;
    value = 0;
}

// Destructor: Does not perform any specific operations in this case
Animal::~Animal() {}