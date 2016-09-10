#include "length.h"
#include <iostream>


using namespace std;

//double squareRoot(double N, double tol);
//double length(double x, double y, double z, double tol);

int main() {
  

  double tol = 1e-6;
  cout << fixed;
  cout << "sqrt(3) is roughly " << squareRoot(3, tol) << endl;
  cout << "The length of (12, 16, 21) is "
            << length(12, 16, 21, tol) << endl;
  return 0;
}
