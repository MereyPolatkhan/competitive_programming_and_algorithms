#include <iostream>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    char a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    char c;
    cin >> c;

    int l = 0;
    int r = n - 1;
    
    while (l <= r) {
        int mid = (l + r) / 2;

        if (a[mid] <= c) {
            l = mid + 1;
        }    
        else {
            r = mid - 1;
        }
    }
    if (l >= n) {
        cout << a[0];
    }
    else {
        cout << a[l];
    }
    return 0;
}