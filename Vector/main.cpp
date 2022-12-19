#include "vector.h"

int main() 
{
  int array[]{ 1, 2, 3, 4 }
  TDynamicVector<int> A(5);
  TDynamicVector<int> B(array, 3);
  TDynamicVector<int> C;
  cout << A;
  return 0;
}