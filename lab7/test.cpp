
# include <iostream>
using namespace std;
int main(int argc, char **arvg)
{
  unsigned long int start;
  cout << "Please enter the starting value: ";
  cin >> start;
  cout << "You entered " << start << "." << endl;
  unsigned long int a = start;
  unsigned long int b = 0;
  unsigned long int c = 0;
  unsigned long int sum = a + b + c;
  while (true)
    {
      c = b;
      b = a;
      a = a + 1;
      sum = a + b + c;
    }
  return 0;

}
