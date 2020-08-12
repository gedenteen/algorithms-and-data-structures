#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, l;
    cin >> k >> l;
    int i, j;
    map<string, char> table;
    char c1, c2, c3;
    string st, code;

    for (i = 0; i < k; i++) {
        cin >> c1 >> c2;
        cin >> st;
        table.emplace(st, c1); ///добавление элемента в map
        //cout << st << table[st] << endl;
    }

    //getline(cin, code);
    string ans = "";
    st = "";
    for (i = 0; i < l; i++) {
        cin >> c1;
        st += c1;
        //cout << st << endl;
        auto itr = table.find(st);
        if (itr != table.end()) {
            //cout << itr->second;
            ans += itr->second;
            st = "";
        }
    }
    cout << ans << endl;
    return 0;
}
