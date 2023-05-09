#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = 300000;

int main() {
 
    ll n, s;
    cin >> n >> s;

    vector<ll> w(n);
    for (ll i = 0; i < n; i++) cin >> w[i];

    vector<ll> c(n);
    for (ll i = 0; i < n; i++) cin >> c[i];


    ll res = INT_MIN;
    ll l = 0;
    ll weight = 0;
    ll cost = 0;
    for (ll r = 0; r < n; r++) {
        weight += w[r];
        cost += c[r];
        while (weight > s) {
            weight -= w[l];
            cost -= c[l];
            l++;
        }

        res = max(res, cost);

    }

    cout << res;
    return 0;
}