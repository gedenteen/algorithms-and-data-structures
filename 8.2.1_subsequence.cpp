#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

int get_length_of_longest_divisible_subsequence(const std::vector<int> &numbers) {
    int result = 0;
    std::vector<size_t> D(numbers.size());
    for (size_t i = 0; i < numbers.size(); i++) {
        D[i] = 1;
        for (int j = 0; j < i; j++) {
            if (numbers[i] % numbers[j] == 0 && D[j] + 1 > D[i])
                D[i] = D[j] + 1;
        }
        //std::cout << D[i] << " ";
        if (D[i] > result) {
            result = D[i];
        }
    }
    return result;
}

int main(void) {
    size_t number_count;
    std::cin >> number_count;
    std::vector<int> numbers(number_count);
    for (auto &number:numbers) {
        std::cin >> number;
    }

    std::cout << get_length_of_longest_divisible_subsequence(numbers) << std::endl;
}
