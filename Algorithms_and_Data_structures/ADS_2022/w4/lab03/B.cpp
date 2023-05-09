#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll binary(ll a[], ll n, ll k) {
    ll sum = 0, max = -(1e6);
    for (ll i = 0; i < n; i++) {
        sum += a[i];
        if (a[i] > max) {
            max = a[i];
        }
    }

    ll left = max;
    ll right = sum;

    ll ans = 0;
    while (left <= right) {
        ll cur_sum = 0;
        ll cnt = 1;
        ll mid = (left + right) / 2;

        for (ll i = 0; i < n; i++) {
            if (cur_sum + a[i] > mid) {
                cur_sum = a[i];
                cnt++;
            }
            else {
                cur_sum += a[i];
            }
        }

        if (cnt > k) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
            ans = mid;
        }
    }

    return ans;
}   

int main() {
    // freopen("input.txt", "r", stdin);
    ll n, k;
    cin >> n >> k;

    ll a[n];
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << binary(a, n, k);

    return 0;
}