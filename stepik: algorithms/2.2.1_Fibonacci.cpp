#include <cassert>
#include <iostream>

class Fibonacci {
 public:
  static int get(int n) {
    assert(n >= 0);
    long int arr[n];
    arr[0] = 0; arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
         arr[i] = arr[i-2] + arr[i-1];   
    }
    return arr[n];
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get(n) << std::endl;
  return 0;
}
