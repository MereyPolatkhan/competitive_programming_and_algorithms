#include <iostream>

using namespace std;

int binary(int x, int n, int a[]) {
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x) {
            return mid;
        }
        else if (a[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    cin >> x;

    if (binary(x, n, a) == -1) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }
}