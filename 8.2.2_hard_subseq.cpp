#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

#define ll long long

long binsearch_reverse(vector<long> &numbers, int number) {
  long n = numbers.size(), l = 0, r = n, m, i;
    while (l < r) {
        m = (l + r) / 2;
        if (number < numbers[m])
            l = m + 1;
        else
            r = m;
    }
    if (number == numbers[l])
        while (number == numbers[l])
            l++;
    return l;
}

void get_subsequence(const vector<long> &numbers) {
    long result = 0, n = numbers.size(), mxj = -1;
    vector<long> vals(n+1); ///vals[i] = равен мин. эл-ту в подпослед-ти длины i
    vector<long> val_inds(n+1); ///индексы из nums[] в vals[]
    vector<long> num_inds(n+1); ///индексы для восстановления подпослед-ти

    vals[0] = 1e9;
    num_inds[0] = -1;
    for (int i=1; i<n+1; ++i) {
        vals[i] = -1e9;
        num_inds[i] = -1;
    }

    for (long i=0; i<n; i++) {
        long j = long (binsearch_reverse(vals, numbers[i]));
        if (vals[j-1] >= numbers[i] && numbers[i] > vals[j]) {
            vals[j] = numbers[i];
            val_inds[j] = i;
            num_inds[i] = val_inds[j-1];
            if (j >  mxj)
                mxj = j;
        }
    }
    printf("%ld \n", mxj);
    
    /*for(long i = 0; i < n; i++)
       printf("\n num_inds[%ld] = %ld ", i, num_inds[i]);  
    for(long i = 0; i < n; i++)
       printf("\n vals[%ld] = %ld ", i, vals[i]); */
    
    vals[0] = val_inds[ mxj];
    long j = mxj;
    long i = 0;
    j = val_inds[ j];
    do {
        vals[++i] = j;
        j = num_inds[j];
    } while (j != 0);
    vals[++i] = j;
    
    //printf("\n");
    for (j = mxj; j >= 1; j--)
        printf("%ld ", vals[j]+1);
    
    return;
}

int main(void) {
    long number_count;
    cin >> number_count;
    vector<long> numbers(number_count);
    for (auto &number:numbers) {
        cin >> number;
    }

    get_subsequence(numbers);
}
