
#include <iostream>

using namespace std;

int main()
{

  int N;
  int count = 1;

  cout << "N: ";
  cin >> N;

  if (N == 0)
  {
    cout << "Invalid value for N!";
  }


  do
  {
   

    if (N <= 0 || N >= 10 )
    {
      cout << "Invalid value for N!"; 
    }
    
    while (N > 0 && N < 10)
    {
    
    }
    
    
    if (N >= 0 && N < 10) 
    { 
      cout << endl << "Please enter new number: ";
      cin >> N;
    }
    
  } (while N >= 0 && N < 10);


  
  cout << " Exiting." << endl;



  return 0;

}
