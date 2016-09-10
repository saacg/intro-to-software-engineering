#include <iostream>
//#include "bubbleSorting.h"

using namespace std;

void printArray (int * myArray, int size){
 for (int i = 0; i < size; i++){
    cout << " " << myArray[i];
  }
  cout << endl;
}

void printArray (char * myArray, int size){
 for (int i = 0; i < size; i++){
    cout << " " << myArray[i];
  }
  cout << endl;
}

int main(){

  int intArray[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  char charArray[] = {'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
  int size = 10;
  
  cout << "Arrays before sort:";
  
  printArray(intArray, size);
  printArray(charArray, size);
  

  cout << "Let me sort this out..." << endl;
  bubbleSort(intArray, size);
  bubbleSort(charArray, size);

  cout << "Arrays after sort:";

  printArray(intArray, size);
  printArray(charArray, size);
  

  return 0;
}
