#include <iostream>
#include "print.h"
using namespace std;

void printArray(int * intArray, int size){
  cout << "The int array passed is: ";
  for (int i = 0; i < size; i++)
    cout << intArray[i] << " ";
  cout << endl;
}

void printArray(char * charArray, int size){
  cout << "The char array passed is: ";
  for (int i = 0; i < size; i++)
    cout << charArray[i] << " ";
  cout << endl;	
}
