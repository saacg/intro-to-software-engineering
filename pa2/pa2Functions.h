#include <fstream>

#ifndef PA2FUNCTIONS_H
#define PA2FUNCTIONS_H

extern const int ENTRIES; // declares ENTRIES as a constant variable that can be used across all of the files that include this header file
extern std:: ofstream output;
extern std:: ifstream input;

void initialize(); // prints program output header
bool checkCode (char); // checks if user input is valid


void writeDataToFile (const char *); // writes the output of the program to a user-specified file
void readDataFromFile (const char *); // reads commands from a file specified by user input

double findNyanCatValue (double); // multiplies input number by 2 and adds it to the product of the number and 6 raised to the power of the number
int factorial (int); // returns factorial value of the argument
int fibonacci (int); // returns Fibonacci number at the index of the argument
double findSqrtValue (double); // returns square root of the argument
double naturalLog (double); // returns natural log of the argument
int findNextOddValue (int); // returns the closest odd number higher than the parameter


#endif
