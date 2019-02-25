


#include "BinarySearch.h"
using namespace std;
#include <iostream>
#include <string>

bool contains(double target, double numbers[], int size)
{
  if (size <= 0)
    {
      cout << "Invalid Array" << endl;
      return false;
    }
  //initialize variables
  int home = 0;
  int end = size - 1;
  double selected;
  int center;
  bool found = false;

  //conditional to loop until all items are searched
  while (end >= home && !found)
  {
    //get center
    center = (end + home) / 2;
    //get center num
    selected = numbers[center];
    cout << "Selected: " << selected << endl;
    //compare
    int result = compare(selected, target);
    cout << "Result: " << result << endl;
    //if equal, found
    if (result == 0)
    {
      found = true;
    }
    //if greater than, make center + 1 new home
    else if (result == 1)
    {
      home = center + 1;
    }
    //if less than, make center - 1 new end
    else
    {
      end = center - 1;
    }
  }

  //return result
  return found;
}

int compare(double selected, double target)
{
  if (selected >= target - 0.000001 && selected <= target + 0.000001)
  {
    return 0;
  }
  else if (selected > target + 0.000001)
  {
    return -1;
  }
  else
  {
    return 1;
  }
}
