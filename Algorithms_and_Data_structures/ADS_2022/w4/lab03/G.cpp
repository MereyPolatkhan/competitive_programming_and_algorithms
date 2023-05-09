#include <bits/stdc++.h>

using namespace std;


int main() {

    int n, f;
    cin >> n >> f;

    int a[n];
    int mx = -1e6;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int l = 1;
    int r = mx;

    int res;
    while (l <= r) {
        int cnt = 0;
        int mid = (l + r) / 2;

        for (int i = 0; i < n; i++) {
            int k = ceil((1.0*a[i]) / mid);
            cnt += k;
        }

        if (cnt <= f) {
            res = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << res;

    return 0;
}