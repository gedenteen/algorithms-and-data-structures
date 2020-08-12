#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long ans = 0;
void mergeSort2(vector<unsigned long> &a, long n)
{
  long step = 1;  // шаг разбиения последовательности
  vector<unsigned long> temp(n); // дополнительный массив
  while (step < n)  // пока шаг меньше длины массива
  {
    long index = 0;    // индекс результирующего массива
    long l = 0;      // левая граница участка
    long m = l + step;  // середина участка
    long r = l + step * 2;  // правая граница участка
    do
    {
      m = m < n ? m : n;  // сортируемый участок не выходит за границы последовательности
      r = r < n ? r : n;
      long i1 = l, i2 = m; // индексы сравниваемых элементов
      while (i1 < m && i2 < r) // пока i1 не дошёл до середины и i2 не дошёл до конца
      {
        if (a[i1] <= a[i2]) { temp[index++] = a[i1++]; } // заполняем участок результирующей последовательности
        else { 
             temp[index++] = a[i2++]; 
            ans = ans + m - i1;
            //printf("l=%d i1=%d m=%d i2=%d r=%d \n", l, i1, m, i2, r);
            }
      }
      while (i1 < m) {
          temp[index++] = a[i1++]; // заносим оставшиеся элементы сортируемых участков
      }
      while (i2 < r) {
          temp[index++] = a[i2++]; // в результирующий массив
      }
      l += step * 2; // перемещаемся на следующий сортируемый участок
      m += step * 2;
      r += step * 2;
    } while (l < n); // пока левая граница сортируемого участка - в пределах последоватльности
    for (long i = 0; i < n; i++) // переносим сформированный массив обратно в a
      a[i] = temp[i];
    step *= 2; // увеличиваем в 2 раза шаг разбиения
  }
}

int main() {
    long n, i, j;
    cin >> n;
    
    long pow = 0, n_copy = n, n_new;
    while (n_copy > 0){
        n_copy >>= 1;
        pow++;
    }
    n_new = 1 << pow;
    //printf("pow=%d n_new=%d \n", pow, n_new);
    
    vector<unsigned long> a(n_new);
    for(i = 0; i < n_new - n; i++)
        a[i] = 0;
    for (; i < n_new; i++)
        cin >> a[i];
    
    /*for (i=0; i < n_new; i++) {
       cout << a[i] << " ";
    }
    cout << endl;*/
    
    //mergeSort(a, 0, n-1); 
    mergeSort2(a, n_new);
    /*for (i=0; i < n_new; i++) {
       cout << a[i] << " ";
    }
    cout << endl;*/
    cout << ans << " ";
    return 0;
}
