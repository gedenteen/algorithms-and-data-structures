#include <stdio.h>
#include <vector>

int binsearch(int* arr, int n, int value) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int guess = arr[mid];
        if (guess == value)
            return mid;
        if (guess > value)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main() {
    int arr[5] = {1, 3, 5, 7, 9};
    printf("%d %d \n", binsearch(arr, 5, 9), binsearch(arr, 5, -1));

    return 0;
}
