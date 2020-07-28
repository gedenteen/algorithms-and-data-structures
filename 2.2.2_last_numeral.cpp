#include <cassert>
#include <iostream>

class Fibonacci {
 public:
  static int get_last_digit(int n) {
    assert(n >= 1);
    int fnm1 = 1, fnm2 = 0; //f[i-1], f[i-2], в начале f[1], f[0]
    int fnm0;
    //if (n == 0)
    //    return fnm2;
    if (n == 1)
        return fnm1;
    for (int i = 2; i <= n; i++)
    {
        fnm0 = (fnm1 + fnm2) % 10;
        fnm2 = fnm1;
        fnm1 = fnm0;
    }
    return fnm0;
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get_last_digit(n) << std::endl;
  return 0;
}
