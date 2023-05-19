#include <bits/stdc++.h>



using namespace std;

typedef long long ll;

ll func(vector<ll> & a, vector<ll> & b) {
    ll d = a[0];
    for (int i = 1; i < a.size(); i++) {
        d = __gcd(d, a[i]);
    }

    if (d == 1) {
        return 0;
    }

    for (int i = 0; i < b.size(); i++) {
        if (b[i] % d == 0) {
            return 0;
        }
    }
    return d;
}

void solve() {
    int n;
    cin >> n;

    vector<ll> blue, red;

    for (int i = 1; i <= n; i++) {
        ll x; 
        cin >> x;
        if (i % 2 == 0) {
            blue.push_back(x);
        }
        else {
            red.push_back(x);
        }
    }   
    // cout << "here\n";
    ll fst = func(blue, red);
    ll scd = func(red, blue);

    if (fst > 0 || scd > 0) {
        if (fst > 0) {
            cout << fst << "\n";
        }
        else {
            cout << scd << "\n";
        }
    }
    else {
        cout << 0 << "\n";
    }
}   


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}