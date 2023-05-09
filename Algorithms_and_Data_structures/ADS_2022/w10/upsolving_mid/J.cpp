#include <bits/stdc++.h>

using namespace std;


void solve() {
    long long sum;
    cin >> sum;

    long long n;
    cin >> n;

    long long a[n];

    for (long long i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    long long l = 0;
    long long r = n - 1;
    while (l <= r) {
        if (a[l] + a[r] == sum) {
            cout << a[l] << " " << a[r];
            return;
        }
        else if (a[l] + a[r] < sum) {
            l++;
        }
        else {
            r--;
        }
    }
}

int main() {

    solve();

    return 0;
}