
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;


/*double abs(double number){

  double absVal = number < 0 ?
    -1.0 * number:
    number;
  
  return absVal;
  }*/

double squareRoot(double N, double tol){

  double guess = N / 2;

  while (abs(guess - N / guess) / min(guess, N / guess) > tol){

    guess = (guess + N / guess) / 2;
    //cout << guess << endl;
  } 


  return guess;

}


 int main (){

   double N;
   double tol = .001 ;

   cout << "Enter N: ";
   cin >> N;
  
  
  
   cout << fixed << setprecision(2) << squareRoot(N, tol) << endl;


   return 0;
 } 

