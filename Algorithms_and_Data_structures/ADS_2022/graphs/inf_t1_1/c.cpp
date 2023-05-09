#include <iostream>

using namespace std;


int main(){
    int n;
    cin >> n;

    int g[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k = 0;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (g[i][j] == 1) {
                if (a[i] != a[j]) {
                    k++;
                }
            }
        }
    }

    cout << k;


    return 0;
}