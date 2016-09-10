#include <iostream>
#include "bubbleSorting.h"

using namespace std;

void bubbleSort(int * intArray, int size){

  bool changed = true;
  
  do {
    changed = false;
    for (int j = 0; j < size - 1; j++){
      if (intArray[j] > intArray[j + 1]){
	int temp = intArray[j];
	intArray[j] = intArray[j + 1];
	intArray[j + 1] = temp;
	changed = true;
      }
    }


  } while (changed);


}


void bubbleSort(char * charArray, int size){
  bool changed = true;

  do {
    changed = false;
    for (int j = 0; j < size -1; j++){
      if (charArray[j] > charArray[j + 1]){
	char temp = charArray[j];
	charArray [j] = charArray [j + 1];
	charArray[j + 1] = temp;
	changed = true;
      }

    }

  } while (changed);



}

