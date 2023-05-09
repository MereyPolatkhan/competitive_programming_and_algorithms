#include <bits/stdc++.h>

using namespace std;

int a[300][300];

int main() {

    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 and j == 1) {
                a[i][j] = 1;
            }        
            if (a[i][j] >= 1) {
                a[i + 1][j + 2] += a[i][j];
                a[i + 2][j + 1] += a[i][j];
            }
        }
    }
    
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    cout << a[n][m];
    return 0;
}