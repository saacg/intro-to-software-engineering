#ifndef Length_H
#define Length_H

double squareRoot(double N, double tol);

double length(double x, double y, double z, double tol);

#ifndef min
#define min(num1, num2)(num1 < num2 ? num1: num2)
#endif

#ifndef abs
#define abs(num)(num < 0 ? -1 * (num): num)
#endif

#endif
