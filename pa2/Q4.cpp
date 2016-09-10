#include <iostream>

using namespace std;

// doubles the size of an integer array and fills the second half with a copy of the first half in reverse order
// adds a final additional location for the product of all the numbers
int *ReverseMultiply (int *list, int size){

  int newSize = (2 * size) + 1;
  int almostNewSize = newSize - 1;

  // creates a pointer to an array on the heap so the size can assigned at runtime as it is dependent on user input
  int* revAndMultiply = new int[newSize];
  
  // fills the first half of the new array with a copy of the passed in array
  for (int i = 0; i < size; i++){
    *(revAndMultiply + i) = *(list + i);
  }

  // fills the second half of the array with the first half in reverse order
  for (int i = size, j = (size - 1); i < almostNewSize; i++, j--) {
    *(revAndMultiply + i) = *(list + j);
  }

  // takes the product of all the numbers in the array and assigns it to the final index of the new array
  *(revAndMultiply + almostNewSize) = 1;
  for (int i = 0; i < almostNewSize; i++) {
    *(revAndMultiply + almostNewSize) *= *(revAndMultiply + i);
  }
  
  // returns a pointer to the new array
  return revAndMultiply; 
}


int main(){

  // prompts user to input size of an array
  int size;
  cout << "Enter the number of entries: ";
  cin >> size;

  // verifies that size of array is greater than zero, if it is not, returns error message
  if (size < 1) {
    cout << "Invalid size entered." << endl;
  }

  else {

    // prompts user to enter values for the array entries, array is on the heap as the size must be allocated at runtime
    int* list = new int[size];
    for (int i = 0; i < size; i++) {
      cout << "Entry " << i << " is: ";
      cin >> list[i];
    }
    cout << "*****" << endl;

    // calls reverse and multiply function, prints out the original array and its memory address and the new array and its memory address
    int * finalArray = ReverseMultiply(list, size);

    cout << "Original array is:";

    for (int i = 0; i < size; i++) {
      cout << " " << list[i];
    }

    cout << " and the address of the zero element is: " << list << endl;
    cout << "Final array is:";

    for (int i = 0; i < ((2 * size) + 1); i++) {
      cout << " " << finalArray[i];
    }

    cout << " and the address of the zero element is: " << finalArray << endl;


    // deallocates the memory on the heap from its respective pointers
    delete [] list;
    delete [] finalArray;

  }
  return 0;
}
