#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include "pa2Functions.h"

using namespace std;


// prints program output header
void initialize(){  
  cout << "EC327: Introduction to Software Engineering" << endl << "Fall 2015" << endl <<
    "Programming Assignment 2" << endl << "Value of Entries is: " << ENTRIES << endl;
}


// checks if user input is valid character, if not, returns false
bool checkCode (char inputChar) {  
  bool result;

  switch (inputChar){

  case 'F': result = true; break;
  case 'f': result = true; break;
  case 'B': result = true; break;
  case 'b': result = true; break;
  case 'R': result = true; break;
  case 'r': result = true; break;
  case 'D': result = true; break;
  case 'd': result = true; break;
  case 'L': result = true; break;
  case 'l': result = true; break;
  case 'N': result = true; break;
  case 'n': result = true; break;
  case 'I': result = true; break;
  case 'i': result = true; break;
  case 'O': result = true; break;
  case 'o': result = true; break;
  case 'Q': result = true; break;
  case 'q': result = true; break;
  default:  result = false;
  }
    
  return result;
}


// opens user-specified output file that the program will write to
void writeDataToFile (const char * fileName){  
  output.open(fileName); 
}

// opens user-specified input file that the program will read from
void readDataFromFile (const char * inputFile){
  input.open(inputFile); 
}

// multiplies input number by 2 and adds it to the product of the number and 6 raised to the power of the number
// returns the resulting value
double findNyanCatValue (double myNum){  
  double nyanCatVal = (2 * myNum) + (myNum * (pow(6, myNum)));

  return nyanCatVal;
}

// REFERENCE NOTE: The following function was discussed in class and lab, and can also be found in the assigned Liang reading (p. 627)
int factorial (int n){  // returns factorial value of the argument. 
  if (n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}

// returns Fibonacci number at the index of the argument
// 
int fibonacci (int index){ 
  int currentVal = 1;
  int prevVal = 0;
  int nextVal;

  if (index == 0){
    return 0;
  }

  else if (index == 1){
    return 1;
  }

  else {
    for (int i = 1; i < index; i++){
      nextVal = currentVal + prevVal;
      prevVal = currentVal;
      currentVal = nextVal;
    }
    
    return nextVal;
  }
    
}

// returns square room of the argument
double findSqrtValue (double num1){ 
  double squareRoot = sqrt(num1);

  return squareRoot;
}

// returns natural log of the argument
double naturalLog (double num1){ 
  double natLog = log(num1);

  return natLog;
}

// returns the closest odd number higher than the parameter
// determines if the number is odd, then adds 2 if it is odd, and adds 1 if it is even to get the next closest odd number
int findNextOddValue (int num1){  
  int nextOddValue = num1 % 2 == 1? num1 + 2: num1 + 1;

  return nextOddValue;
}
