
#include <iostream>

using namespace std;

int main()
{
  int number;
  
  // take user input for number
  cout << "You should probably put in a number here: ";
  cin >> number;
  
  // do some math with the user input
  int answer = 0;
  answer = (number * 2 + 8) / 2 - number;

  // print out the answer!
  cout << "The answer is " << answer << endl;
  cout << "Most probably, your answer is 4;) Check with a neighbour! " << endl;


  return 0;
}
