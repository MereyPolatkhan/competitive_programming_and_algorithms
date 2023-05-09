#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n, k;
    cin >> n >> k;


    vector<ll> a;

    for (ll i = 0; i < n; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ll x = max(y2, x2);

        a.push_back(x);
    }
    ll l = 1;
    ll r = 1e9;
    ll ans;

    while (l <= r) {
        ll cnt = 0;
        ll mid = (l + r) / 2;
         
        for (auto x: a) {
            if (x <= mid) {
                cnt++;
            }
        }

        if (cnt >= k) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans;


    return 0;
}