#include "print.h"
#include "reverse.h"
#include "bubbleSorting.h"
#include <iostream>
using namespace std;

int main(){
  int list[6];
	
  for (int i = 0; i < 6; i++)
    list[i] = i + 1;
  printArray(list, 6);	
	
  char list2[] = { 'a', 'b', 'c', 'd', 'e'};
  printArray(list2, 5);

  int messedUpArray[] = {5, 3, 8, 9, 4, 2, 44};
  char iDontChar [] = {'b', 'o', 'b', 'l', 'o', 'b', 'l', 'a', 'w', 's', 'l', 'a', 'w', 'b', 'l', 'o', 'g'};
	
  int * p = reverse(list, 6);
  char * p2 = reverse(list2, 5);
	
  printArray(p, 6);
  printArray(list, 6);
  printArray(p2, 5);
  printArray(list2, 5);
  printArray(messedUpArray, 7);
  printArray(iDontChar, 17);
  bubbleSort(messedUpArray, 7);
  bubbleSort(iDontChar, 17);
  printArray(messedUpArray, 7);
  printArray(iDontChar, 17);
  return 0;
}
