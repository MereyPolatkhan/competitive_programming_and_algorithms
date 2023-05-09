#include <bits/stdc++.h>

using namespace std;

int binary_search(int x, int n, int a[]) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == x) {
            return mid;
        }
        else if (a[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int a[n];
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i != 0) {
            a[i] += a[i - 1];
        }
    }

    // for (int i = 0; i < n; i++) cout << a[i] << " " ;

    for (int i = 0; i < m; i++) {
        int line;
        cin >> line;
        cout << binary_search(line, n, a) + 1 << "\n";
    }


    return 0;
}