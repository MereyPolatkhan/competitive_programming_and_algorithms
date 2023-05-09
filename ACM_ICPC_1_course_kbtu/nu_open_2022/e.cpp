#include <bits/stdc++.h>

using namespace std;


long long bs_r(long long * a, long long n, long long x) {
    long long l = 0;
    long long r = n - 1;

    while (l <= r) {
        long long mid = (l + r) / 2;
        if (a[mid] <= x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return r;
}

long long bs_l(long long * a, long long n, long long x) {
    long long l = 0;
    long long r = n - 1;

    while (l <= r) {
        long long mid = (l + r) / 2;
        if (a[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return l;
}

long long res(long long * a, long long n, long long l, long long r) {
    return bs_r(a, n, r) - bs_l(a, n, l) + 1;
}

void seg(long long * a, long long n, long long l, long long r) {
    long long right_most = bs_r(a, n, r);
    long long left_most = bs_l(a, n, l);

    long long delta = r - a[right_most];
    if (delta <= 0){
        return;
    }

    for (long long i = left_most; i <= right_most; i++) {
        a[i] += delta;
    }
    return;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    // freopen("input.txt", "r", stdin);
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);


    long long m;
    cin >> m;

    for (long long i = 0; i < m; i++) {
        long long t, l, r;
        cin >> t >> l >> r;

        if (t == 1) {
            if (a[n - 1] < l) {
                continue;
            }
            if (r < a[0]) {
                continue;
            }
            seg(a, n, l, r) ;
            sort(a, a + n);
        }
        else if (t == 2) {
            if (a[n - 1] < l) {
                cout << 0 << "\n";
            }
            if (r < a[0]) {
                cout << 0 << "\n";
            }
            cout << res(a, n, l, r) << "\n";
        }
    }

    return 0;
}