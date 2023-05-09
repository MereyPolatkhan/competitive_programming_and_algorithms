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

    int even = 0, odd = 0;

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                cnt++;
                if (i == j) {
                    cnt++;
                }
            }
        }
        if (cnt % 2 == 0) even++;
        else odd++;
    }

    
    cout << even << " " << odd;

    return 0;
}