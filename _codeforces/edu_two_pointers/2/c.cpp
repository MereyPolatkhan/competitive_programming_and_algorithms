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
    ll cnt = 0;

    for (ll r = 0; r < n; r++) {
        sum += a[r];
        while (sum > s) {
            sum -= a[l];
            l++;
        }
        cnt += r - l + 1;
    }

 
    cout << cnt;

    return 0;
}