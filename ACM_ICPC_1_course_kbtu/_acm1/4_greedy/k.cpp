#include <bits/stdc++.h>

using namespace std;

bool check(long long teams, vector<long long> & a, long long m) {
    long long cnt = 0;
    long long delta = 0;
    for (long long i = 0; i < a.size(); i++) {
        if (a[i] >= teams) {
            cnt++;
        }
        else {
            delta += a[i];
            while (delta < teams) {
                i++;
                if (i < a.size()) delta += a[i];
                else break;
            }
            if (delta >= teams) {
                cnt++;
                delta -= teams;
            }
        }
    }
    return cnt >= m;
}

int main() {
    freopen("justforfood.in", "r", stdin);
    freopen("justforfood.out", "w", stdout);

    long long n;
    cin >> n;

    long long m;
    cin >> m;

    vector<long long> a(n);


    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    long long l = 1;
    long long r = 0;
    for (int i : a) r += i; r+=1;

    long long res = -1;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid, a, m)) {
            res = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << res;

    return 0;
}