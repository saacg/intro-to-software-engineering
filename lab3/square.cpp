
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
  char N;  
  int digit = 1;
  char digitChar = '1'; 
  string row = "1";
  char count = '1';

  cout << "N: ";
  cin >> N;

  do
  {
    if (N == '0')
    {
      cout << "Invalid value for N!" << endl;
    }
    
    else
    {
      while (N > '0' && digitChar <= N)
      {
	for (count = '1'; count <= N; count++)
	{   
	  row = digitChar;
	  row += digitChar;
	}

	cout << row << endl;
	digitChar = digitChar++;             //(atoi(digit[0]))++; // = static_cast<int>(digit[0])++;
        count = '1';
     }
      
    }

    cout << endl << "Please enter new number: ";
    cin >> N;

  } while (N >= '0' && N < '10');

  cout << "Invalid value for N! Exiting." << endl;

  return 0;
}
