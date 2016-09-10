
#include <iostream>

using namespace std;

void findModes (int input[], int size, int & frequency, int array_result[], int & result_count){
  
  // first sort the list
  int sortedInput[size];
  
  // copy input list to the list that will be sorted
  for (int i = 0; i < size; i++){
    sortedInput[i] = input[i];
  }

  // selection sort
  for (int i = 0; i < size - 1; i++){
    int tempMin = sortedInput[i];
    int mIndex = i;

    for (int j = i + 1; j < size; j++){
      if (tempMin > sortedInput[j]){
	tempMin = sortedInput[j];
	mIndex = j;
      }
    }
    
    if (mIndex != i){
      sortedInput[mIndex] = sortedInput[i];
      sortedInput[i] = tempMin;
    }

  }

  
  // now that the list is sorted, find the modes by comparing elements

  // first find the mode frequency
  int count = 1;
  frequency = 1;
  result_count = 1;
  int currentMode = 0;
  //int j = 0;
  array_result[0] = sortedInput[0];
  for (int i = 0; i < size - 1; i++){
    
    if (sortedInput[i] == sortedInput[i + 1] ){
      count++;
    }
    
    else {
      count = 1;
    }
    
    
    if (count > frequency){
      frequency = count;
      result_count = 1;
      currentMode = sortedInput[i];
      array_result[result_count - 1] = sortedInput[i + 1];
    }
    
    else if (count == frequency){
      result_count++;
      array_result[result_count - 1] = sortedInput[i + 1];
      currentMode = sortedInput[i + 1];
    }
    
   
  }





  // now that frequency is defined, numbers that have that frequency will be the mode. Count the modes, and store them in an array
 
}


void printModes(int input[], int size,  int frequency, int result[], int result_count){

    cout << "Input: ";
    for(int i = 0; i < size; i++) {
        cout << input[i];
        if (i != size -1)
            cout << ", ";
    }
    cout << endl;
    cout << "Modes: ";
    for(int i = 0 ; i < result_count; i++) {
        cout << result[i];
        if (i != result_count -1)
            cout << ", ";
    }
    cout << endl;
    cout << "Frequency : " << frequency << endl;;

}




/*int main() {
  
  const int SIZE = 10; 
  int sortedInput[SIZE];
  int test[SIZE] = {2, 3, 4, 4, 3, 1, 2, 1, 2, 3};
  int frequency;
  int result_count;
  findModes (test, SIZE, sortedInput, frequency, array_result[], result_count);
  for (int i = 0; i < SIZE; i++){
    cout << sortedInput[i];
    if (i != SIZE - 1){
      cout << ", ";
    }
  }
  cout << endl << frequency << endl << result_count << endl;



  return 0;
}
*/
