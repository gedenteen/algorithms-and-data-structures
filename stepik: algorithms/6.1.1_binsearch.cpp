#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int get_pos(const std::vector<int> &numbers, int number) {
  // TODO optimize this function
  int n = numbers.size(), l = 0, r = n, m, i;
    while (l < r) {
        m = (l + r) / 2;
        if (number > numbers[m])
            l = m + 1;
        else
            r = m;
    }
    if (number == numbers[l])
        return l + 1;
    else
        return -1;
}

int main(void) {
  size_t number_count;
  std::cin >> number_count;
  std::vector<int> numbers(number_count);
  for (auto &number:numbers) {
    std::cin >> number;
  }
  assert(std::is_sorted(numbers.begin(), numbers.end()));

  size_t query_count;
  std::cin >> query_count;
  while (query_count-- > 0) {
    int number;
    std::cin >> number;
    std::cout << get_pos(numbers, number) << " ";
  }
  std::cout << std::endl;
}
