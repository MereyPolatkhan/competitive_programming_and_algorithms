#include <bits/stdc++.h>

using namespace std;

long long f[100];

void fac(long long n) {
    long long h = 1;
    for (long long i = 1; i <= n; i++) {
        h *= i;
        f[i] = h;
    }
}

int main() {

    long long n;
    cin >> n;

    fac(n);

    vector<long long> a(n);
    
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long res = 0;
    for (long long i = 0; i < n; i++) {
        long long cnt = 0;
        for (long long j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                cnt++;
            }
        } 
        res += cnt * f[n - i - 1];
    }


    cout << res + 1;

    return 0;
}