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

    int stok = 0;
    int istok = 0;

    for (int i = 0; i < n; i++) {
        bool flag1 = true;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                flag1 = false;
                break;
            }
        }
        if (flag1) {
            stok++;
        }
    }

    for (int j = 0; j < n; j++){
        bool flag2 = true;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == 1) {
                flag2 = false;
                break;
            }
        }
        if (flag2) {
            istok++;
        }
    }


    cout << istok << " " << stok;


    return 0;
}