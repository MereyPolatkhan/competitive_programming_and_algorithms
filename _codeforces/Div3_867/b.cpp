#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> pi;

void solve() {
    long long n;
    cin >> n;

    if (n == 2){
        long long a, b;
        cin >> a >> b;
        cout << a * b << "\n";
        return;
    }
    
    vector<long long> minus;
    vector<long long> plus;

    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (x > 0) {
            plus.push_back(x);
        }
        else if (x < 0) {
            minus.push_back(x);
        }
    }

    long long res = 0;
    if (plus.size() >= 2) {
        sort(plus.rbegin(), plus.rend());
        res = max(res, plus[0] * plus[1]);
    }
    if (minus.size() >= 2) {
        sort(minus.begin(), minus.end());
        res = max(res, minus[0] * minus[1]);
    }

    cout << res << "\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long q;
    cin >> q;
    while (q--) {
        solve();
    }

    return 0;
}