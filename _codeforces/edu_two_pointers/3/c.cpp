#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = 300000;

int main() {
    ll n, d;
    cin >> n >> d;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll l = 0;
    ll cnt = 0;
    
    for (ll r = 0; r < n; r++) {
        while (a[r] - a[l] > d) {
            // cout << l << " " << r << "\n";
            cnt += (n - r);
            l++;
        }
    }
    
    cout << cnt;


    return 0;
}