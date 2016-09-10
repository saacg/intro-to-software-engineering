
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

  int number = 0;

  // Use do-while loop to continue reading in values for N until N <= 0 or N >= 10
  do
  {
    
    // To print diagonal pattern, begin with a print field width = N, decrement after each iteration 
    for (int width = number; width > 0; width--)   
    {
      cout << setw(width) << width << endl;
    }

    cout << "N: ";
    cin >> number;
  } while (number > 0 && number < 10);


  // If N <= 0 or N >= 10, end program and self-destruct
  cout << "Invalid value for N!" << endl;
  cout << "Self-destruct sequence initiated..." << endl;

  return 0;
}
