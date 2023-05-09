// accepted
#include <bits/stdc++.h> 

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int colors[n];
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[i][j] == 1 && colors[i] != colors[j]) {
                k++;
            }        
        }
    }

    cout << k;




    return 0;
}