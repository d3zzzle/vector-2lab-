#include "Vector.h"

int main()
{
  TDynamicVector<int> a(3);

  cout << a << '\n';

  TDynamicVector<int> f(a);
  cout << f << '\n';
  cout << (a == f) << '\n';

  int arr[3] = {0, 0, 2};

  TDynamicVector<int> b(arr, 3);

  TDynamicVector<int> c = a + b;

  cout << c;
}