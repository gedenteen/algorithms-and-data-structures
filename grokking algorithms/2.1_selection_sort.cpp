#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

int findSmallest(vector<int> &arr) {
    int n = arr.size();
	int smallest = arr[0];
	int smallest_ind = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < smallest) {
			smallest = arr[i];
			smallest_ind = i;
		}
	}
    arr[smallest_ind] = arr[n - 1];
    arr.pop_back();
	return smallest;
}

void selectionSort(vector<int> arr, vector<int> &newArr) {
    int n = arr.size();
	for (int i = 0; i < n; i++) {
		int smallest = findSmallest(arr);
		newArr[i] = smallest;
	}
}

int main() {
    srand(time(0));
	vector<int> arr1(5);
	int i;
	for (i = 0; i < 5; i++) {
		arr1[i] = rand() % 20;
		printf("%d ", arr1[i]);
	}
	printf("\n");
	vector<int> arr2(5);
	selectionSort(arr1, arr2);
	for (i = 0; i < 5; i++)
		printf("%d ", arr2[i]);
	printf("\n");
	return 0;
}
