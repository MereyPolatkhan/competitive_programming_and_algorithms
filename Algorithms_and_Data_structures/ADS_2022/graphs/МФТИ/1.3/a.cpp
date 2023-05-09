#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int a[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && a[i][j] == 1) {k++;}
        }
    }
    cout << k;
    

    return 0;
}