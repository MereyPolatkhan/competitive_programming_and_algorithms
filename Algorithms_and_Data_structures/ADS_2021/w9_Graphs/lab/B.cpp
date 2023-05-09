// accepted
#include <bits/stdc++.h> 

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int a[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int mn = 1e6;

    int one, two, three;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (mn > a[i][j] + a[j][k] + a[i][k]) {
                    mn = a[i][j] + a[j][k] + a[i][k];
                    
                    one = i + 1;
                    two = j + 1;
                    three = k + 1;

                }
            }    
        }
    }

    cout << one << " " << two << " " << three;
    return 0;
}