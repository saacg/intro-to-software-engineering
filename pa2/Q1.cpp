#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
#include "pa2Functions.h"

using namespace std;

// initializes the external global variables declared in pa2Functions.h
const int ENTRIES = 10;  
ofstream output;
ifstream input;

// function prints out program header, prompts user for command code input, checks if command code is valid, and then evaluates command and its associated paramters by a sucession of nested if - else statements 
// conditional statements within each command code group check if the input/output file functions have been called by user commands, and trigger additional actions 
// I am aware of the redundancy of a lot of my if-else checks, however for this question I ran into various problems as I was writing it, and doing these checks solved them. If I have time, I plan to go through and remove some of the redundancy.   
int main(){

  const char * pFileName;
  const char * pInputFile;


  initialize(); 

  char commandCode = 0;  // declares commandCode variable, which will be initialized with user input
  char charTest;


  // if command is q or Q, program terminates, otherwise it continues to iterate
  while (commandCode != 'Q' && commandCode != 'q'){ 
    
    
     if (input.is_open()){
       if (input >> charTest){
	 commandCode = charTest;
       }
       
       else {
	 input.close();
       }
    }

     // if the input file is open, the command code will have been defined by the file input and will no longer be 0
    if (commandCode == 0) {
      cout << "Please enter command code: ";          
      cin >> commandCode;                              
      if (output.is_open()){
	output << "Please enter command code: " << commandCode << endl;
      }
    }

    // if an incorrect character is entered, prints out error message
    if (checkCode(commandCode) == false){           
      cout << "Invalid command code" << endl;       
      if (output.is_open()){
	output << "Invalid command code" << endl;
      }
    }

    else  if (commandCode == 'O' || commandCode == 'o'){
        string fileName;
	if (input.is_open()){
	  input >> fileName;
	}

	else {
	  cout << "Please enter command parameters: ";
	  cin >> fileName;
	}

	pFileName = fileName.c_str();  // converts from string to c-string to accommodate given function parameters
	writeDataToFile(pFileName);
    }
	
    else if (commandCode == 'I' || commandCode == 'i'){
      string inputFile;
      if (input.is_open()){
	input >> inputFile;
      }
      else {
	cout << "Please enter command parameters: ";
	cin >> inputFile;
	if (output.is_open()){
	  output << "Please enter command parameters: " << inputFile << endl;
	}
      }
      pInputFile = inputFile.c_str();  // see previous comment
      readDataFromFile(pInputFile);
    }
    
  
    else  if (commandCode == 'F' || commandCode == 'f' || commandCode == 'B' || commandCode == 'b'){  
	int singlePar;
	if (input.is_open()){
	  input >> singlePar;
	}
	else {
	  cout << "Please enter command parameters: ";
	  cin >> singlePar;
	  if (output.is_open()){
	    output << "Please enter command parameters: " << singlePar << endl;
	  }
	}
	
	if (commandCode == 'F' || commandCode == 'f'){
	  cout << "factorial(" << singlePar << ") = " << factorial(singlePar) << endl;
	  if (output.is_open()){
	    output << "factorial(" << singlePar << ") = " << factorial(singlePar) << endl;
	  }
	}
	
	else if (commandCode == 'B' || commandCode == 'b'){
	  cout << "fibonacci(" << singlePar << ") = " << fibonacci(singlePar) << endl;
	    if (output.is_open()){
	    output << "fibonacci(" << singlePar << ") = " << fibonacci(singlePar) << endl;
	  }
	}
    }

    else if (commandCode == 'D' || commandCode == 'd'){
	int firstVal, lastVal;

	if (input.is_open()){
	  input >> firstVal >> lastVal;
	}

	else {
	  cout << "Please enter command parameters: ";
	  cin >> firstVal >> lastVal;
	  if (output.is_open()){
	    output << "Please enter command parameters: " << firstVal << " " << lastVal << endl;
	  }
	}

	int currentNum = firstVal % 2 == 1? firstVal: firstVal + 1;
	cout << currentNum;
	if (output.is_open()){
	  output << currentNum;
	}
	for (int i = 1; i < ENTRIES && currentNum < lastVal; i++){
	  currentNum = findNextOddValue(currentNum);
	  if (currentNum <= lastVal){
	    cout << ", " << currentNum;
	    if (output.is_open()){
	      output << ", " << currentNum;
	    }
	  }
	} 
	cout << endl;
	if (output.is_open()){
	  output << endl;
	}
    } 

    else if (commandCode == 'L' || commandCode == 'l' || commandCode == 'R' || commandCode == 'r' || commandCode == 'N' || commandCode == 'n'){
        double firstPar, lastPar, delta;
	if (input.is_open()){
	  input >> firstPar >> lastPar >> delta;
	}
	else {
	  cout << "Please enter command parameters: ";
	  cin >> firstPar >> lastPar >> delta;
	  if (output.is_open()){
	    output << "Please enter command parameters: " << firstPar << " " << lastPar << " " << delta << endl;
	  }
	}

	if (firstPar > lastPar || delta <= 0) {
	  cout << "No computation needed." << endl;
	  if (output.is_open()){
	    output << "No computation needed." << endl;
	  }
	}
	

	else if (commandCode == 'L' || commandCode == 'l'){
	  double currentNum = firstPar;
	  cout << "Natural log of " << currentNum << " = " << fixed << setprecision(4) << naturalLog(currentNum) << endl;
	  if (output.is_open()){
	    output << "Natural log of " << currentNum << " = " << fixed << setprecision(4) << naturalLog(currentNum) << endl;
	  }
	  for (double i = 1; i < ENTRIES && currentNum < lastPar; i++){
	    currentNum = firstPar + (delta * i);
	    if (currentNum <= lastPar){
	      cout << "Natural log of " << currentNum << " = " << fixed << setprecision(4) << naturalLog(currentNum) << endl;
	      if (output.is_open()){
		output << "Natural log of " << currentNum << " = " << fixed << setprecision(4) << naturalLog(currentNum) << endl;
	      }
	    }
	  } 
	  if (currentNum > lastPar){
	    cout << "Natural log of " << lastPar << " = " << fixed << setprecision(4) << naturalLog(lastPar) << endl;
	    if (output.is_open()){
	      output << "Natural log of " << lastPar << " = " << fixed << setprecision(4) << naturalLog(lastPar) << endl;
	    }
	  }
	}
       
        else if (commandCode == 'R' || commandCode == 'r'){
	  double currentNum = firstPar;
	  cout << "Square root of " << currentNum << " = " << fixed << setprecision(4) << findSqrtValue(currentNum) << endl;
	  if (output.is_open()){
	    output << "Square root of " << currentNum << " = " << fixed << setprecision(4) << findSqrtValue(currentNum) << endl;
	  }
	  for (double i = 1; i < ENTRIES && currentNum < lastPar; i++){
	    currentNum = firstPar + (delta * i);
	    if (currentNum <= lastPar){
	      cout << "Square root of " << currentNum << " = " << fixed << setprecision(4) << findSqrtValue(currentNum) << endl;
	      if (output.is_open()){
		output << "Square root of " << currentNum << " = " << fixed << setprecision(4) << findSqrtValue(currentNum) << endl;
	      }
	    }
	  }
	  if (currentNum > lastPar){
	    cout << "Square root of " << lastPar << " = " << fixed << setprecision(4) << findSqrtValue(lastPar) << endl;
	    if (output.is_open()){
	      output << "Square root of " << lastPar << " = " << fixed << setprecision(4) << findSqrtValue(lastPar) << endl;
	    }
	  }
	} 
	
	else if (commandCode == 'N' || commandCode == 'n'){
	  double currentNum = firstPar;
	  cout << "NyanCat value of " << currentNum << " = " << fixed << setprecision(4) << findNyanCatValue(currentNum) << endl;
	  if (output.is_open()){
	    output << "NyanCat value of " << currentNum << " = " << fixed << setprecision(4) << findNyanCatValue(currentNum) << endl;
	  }
	  for (double i = 1.0; i < ENTRIES && currentNum < lastPar; i++){
	    currentNum = firstPar + (delta * i);
	    if (currentNum <= lastPar){
	      cout << "NyanCat value of " << currentNum << " = " << fixed << setprecision(4) << findNyanCatValue(currentNum) << endl;
	      if (output.is_open()){
		output << "NyanCat value of " << currentNum << " = " << fixed << setprecision(4) << findNyanCatValue(currentNum) << endl;
	      }
	    }
	  }
	  if (currentNum > lastPar){
	    cout << "NyanCat value of " << lastPar << " = " << fixed << setprecision(4) << findNyanCatValue(lastPar) << endl;
	    if (output.is_open()){
	      output << "NyanCat value of " << lastPar << " = " << fixed << setprecision(4) << findNyanCatValue(lastPar) << endl;
	    }
	  }
	}
    }

    // command code must be reset to 0 in order to keep an input file command from using the same command more than once
    // according to my understanding at least. I was having that problem, and resetting command code back to 0 fixed it
    if (commandCode != 'Q' && commandCode != 'q'){
      commandCode = 0;
    }
  }

  if (output.is_open()){
    output.close();
  }

  return 0;
}
