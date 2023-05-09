#include <iostream>
#include <algorithm>

using namespace std;

long long bs(long long a[], long long n, long long x, long long lr) {
    long long l = 0;
    long long r = n - 1;

    while (l <= r) {
        long long mid = (l + r) / 2;
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

    if (lr == 0) {
        return l;
    }
    else return r;
}

long long num_of_indeces(long long l, long long r, long long a[], long long n) {
    return bs(a, n, r, 1) - bs(a, n, l, 0) + 1;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;
    
    long long a[n];
    for (long long i = 0; i < n; i++) {
        cin >> a[i];    
    }
    sort(a, a + n);
    for (long long i = 0; i < m; i++) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if (r1 < l2 || r2 < l1) {
            cout << num_of_indeces(l1, r1, a, n) + num_of_indeces(l2, r2, a, n) << "\n";
        }
        else {
            long long l = min(l1, l2);
            long long r = max(r1, r2);

            cout << num_of_indeces(l, r, a, n) << "\n";
        }
    }
    
    return 0;
}