#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = 100000;

int main() {

    vector<ll> pref(N + 7, 0);
    for (ll i = 0; i < pref.size(); i++) {
        pref[i] = i;
    }
    for (ll i = 1; i <= N; i++) {
        pref[i] += pref[i - 1];
    }


    ll n, s;
    cin >> n >> s;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll l = 0;
    ll sum = 0;
    ll res = 0;
    for (ll r = 0; r < n; r++) {
        sum += a[r];
        while (sum > s) {
            sum -= a[l];
            l++;
        }
        res += pref[r - l + 1];
    }
    cout << res;


    return 0;
}