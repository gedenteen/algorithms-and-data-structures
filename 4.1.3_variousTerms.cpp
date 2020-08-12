#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    long int n, k = 0;
    cin >> n;
    /*if (n == 2)
    {
        printf("1 \n2 \n");
        return 0;
    }*/
    vector<long int> arr;
    long int numeral = 0, number = 0; //цифра, число
    while (number != n)
    {
        if (n - number >= numeral * 2 + 3) //следующая цифра + позаследующая цифра
            numeral++;
        else
            numeral = n - number;
        number += numeral;
        arr.push_back(numeral);
        k++;
    }
    
    cout << k << endl;
    for (int i = 0; i < k; i++)
        cout << arr[i] << " ";
    return 0;
}
