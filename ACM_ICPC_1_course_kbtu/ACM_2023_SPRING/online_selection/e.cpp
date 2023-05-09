#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {


    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;


    unordered_set<char> stt;

    for (ll i = 0; i < k; i++) {
        char x;
        cin >> x;
        stt.insert(x);
    }

    vector<bool> a(n, false);

    for (ll i = 0; i < n; i++) {
        if (stt.count(s[i]) == 1) {
            a[i] = true;
        }
    }

    // for (bool i: a) cout << i << " ";
    // cout <<"\n";
    vector<ll> b;
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] == 1) {
            cnt++;
        }
        else {
            b.push_back(cnt);
            cnt = 0;
        }
    }
    b.push_back(cnt);
    cnt = 0;

    ll res = 0;

    for (ll i: b) {
        if (i != 0)
            res += (i * (i+1) / 2);
    }

    cout << res << "\n";
}


int main() {
    // freopen("input.txt", "r", stdin);
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}