#include <string>
#include <iostream>
using namespace std;

int EditDistBU(string sa, string sb)
{
    int la, lb;
    la = sa.length() + 1;
    lb = sb.length() + 1;
    
    int D[la][lb], i, j;
    for (i = 0; i < la; i++)
        D[i][0] = i;
    for (i = 0; i < lb; i++)
        D[0][i] = i;
    
    for (i = 1; i < la; i++) {
        for (j = 1; j < lb; j++) {
            int c = 0;
            if (sa[i-1] != sb[j-1])
                c = 1;
            D[i][j] = min(D[i-1][j] + 1, D[i][j-1] + 1);
            D[i][j] = min(D[i][j], D[i-1][j-1] + c);
        }
    }
    
    return D[la-1][lb-1];
}

int main() {
    string sa, sb;
    cin >> sa >> sb;
    
    cout << EditDistBU(sa, sb);
    return 0;
}
