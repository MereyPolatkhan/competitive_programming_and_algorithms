#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m = n;

    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i != j) {
                a[i][j] = abs(a[i][j] - 1);
            }
        }
    }
    

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";

        }
        cout << "\n";
    }
    

    return 0;
}