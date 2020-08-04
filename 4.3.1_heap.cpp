#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long i, n, j, y;
    vector<long long> tree(1);

    cin >> n;
    for (i = 0; i < n; i++) {
        string st;
        long long val, temp, range = 1, size;

        cin >> st;
        if (st == "Insert") {
            cin >> val;
            tree.push_back(val);
            j = tree.size() - 1;
            while (1) {
                int y = j / 2; ///родитель
                if (y == 0)
                    break;
                //cout << "y=" << y << endl;
                if (tree[j] > tree[y]) {
                    temp = tree[j];
                    tree[j] = tree[y];
                    tree[y] = temp;
                    j = y;
                }
                else
                    break;
            }
                
        }
        else if (st == "ExtractMax") { ///extract
            if (tree.size() == 1) 
                continue;
            if (tree[1] == -1)
                continue;
            cout << tree[1] << endl;
            
            j = 1;
            while (1) {
                int y = j * 2; ///ребенок
                if (tree.size() - 1 < y)
                    break;
                if (tree.size() - 1 >= y + 1) {
                    if (tree[y] < tree[y+1]) 
                        y++;
                }
                if (tree[j] >= tree[y]) {
                    temp = tree[j];
                    tree[j] = tree[y];
                    tree[y] = temp;
                    j = y;
                } else
                    break;
            }
            //temp = temp[j];
            tree[j] = -1;
        }
        /*cout << i << ": ";
        for (j = 0; j < tree.size(); j++)
            cout << tree[j] << " ";
        cout << endl;*/
    }
    return 0;
}
