#include "length.h"

using namespace std;

double squareRoot(double N, double tol){

  double guess = 1;
  double guessLoop = (abs(guess - N / guess)) / ( min (guess, N / guess));
  
  while (guessLoop > tol){

    guess = (guess + N / guess) / 2;
    guessLoop = (abs(guess - N / guess)) / ( min (guess, N / guess));
  }


  return guess;

}


double length(double x, double y, double z, double tol){

  double vectorLength = squareRoot((x * x + y * y + z * z), tol);

  return vectorLength;
}
