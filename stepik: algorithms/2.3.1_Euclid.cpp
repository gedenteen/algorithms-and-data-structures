#include <cassert>
#include <iostream>

template <class Int>
Int gcd(Int a, Int b) {
  assert(a > 0 && b > 0);
  // optimize this function
  int pa = a, pb = b;
  while (1)
  {
      if (pa == 0)
          return pb;
      if (pb == 0)
          return pa;
      if (pa >= pb)
          pa = pa % pb;
      else
          pb = pb % pa;
  }
  return 1;
}

int main(void) {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
