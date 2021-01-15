#include <iostream>
#include <stdio.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

void quickSort(long a[], long l, long r) {
// На входе - массив a[], a[N] - его последний элемент.

  long i = l, j = r; 		// поставить указатели на исходные места
  long temp, p;

  p = a[ (l + r) / 2 ];		// центральный элемент

  // процедура разделения
  do {
    //printf("i=%d j=%d \n", i, j);
    while ( a[i] < p ) i++;
    while ( a[j] > p ) j--;

    if (i <= j) {
      temp = a[i]; a[i] = a[j]; a[j] = temp;
      i++; j--;
    }
  } while ( i<=j );

  // рекурсивные вызовы, если есть, что сортировать
  if ( l < j ) quickSort(a, l, j);
  if ( r > i ) quickSort(a, i, r);
}

int main() {
    long n, m;
    cin >> n >> m;
    long lp[n], rp[n], pnts[m];

    forn(i, n) {
        cin >> lp[i] >> rp[i];
        //cout << a << " " << b << endl;
    }

    //forn(i, n)
    //    cout << lp[i] << endl;
    quickSort(lp, 0, n-1);
    quickSort(rp, 0, n-1);
    //forn(i, n)
    //    cout << "f5 " << lp[i] << " " << rp[i] << endl;

    forn(i, m) {
        cin >> pnts[i];
        long p1 = 0, p2 = 0;
        int l = 0, r = n, m;
        while (l < r) { ///бинпоиск для левой границы
            m = (l + r) / 2;
            if (pnts[i] > lp[m])
                l = m + 1;
            else
                r = m;
        }
        if (pnts[i] == lp[l]) {
            //l++;
            while (l != n && pnts[i] == lp[l]) {
                l++;
            }
        }
        p1 = l;
        
        l = 0, r = n, m;
        while (l < r) { ///бинпоиск для правой границы
            m = (l + r) / 2;
            if (pnts[i] > rp[m])
                l = m + 1;
            else
                r = m;
        }
        if (pnts[i] == rp[l]) {
            //l--;
            while (pnts[i] == rp[l-1]) {
                l--;
            }
        }
            p2 = l;
        
        //printf("p1=%d p2=%d \n", p1, p2);
        cout << p1 - p2 << endl;
    }

    return 0;
}
