#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 2000

int sum_cycle(int *arr, int size) {
	int rez = 0;
	for (int i = 0; i < size; i++)
		rez += arr[i];
	return rez;
}

int sum_recursion(int *arr, int size) {
	if (size == 1)
		return arr[0];
	if (size == 0)
		return 0;
	else
		return arr[size - 1] + sum_recursion(arr, size - 1);
}

int main() {
	srand(time(0));
	int *arr = (int*) malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100;
	struct timespec mt1, mt2;
	clock_gettime(CLOCK_REALTIME, &mt1);
	int rez = sum_cycle(arr, n);
	clock_gettime(CLOCK_REALTIME, &mt2);
   	double time_d = (double)(mt2.tv_sec - mt1.tv_sec) +
             (double)(mt2.tv_nsec - mt1.tv_nsec) / 1e9; ///время в секундах
	printf("sum_cycle: rez = %d, time = %e \n", rez, time_d);
	
	clock_gettime(CLOCK_REALTIME, &mt1);
	rez = sum_recursion(arr, n);
	clock_gettime(CLOCK_REALTIME, &mt2);
   	time_d = (double)(mt2.tv_sec - mt1.tv_sec) +
             (double)(mt2.tv_nsec - mt1.tv_nsec) / 1e9; ///время в секундах
	printf("sum_recursion: rez = %d, time = %e \n", rez, time_d);	
	
	return 0;
}
