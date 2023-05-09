#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll func(string s, char c) {
    ll k = 0;
    ll res = 0;
    for (ll i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            k++;
        }
        else {
            res = max(res, k);
            k = 0;
        }
    }
    res = max(res, k);
    return res;
}

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll zeros = 0;
    ll ones = 0;

    for (ll i = 0; i < n; i++) {
        if (s[i] == '0') {
            zeros++;
        } 
        else {
            ones++;
        }
    }

    ll max_zeros = func(s, '0');
    ll max_ones = func(s, '1');

    ll a = zeros * ones;
    ll b = max_ones * max_ones;
    ll c = max_zeros * max_zeros;
    // cout << s << endl; 
    // cout << "ll a = zeros * ones; -- " << a << "\n";
    // cout << "ll b = max_ones * max_ones; --" << b << "\n";
    // cout << "ll c = max_zeros * max_zeros; --" << c << "\n";
    // cout << "\n";
    

    cout << max(max(a, b), c) << "\n";
    return;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}