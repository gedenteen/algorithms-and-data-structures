#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int n;
    cin >> n;
    
    int a[n], nums[11] = {0}; 
    forn(i, n) {
        cin >> a[i];
        nums[a[i]]++;
    }
    forn(i, 11) {
        while(nums[i]--) {
            cout << i << " ";
        }
    }
    return 0;
}
