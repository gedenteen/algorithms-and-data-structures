#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long i, n;
    
    cin >> n;
    vector<long long> a(n+1), d(n+1);
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        if (i >= 2)
            d[i] = a[i] + max(d[i-1], d[i-2]);
        else
            d[1] = a[1];
    }
    cout << d[n] << endl;
    
    return 0;
}
