#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ll n, s;
    cin >> n >> s;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    ll l = 0;
    ll sum = 0;
    ll res = INT_MAX;


    for (ll r = 0; r < n; r++) {
        sum += a[r];
        while (sum - a[l] >= s) {
            sum -= a[l];
            l++;
        }
        if(sum >= s) res = min(res, r - l + 1);
    }

    if (res == INT_MAX) {
        cout << -1;
        return 0;
    }

    cout << res;


    return 0;
}