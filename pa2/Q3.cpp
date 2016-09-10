#include <iostream>
#include <cstring>
#include <iomanip>
#include "q3func.h"
#include "statistics.h"


using namespace std;

//used this function to test my data to file function
void generatenumbers(){

  const char *filename = "numbers.txt";

  int N = 10;
  int M = 1000; 
  int result = DataToFile(filename, N, M);
  if (result == 0){
    cout << "Great success!" << endl;
  }

  else {
    cout << "Nisht geshtoygn un nisht gefloygn." << endl;
  }
  
}


int main(){

  // used this to call the function that would test my data to file function, I kept it in here commented out in case I ever need to test it again
  generatenumbers(); 

  int size;
  int myArray[1000];  // made array size 1000 because that is the maximum size it can be, but the actual size is calculated in the dataFromFile function

  // calls data from file function
  // if function is successful and the file has a size greater than zero, carries out the operations specified in the assignment
  if (DataFromFile("numbers.txt", myArray, size) == 0 && size > 0){
    cout << "Array size is: " << size << endl;
    cout << "Mean is: " << fixed << setprecision(2) << getMean(myArray, size) << endl;
    cout << "StdDev is: " << fixed << setprecision(2) << getStdDev(myArray, size) << endl;

    cout << "Array values forward are: " << myArray[0];
    for (int i = 1; i < size; i++){
      cout << ", " << myArray[i];
    }
    cout << endl;

    cout << "Array values reverse are: " << myArray[size -1];
    for (int j = size - 2; j >= 0; j--){
      cout << ", " << myArray[j];
    }
    cout << endl;

    cout << "The largest array value is: ";
    int currentMax = myArray[0];
    for (int i = 1; i < size; i++){
      if (myArray[i] > currentMax){
	currentMax = myArray[i];
      }
    }
    cout << currentMax << endl;

    cout << "The smallest array value is: ";
    int currentMin = myArray[0];

    for (int i = 1; i < size; i++){
      if (myArray[i] < currentMin){
	currentMin = myArray[i];
      }
    }
    cout << currentMin << endl;
  }

  // if array size is zero, returns "none" for every operation
  else if (size == 0){
    cout << "Array size is: 0" << endl << "Mean is: None" << endl << "StdDev is: None" << endl <<
      "Array values forward are: None" << endl << "Array values reverse are: None" << endl <<
      "The largest array value is: None" << endl << "The smallest array value is: None" << endl;
  }

  // if "numbers.txt" file does not exist, returns error message
  else {
    cout << "This is a generic error message that Timothy said he probably will not be testing. The program will now exit. Goodbye. " << endl;
  }


  return 0;
}
