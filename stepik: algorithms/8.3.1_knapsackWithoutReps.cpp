#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define ll long long

ll KnapsackWithoutReps() {
    ll capacity, n;
    cin >> capacity >> n;
    ///массив для каждого кг рюкзака в зависимости от кол-ва слитков:
    vector<vector<ll>> backpack(capacity+1, vector<ll> (n+1));
    ///массив весов слитков:
    vector<ll> ingots(n+1); 
    for (ll i = 1; i <= n; i++)
        cin >> ingots[i];
    forn(i, capacity+1)
        backpack[i][0] = 0;
    forn(i, n+1)
        backpack[0][i] = 0;
    
    for (ll i = 1; i <= n; i++) {
        for (ll w = 1; w <= capacity; w++) {
            backpack[w][i] = backpack[w][i-1];
            if (ingots[i] <= w)   
                backpack[w][i] = max(backpack[w][i], backpack[w-ingots[i]][i-1] + ingots[i]);
            //printf("b[%lld][%lld] = %lld \n", w, i, backpack[w][i]);
        }
    }
    return backpack[capacity][n];
}

int main() {
    cout << KnapsackWithoutReps();
    return 0;
}
