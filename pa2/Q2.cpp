#include <iostream>
#include <iomanip>

using namespace std;

// prints out one line of the rhombus by calling itself
// I have been working on ways to also format the entire rhombus within the function,
// but as that is not a requirement, I am submitting this now to make sure it is in before going further
// Also, I have noted a slight discrepancy between this program's output and the sample output (the '1' at the top and bottom
// of mine have a space where the sample output does not. As I do not want to risk a late submission, I am submitting it
// with this slight discrepancy and then go back and try to correct it asap. Enjoy! 
void PrintRhombus (int n){
  

  // to print out the first half of the line, I created a static variable num1 that starts at 1, and then increments
  // until it is equal to the passed in parameter. The function calls itself with the same parameter until they are equal
  static int num1 = 1;

  if (num1 < n) {
    cout << num1 << " ";
    num1++;
    PrintRhombus(n);
  }

  // once the parameter and num1 are equal, program prints out the second half of the line by decrementing both num1 and the parameter
  // the program calls itself with the decreasing parameter until it equals 1, the base case.
  else if (num1 == n && num1 > 1) {
    cout << num1 << " ";
    n--;
    num1 = n;
    PrintRhombus(n);
  }

  // when num1 and the parameter both equal the base case 1, function prints it out and ends 
  else {
    cout << num1 << " " << endl;
  }
}


int main (){


  int rhombusNum;

  do {
    cout << "Enter a number [1-9]: ";
    cin >> rhombusNum;

    if (rhombusNum < 1 || rhombusNum > 9){
      cout << "Wrong input, please enter a single digit number between 1 and 9. " << endl << endl;
    }
  
  } while (rhombusNum < 1 || rhombusNum > 9);

  // to format the spaces, j is intialized to the max number of spaces
  int j = (2 * rhombusNum) - 1;

  // to format the top half of the bus, the set with function sets the spaces and the parameter is decremented
  for (int i = 1; i < rhombusNum; i++) {
    cout << setw(j);
    PrintRhombus(i);
    //cout << endl;
    j -= 2;
  }

  // the middle of the bus is just the line, no spaces
  PrintRhombus (rhombusNum);

  // for the bottom half, set with is also used, but the paramater is incrememented until it returns to its original length
  for (int i = rhombusNum - 1; i > 0; i--) {
    j += 2;
    cout << setw(j);
    PrintRhombus(i);
  }


  return 0;
}
