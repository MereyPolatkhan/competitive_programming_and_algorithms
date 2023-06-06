#include <bits/stdc++.h>



using namespace std;

typedef long long ll;

double cubic_root(double a) {
    return pow(a, 1.0 / 3.0);
}

bool func(ll b) {
    if (b == 0) {
        return false;
    }
    ll y = ceil(cubic_root(b));
    return y * y * y == b;
}

void solve() { 

    ll x;
    cin >> x;

    for (ll a = 1; a <= (ll)cubic_root(x); a++) {
        if (func(x - a * a * a)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
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