#include <iostream>
#include <cmath>  // only included for using sqrt function to find the std dev
#include "statistics.h"

using namespace std;

// computes mean of the values in the array passed in to function
float getMean(int myArray[], int size){

  float mean;
  float sum = 0.0;

  // computes sum of all the values in array
  for (int i = 0; i < size; i++){
    sum += myArray[i];
  }
  
  mean = sum / size;

  return mean;
}

// computes standard deviation of the values in the array according to the formula given in the assignment
float getStdDev(int myArray[], int size){
  
  float mean, stdDev, deviation;
  float deviationSum = 0.0;

  // calculates mean by calling getMean function defined above
  mean = getMean(myArray, size);
  
  // calculates the deviation from the mean for each array value, then takes the sum of the deviations
  for (int i = 0; i < size; i++){
    deviation = ((myArray[i] - mean) * (myArray[i] - mean));
    deviationSum += deviation;
  }

  // calculates the standard deviation
  stdDev = sqrt(deviationSum / size);


  return stdDev;
}
