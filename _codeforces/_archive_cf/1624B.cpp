#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool checker(ll c2, ll c) {
    if ((c2 > 0 and c > 0) || (c2 < 0 and c < 0)) {
        return c2 % c == 0;
    }
    return false;
}

bool ab(ll a, ll b, ll c) { 
    ll d = b - a;
    ll c2 = b + d;

    return checker(c2, c);
}

bool bc(ll a, ll b, ll c) {
    ll d = c - b;
    ll a2 = b - d; 
    return checker(a2, a);
}

bool ac(ll a, ll b, ll c) {
    if ((c - a) % 2 == 0) {
        ll b2 = (c - a) / 2 + a;
        return checker(b2, b);
    }
    return false;
}

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;

    if (ab(a, b, c) || bc(a, b, c) || ac(a, b, c)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout << "\n-----------RESULTS---------\n";
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}