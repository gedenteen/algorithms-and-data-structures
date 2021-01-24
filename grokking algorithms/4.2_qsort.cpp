#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

#define N 25

vector<int> my_qsort(vector<int> arr) {
	if (arr.size() < 2)
		return arr;
	
	int pivot = arr[0]; //опорный элемент
	vector<int> less, greater;
	for (long unsigned i = 1; i < arr.size(); i++) {
		if (arr[i] <= pivot) 
			less.push_back(arr[i]);
		else
			greater.push_back(arr[i]);
	}
	vector<int> arr_sorted = my_qsort(less); //получаем рекурсивно отсортированную левую часть
	arr_sorted.push_back(pivot); //добавляем опорный элемент
	vector<int> greater_sorted = my_qsort(greater); //сортируем правую часть
	arr_sorted.reserve(arr_sorted.size() + greater_sorted.size()); //выделяем память
	//и соединяем массивы:
	arr_sorted.insert(arr_sorted.end(), greater_sorted.begin(), greater_sorted.end());
	return arr_sorted;
}

int main() {
	srand(time(0));
	int n = 25;
	vector<int> arr_for_sort(n);
	for (int i = 0; i < n; i++) {
		arr_for_sort[i] = rand() % 10;
		printf("%d ", arr_for_sort[i]);
	}
	
	vector<int> arr_after_sort = my_qsort(arr_for_sort);
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr_after_sort[i]);
	}
	printf("\n");
	
	return 0;
}
