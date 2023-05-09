#include <bits/stdc++.h>

using namespace std;


int bs(int a[], int n, int x) {
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

    return l;
}

int main(){     
    int n, m;
    cin >> n >> m;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);


    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        cout << "res: " << a[bs(a, n, x)] << "\n";

    }





    return 0;
}