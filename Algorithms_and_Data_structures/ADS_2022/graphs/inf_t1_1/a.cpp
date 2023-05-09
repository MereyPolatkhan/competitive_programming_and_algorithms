#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int g[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> g[i][j];
        }
    }
    int k = 0;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (g[i][j] == 1) {
                k++;
            }
        }
    }
    cout << k;
    

    return 0;
}