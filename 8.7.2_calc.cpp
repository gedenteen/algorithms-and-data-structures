#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, i, j;
    
    cin >> n;
    vector<long long> d(n+1, 1e9), ind(n+1, -1);
    d[1] = 0;
    for (i = 2; i <= n; i++) {
        if (i % 3 == 0 && d[i/3] + 1 < d[i]) {
            d[i] = d[i/3] + 1;
            ind[i] = i/3;
        }
        if (i % 2 == 0 && d[i/2] + 1 < d[i]) {
            d[i] = d[i/2] + 1;
            ind[i] = i/2;
        }
        if (d[i-1] + 1 < d[i]) {
            d[i] = d[i-1] + 1;
            ind[i] = i-1;
        } 
    }
    
    cout << d[n] << endl;
    i = n;
    vector<long long> ans;
    ans.push_back(n);
    while (ind[i] != -1) {
        ans.push_back(ind[i]);
        i = ind[i];
    }
    for (i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}
