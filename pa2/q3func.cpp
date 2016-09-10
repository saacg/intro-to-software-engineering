#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "q3func.h"

using namespace std;

// genarates N random integers from 0 to M
// and writes them to "numbers.txt"
// returns 0 if sucessful, 1 if not
int DataToFile(const char *filename, int N, int M){

  ofstream output(filename);

  srand(time(0));
  for (int i = 0; i < N; i++){
    output << rand() % (M + 1) << endl;  // uses M + 1 to keep the numbers between 0 - M (inclusive)
  }
  
  output.close();

  

  return output.fail()? 1 : 0;
}

// reads in data from specified text file ("numbers.txt") and finds the size 
// returns 0 if successful, 1 if not 
int DataFromFile(const char *filename, int myArray[], int& size) {
  ifstream input (filename);

  if (input.fail()){
    return 1;
  }

  else {
    int inputCheck;
    int i = 0;

    // reads in data from until it fails, assigns each entry to the next index in array
    // size will be the value of i when the input ends
    while (input >> inputCheck){  
      myArray[i] = inputCheck;
      i++;
    }
    
    input.close();

    size = i;       

    return 0;
  }
  
}
